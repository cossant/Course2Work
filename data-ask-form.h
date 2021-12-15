#pragma once

namespace HotelInfoSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for dataaskform
	/// </summary>
	public ref class dataaskform : public System::Windows::Forms::Form
	{
	public:
		dataaskform()
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

		}

	System::Windows::Forms::DateTimePicker^ dateTimePicker1;
		
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~dataaskform()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(53, 51);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(171, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Введите рассматриваемую дату";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(43, 78);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->button1->Location = System::Drawing::Point(82, 104);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(111, 24);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Подтвердить";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// dataaskform
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 149);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->label1);
			this->Name = L"dataaskform";
			this->Text = L"Запрос даты";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void dateTimePicker1_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
