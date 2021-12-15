#pragma once

namespace HotelInfoSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for askdaysform
	/// </summary>
	public ref class askdaysform : public System::Windows::Forms::Form
	{
	public:
		askdaysform(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	System::Windows::Forms::NumericUpDown^ numericUpDown1;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~askdaysform()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
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
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(98, 64);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 365, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(120, 20);
			this->numericUpDown1->TabIndex = 0;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 31, 0, 0, 0 });
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(45, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(233, 39);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Считать долговреммым клиентом в случае, \r\nесли общее число дней аренды составляет"
				L" \r\nне менее";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(224, 66);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(31, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"дней";
			// 
			// button1
			// 
			this->button1->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->button1->Location = System::Drawing::Point(98, 106);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(120, 30);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Выполнить поиск";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// askdaysform
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(326, 148);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->numericUpDown1);
			this->Name = L"askdaysform";
			this->Text = L"Запрос числа дней";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
