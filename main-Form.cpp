#include "main-form.h"

System::Void HotelInfoSystem::mainform::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	enactCommand(textBox1->Text);
	if (textBox1->Text->Contains("SELECT"))
		showTable("�����");
	descLabel->Text = L"������������� ������� ���������.";
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
		enactCommand(L"SELECT �����.���_������ FROM ����� WHERE ((�����.���_������) Not In "
			+ L"(SELECT �������.���_������ FROM ������� WHERE((#" + date + L"#   >= ����_����������) AND(#" 
			+ date + "# <= (����_���������� + ������������)))))");
		showTable("�����");
		descLabel->Text = L"��������� �� " + date + " ������:";
	}
	return System::Void();
}

System::Void HotelInfoSystem::mainform::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
	enactCommand(L"SELECT �������.���_��������, �����.�������, �������.���_������ "
		+ L"FROM ������� LEFT JOIN ����� ON �������.���_�������� = �����.���_�������� "
		+ L"WHERE �������.���_�������� IN "
		+ L"(SELECT ���_�������� "
		+ L"FROM ������� "
		+ L"WHERE((Date() >= ����_����������) AND(Date() <= ����_���������� + ������������)));");
	showTable("�����");
	descLabel->Text = L"����������� � ��������� �� ������ ������:";
	return System::Void();
}

System::Void HotelInfoSystem::mainform::button6_Click(System::Object^ sender, System::EventArgs^ e)
{	
	dataaskform^ tempform = gcnew dataaskform();
	System::Windows::Forms::DialogResult result = tempform->ShowDialog();
	if (result == System::Windows::Forms::DialogResult::OK)
	{
		System::String^ date = tempform->dateTimePicker1->Value.ToString("yyyy-MM-dd");
		enactCommand(L"SELECT �����.�������, �������.���_��������, �������.���_������ "
			+ L"FROM (������� INNER JOIN ����� ON (�����.���_�������� = �������.���_��������)) "
			+ L"WHERE ((�������.����_���������� + �������.������������) = #" + date + L"#);");
		showTable("�����");
		descLabel->Text = L"������������� ������ " + date + " �����:";
	}
	return System::Void();
}

System::Void HotelInfoSystem::mainform::button7_Click(System::Object^ sender, System::EventArgs^ e)
{
	askdaysform^ tempDialForm = gcnew askdaysform();
	if (tempDialForm->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		System::Int32^ daysNeeded = Int32(tempDialForm->numericUpDown1->Value);
		enactCommand("SELECT �����.���_��������, �����.�������, �����.���, �����.��������, Sum(�������.������������) AS [����� ���� ����������] "
			+ L"FROM ����� INNER JOIN ������� ON �����.���_�������� = �������.���_�������� "
			+ L"GROUP BY �����.���_��������, �����.�������, �����.���, �����.�������� "
			+ L"HAVING(((Sum(�������.������������)) >"+daysNeeded+"));");
		showTable("�����");
		descLabel->Text = L"\"�����������\" ���������:";
	}
	return System::Void();
}

System::Void HotelInfoSystem::mainform::button8_Click(System::Object^ sender, System::EventArgs^ e)
{
	System::Windows::Forms::DataGridViewSelectedRowCollection^ guests =  dataGridView1->SelectedRows;
	if (guests->Count > 0)
	{
		System::Windows::Forms::DialogResult result = MessageBox::Show("�� �������, ��� ������ ������� �� ������� "
			+ guests->Count + " ������?", L"�������� ������", MessageBoxButtons::OKCancel);
		if (result == System::Windows::Forms::DialogResult::OK)
		{
			for (int i = 0; i < guests->Count; i++)
			{
				enactCommand(L"DELETE * FROM ����� WHERE ���_�������� = " + guests[i]->Cells[0]->Value->ToString() + L";");
			}
			button3_Click(sender, e);
		}
	}
	else
		MessageBox::Show("�� �������� �� ����� ������ � ������ ��� ��������");
	return System::Void();
}

System::Void HotelInfoSystem::mainform::button9_Click(System::Object^ sender, System::EventArgs^ e)
{
	addcontractform^ tempaddingform = gcnew addcontractform(oleDbConnection1, oleDbDataAdapter1);
	if (tempaddingform->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		enactCommand(L"INSERT INTO ������� (���_������, ���_��������, ����_����������, ������������) "
			+ L"VALUES("+tempaddingform->comboBox1->SelectedValue->ToString()+", "+tempaddingform->comboBox2->SelectedValue->ToString()
			+", #"+tempaddingform->dateTimePicker1->Value.ToString("yyyy-MM-dd") + "#, "+Int32(tempaddingform->numericUpDown1->Value)+"); ");
		MessageBox::Show("������� � ���������� ���������������� ������.","�������", MessageBoxButtons::OK);
	}
	oleDbSelectCommand1->CommandText = L"SELECT �����.*, �������.*, �����.* FROM((����� INNER JOIN ������� ON �����.[���_��������] = �������.[���_��������]) INNER JOIN ����� ON �������.[���_������] = �����.[���_������])";
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
	enactCommand(L"SELECT * FROM �����;");
	showTable("�����");
	descLabel->Text = L"������������������ �����";
	button8->Enabled = true;
	return System::Void();
}
