#pragma once


namespace InventorySystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MBox
	/// </summary>
	public ref class MBox : public System::Windows::Forms::Form
	{

	public:
		String^ msuccess = "false";
		MBox(String^ msg, int type)
		{
			InitializeComponent();
			mainbox->Text = msg;
			if (type == 1) {
				button2->Hide();
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MBox()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::RichTextBox^ mainbox;
	private: System::Windows::Forms::Panel^ panel3;

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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->mainbox = (gcnew System::Windows::Forms::RichTextBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->panel1->Location = System::Drawing::Point(387, 263);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(299, 48);
			this->panel1->TabIndex = 2;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Navy;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Location = System::Drawing::Point(37, 7);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(114, 41);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Close";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MBox::button2_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Navy;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::Cyan;
			this->button1->Location = System::Drawing::Point(185, 7);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(114, 41);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Confirm";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MBox::button1_Click);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->mainbox);
			this->panel2->Location = System::Drawing::Point(12, 30);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(674, 229);
			this->panel2->TabIndex = 3;
			// 
			// mainbox
			// 
			this->mainbox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->mainbox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->mainbox->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->mainbox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mainbox->ForeColor = System::Drawing::Color::White;
			this->mainbox->Location = System::Drawing::Point(0, 0);
			this->mainbox->Name = L"mainbox";
			this->mainbox->Size = System::Drawing::Size(674, 229);
			this->mainbox->TabIndex = 1;
			this->mainbox->Text = L"";
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::Cyan;
			this->panel3->Location = System::Drawing::Point(-14, -5);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(746, 10);
			this->panel3->TabIndex = 4;
			// 
			// MBox
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 17);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ClientSize = System::Drawing::Size(701, 323);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::Color::Red;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MBox";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MBox";
			this->TopMost = true;
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void mainbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	msuccess = "false";
	Close();
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	msuccess = "true";
	Close();
}
public: String^ ReturnData() {
	return msuccess;
}
private: System::Void ainox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
