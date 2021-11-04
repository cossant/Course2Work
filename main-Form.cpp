#include "main-form.h"

System::Void HotelInfoSystem::mainform::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	enactCommand(textBox1->Text);
	if (textBox1->Text->Contains("SELECT"))
		showTable("�����");
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
		date = L"SELECT �����.���_������ FROM ����� WHERE ((�����.���_������) Not In "
			+ L"(SELECT �������.���_������ FROM ������� WHERE((#"+date+L"#   >= ����_����������) AND(#"+date+"# <= (����_���������� + ������������)))))";
		enactCommand(date);
		showTable("�����");
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
	return System::Void();
}

System::Void HotelInfoSystem::mainform::button6_Click(System::Object^ sender, System::EventArgs^ e)
{	
	dataaskform^ tempform = gcnew dataaskform();
	System::Windows::Forms::DialogResult result = tempform->ShowDialog();
	if (result == System::Windows::Forms::DialogResult::OK)
	{
		System::String^ date = tempform->dateTimePicker1->Value.ToString("yyyy-MM-dd");
		date = L"SELECT �����.�������, �������.���_��������, �������.���_������ "
			+ L"FROM (������� INNER JOIN ����� ON (�����.���_�������� = �������.���_��������)) "
			+ L"WHERE ((�������.����_���������� + �������.������������) = #" + date + L"#);";
		enactCommand(date);
		showTable("�����");
	}
	return System::Void();
}

System::Void HotelInfoSystem::mainform::button7_Click(System::Object^ sender, System::EventArgs^ e)
{
	askdaysform^ tempDialForm = gcnew askdaysform();
	if (tempDialForm->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		System::Int32^ daysNeeded = Int32(tempDialForm->numericUpDown1->Value);
		enactCommand("SELECT �����.���_��������, �����.�������, �����.���, �����.��������, Sum(�������.������������) AS [Sum-������������] "
			+ L"FROM ����� INNER JOIN ������� ON �����.���_�������� = �������.���_�������� "
			+ L"GROUP BY �����.���_��������, �����.�������, �����.���, �����.�������� "
			+ L"HAVING(((Sum(�������.������������)) >"+daysNeeded+"));");
		showTable("�����");
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
	enactCommand(L"SELECT * FROM �����;");
	showTable("�����");
	return System::Void();
}
