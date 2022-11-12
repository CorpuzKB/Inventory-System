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
	/// Summary for NewProduct
	/// </summary>
	public ref class NewProduct : public System::Windows::Forms::Form
	{
		blackdog four;
	public:
		NewProduct(void)
		{
			four.connect();
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~NewProduct()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^ txtboxBrand;

	private: System::Windows::Forms::Label^ lblProdName;
	private: System::Windows::Forms::TextBox^ txtboxProdName;
	private: System::Windows::Forms::Label^ lblCategory;

	private: System::Windows::Forms::Label^ lblPrice;
	private: System::Windows::Forms::TextBox^ txtBoxPrice;



	private: System::Windows::Forms::Button^ btRegister;
	private: System::Windows::Forms::Panel^ panel5;


	private: System::Windows::Forms::TextBox^ txtBoxCateg;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::PictureBox^ pictureBox1;







	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(NewProduct::typeid));
			this->txtboxBrand = (gcnew System::Windows::Forms::TextBox());
			this->lblProdName = (gcnew System::Windows::Forms::Label());
			this->txtboxProdName = (gcnew System::Windows::Forms::TextBox());
			this->lblCategory = (gcnew System::Windows::Forms::Label());
			this->lblPrice = (gcnew System::Windows::Forms::Label());
			this->txtBoxPrice = (gcnew System::Windows::Forms::TextBox());
			this->btRegister = (gcnew System::Windows::Forms::Button());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->txtBoxCateg = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// txtboxBrand
			// 
			this->txtboxBrand->BackColor = System::Drawing::Color::White;
			this->txtboxBrand->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtboxBrand->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtboxBrand->ForeColor = System::Drawing::Color::Navy;
			this->txtboxBrand->Location = System::Drawing::Point(20, 165);
			this->txtboxBrand->Margin = System::Windows::Forms::Padding(4);
			this->txtboxBrand->Name = L"txtboxBrand";
			this->txtboxBrand->Size = System::Drawing::Size(481, 36);
			this->txtboxBrand->TabIndex = 1;
			// 
			// lblProdName
			// 
			this->lblProdName->AutoSize = true;
			this->lblProdName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblProdName->ForeColor = System::Drawing::Color::MidnightBlue;
			this->lblProdName->Location = System::Drawing::Point(15, 222);
			this->lblProdName->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblProdName->Name = L"lblProdName";
			this->lblProdName->Size = System::Drawing::Size(148, 28);
			this->lblProdName->TabIndex = 2;
			this->lblProdName->Text = L"Product Name";
			this->lblProdName->Click += gcnew System::EventHandler(this, &NewProduct::label1_Click_1);
			// 
			// txtboxProdName
			// 
			this->txtboxProdName->BackColor = System::Drawing::Color::White;
			this->txtboxProdName->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtboxProdName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtboxProdName->ForeColor = System::Drawing::Color::Navy;
			this->txtboxProdName->Location = System::Drawing::Point(20, 259);
			this->txtboxProdName->Margin = System::Windows::Forms::Padding(4);
			this->txtboxProdName->Name = L"txtboxProdName";
			this->txtboxProdName->Size = System::Drawing::Size(481, 36);
			this->txtboxProdName->TabIndex = 3;
			// 
			// lblCategory
			// 
			this->lblCategory->AutoSize = true;
			this->lblCategory->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCategory->ForeColor = System::Drawing::Color::MidnightBlue;
			this->lblCategory->Location = System::Drawing::Point(15, 315);
			this->lblCategory->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblCategory->Name = L"lblCategory";
			this->lblCategory->Size = System::Drawing::Size(98, 28);
			this->lblCategory->TabIndex = 4;
			this->lblCategory->Text = L"Category";
			this->lblCategory->Click += gcnew System::EventHandler(this, &NewProduct::label1_Click_2);
			// 
			// lblPrice
			// 
			this->lblPrice->AutoSize = true;
			this->lblPrice->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPrice->ForeColor = System::Drawing::Color::MidnightBlue;
			this->lblPrice->Location = System::Drawing::Point(15, 416);
			this->lblPrice->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblPrice->Name = L"lblPrice";
			this->lblPrice->Size = System::Drawing::Size(59, 28);
			this->lblPrice->TabIndex = 6;
			this->lblPrice->Text = L"Price";
			this->lblPrice->Click += gcnew System::EventHandler(this, &NewProduct::label1_Click_3);
			// 
			// txtBoxPrice
			// 
			this->txtBoxPrice->BackColor = System::Drawing::Color::White;
			this->txtBoxPrice->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxPrice->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtBoxPrice->ForeColor = System::Drawing::Color::Navy;
			this->txtBoxPrice->Location = System::Drawing::Point(23, 448);
			this->txtBoxPrice->Margin = System::Windows::Forms::Padding(4);
			this->txtBoxPrice->Name = L"txtBoxPrice";
			this->txtBoxPrice->Size = System::Drawing::Size(152, 36);
			this->txtBoxPrice->TabIndex = 7;
			this->txtBoxPrice->Text = L"0";
			// 
			// btRegister
			// 
			this->btRegister->BackColor = System::Drawing::Color::Blue;
			this->btRegister->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btRegister->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btRegister->ForeColor = System::Drawing::Color::White;
			this->btRegister->Location = System::Drawing::Point(276, 529);
			this->btRegister->Margin = System::Windows::Forms::Padding(4);
			this->btRegister->Name = L"btRegister";
			this->btRegister->Size = System::Drawing::Size(230, 58);
			this->btRegister->TabIndex = 14;
			this->btRegister->Text = L"Register";
			this->btRegister->UseVisualStyleBackColor = false;
			this->btRegister->Click += gcnew System::EventHandler(this, &NewProduct::btRegister_Click);
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::MidnightBlue;
			this->panel5->Location = System::Drawing::Point(20, 203);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(481, 2);
			this->panel5->TabIndex = 18;
			// 
			// txtBoxCateg
			// 
			this->txtBoxCateg->BackColor = System::Drawing::Color::White;
			this->txtBoxCateg->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxCateg->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtBoxCateg->ForeColor = System::Drawing::Color::Navy;
			this->txtBoxCateg->Location = System::Drawing::Point(20, 352);
			this->txtBoxCateg->Margin = System::Windows::Forms::Padding(4);
			this->txtBoxCateg->Name = L"txtBoxCateg";
			this->txtBoxCateg->Size = System::Drawing::Size(481, 36);
			this->txtBoxCateg->TabIndex = 22;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::MidnightBlue;
			this->label1->Location = System::Drawing::Point(15, 129);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(68, 28);
			this->label1->TabIndex = 23;
			this->label1->Text = L"Brand";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::MidnightBlue;
			this->label2->Location = System::Drawing::Point(12, 34);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(163, 45);
			this->label2->TabIndex = 24;
			this->label2->Text = L"Add Item";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::MidnightBlue;
			this->panel2->Location = System::Drawing::Point(20, 293);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(481, 2);
			this->panel2->TabIndex = 19;
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::MidnightBlue;
			this->panel4->Location = System::Drawing::Point(20, 390);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(481, 2);
			this->panel4->TabIndex = 20;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::MidnightBlue;
			this->panel3->Location = System::Drawing::Point(23, 487);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(152, 2);
			this->panel3->TabIndex = 20;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Black;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(482, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(25, 25);
			this->pictureBox1->TabIndex = 24;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &NewProduct::pictureBox1_Click);
			// 
			// NewProduct
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 17);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(519, 600);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtBoxCateg);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->btRegister);
			this->Controls->Add(this->lblPrice);
			this->Controls->Add(this->lblCategory);
			this->Controls->Add(this->txtboxProdName);
			this->Controls->Add(this->lblProdName);
			this->Controls->Add(this->txtboxBrand);
			this->Controls->Add(this->txtBoxPrice);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::Color::Transparent;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"NewProduct";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Add New Product";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &NewProduct::NewProduct_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click_2(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label1_Click_3(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btRegister_Click(System::Object^ sender, System::EventArgs^ e) {

	String^ prodBrand;
	String^ prodName;
	String^ prodCateg;
	int^ prodPrice;



	

	if (txtboxBrand->Text == "" || txtboxProdName->Text == "" || txtBoxCateg->Text == "") {
		String^ msg = "You left an information blank.";
		MBox^ adform = gcnew MBox(msg, 1);
		adform->ShowDialog();
		delete adform;
	}
	else if (txtBoxPrice->Text == "0") {
		String^ msg = "Product price cannot be 0.";
		MBox^ adform = gcnew MBox(msg, 1);
		adform->ShowDialog();
		delete adform;
		return;
	}
	else {
		String^ message, ^ err;
		prodBrand = txtboxBrand->Text;
		prodName = txtboxProdName->Text;
		prodCateg = txtBoxCateg->Text;
		try {
			prodPrice = Convert::ToInt32(txtBoxPrice->Text);
		}
		catch (Exception^ ex) {
		err = "Invalid price input.";
		MBox^ adform = gcnew MBox(err, 1);
		adform->ShowDialog();
		txtBoxPrice->Text = "0";
		return;
		}
		
		message = "Add product:" + "\nBrand: " + prodBrand + "\nName: " + prodName + "\nCategory: " + prodCateg + "\nPrice: " + prodPrice;
		MBox^ adform = gcnew MBox(message, 0);
		adform->ShowDialog();
		if (adform->ReturnData() == "true") {
			delete adform;
			four.stock_sale_insert(prodName, prodBrand, prodCateg, 0, prodPrice);
			message = "Product is added to the database.";
			adform = gcnew MBox(message, 1);
			delete adform;
			this->Close();			
		}
		delete adform;
	}
}
private: System::Void NewProduct_Load(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
