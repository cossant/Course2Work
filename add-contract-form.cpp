#include "add-contract-form.h"

System::Void HotelInfoSystem::addcontractform::fillPassPossibleValues()
{
	connection->Open();
	numbSearchCommand = gcnew System::Data::OleDb::OleDbCommand();
	System::Data::DataSet^ tempset = gcnew DataSet();
	numbSearchCommand->Connection = connection;
	numbSearchCommand->CommandText = "SELECT ���_�������� FROM �����;";
	adapter->SelectCommand = numbSearchCommand;
	adapter->Fill(tempset);
	connection->Close();

	comboBox2->ValueMember = "���_��������";
	comboBox2->DataSource = tempset->Tables["�����"];
}



System::Void HotelInfoSystem::addcontractform::refilNumbPossibleValues()
{
	connection->Open();
	System::Data::DataSet^ tempset = gcnew System::Data::DataSet();
	numbSearchCommand = gcnew System::Data::OleDb::OleDbCommand();
	numbSearchCommand->Connection = connection;
	numbSearchCommand->CommandText = L"SELECT �����.���_������ FROM ����� WHERE ((�����.���_������) Not In "
		+ L"(SELECT �������.���_������ FROM ������� WHERE((#" + dateTimePicker1->Value.ToString("yyyy-MM-dd")
		+ L"#   >= ����_����������) AND(#" + dateTimePicker1->Value.ToString("yyyy-MM-dd") 
		+ "# <= (����_���������� + ������������)))));";
	adapter->SelectCommand = numbSearchCommand;
	adapter->Fill(tempset);
	connection->Close();

	dataGridView1->DataSource = tempset;
	dataGridView1->DataMember = "�����";

	comboBox1->ValueMember = "���_������";
	comboBox1->DataSource = tempset->Tables["�����"];
}

System::Void HotelInfoSystem::addcontractform::dateTimePicker1_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	refilNumbPossibleValues();
	return System::Void();
}



