#include "main-form.h"

System::Void HotelInfoSystem::mainform::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	enactCommand(textBox1->Text);
	if (textBox1->Text->Contains("SELECT"))
		showTable("Гость");
	return System::Void();
}

System::Void HotelInfoSystem::mainform::enactCommand(System::String^ command)
{
	oleDbConnection1->Open();
	myDs = gcnew DataSet();
	oleDbSelectCommand1->Connection = oleDbConnection1;
	oleDbSelectCommand1->CommandText = command;
	oleDbDataAdapter1->Fill(myDs);
	oleDbConnection1->Close();
}

System::Void HotelInfoSystem::mainform::button5_Click(System::Object^ sender, System::EventArgs^ e)
{
	dataaskform^ tempform = gcnew dataaskform();
	System::Windows::Forms::DialogResult result = tempform->ShowDialog();
	if (result == System::Windows::Forms::DialogResult::OK)
	{
		System::String^ date = tempform->dateTimePicker1->Value.ToString("yyyy-MM-dd");
		date = L"SELECT Номер.Код_номера FROM Номер WHERE ((Номер.Код_номера) Not In "
			+ L"(SELECT Договор.Код_номера FROM Договор WHERE((#"+date+L"#   >= Дата_подписания) AND(#"+date+"# <= (Дата_подписания + Длительность)))))";
		enactCommand(date);
		showTable("Гость");
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
	return System::Void();
}

System::Void HotelInfoSystem::mainform::button6_Click(System::Object^ sender, System::EventArgs^ e)
{	
	dataaskform^ tempform = gcnew dataaskform();
	System::Windows::Forms::DialogResult result = tempform->ShowDialog();
	if (result == System::Windows::Forms::DialogResult::OK)
	{
		System::String^ date = tempform->dateTimePicker1->Value.ToString("yyyy-MM-dd");
		date = L"SELECT Гость.Фамилия, Договор.Код_паспорта, Договор.Код_номера "
			+ L"FROM (Договор INNER JOIN Гость ON (Гость.Код_паспорта = Договор.Код_паспорта)) "
			+ L"WHERE ((Договор.Дата_подписания + Договор.Длительность) = #" + date + L"#);";
		enactCommand(date);
		showTable("Гость");
	}
	return System::Void();
}

System::Void HotelInfoSystem::mainform::button7_Click(System::Object^ sender, System::EventArgs^ e)
{
	askdaysform^ tempDialForm = gcnew askdaysform();
	if (tempDialForm->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		System::Int32^ daysNeeded = Int32(tempDialForm->numericUpDown1->Value);
		enactCommand("SELECT Гость.Код_паспорта, Гость.Фамилия, Гость.Имя, Гость.Отчество, Sum(Договор.Длительность) AS [Sum-Длительность] "
			+ L"FROM Гость INNER JOIN Договор ON Гость.Код_паспорта = Договор.Код_паспорта "
			+ L"GROUP BY Гость.Код_паспорта, Гость.Фамилия, Гость.Имя, Гость.Отчество "
			+ L"HAVING(((Sum(Договор.Длительность)) >"+daysNeeded+"));");
		showTable("Гость");
	}
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
	return System::Void();
}

System::Void HotelInfoSystem::mainform::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	enactCommand(L"SELECT * FROM Гость;");
	showTable("Гость");
	return System::Void();
}
