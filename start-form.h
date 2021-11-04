#pragma once

namespace HotelInfoSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for startform
	/// </summary>
	public ref class startform : public System::Windows::Forms::Form
	{
	public:
		startform(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~startform()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Button^ fileSetButton;
	private: System::Windows::Forms::Label^ WellcomeText;






	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->fileSetButton = (gcnew System::Windows::Forms::Button());
			this->WellcomeText = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// fileSetButton
			// 
			this->fileSetButton->Location = System::Drawing::Point(133, 169);
			this->fileSetButton->Name = L"fileSetButton";
			this->fileSetButton->Size = System::Drawing::Size(75, 23);
			this->fileSetButton->TabIndex = 0;
			this->fileSetButton->Text = L"Файл";
			this->fileSetButton->UseVisualStyleBackColor = true;
			this->fileSetButton->Click += gcnew System::EventHandler(this, &startform::fileSetButton_Click);
			// 
			// WellcomeText
			// 
			this->WellcomeText->AutoSize = true;
			this->WellcomeText->Location = System::Drawing::Point(82, 61);
			this->WellcomeText->Name = L"WellcomeText";
			this->WellcomeText->Size = System::Drawing::Size(189, 13);
			this->WellcomeText->TabIndex = 1;
			this->WellcomeText->Text = L"Укажите путь к файлу базы данных";
			// 
			// startform
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(346, 261);
			this->Controls->Add(this->WellcomeText);
			this->Controls->Add(this->fileSetButton);
			this->Name = L"startform";
			this->Text = L"Hotel Information System";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	// Функции событий объектов.

	private: System::Void fileSetButton_Click(System::Object^ sender, System::EventArgs^ e);

	// Самописные вспомогательные функции.
	private: System::Void TryToInitiate(System::String^ filepath);

	};
}
