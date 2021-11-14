#include "add-contract-form.h"

System::Void HotelInfoSystem::addcontractform::fillPassPossibleValues()
{
	connection->Open();
	numbSearchCommand = gcnew System::Data::OleDb::OleDbCommand();
	System::Data::DataSet^ tempset = gcnew DataSet();
	numbSearchCommand->Connection = connection;
	numbSearchCommand->CommandText = "SELECT Код_паспорта FROM Гость;";
	adapter->SelectCommand = numbSearchCommand;
	adapter->Fill(tempset);
	connection->Close();

	comboBox2->ValueMember = "Код_паспорта";
	comboBox2->DataSource = tempset->Tables["Гость"];
}



System::Void HotelInfoSystem::addcontractform::refilNumbPossibleValues()
{
	connection->Open();
	System::Data::DataSet^ tempset = gcnew System::Data::DataSet();
	numbSearchCommand = gcnew System::Data::OleDb::OleDbCommand();
	numbSearchCommand->Connection = connection;
	numbSearchCommand->CommandText = L"SELECT Номер.Код_номера FROM Номер WHERE ((Номер.Код_номера) Not In "
		+ L"(SELECT Договор.Код_номера FROM Договор WHERE((#" + dateTimePicker1->Value.ToString("yyyy-MM-dd")
		+ L"#   >= Дата_подписания) AND(#" + dateTimePicker1->Value.ToString("yyyy-MM-dd") 
		+ "# <= (Дата_подписания + Длительность)))));";
	adapter->SelectCommand = numbSearchCommand;
	adapter->Fill(tempset);
	connection->Close();

	dataGridView1->DataSource = tempset;
	dataGridView1->DataMember = "Гость";

	comboBox1->ValueMember = "Код_номера";
	comboBox1->DataSource = tempset->Tables["Гость"];
}

System::Void HotelInfoSystem::addcontractform::dateTimePicker1_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	refilNumbPossibleValues();
	return System::Void();
}



