#pragma once
#include "blackdog.h"
#include "NewProduct.h"
#include "MBox.h"
#include "NotifForm.h"
#include "ChangeF.h"
#include "AboutForm.h"
#include "LogForm.h"
#include "EditItemForm.h"
#include <string>

namespace InventorySystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;



	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private: bool dragging;
	private: Point offset;
		String^ transdate,^ path;
		blackdog three;
		int total, discount, nTotal;




	private: System::Windows::Forms::ToolStripMenuItem^ aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ viewLogToolStripMenuItem;
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::Label^ lblTransDate;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ToolStripMenuItem^ databaseToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ closeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ resetToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ changePasswordToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ itemToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ addItemToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ editToolStripMenuItem;
	private: System::Windows::Forms::Panel^ panel3;

	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::ToolStripMenuItem^ watchdogToolStripMenuItem;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::RichTextBox^ richTextBox2;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::RichTextBox^ richTextBox3;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::RichTextBox^ numDiscount;

	private: System::Windows::Forms::Label^ label2;


	public:

	public: System::Void syncb() {
		cboxProduct->Items->Clear();
		three.reset("search results");
		three.search("", "ProductName ASC");
		dataClass^ str = gcnew dataClass;
		str = three.start;

		bool end = false, hit = true;
		String^ temp1 = "0", ^ temp2 = "0";
		if (str->ProductName == nullptr) {
			hit = false;
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
		System::DateTime date = System::DateTime::Now;
		transdate = date.ToString();
		label4->Text = transdate;
		delete str;

		if (hit) {
			temp1 = three.getStockLow();
			temp2 = three.getStockLow("1");
			if (Convert::ToInt32(temp2) > 0) {
				label5->Text = "Critical:";
				richTextBox2->Text = temp2 + " item/s are out of stock.";
				
			}
			else {
				label5->Text = "";
				richTextBox2->Text = "";
			}


			int ftemp = Convert::ToInt32(temp1) - Convert::ToInt32(temp2);
			if (ftemp > 0) {

				richTextBox1->Text = ftemp + " item/s are low in stock/s. Visit the inventory watchdog to view the complete list of the item/s.";
				label6->Text = "Warning:";
				label6->ForeColor = Color::Gold;		
			}
			else {
				if (Convert::ToInt32(temp2) > 0) {
					richTextBox1->Text = "";
				}
				else {
					richTextBox1->Text = "No notifications.";

				}
				label6->Text = "";	
			}



			if (Convert::ToInt32(temp1) > 0 || Convert::ToInt32(temp2) > 0) {
				watchdogToolStripMenuItem->ForeColor = Color::Red;
			}
			else {
				watchdogToolStripMenuItem->ForeColor = Color::White;
			}
		}
		else {
			richTextBox1->Text = "No notifications.";
			label6->Text = "";
			label5->Text = "";
			richTextBox2->Text = "";
			watchdogToolStripMenuItem->ForeColor = Color::White;
		}

	}

		MyForm(String^ data)
		{
			InitializeComponent();

			discount = nTotal = 0;
			path = data;
			three.connect();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::MenuStrip^ menuStrip1;


	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ lblProduct;
	private: System::Windows::Forms::Label^ lblQty;

	private: System::Windows::Forms::ComboBox^ cboxProduct;
	private: System::Windows::Forms::RadioButton^ rbtSales;

	private: System::Windows::Forms::RadioButton^ rbtStock;


	private: System::Windows::Forms::Panel^ panel2;


	private: System::Windows::Forms::ComboBox^ cboxPayMethod;
	private: System::Windows::Forms::Label^ lblPayMethod;




	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Button^ btConfirm;


	private: System::Windows::Forms::RichTextBox^ rtbSumLog;
	private: System::Windows::Forms::Label^ lblSumLog;
	private: System::Windows::Forms::NumericUpDown^ numQty;
	private: System::Windows::Forms::Label^ lblSubprice;

	private: System::Windows::Forms::RichTextBox^ rtbSubprice;
	private: System::Windows::Forms::Label^ lblTotal;


	private: System::Windows::Forms::RichTextBox^ rtbTotal;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Button^ btnSync;
	private: System::Windows::Forms::Label^ lblStock;



	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->itemToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addItemToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewLogToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->watchdogToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->databaseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->changePasswordToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->closeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->resetToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->lblStock = (gcnew System::Windows::Forms::Label());
			this->btnSync = (gcnew System::Windows::Forms::Button());
			this->numQty = (gcnew System::Windows::Forms::NumericUpDown());
			this->rbtSales = (gcnew System::Windows::Forms::RadioButton());
			this->rbtStock = (gcnew System::Windows::Forms::RadioButton());
			this->lblQty = (gcnew System::Windows::Forms::Label());
			this->cboxProduct = (gcnew System::Windows::Forms::ComboBox());
			this->lblProduct = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->numDiscount = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox3 = (gcnew System::Windows::Forms::RichTextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cboxPayMethod = (gcnew System::Windows::Forms::ComboBox());
			this->lblPayMethod = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->lblTransDate = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->lblTotal = (gcnew System::Windows::Forms::Label());
			this->rtbTotal = (gcnew System::Windows::Forms::RichTextBox());
			this->lblSubprice = (gcnew System::Windows::Forms::Label());
			this->rtbSubprice = (gcnew System::Windows::Forms::RichTextBox());
			this->btConfirm = (gcnew System::Windows::Forms::Button());
			this->rtbSumLog = (gcnew System::Windows::Forms::RichTextBox());
			this->lblSumLog = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->menuStrip1->SuspendLayout();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numQty))->BeginInit();
			this->panel2->SuspendLayout();
			this->panel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->panel7->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::Transparent;
			this->menuStrip1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->itemToolStripMenuItem,
					this->viewLogToolStripMenuItem, this->watchdogToolStripMenuItem, this->databaseToolStripMenuItem, this->aboutToolStripMenuItem
			});
			this->menuStrip1->LayoutStyle = System::Windows::Forms::ToolStripLayoutStyle::HorizontalStackWithOverflow;
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(7, 2, 0, 2);
			this->menuStrip1->RenderMode = System::Windows::Forms::ToolStripRenderMode::Professional;
			this->menuStrip1->Size = System::Drawing::Size(1522, 31);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			this->menuStrip1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::FrontForm_MouseDown);
			this->menuStrip1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::FrontForm_MouseMove);
			this->menuStrip1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::FrontForm_MouseUp);
			// 
			// itemToolStripMenuItem
			// 
			this->itemToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->addItemToolStripMenuItem,
					this->editToolStripMenuItem
			});
			this->itemToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->itemToolStripMenuItem->ForeColor = System::Drawing::Color::White;
			this->itemToolStripMenuItem->Name = L"itemToolStripMenuItem";
			this->itemToolStripMenuItem->Size = System::Drawing::Size(59, 27);
			this->itemToolStripMenuItem->Text = L"Item";
			this->itemToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::itemToolStripMenuItem_Click);
			// 
			// addItemToolStripMenuItem
			// 
			this->addItemToolStripMenuItem->Name = L"addItemToolStripMenuItem";
			this->addItemToolStripMenuItem->Size = System::Drawing::Size(125, 28);
			this->addItemToolStripMenuItem->Text = L"Add";
			this->addItemToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::addItemToolStripMenuItem_Click);
			// 
			// editToolStripMenuItem
			// 
			this->editToolStripMenuItem->Name = L"editToolStripMenuItem";
			this->editToolStripMenuItem->Size = System::Drawing::Size(125, 28);
			this->editToolStripMenuItem->Text = L"Edit";
			this->editToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::editToolStripMenuItem_Click);
			// 
			// viewLogToolStripMenuItem
			// 
			this->viewLogToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->viewLogToolStripMenuItem->ForeColor = System::Drawing::Color::White;
			this->viewLogToolStripMenuItem->Name = L"viewLogToolStripMenuItem";
			this->viewLogToolStripMenuItem->Size = System::Drawing::Size(90, 27);
			this->viewLogToolStripMenuItem->Text = L"Statistics";
			this->viewLogToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::viewLogToolStripMenuItem_Click);
			// 
			// watchdogToolStripMenuItem
			// 
			this->watchdogToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->watchdogToolStripMenuItem->ForeColor = System::Drawing::Color::White;
			this->watchdogToolStripMenuItem->Name = L"watchdogToolStripMenuItem";
			this->watchdogToolStripMenuItem->Size = System::Drawing::Size(102, 27);
			this->watchdogToolStripMenuItem->Text = L"Watchdog";
			this->watchdogToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::watchdogToolStripMenuItem_Click);
			// 
			// databaseToolStripMenuItem
			// 
			this->databaseToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->changePasswordToolStripMenuItem1,
					this->closeToolStripMenuItem, this->resetToolStripMenuItem
			});
			this->databaseToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->databaseToolStripMenuItem->ForeColor = System::Drawing::Color::White;
			this->databaseToolStripMenuItem->Name = L"databaseToolStripMenuItem";
			this->databaseToolStripMenuItem->Size = System::Drawing::Size(95, 27);
			this->databaseToolStripMenuItem->Text = L"Database";
			// 
			// changePasswordToolStripMenuItem1
			// 
			this->changePasswordToolStripMenuItem1->Name = L"changePasswordToolStripMenuItem1";
			this->changePasswordToolStripMenuItem1->Size = System::Drawing::Size(230, 28);
			this->changePasswordToolStripMenuItem1->Text = L"Change Password";
			this->changePasswordToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::changePasswordToolStripMenuItem1_Click);
			// 
			// closeToolStripMenuItem
			// 
			this->closeToolStripMenuItem->Name = L"closeToolStripMenuItem";
			this->closeToolStripMenuItem->Size = System::Drawing::Size(230, 28);
			this->closeToolStripMenuItem->Text = L"Close Database";
			this->closeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::closeToolStripMenuItem_Click);
			// 
			// resetToolStripMenuItem
			// 
			this->resetToolStripMenuItem->ForeColor = System::Drawing::Color::Firebrick;
			this->resetToolStripMenuItem->Name = L"resetToolStripMenuItem";
			this->resetToolStripMenuItem->Size = System::Drawing::Size(230, 28);
			this->resetToolStripMenuItem->Text = L"Clear Database";
			this->resetToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::resetToolStripMenuItem_Click);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->aboutToolStripMenuItem->ForeColor = System::Drawing::Color::White;
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(71, 27);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::aboutToolStripMenuItem_Click);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->lblStock);
			this->panel1->Controls->Add(this->btnSync);
			this->panel1->Controls->Add(this->numQty);
			this->panel1->Controls->Add(this->rbtSales);
			this->panel1->Controls->Add(this->rbtStock);
			this->panel1->Controls->Add(this->lblQty);
			this->panel1->Controls->Add(this->cboxProduct);
			this->panel1->Controls->Add(this->lblProduct);
			this->panel1->ForeColor = System::Drawing::Color::Transparent;
			this->panel1->Location = System::Drawing::Point(13, 111);
			this->panel1->Margin = System::Windows::Forms::Padding(4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(739, 230);
			this->panel1->TabIndex = 4;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Firebrick;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Location = System::Drawing::Point(604, 179);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(110, 36);
			this->button2->TabIndex = 16;
			this->button2->Text = L"Delete";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click_1);
			// 
			// lblStock
			// 
			this->lblStock->AutoSize = true;
			this->lblStock->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblStock->Location = System::Drawing::Point(227, 131);
			this->lblStock->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblStock->Name = L"lblStock";
			this->lblStock->Size = System::Drawing::Size(75, 28);
			this->lblStock->TabIndex = 15;
			this->lblStock->Text = L"Stocks:";
			// 
			// btnSync
			// 
			this->btnSync->BackColor = System::Drawing::Color::Blue;
			this->btnSync->FlatAppearance->BorderSize = 0;
			this->btnSync->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSync->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSync->ForeColor = System::Drawing::Color::White;
			this->btnSync->Location = System::Drawing::Point(604, 131);
			this->btnSync->Margin = System::Windows::Forms::Padding(4);
			this->btnSync->Name = L"btnSync";
			this->btnSync->Size = System::Drawing::Size(110, 36);
			this->btnSync->TabIndex = 14;
			this->btnSync->Text = L"Sync";
			this->btnSync->UseVisualStyleBackColor = false;
			this->btnSync->Click += gcnew System::EventHandler(this, &MyForm::btnSync_Click);
			// 
			// numQty
			// 
			this->numQty->BackColor = System::Drawing::Color::White;
			this->numQty->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->numQty->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->numQty->ForeColor = System::Drawing::Color::Navy;
			this->numQty->InterceptArrowKeys = false;
			this->numQty->Location = System::Drawing::Point(136, 131);
			this->numQty->Margin = System::Windows::Forms::Padding(4);
			this->numQty->Name = L"numQty";
			this->numQty->Size = System::Drawing::Size(70, 30);
			this->numQty->TabIndex = 13;
			this->numQty->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->numQty->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown2_ValueChanged);
			// 
			// rbtSales
			// 
			this->rbtSales->Appearance = System::Windows::Forms::Appearance::Button;
			this->rbtSales->AutoSize = true;
			this->rbtSales->BackColor = System::Drawing::Color::Navy;
			this->rbtSales->FlatAppearance->BorderSize = 0;
			this->rbtSales->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->rbtSales->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rbtSales->ForeColor = System::Drawing::Color::White;
			this->rbtSales->Location = System::Drawing::Point(232, 178);
			this->rbtSales->Margin = System::Windows::Forms::Padding(4);
			this->rbtSales->Name = L"rbtSales";
			this->rbtSales->Padding = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->rbtSales->Size = System::Drawing::Size(70, 38);
			this->rbtSales->TabIndex = 8;
			this->rbtSales->Text = L"Sales";
			this->rbtSales->UseVisualStyleBackColor = false;
			this->rbtSales->CheckedChanged += gcnew System::EventHandler(this, &MyForm::rbtSales_CheckedChanged);
			// 
			// rbtStock
			// 
			this->rbtStock->Appearance = System::Windows::Forms::Appearance::Button;
			this->rbtStock->AutoSize = true;
			this->rbtStock->BackColor = System::Drawing::Color::Navy;
			this->rbtStock->Checked = true;
			this->rbtStock->FlatAppearance->BorderSize = 0;
			this->rbtStock->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->rbtStock->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rbtStock->ForeColor = System::Drawing::Color::White;
			this->rbtStock->Location = System::Drawing::Point(136, 178);
			this->rbtStock->Margin = System::Windows::Forms::Padding(4);
			this->rbtStock->Name = L"rbtStock";
			this->rbtStock->Size = System::Drawing::Size(70, 38);
			this->rbtStock->TabIndex = 5;
			this->rbtStock->TabStop = true;
			this->rbtStock->Text = L"Stock";
			this->rbtStock->UseVisualStyleBackColor = false;
			this->rbtStock->CheckedChanged += gcnew System::EventHandler(this, &MyForm::rbtStock_CheckedChanged);
			// 
			// lblQty
			// 
			this->lblQty->AutoSize = true;
			this->lblQty->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblQty->Location = System::Drawing::Point(15, 131);
			this->lblQty->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblQty->Name = L"lblQty";
			this->lblQty->Size = System::Drawing::Size(95, 28);
			this->lblQty->TabIndex = 6;
			this->lblQty->Text = L"Quantity";
			// 
			// cboxProduct
			// 
			this->cboxProduct->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
			this->cboxProduct->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
			this->cboxProduct->BackColor = System::Drawing::Color::White;
			this->cboxProduct->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cboxProduct->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cboxProduct->ForeColor = System::Drawing::Color::Navy;
			this->cboxProduct->FormattingEnabled = true;
			this->cboxProduct->Location = System::Drawing::Point(19, 61);
			this->cboxProduct->Margin = System::Windows::Forms::Padding(4);
			this->cboxProduct->Name = L"cboxProduct";
			this->cboxProduct->Size = System::Drawing::Size(695, 36);
			this->cboxProduct->TabIndex = 5;
			this->cboxProduct->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::cboxProduct_SelectedIndexChanged);
			// 
			// lblProduct
			// 
			this->lblProduct->AutoSize = true;
			this->lblProduct->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblProduct->Location = System::Drawing::Point(14, 15);
			this->lblProduct->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblProduct->Name = L"lblProduct";
			this->lblProduct->Size = System::Drawing::Size(86, 28);
			this->lblProduct->TabIndex = 5;
			this->lblProduct->Text = L"Product";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Transparent;
			this->panel2->Controls->Add(this->numDiscount);
			this->panel2->Controls->Add(this->richTextBox3);
			this->panel2->Controls->Add(this->label7);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Controls->Add(this->cboxPayMethod);
			this->panel2->Controls->Add(this->lblPayMethod);
			this->panel2->ForeColor = System::Drawing::Color::White;
			this->panel2->Location = System::Drawing::Point(13, 349);
			this->panel2->Margin = System::Windows::Forms::Padding(4);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(739, 176);
			this->panel2->TabIndex = 9;
			// 
			// numDiscount
			// 
			this->numDiscount->BackColor = System::Drawing::Color::White;
			this->numDiscount->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->numDiscount->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->numDiscount->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->numDiscount->ForeColor = System::Drawing::Color::Navy;
			this->numDiscount->Location = System::Drawing::Point(218, 66);
			this->numDiscount->Margin = System::Windows::Forms::Padding(4);
			this->numDiscount->Multiline = false;
			this->numDiscount->Name = L"numDiscount";
			this->numDiscount->Size = System::Drawing::Size(173, 36);
			this->numDiscount->TabIndex = 20;
			this->numDiscount->Text = L" 0";
			this->numDiscount->TextChanged += gcnew System::EventHandler(this, &MyForm::numDiscount_TextChanged);
			this->numDiscount->Leave += gcnew System::EventHandler(this, &MyForm::numDiscount_Leave);
			// 
			// richTextBox3
			// 
			this->richTextBox3->BackColor = System::Drawing::Color::White;
			this->richTextBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox3->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->richTextBox3->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox3->ForeColor = System::Drawing::Color::Navy;
			this->richTextBox3->Location = System::Drawing::Point(218, 118);
			this->richTextBox3->Margin = System::Windows::Forms::Padding(4);
			this->richTextBox3->Multiline = false;
			this->richTextBox3->Name = L"richTextBox3";
			this->richTextBox3->Size = System::Drawing::Size(173, 36);
			this->richTextBox3->TabIndex = 19;
			this->richTextBox3->Text = L" 0";
			this->richTextBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::richTextBox3_TextChanged);
			this->richTextBox3->Leave += gcnew System::EventHandler(this, &MyForm::richTextBox3_Leave);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(14, 126);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(122, 28);
			this->label7->TabIndex = 12;
			this->label7->Text = L"Adjustment";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(15, 74);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(96, 28);
			this->label1->TabIndex = 11;
			this->label1->Text = L"Discount";
			// 
			// cboxPayMethod
			// 
			this->cboxPayMethod->BackColor = System::Drawing::Color::White;
			this->cboxPayMethod->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cboxPayMethod->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cboxPayMethod->ForeColor = System::Drawing::Color::Navy;
			this->cboxPayMethod->FormattingEnabled = true;
			this->cboxPayMethod->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Cash On-Hand", L"Physical Credit Card", L"Virtual Payment" });
			this->cboxPayMethod->Location = System::Drawing::Point(218, 14);
			this->cboxPayMethod->Margin = System::Windows::Forms::Padding(4);
			this->cboxPayMethod->Name = L"cboxPayMethod";
			this->cboxPayMethod->Size = System::Drawing::Size(440, 36);
			this->cboxPayMethod->TabIndex = 5;
			// 
			// lblPayMethod
			// 
			this->lblPayMethod->AutoSize = true;
			this->lblPayMethod->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPayMethod->Location = System::Drawing::Point(15, 22);
			this->lblPayMethod->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblPayMethod->Name = L"lblPayMethod";
			this->lblPayMethod->Size = System::Drawing::Size(175, 28);
			this->lblPayMethod->TabIndex = 5;
			this->lblPayMethod->Text = L"Payment Method";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(226, 529);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 28);
			this->label4->TabIndex = 11;
			// 
			// lblTransDate
			// 
			this->lblTransDate->AutoSize = true;
			this->lblTransDate->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTransDate->ForeColor = System::Drawing::Color::Transparent;
			this->lblTransDate->Location = System::Drawing::Point(27, 529);
			this->lblTransDate->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblTransDate->Name = L"lblTransDate";
			this->lblTransDate->Size = System::Drawing::Size(172, 28);
			this->lblTransDate->TabIndex = 10;
			this->lblTransDate->Text = L"Transaction Date";
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::Transparent;
			this->panel4->Controls->Add(this->panel6);
			this->panel4->Controls->Add(this->panel5);
			this->panel4->Controls->Add(this->lblTotal);
			this->panel4->Controls->Add(this->rtbTotal);
			this->panel4->Controls->Add(this->lblSubprice);
			this->panel4->Controls->Add(this->rtbSubprice);
			this->panel4->Controls->Add(this->btConfirm);
			this->panel4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->panel4->ForeColor = System::Drawing::Color::White;
			this->panel4->Location = System::Drawing::Point(13, 579);
			this->panel4->Margin = System::Windows::Forms::Padding(4);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(739, 131);
			this->panel4->TabIndex = 11;
			// 
			// panel6
			// 
			this->panel6->BackColor = System::Drawing::Color::White;
			this->panel6->Location = System::Drawing::Point(218, 50);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(116, 2);
			this->panel6->TabIndex = 18;
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::White;
			this->panel5->Location = System::Drawing::Point(218, 103);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(116, 2);
			this->panel5->TabIndex = 17;
			// 
			// lblTotal
			// 
			this->lblTotal->AutoSize = true;
			this->lblTotal->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTotal->Location = System::Drawing::Point(15, 77);
			this->lblTotal->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblTotal->Name = L"lblTotal";
			this->lblTotal->Size = System::Drawing::Size(164, 28);
			this->lblTotal->TabIndex = 16;
			this->lblTotal->Text = L"Total Stock Cost";
			// 
			// rtbTotal
			// 
			this->rtbTotal->BackColor = System::Drawing::Color::MidnightBlue;
			this->rtbTotal->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->rtbTotal->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->rtbTotal->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rtbTotal->ForeColor = System::Drawing::Color::Transparent;
			this->rtbTotal->Location = System::Drawing::Point(218, 69);
			this->rtbTotal->Margin = System::Windows::Forms::Padding(4);
			this->rtbTotal->Name = L"rtbTotal";
			this->rtbTotal->ReadOnly = true;
			this->rtbTotal->Size = System::Drawing::Size(116, 36);
			this->rtbTotal->TabIndex = 15;
			this->rtbTotal->Text = L"";
			this->rtbTotal->TextChanged += gcnew System::EventHandler(this, &MyForm::rtbTotal_TextChanged);
			// 
			// lblSubprice
			// 
			this->lblSubprice->AutoSize = true;
			this->lblSubprice->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblSubprice->Location = System::Drawing::Point(15, 24);
			this->lblSubprice->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblSubprice->Name = L"lblSubprice";
			this->lblSubprice->Size = System::Drawing::Size(123, 28);
			this->lblSubprice->TabIndex = 14;
			this->lblSubprice->Text = L"Single Price";
			// 
			// rtbSubprice
			// 
			this->rtbSubprice->BackColor = System::Drawing::Color::MidnightBlue;
			this->rtbSubprice->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->rtbSubprice->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->rtbSubprice->Font = (gcnew System::Drawing::Font(L"Segoe UI Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rtbSubprice->ForeColor = System::Drawing::Color::White;
			this->rtbSubprice->Location = System::Drawing::Point(218, 16);
			this->rtbSubprice->Margin = System::Windows::Forms::Padding(4);
			this->rtbSubprice->Name = L"rtbSubprice";
			this->rtbSubprice->ReadOnly = true;
			this->rtbSubprice->Size = System::Drawing::Size(116, 36);
			this->rtbSubprice->TabIndex = 13;
			this->rtbSubprice->Text = L"";
			// 
			// btConfirm
			// 
			this->btConfirm->BackColor = System::Drawing::Color::Blue;
			this->btConfirm->FlatAppearance->BorderSize = 0;
			this->btConfirm->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btConfirm->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btConfirm->ForeColor = System::Drawing::Color::White;
			this->btConfirm->Location = System::Drawing::Point(554, 63);
			this->btConfirm->Margin = System::Windows::Forms::Padding(4);
			this->btConfirm->Name = L"btConfirm";
			this->btConfirm->Size = System::Drawing::Size(170, 48);
			this->btConfirm->TabIndex = 12;
			this->btConfirm->Text = L"Confirm";
			this->btConfirm->UseVisualStyleBackColor = false;
			this->btConfirm->Click += gcnew System::EventHandler(this, &MyForm::btConfirm_Click);
			// 
			// rtbSumLog
			// 
			this->rtbSumLog->BackColor = System::Drawing::Color::MidnightBlue;
			this->rtbSumLog->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->rtbSumLog->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->rtbSumLog->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rtbSumLog->ForeColor = System::Drawing::Color::White;
			this->rtbSumLog->Location = System::Drawing::Point(793, 172);
			this->rtbSumLog->Margin = System::Windows::Forms::Padding(4);
			this->rtbSumLog->Name = L"rtbSumLog";
			this->rtbSumLog->ReadOnly = true;
			this->rtbSumLog->Size = System::Drawing::Size(716, 471);
			this->rtbSumLog->TabIndex = 12;
			this->rtbSumLog->Text = L"";
			this->rtbSumLog->TextChanged += gcnew System::EventHandler(this, &MyForm::rtbSumLog_TextChanged);
			// 
			// lblSumLog
			// 
			this->lblSumLog->AutoSize = true;
			this->lblSumLog->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblSumLog->ForeColor = System::Drawing::Color::White;
			this->lblSumLog->Location = System::Drawing::Point(788, 126);
			this->lblSumLog->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblSumLog->Name = L"lblSumLog";
			this->lblSumLog->Size = System::Drawing::Size(142, 28);
			this->lblSumLog->TabIndex = 9;
			this->lblSumLog->Text = L"Summary Log";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Blue;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(1339, 651);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(170, 48);
			this->button1->TabIndex = 19;
			this->button1->Text = L"Clear Log";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_2);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Cyan;
			this->label2->Location = System::Drawing::Point(25, 46);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(141, 46);
			this->label2->TabIndex = 20;
			this->label2->Text = L"Control";
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Navy;
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->pictureBox2->Location = System::Drawing::Point(1484, 6);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(25, 25);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 21;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &MyForm::pictureBox2_Click_1);
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::Navy;
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->pictureBox3->Location = System::Drawing::Point(1433, 6);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(25, 25);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 23;
			this->pictureBox3->TabStop = false;
			this->pictureBox3->Click += gcnew System::EventHandler(this, &MyForm::pictureBox3_Click);
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::Cyan;
			this->panel3->Location = System::Drawing::Point(794, 172);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(716, 2);
			this->panel3->TabIndex = 24;
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->richTextBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox1->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox1->ForeColor = System::Drawing::Color::White;
			this->richTextBox1->Location = System::Drawing::Point(140, 12);
			this->richTextBox1->Margin = System::Windows::Forms::Padding(4);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(944, 28);
			this->richTextBox1->TabIndex = 26;
			this->richTextBox1->Text = L"No new notifications.";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::Transparent;
			this->label6->Location = System::Drawing::Point(37, 12);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(17, 28);
			this->label6->TabIndex = 27;
			this->label6->Text = L" ";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Red;
			this->label5->Location = System::Drawing::Point(37, 53);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(17, 28);
			this->label5->TabIndex = 29;
			this->label5->Text = L" ";
			// 
			// richTextBox2
			// 
			this->richTextBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->richTextBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox2->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->richTextBox2->Font = (gcnew System::Drawing::Font(L"Segoe UI Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox2->ForeColor = System::Drawing::Color::White;
			this->richTextBox2->Location = System::Drawing::Point(140, 53);
			this->richTextBox2->Margin = System::Windows::Forms::Padding(4);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->ReadOnly = true;
			this->richTextBox2->Size = System::Drawing::Size(944, 28);
			this->richTextBox2->TabIndex = 28;
			this->richTextBox2->Text = L" ";
			// 
			// panel7
			// 
			this->panel7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panel7->Controls->Add(this->label6);
			this->panel7->Controls->Add(this->label5);
			this->panel7->Controls->Add(this->richTextBox1);
			this->panel7->Controls->Add(this->richTextBox2);
			this->panel7->Location = System::Drawing::Point(-9, 732);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(1531, 130);
			this->panel7->TabIndex = 30;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 17);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::MidnightBlue;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1522, 855);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->lblTransDate);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->lblSumLog);
			this->Controls->Add(this->rtbSumLog);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel7);
			this->DoubleBuffered = true;
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Inventory Control";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::FrontForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::FrontForm_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::FrontForm_MouseUp);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numQty))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->panel7->ResumeLayout(false);
			this->panel7->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		syncb();
		
		lblPayMethod->Hide();
		cboxPayMethod->Text = "Stock";
		cboxPayMethod->Hide();
		numDiscount->Hide();
		label1->Hide();
	}


	private: System::Void optionsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

	}


	private: System::Void cboxProduct_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		total = 0;
		numQty->Text = "0";
		richTextBox3->Text = "0";
		numDiscount->Text = "0";
		rtbTotal->Text = "";
		String^ target = cboxProduct->Text;
		dataClass^ str = gcnew dataClass;
		str = three.start;
		bool end = false;
		if (str->ProductName != nullptr) {
			do {
				if (str->last) {
					end = true;
				}
				if (target == str->ProductName) {
					rtbSubprice->Text = str->price->ToString();
					lblStock->Text = ("Stocks: " + str->quantity->ToString());
					delete str;
					break;
				}
				if (str->next != nullptr) {
					str = str->next;
				}
			} while (str->last != true || !end);
		}

	}
	private: System::Void rbtStock_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		lblSubprice->Text = "Single Price";
		lblTotal->Text = "Total Stock Cost";
		label7->Show();
		richTextBox3->Show();
		numDiscount->Text = "0";
		numQty->Text = "0";
		cboxPayMethod->Text = "Stock";
		numDiscount->Hide();
		label1->Hide();
		lblPayMethod->Hide();
		cboxPayMethod->Hide();
		button2->Show();
	}
	private: System::Void btConfirm_Click(System::Object^ sender, System::EventArgs^ e) {

		String^ adjustment = richTextBox3->Text, ^ prod = cboxProduct->Text, ^categ, ^ brand, ^ payment = cboxPayMethod->Text;
		int^ calcQty, ^ prodPrice, ^ prodindex = cboxProduct->SelectedIndex,^ adj = 0;
		int payindex = cboxPayMethod->SelectedIndex, qty = Convert::ToInt32(numQty->Value);
		bool hit = false;
		


		if (prodindex == 0 || cboxPayMethod->Text == "" || qty == 0 || cboxProduct->Text == "")
		{
			String^ msg = "You left an information blank.";
			MBox^ adform = gcnew MBox(msg, 1);
			adform->ShowDialog();
			delete adform;
			return;
		}
		

		if (rbtSales->Checked == true) {
			calcQty = qty * -1;
		}
		else if (rbtStock->Checked == true) {
			calcQty = qty * 1;
		}

		dataClass^ str = gcnew dataClass;
		str = three.start;
		bool end = false;
		if (str->ProductName != nullptr) {
			do {
				if (str->last) { 
					end = true;
				}

				if (cboxProduct->Text == str->ProductName) {
					if (rbtSales->Checked == true && (int)str->quantity < qty) {
						String^ msg = "The input quantity exceeds the amount of stocks in the database.";
						MBox^ adform = gcnew MBox(msg, 1);
						adform->ShowDialog();
						adform->Close();
						return;
					}
					else {

						if (rbtStock->Checked == true && adj != 0) {
							adj = Convert::ToInt32(adjustment);
							nTotal = total - (int)adj;
						}
						else {
							int^ distemp = Convert::ToInt32(numDiscount->Text);
							nTotal = total - (int)distemp;
						}
					

						categ = str->Category;
						brand = str->Brand;
						prodPrice = str->price;
						int^ temp = (int)str->quantity +  (int)calcQty;
						lblStock->Text = "Stocks: " + temp;
						rtbSumLog->AppendText("| " + qty + " | " + prod + "\nMethod:\t" + payment + "\nTotal:\t\t" + nTotal+ "\n\n\n");
						three.stock_sale_insert(prod, brand, categ, calcQty, prodPrice);
						three.log(prod, brand, categ, calcQty, nTotal);
						hit = true;
						syncb();
						delete str;
						break;
					}

				}
				if (str->next != nullptr) {
					str = str->next;
				}
			} while (str->last != true || !end);
		}
	
		if (!hit) {
			String^ msg = "Item does not exist.";
			MBox^ merr = gcnew MBox(msg, 1);
			merr->ShowDialog();
			delete msg;
		}


	}
	private: System::Void numericUpDown1_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		if (cboxProduct->Text == "") {
			return;
		}

		discount = Convert::ToInt32(numDiscount->Text);
		nTotal = Convert::ToInt32(rtbSubprice->Text)*Convert::ToInt32(numQty->Text) - discount ;

		rtbTotal->Text = nTotal.ToString();
	}

	private: System::Void numericUpDown2_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		int qty = Convert::ToInt32(numQty->Value);
		int^ Subprice;
		dataClass^ str = gcnew dataClass;
		str = three.start;
		bool end = false, hit = false;
		if (str->ProductName != nullptr) {
			do {
				if (str->last) {
					end = true;
				}
				if (cboxProduct->Text == str->ProductName) {
					Subprice = str->price;
					hit = true;
				}
				if (str->next != nullptr) {
					str = str->next;
				}
			} while (str->last != true || !end);
		}
		if (hit) {
			total = (int)Subprice * qty;
			String^ ttl;
			int^ sub = 0;
			try {
				if (rbtSales->Checked == true) {
					sub = total - Convert::ToInt32(numDiscount->Text);
					ttl = sub + "";

				}
				else {
					sub = total - Convert::ToInt32(richTextBox3->Text);
					ttl = sub + "";
				}
			}
			catch (Exception^ ex) {
				String^ err = "Invalid adjustment/discount input.";
				MBox^ adform = gcnew MBox(err, 1);
				adform->ShowDialog();
				richTextBox3->Text = "0";
				numDiscount->Text = "0";
				delete adform;
				return;
			}
			rtbTotal->Text = ttl;
			delete str;
		}

	}

	


	private: System::Void rbtSales_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		lblSubprice->Text = "Subtotal";
		lblTotal->Text = "Total";
		richTextBox3->Text = "0";
		numQty->Text = "0";
		cboxPayMethod->Text = "";
		label7->Hide();
		button2->Hide();
		richTextBox3->Hide();
		lblPayMethod->Show();
		cboxPayMethod->Show();
		panel2->Show();
		label1->Show();
		numDiscount->Show();
		

	}
	private: System::Void locateDatabaseToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private: System::Void clearDatabaseToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void changePasswordToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private: System::Void aboutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		AboutForm^ cform = gcnew AboutForm();
		cform->ShowDialog();
	}
	private: System::Void viewLogToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		LogForm^ lg = gcnew LogForm();
		lg->Show();
	}
	private: System::Void button1_Click_2(System::Object^ sender, System::EventArgs^ e) {
		rtbSumLog->Text = "";
	}
	private: System::Void btnSync_Click(System::Object^ sender, System::EventArgs^ e) {
		syncb();
	}


	private: System::Void button2_Click_1(System::Object^ sender, System::EventArgs^ e) {
		if (cboxProduct->Text == "") {
			return;
		}
		String^ msg = "Delete item?";
		MBox^ adform = gcnew MBox(msg, 0);
		adform->ShowDialog();
		delete adform;
		if (adform->ReturnData() == "true") {

			bool hit = false, end = false;
			String^ msg;
			dataClass^ str = gcnew dataClass;
			str = three.start;

			if (str->ProductName != nullptr) {
				do {
					if (str->last) {
						end = true;
					}

					if (cboxProduct->Text == str->ProductName) {
						three.deleteItem(str->ProductName);
						hit = true;
						break;
					}
					if (str->next != nullptr) {
						str = str->next;
					}
				} while (str->last != true || !end);
			}
			if (hit) {
				msg = "Deleted item:\n\n" + cboxProduct->Text;
				MBox^ mform = gcnew MBox(msg, 1);
				mform->ShowDialog();
				cboxProduct->Text = "";
				numQty->Text = "0";
				rtbSubprice->Text = "";
				rtbTotal->Text = "";
				delete mform;

				syncb();
			}
			else {
				msg = "Invalid item name.";
				MBox^ mform = gcnew MBox(msg, 1);
				delete mform;
			}
			delete str;
		}

	}


private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pictureBox2_Click_1(System::Object^ sender, System::EventArgs^ e) {
	this->Close();

}
private: System::Void pictureBox3_Click(System::Object^ sender, System::EventArgs^ e) {
	this->WindowState = FormWindowState::Minimized;
}

private: System::Void FrontForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (this->dragging) { //Move, soldier, MOVE!
		Point currentScreenPos = PointToScreen(e->Location);
		Location = Point(currentScreenPos.X - this->offset.X,
			currentScreenPos.Y - this->offset.Y);
	}
}
private: System::Void FrontForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	this->dragging = false;
}
private: System::Void FrontForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	this->dragging = true;
	this->offset = Point(e->X, e->Y);
}



private: System::Void closeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ msg = "The current database will be unloaded. Proceed?";
	MBox^ adform = gcnew MBox(msg, 0);
	adform->ShowDialog();
	if (adform->ReturnData() == "true") {
		IO::File::Delete(path + "\\InventorySystem.exe.config");
		delete adform;
		Application::Restart();
	}
	delete adform;
}
private: System::Void resetToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ msg = "All database item entries will be deleted. Proceed?";
	MBox^ adform = gcnew MBox(msg, 0);
	adform->ShowDialog();
	if (adform->ReturnData() == "true") {
		three.eraseDB();
		delete adform;
		Application::Restart();
	}
	delete adform;
}
private: System::Void changePasswordToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
	ChangeF^ cform = gcnew ChangeF();
	cform->ShowDialog();
}
private: System::Void rtbSumLog_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void itemToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void addItemToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	NewProduct^ newprod = gcnew NewProduct();
	newprod->ShowDialog();
}
private: System::Void editToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	EditItemForm^ wind = gcnew EditItemForm();
	wind->ShowDialog();
}
private: System::Void watchdogToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	NotifForm^ watchdog = gcnew NotifForm();
	watchdog->ShowDialog();
	syncb();
}

private: System::Void numDiscount_TextChanged(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void numDiscount_Leave(System::Object^ sender, System::EventArgs^ e) {
	if (cboxProduct->Text == "") {
		return;
	}
	try {
		discount = Convert::ToInt32(numDiscount->Text);
	}
	catch (Exception^ ex) {
		String^ err = "Invalid adjustment/discount input.";
		MBox^ adform = gcnew MBox(err, 1);
		adform->ShowDialog();
		numDiscount->Text = "0";
		numQty->Text = "0";
		delete adform;
		return;
	}

	nTotal = total - discount;
	rtbTotal->Text = nTotal.ToString();
}
private: System::Void richTextBox3_Leave(System::Object^ sender, System::EventArgs^ e) {
	if (cboxProduct->Text == "") {
		return;
	}
	try {
		discount = Convert::ToInt32(richTextBox3->Text);
	}
	catch (Exception^ ex) {
		String^ err = "Invalid adjustment/discount input.";
		MBox^ adform = gcnew MBox(err, 1);
		adform->ShowDialog();
		richTextBox3->Text = "0";
		numQty->Text = "0";
		delete adform;
		return;
	}

	nTotal = total - discount;
	rtbTotal->Text = nTotal.ToString();
}
private: System::Void rtbTotal_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void richTextBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
