#include "add-guest-form.h"

System::Void HotelInfoSystem::addguestform::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	addingCommand->CommandText = L"INSERT INTO Гость VALUES (" + textBox1->Text + ",\'" + textBox2->Text + "\',\'" + textBox3->Text + "\',\'" + textBox4->Text + "\');";
	outerConnector->Open();
	addingCommand->Connection = outerConnector;
	addingCommand->ExecuteNonQuery();
	tempDS = gcnew DataSet;
	outerAdapter->Fill(tempDS);
	outerConnector->Close();
	label6->Text = L"Гость " + textBox2->Text + L" успешно добавлен в систему";
	return System::Void();
}
