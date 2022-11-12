#pragma once
#include "blackdog.h"
#include "MBox.h"

namespace InventorySystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for EditItemForm
	/// </summary>
	public ref class EditItemForm : public System::Windows::Forms::Form
	{
	public:
		blackdog edit;
		EditItemForm(void)
		{
			InitializeComponent();
			edit.connect();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~EditItemForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;



	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::ComboBox^ cboxProduct;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::TextBox^ textBox1;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Panel^ panel6;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(EditItemForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->cboxProduct = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::MidnightBlue;
			this->label1->Location = System::Drawing::Point(12, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(160, 45);
			this->label1->TabIndex = 13;
			this->label1->Text = L"Edit Item";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Black;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(691, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(25, 25);
			this->pictureBox1->TabIndex = 24;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &EditItemForm::pictureBox1_Click);
			// 
			// cboxProduct
			// 
			this->cboxProduct->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
			this->cboxProduct->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
			this->cboxProduct->BackColor = System::Drawing::Color::White;
			this->cboxProduct->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cboxProduct->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cboxProduct->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->cboxProduct->FormattingEnabled = true;
			this->cboxProduct->Location = System::Drawing::Point(20, 164);
			this->cboxProduct->Margin = System::Windows::Forms::Padding(4);
			this->cboxProduct->Name = L"cboxProduct";
			this->cboxProduct->Size = System::Drawing::Size(579, 36);
			this->cboxProduct->TabIndex = 25;
			this->cboxProduct->SelectedIndexChanged += gcnew System::EventHandler(this, &EditItemForm::cboxProduct_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::MidnightBlue;
			this->label2->Location = System::Drawing::Point(14, 128);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(135, 32);
			this->label2->TabIndex = 26;
			this->label2->Text = L"Select item";
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->panel5);
			this->panel1->Controls->Add(this->panel4);
			this->panel1->Controls->Add(this->textBox4);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->textBox3);
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->textBox2);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Location = System::Drawing::Point(12, 231);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(703, 462);
			this->panel1->TabIndex = 27;
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panel5->Location = System::Drawing::Point(5, 272);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(579, 2);
			this->panel5->TabIndex = 35;
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panel4->Location = System::Drawing::Point(8, 174);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(579, 2);
			this->panel4->TabIndex = 32;
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::Color::White;
			this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->textBox4->Location = System::Drawing::Point(5, 238);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(574, 36);
			this->textBox4->TabIndex = 34;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::Cyan;
			this->button1->Location = System::Drawing::Point(494, 418);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(206, 41);
			this->button1->TabIndex = 28;
			this->button1->Text = L"Save Changes";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &EditItemForm::button1_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::MidnightBlue;
			this->label6->Location = System::Drawing::Point(3, 203);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(114, 32);
			this->label6->TabIndex = 33;
			this->label6->Text = L"Category";
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::Color::White;
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->textBox3->Location = System::Drawing::Point(8, 140);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(574, 36);
			this->textBox3->TabIndex = 31;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panel3->Location = System::Drawing::Point(9, 373);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(239, 2);
			this->panel3->TabIndex = 31;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::MidnightBlue;
			this->label5->Location = System::Drawing::Point(3, 105);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(79, 32);
			this->label5->TabIndex = 30;
			this->label5->Text = L"Brand";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::MidnightBlue;
			this->label4->Location = System::Drawing::Point(3, 304);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(67, 32);
			this->label4->TabIndex = 30;
			this->label4->Text = L"Price";
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::White;
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->textBox2->Location = System::Drawing::Point(9, 339);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(234, 36);
			this->textBox2->TabIndex = 30;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panel2->Location = System::Drawing::Point(8, 80);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(579, 2);
			this->panel2->TabIndex = 29;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::White;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->textBox1->Location = System::Drawing::Point(8, 46);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(574, 36);
			this->textBox1->TabIndex = 28;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::MidnightBlue;
			this->label3->Location = System::Drawing::Point(3, 11);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(187, 32);
			this->label3->TabIndex = 27;
			this->label3->Text = L"New item name";
			// 
			// panel6
			// 
			this->panel6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panel6->Location = System::Drawing::Point(20, 198);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(579, 2);
			this->panel6->TabIndex = 30;
			// 
			// EditItemForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 17);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(729, 705);
			this->Controls->Add(this->panel6);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->cboxProduct);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"EditItemForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"EditItemForm";
			this->Load += gcnew System::EventHandler(this, &EditItemForm::EditItemForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private: System::Void btnProdSearch_Click(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void EditItemForm_Load(System::Object^ sender, System::EventArgs^ e) {
	edit.reset("search results");
	edit.search(cboxProduct->Text, "ProductName ASC");
	dataClass^ str = gcnew dataClass;
	str = edit.start;

	bool end = false;
	if (str->ProductName == nullptr) {
		cboxProduct->Items->Add("");
	}
	else {
		do {
			if (str->last) {
				end = true;
			}
			cboxProduct->Items->Add(str->ProductName);
			if (str->next != nullptr) {
				str = str->next;
			}
		} while (str->last != true || !end);
	}
}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (textBox2->Text == "0") {
		String^ msg = "Product price cannot be 0.";
		MBox^ adform = gcnew MBox(msg, 1);
		adform->ShowDialog();
		delete adform;
		return;
	}
	try {
		Convert::ToInt32(textBox2->Text);
	}
	catch (Exception^ ex) {
		String^ err = "Invalid price input.";
		MBox^ adform = gcnew MBox(err, 1);
		adform->ShowDialog();
		textBox2->Text = "0";
		return;
	}
	dataClass^ str = gcnew dataClass;
	str = edit.start;
	bool end = false, hit  = false;
	if (str->ProductName != nullptr) {
		do {
			if (str->last) {
				end = true;
			}

			if (cboxProduct->Text == str->ProductName) {
				int^ q = str->quantity;
				edit.deleteItem(str->ProductName);
				edit.stock_sale_insert(textBox1->Text, textBox3->Text, textBox4->Text, q, Convert::ToInt32(textBox2->Text));
				delete str;
				hit = true;
				break;	
			}
			if (str->next != nullptr) {
				str = str->next;
			}
		} while (str->last != true || !end);
	}
	if (hit) {
		String^ msg = "Item edited succesfully.";
		MBox^ adform = gcnew MBox(msg, 1);
		adform->ShowDialog();
		delete adform;
		this->Close();
	}
	else {
		String^ msg = "Item not found.";
		MBox^ adform = gcnew MBox(msg, 1);
		adform->ShowDialog();
		delete adform;
	}

}
private: System::Void cboxProduct_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	
}

};
}
