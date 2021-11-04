#include "start-form.h"
#include "main-form.h"

System::Void HotelInfoSystem::startform::fileSetButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	openFileDialog1->ShowDialog();
	TryToInitiate(openFileDialog1->FileName);
	return System::Void();
}

System::Void HotelInfoSystem::startform::TryToInitiate(System::String^ filepath)
{
	{
		if (System::IO::File::Exists(openFileDialog1->FileName))
		{
			mainform^ activemainform = gcnew mainform(openFileDialog1->FileName);
			activemainform->Show();
			this->Hide();
		}
		else
			Windows::Forms::DialogResult badPath = MessageBox::Show("”казанный файл не может быть найден", "ќшибка", MessageBoxButtons::OK);
	}
	return System::Void();
}
