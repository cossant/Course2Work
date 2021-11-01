#include "add-guest-form.h"

System::Void HotelInfoSystem::addguestform::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	addingCommand->CommandText = L"INSERT INTO Гость VALUES (" + textBox1->Text + ",\'" + textBox2->Text + "\',\'" + textBox3->Text + "\',\'" + textBox4->Text + "\');";
	outerConnector->Open();
	addingCommand->Connection = outerConnector;
	tempDS = gcnew DataSet;
	outerAdapter->Fill(tempDS);
	outerConnector->Close();
	return System::Void();
}
 // DOESN'T WORK A GUES CREATION FROM THE INSIDE OF AN ADDITIONAL CREATING FORM