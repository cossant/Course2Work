#include "main-form.h"

System::Void HotelInfoSystem::mainform::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	enactCommand(textBox1->Text);
	if (textBox1->Text->Contains("SELECT"))
		showTable("Гость");
	descLabel->Text = L"Нестандартная команда исполнена.";
	return System::Void();
}

System::Void HotelInfoSystem::mainform::enactCommand(System::String^ command)
{
	oleDbConnection1->Open();
	myDs = gcnew DataSet();
	oleDbSelectCommand1->Connection = oleDbConnection1;
	oleDbSelectCommand1->CommandText = command;
	oleDbSelectCommand1->ExecuteNonQuery();
	oleDbDataAdapter1->Fill(myDs);
	oleDbConnection1->Close();
	button8->Enabled = false;
}

System::Void HotelInfoSystem::mainform::button5_Click(System::Object^ sender, System::EventArgs^ e)
{
	dataaskform^ tempform = gcnew dataaskform();
	System::Windows::Forms::DialogResult result = tempform->ShowDialog();
	if (result == System::Windows::Forms::DialogResult::OK)
	{
		System::String^ date = tempform->dateTimePicker1->Value.ToString("yyyy-MM-dd");
		enactCommand(L"SELECT Номер.Код_номера FROM Номер WHERE ((Номер.Код_номера) Not In "
			+ L"(SELECT Договор.Код_номера FROM Договор WHERE((#" + date + L"#   >= Дата_подписания) AND(#" 
			+ date + "# <= (Дата_подписания + Длительность)))))");
		showTable("Гость");
		descLabel->Text = L"Свободные на " + date + " номера:";
	}
	return System::Void();
}

System::Void HotelInfoSystem::mainform::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
	enactCommand(L"SELECT Договор.Код_паспорта, Гость.Фамилия, Договор.Код_номера "
		+ L"FROM Договор LEFT JOIN Гость ON Договор.Код_паспорта = Гость.Код_паспорта "
		+ L"WHERE Договор.Код_договора IN "
		+ L"(SELECT Код_договора "
		+ L"FROM Договор "
		+ L"WHERE((Date() >= Дата_подписания) AND(Date() <= Дата_подписания + Длительность)));");
	showTable("Гость");
	descLabel->Text = L"Проживающие в гостинице на данный момент:";
	return System::Void();
}

System::Void HotelInfoSystem::mainform::button6_Click(System::Object^ sender, System::EventArgs^ e)
{	
	dataaskform^ tempform = gcnew dataaskform();
	System::Windows::Forms::DialogResult result = tempform->ShowDialog();
	if (result == System::Windows::Forms::DialogResult::OK)
	{
		System::String^ date = tempform->dateTimePicker1->Value.ToString("yyyy-MM-dd");
		enactCommand(L"SELECT Гость.Фамилия, Договор.Код_паспорта, Договор.Код_номера "
			+ L"FROM (Договор INNER JOIN Гость ON (Гость.Код_паспорта = Договор.Код_паспорта)) "
			+ L"WHERE ((Договор.Дата_подписания + Договор.Длительность) = #" + date + L"#);");
		showTable("Гость");
		descLabel->Text = L"Освобождающие номера " + date + " гости:";
	}
	return System::Void();
}

System::Void HotelInfoSystem::mainform::button7_Click(System::Object^ sender, System::EventArgs^ e)
{
	askdaysform^ tempDialForm = gcnew askdaysform();
	if (tempDialForm->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		System::Int32^ daysNeeded = Int32(tempDialForm->numericUpDown1->Value);
		enactCommand("SELECT Гость.Код_паспорта, Гость.Фамилия, Гость.Имя, Гость.Отчество, Sum(Договор.Длительность) AS [Общий срок проживания] "
			+ L"FROM Гость INNER JOIN Договор ON Гость.Код_паспорта = Договор.Код_паспорта "
			+ L"GROUP BY Гость.Код_паспорта, Гость.Фамилия, Гость.Имя, Гость.Отчество "
			+ L"HAVING(((Sum(Договор.Длительность)) >"+daysNeeded+"));");
		showTable("Гость");
		descLabel->Text = L"\"Долгожители\" гостиницы:";
	}
	return System::Void();
}

System::Void HotelInfoSystem::mainform::button8_Click(System::Object^ sender, System::EventArgs^ e)
{
	System::Windows::Forms::DataGridViewSelectedRowCollection^ guests =  dataGridView1->SelectedRows;
	if (guests->Count > 0)
	{
		System::Windows::Forms::DialogResult result = MessageBox::Show("Вы уверены, что хотите удалить из системы "
			+ guests->Count + " гостей?", L"Удаление гостей", MessageBoxButtons::OKCancel);
		if (result == System::Windows::Forms::DialogResult::OK)
		{
			for (int i = 0; i < guests->Count; i++)
			{
				enactCommand(L"DELETE * FROM Гость WHERE Код_паспорта = " + guests[i]->Cells[0]->Value->ToString() + L";");
			}
			button3_Click(sender, e);
		}
	}
	else
		MessageBox::Show("Не выделено ни одной строки с гостем для удаления");
	return System::Void();
}

System::Void HotelInfoSystem::mainform::button9_Click(System::Object^ sender, System::EventArgs^ e)
{
	addcontractform^ tempaddingform = gcnew addcontractform(oleDbConnection1, oleDbDataAdapter1);
	if (tempaddingform->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		enactCommand(L"INSERT INTO Договор (Код_номера, Код_паспорта, Дата_подписания, Длительность) "
			+ L"VALUES("+tempaddingform->comboBox1->SelectedValue->ToString()+", "+tempaddingform->comboBox2->SelectedValue->ToString()
			+", #"+tempaddingform->dateTimePicker1->Value.ToString("yyyy-MM-dd") + "#, "+Int32(tempaddingform->numericUpDown1->Value)+"); ");
		MessageBox::Show("Договор с указанными характеристиками создан.","Договор", MessageBoxButtons::OK);
	}
	oleDbSelectCommand1->CommandText = L"SELECT Гость.*, Договор.*, Номер.* FROM((Гость INNER JOIN Договор ON Гость.[Код_паспорта] = Договор.[Код_паспорта]) INNER JOIN Номер ON Договор.[Код_номера] = Номер.[Код_номера])";
	oleDbDataAdapter1->SelectCommand = oleDbSelectCommand1;
	return System::Void();
}

System::Void HotelInfoSystem::mainform::showTable(System::String^ table)
{
	dataGridView1->DataSource = myDs;
	dataGridView1->DataMember = table;
	return System::Void();
}

System::Void HotelInfoSystem::mainform::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	addguestform^ tempform = gcnew addguestform(oleDbConnection1, oleDbDataAdapter1);
	tempform->ShowDialog();
	button3_Click(sender, e);
	return System::Void();
}

System::Void HotelInfoSystem::mainform::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	enactCommand(L"SELECT * FROM Гость;");
	showTable("Гость");
	descLabel->Text = L"Зарегистрированные гости";
	button8->Enabled = true;
	return System::Void();
}
