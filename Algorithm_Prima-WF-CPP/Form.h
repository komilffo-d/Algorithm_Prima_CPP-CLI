#pragma once
#include "Graph.h"
#include "Vertex.h"
#include <queue>
using namespace ObjectNamespace;
namespace FormNamespace {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form : public System::Windows::Forms::Form
	{
	public:
		DrawGraph ^G;
		List<Vertex^> ^V;
		List<Edge^>^ E;
		List<Tuple<int,int>^>^ MST;
		int stageMST = 0;
		const int maxCountVertex = 20;
		const int minLengthEdge = 0;
		const int maxLengthEdge = 1000;
		int selectedOne = -1;
	private: System::Windows::Forms::DataGridView^ lengthGrid;
	public:




	private: System::Windows::Forms::Button^ drawEdgeButton;

	private: System::Windows::Forms::Button^ clearButton;
	private: System::Windows::Forms::PictureBox^ sheet;
	private: System::Windows::Forms::DataGridView^ matrixGrid;

	private: System::Windows::Forms::Button^ primButton;
	private: System::Windows::Forms::ListBox^ edgesPrimListBox;



	private: System::Windows::Forms::GroupBox^ typeInputGroup;
	private: System::Windows::Forms::RadioButton^ typeInputRadioButton_1;
	private: System::Windows::Forms::RadioButton^ typeInputRadioButton_2;



	private: System::Windows::Forms::Button^ drawVertexButton;

	private: System::Windows::Forms::Button^ deleteButton;




	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::NumericUpDown^ countVertexMatrixGridNumericUpDown;
	private: System::Windows::Forms::Label^ InfoMatrixGridLabel;
	private: System::Windows::Forms::Button^ stageButton;
	private: System::Windows::Forms::Button^ momentButton;
	private: System::Windows::Forms::GroupBox^ typeMSTMoveGroupBox;
	private: System::Windows::Forms::TextBox^ choicedVertexTextBox;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ selectButton;
	private: System::Windows::Forms::Label^ InfoChoicedVertexLabel;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ V1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ V2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Weight;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ ÒÔ‡‚Í‡ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ‚ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ‚˚ıÓ‰ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem2;





























	public:
		int selectedTwo = -1;

		Form(void)
		{
			InitializeComponent();
			V = gcnew List<Vertex^>();
			E = gcnew List<Edge^>();
			G = gcnew DrawGraph(sheet->Width, sheet->Height);
			sheet->Image = G->GetBitmap();
			typeInputRadioButton_1->Checked = true;
		}

	protected:
		~Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: 








		System::ComponentModel::Container ^components;
		System::Drawing::Point startPoint;




#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form::typeid));
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->lengthGrid = (gcnew System::Windows::Forms::DataGridView());
			this->V1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->V2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Weight = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->drawEdgeButton = (gcnew System::Windows::Forms::Button());
			this->clearButton = (gcnew System::Windows::Forms::Button());
			this->sheet = (gcnew System::Windows::Forms::PictureBox());
			this->matrixGrid = (gcnew System::Windows::Forms::DataGridView());
			this->primButton = (gcnew System::Windows::Forms::Button());
			this->edgesPrimListBox = (gcnew System::Windows::Forms::ListBox());
			this->typeInputGroup = (gcnew System::Windows::Forms::GroupBox());
			this->typeInputRadioButton_1 = (gcnew System::Windows::Forms::RadioButton());
			this->typeInputRadioButton_2 = (gcnew System::Windows::Forms::RadioButton());
			this->drawVertexButton = (gcnew System::Windows::Forms::Button());
			this->deleteButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->countVertexMatrixGridNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->InfoMatrixGridLabel = (gcnew System::Windows::Forms::Label());
			this->stageButton = (gcnew System::Windows::Forms::Button());
			this->momentButton = (gcnew System::Windows::Forms::Button());
			this->typeMSTMoveGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->choicedVertexTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->selectButton = (gcnew System::Windows::Forms::Button());
			this->InfoChoicedVertexLabel = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ÒÔ‡‚Í‡ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->‚ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->‚˚ıÓ‰ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->lengthGrid))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sheet))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->matrixGrid))->BeginInit();
			this->typeInputGroup->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->countVertexMatrixGridNumericUpDown))->BeginInit();
			this->typeMSTMoveGroupBox->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// lengthGrid
			// 
			this->lengthGrid->AllowUserToAddRows = false;
			this->lengthGrid->AllowUserToDeleteRows = false;
			this->lengthGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->lengthGrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->V1, this->V2,
					this->Weight
			});
			this->lengthGrid->Location = System::Drawing::Point(503, 627);
			this->lengthGrid->Name = L"lengthGrid";
			this->lengthGrid->Size = System::Drawing::Size(466, 40);
			this->lengthGrid->TabIndex = 14;
			this->lengthGrid->Visible = false;
			this->lengthGrid->RowsAdded += gcnew System::Windows::Forms::DataGridViewRowsAddedEventHandler(this, &Form::lengthGrid_RowsAdded);
			// 
			// V1
			// 
			this->V1->HeaderText = L"V1";
			this->V1->Name = L"V1";
			this->V1->ReadOnly = true;
			this->V1->Width = 50;
			// 
			// V2
			// 
			this->V2->HeaderText = L"V2";
			this->V2->Name = L"V2";
			this->V2->ReadOnly = true;
			this->V2->Width = 50;
			// 
			// Weight
			// 
			this->Weight->HeaderText = L"ƒÎËÌ‡";
			this->Weight->Name = L"Weight";
			this->Weight->ReadOnly = true;
			// 
			// drawEdgeButton
			// 
			this->drawEdgeButton->BackColor = System::Drawing::Color::White;
			this->drawEdgeButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->drawEdgeButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"drawEdgeButton.Image")));
			this->drawEdgeButton->Location = System::Drawing::Point(445, 171);
			this->drawEdgeButton->Name = L"drawEdgeButton";
			this->drawEdgeButton->Size = System::Drawing::Size(52, 52);
			this->drawEdgeButton->TabIndex = 13;
			this->drawEdgeButton->UseVisualStyleBackColor = false;
			this->drawEdgeButton->Click += gcnew System::EventHandler(this, &Form::drawEdgeButton_Click);
			// 
			// clearButton
			// 
			this->clearButton->BackColor = System::Drawing::Color::White;
			this->clearButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->clearButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"clearButton.Image")));
			this->clearButton->Location = System::Drawing::Point(445, 287);
			this->clearButton->Name = L"clearButton";
			this->clearButton->Size = System::Drawing::Size(52, 52);
			this->clearButton->TabIndex = 11;
			this->clearButton->UseVisualStyleBackColor = false;
			this->clearButton->Click += gcnew System::EventHandler(this, &Form::clearButton_Click);
			// 
			// sheet
			// 
			this->sheet->BackColor = System::Drawing::Color::White;
			this->sheet->Location = System::Drawing::Point(503, 55);
			this->sheet->Name = L"sheet";
			this->sheet->Size = System::Drawing::Size(692, 520);
			this->sheet->TabIndex = 10;
			this->sheet->TabStop = false;
			this->sheet->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form::sheet_MouseClick);
			// 
			// matrixGrid
			// 
			this->matrixGrid->AllowUserToAddRows = false;
			this->matrixGrid->AllowUserToDeleteRows = false;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->matrixGrid->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->matrixGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->matrixGrid->Location = System::Drawing::Point(15, 208);
			this->matrixGrid->Name = L"matrixGrid";
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->matrixGrid->RowHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->matrixGrid->Size = System::Drawing::Size(361, 208);
			this->matrixGrid->TabIndex = 15;
			this->matrixGrid->CellEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form::matrixGrid_CellEnter);
			this->matrixGrid->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form::matrixGrid_CellValueChanged);
			// 
			// primButton
			// 
			this->primButton->Location = System::Drawing::Point(12, 459);
			this->primButton->Name = L"primButton";
			this->primButton->Size = System::Drawing::Size(228, 23);
			this->primButton->TabIndex = 18;
			this->primButton->Text = L"¿Î„ÓËÚÏ œËÏ‡";
			this->primButton->UseVisualStyleBackColor = true;
			this->primButton->Click += gcnew System::EventHandler(this, &Form::primButton_Click);
			// 
			// edgesPrimListBox
			// 
			this->edgesPrimListBox->FormattingEnabled = true;
			this->edgesPrimListBox->Location = System::Drawing::Point(15, 512);
			this->edgesPrimListBox->Name = L"edgesPrimListBox";
			this->edgesPrimListBox->Size = System::Drawing::Size(370, 108);
			this->edgesPrimListBox->TabIndex = 19;
			// 
			// typeInputGroup
			// 
			this->typeInputGroup->Controls->Add(this->typeInputRadioButton_1);
			this->typeInputGroup->Controls->Add(this->typeInputRadioButton_2);
			this->typeInputGroup->Location = System::Drawing::Point(12, 46);
			this->typeInputGroup->Name = L"typeInputGroup";
			this->typeInputGroup->Size = System::Drawing::Size(200, 100);
			this->typeInputGroup->TabIndex = 22;
			this->typeInputGroup->TabStop = false;
			this->typeInputGroup->Text = L"¬˚·Ó ÚËÔ‡ ‚‚Ó‰‡ ‰‡ÌÌ˚ı";
			// 
			// typeInputRadioButton_1
			// 
			this->typeInputRadioButton_1->AutoSize = true;
			this->typeInputRadioButton_1->Location = System::Drawing::Point(23, 31);
			this->typeInputRadioButton_1->Name = L"typeInputRadioButton_1";
			this->typeInputRadioButton_1->Size = System::Drawing::Size(159, 17);
			this->typeInputRadioButton_1->TabIndex = 20;
			this->typeInputRadioButton_1->Text = L"¬‚Ó‰ Ò ÔÓÏÓ˘¸˛ Ï‡ÚËˆ˚";
			this->typeInputRadioButton_1->UseVisualStyleBackColor = true;
			this->typeInputRadioButton_1->CheckedChanged += gcnew System::EventHandler(this, &Form::typeInputRadioButton_1_CheckedChanged);
			// 
			// typeInputRadioButton_2
			// 
			this->typeInputRadioButton_2->AutoSize = true;
			this->typeInputRadioButton_2->Location = System::Drawing::Point(23, 54);
			this->typeInputRadioButton_2->Name = L"typeInputRadioButton_2";
			this->typeInputRadioButton_2->Size = System::Drawing::Size(145, 17);
			this->typeInputRadioButton_2->TabIndex = 21;
			this->typeInputRadioButton_2->Text = L"¬‚Ó‰ Ò ÔÓÏÓ˘¸˛ „‡Ù‡";
			this->typeInputRadioButton_2->UseVisualStyleBackColor = true;
			this->typeInputRadioButton_2->CheckedChanged += gcnew System::EventHandler(this, &Form::typeInputRadioButton_2_CheckedChanged);
			// 
			// drawVertexButton
			// 
			this->drawVertexButton->BackColor = System::Drawing::Color::White;
			this->drawVertexButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->drawVertexButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"drawVertexButton.Image")));
			this->drawVertexButton->Location = System::Drawing::Point(445, 113);
			this->drawVertexButton->Name = L"drawVertexButton";
			this->drawVertexButton->Size = System::Drawing::Size(52, 52);
			this->drawVertexButton->TabIndex = 23;
			this->drawVertexButton->UseVisualStyleBackColor = false;
			this->drawVertexButton->Click += gcnew System::EventHandler(this, &Form::drawVertexButton_Click);
			// 
			// deleteButton
			// 
			this->deleteButton->BackColor = System::Drawing::Color::White;
			this->deleteButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->deleteButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"deleteButton.Image")));
			this->deleteButton->Location = System::Drawing::Point(445, 229);
			this->deleteButton->Name = L"deleteButton";
			this->deleteButton->Size = System::Drawing::Size(52, 52);
			this->deleteButton->TabIndex = 24;
			this->deleteButton->UseVisualStyleBackColor = false;
			this->deleteButton->Click += gcnew System::EventHandler(this, &Form::deleteButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(15, 172);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(167, 18);
			this->label1->TabIndex = 25;
			this->label1->Text = L"Ã‡ÚËˆ‡ ÒÏÂÊÌÓÒÚË";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(500, 28);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(168, 18);
			this->label2->TabIndex = 26;
			this->label2->Text = L"ŒÚÓ·‡ÊÂÌËÂ „‡Ù‡";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(188, 177);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(113, 13);
			this->label4->TabIndex = 28;
			this->label4->Text = L" ÓÎË˜ÂÒÚ‚Ó ‚Â¯ËÌ: ";
			// 
			// countVertexMatrixGridNumericUpDown
			// 
			this->countVertexMatrixGridNumericUpDown->Location = System::Drawing::Point(307, 175);
			this->countVertexMatrixGridNumericUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			this->countVertexMatrixGridNumericUpDown->Name = L"countVertexMatrixGridNumericUpDown";
			this->countVertexMatrixGridNumericUpDown->Size = System::Drawing::Size(39, 20);
			this->countVertexMatrixGridNumericUpDown->TabIndex = 29;
			this->countVertexMatrixGridNumericUpDown->ValueChanged += gcnew System::EventHandler(this, &Form::countVertexMatrixGridNumericUpDown_ValueChanged);
			// 
			// InfoMatrixGridLabel
			// 
			this->InfoMatrixGridLabel->AutoSize = true;
			this->InfoMatrixGridLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->InfoMatrixGridLabel->Location = System::Drawing::Point(9, 419);
			this->InfoMatrixGridLabel->Name = L"InfoMatrixGridLabel";
			this->InfoMatrixGridLabel->Size = System::Drawing::Size(330, 14);
			this->InfoMatrixGridLabel->TabIndex = 30;
			this->InfoMatrixGridLabel->Text = L"*Ã‡ÚËˆÛ ÌÂÎ¸Áˇ Á‡ÔÓÎÌËÚ¸ ‚Û˜ÌÛ˛( ¬‚Ó‰ËÚ¸ ˜ÂÂÁ \"—ÔËÒÓÍ ∏·Â\")";
			// 
			// stageButton
			// 
			this->stageButton->Location = System::Drawing::Point(16, 25);
			this->stageButton->Name = L"stageButton";
			this->stageButton->Size = System::Drawing::Size(174, 23);
			this->stageButton->TabIndex = 31;
			this->stageButton->Text = L"¬ÔÂ∏‰";
			this->stageButton->UseVisualStyleBackColor = true;
			this->stageButton->Click += gcnew System::EventHandler(this, &Form::stageButton_Click);
			// 
			// momentButton
			// 
			this->momentButton->Location = System::Drawing::Point(16, 54);
			this->momentButton->Name = L"momentButton";
			this->momentButton->Size = System::Drawing::Size(174, 23);
			this->momentButton->TabIndex = 32;
			this->momentButton->Text = L"ÃÓÏÂÌÚ‡Î¸ÌÓ";
			this->momentButton->UseVisualStyleBackColor = true;
			this->momentButton->Click += gcnew System::EventHandler(this, &Form::momentButton_Click);
			// 
			// typeMSTMoveGroupBox
			// 
			this->typeMSTMoveGroupBox->Controls->Add(this->momentButton);
			this->typeMSTMoveGroupBox->Controls->Add(this->stageButton);
			this->typeMSTMoveGroupBox->Location = System::Drawing::Point(999, 581);
			this->typeMSTMoveGroupBox->Name = L"typeMSTMoveGroupBox";
			this->typeMSTMoveGroupBox->Size = System::Drawing::Size(196, 91);
			this->typeMSTMoveGroupBox->TabIndex = 33;
			this->typeMSTMoveGroupBox->TabStop = false;
			this->typeMSTMoveGroupBox->Text = L"“ËÔ ÔÂÂÏÂ˘ÂÌËˇ";
			this->typeMSTMoveGroupBox->Visible = false;
			// 
			// choicedVertexTextBox
			// 
			this->choicedVertexTextBox->Location = System::Drawing::Point(381, 459);
			this->choicedVertexTextBox->Name = L"choicedVertexTextBox";
			this->choicedVertexTextBox->ReadOnly = true;
			this->choicedVertexTextBox->Size = System::Drawing::Size(89, 20);
			this->choicedVertexTextBox->TabIndex = 34;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(247, 462);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(132, 13);
			this->label5->TabIndex = 35;
			this->label5->Text = L"¬˚·‡ÌÌ‡ˇ ‚Â¯ËÌ‡:";
			// 
			// selectButton
			// 
			this->selectButton->BackColor = System::Drawing::Color::White;
			this->selectButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->selectButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"selectButton.Image")));
			this->selectButton->Location = System::Drawing::Point(445, 55);
			this->selectButton->Name = L"selectButton";
			this->selectButton->Size = System::Drawing::Size(52, 52);
			this->selectButton->TabIndex = 36;
			this->selectButton->UseVisualStyleBackColor = false;
			this->selectButton->Click += gcnew System::EventHandler(this, &Form::selectButton_Click);
			// 
			// InfoChoicedVertexLabel
			// 
			this->InfoChoicedVertexLabel->AutoSize = true;
			this->InfoChoicedVertexLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 6.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->InfoChoicedVertexLabel->Location = System::Drawing::Point(9, 482);
			this->InfoChoicedVertexLabel->Name = L"InfoChoicedVertexLabel";
			this->InfoChoicedVertexLabel->Size = System::Drawing::Size(396, 14);
			this->InfoChoicedVertexLabel->TabIndex = 37;
			this->InfoChoicedVertexLabel->Text = L"*¬˚·‡ÌÌ‡ˇ ‚Â¯ËÌ‡ - ˝ÚÓ ÌÓÏÂ ÒÚÓÍË ‚˚·‡ÌÌÓÈ ˇ˜ÂÈÍË ‚ Ï‡ÚËˆÂ ÒÏÂÊÌÓÒÚË";
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::White;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->ÒÔ‡‚Í‡ToolStripMenuItem,
					this->‚˚ıÓ‰ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1236, 24);
			this->menuStrip1->TabIndex = 38;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ÒÔ‡‚Í‡ToolStripMenuItem
			// 
			this->ÒÔ‡‚Í‡ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->‚ToolStripMenuItem,
					this->toolStripMenuItem2
			});
			this->ÒÔ‡‚Í‡ToolStripMenuItem->Name = L"ÒÔ‡‚Í‡ToolStripMenuItem";
			this->ÒÔ‡‚Í‡ToolStripMenuItem->Size = System::Drawing::Size(65, 20);
			this->ÒÔ‡‚Í‡ToolStripMenuItem->Text = L"—Ô‡‚Í‡";
			// 
			// ‚ToolStripMenuItem
			// 
			this->‚ToolStripMenuItem->Name = L"‚ToolStripMenuItem";
			this->‚ToolStripMenuItem->Size = System::Drawing::Size(80, 22);
			this->‚ToolStripMenuItem->Text = L"1";
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(80, 22);
			this->toolStripMenuItem2->Text = L"2";
			// 
			// ‚˚ıÓ‰ToolStripMenuItem
			// 
			this->‚˚ıÓ‰ToolStripMenuItem->Name = L"‚˚ıÓ‰ToolStripMenuItem";
			this->‚˚ıÓ‰ToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->‚˚ıÓ‰ToolStripMenuItem->Text = L"¬˚ıÓ‰";
			this->‚˚ıÓ‰ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form::‚˚ıÓ‰ToolStripMenuItem_Click);
			// 
			// Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1236, 679);
			this->Controls->Add(this->InfoChoicedVertexLabel);
			this->Controls->Add(this->selectButton);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->choicedVertexTextBox);
			this->Controls->Add(this->typeMSTMoveGroupBox);
			this->Controls->Add(this->InfoMatrixGridLabel);
			this->Controls->Add(this->countVertexMatrixGridNumericUpDown);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->deleteButton);
			this->Controls->Add(this->drawVertexButton);
			this->Controls->Add(this->lengthGrid);
			this->Controls->Add(this->drawEdgeButton);
			this->Controls->Add(this->clearButton);
			this->Controls->Add(this->sheet);
			this->Controls->Add(this->matrixGrid);
			this->Controls->Add(this->primButton);
			this->Controls->Add(this->edgesPrimListBox);
			this->Controls->Add(this->typeInputGroup);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form";
			this->Text = L"¿Î„ÓËÚÏ œËÏ‡";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->lengthGrid))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sheet))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->matrixGrid))->EndInit();
			this->typeInputGroup->ResumeLayout(false);
			this->typeInputGroup->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->countVertexMatrixGridNumericUpDown))->EndInit();
			this->typeMSTMoveGroupBox->ResumeLayout(false);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private: 
			System::Void clearButton_Click(System::Object^ sender, System::EventArgs^ e);
			System::Void sheet_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
			System::Void drawEdgeButton_Click(System::Object^ sender, System::EventArgs^ e);
			System::Void FillLengthGrid();
			System::Void FillMatrixGrid(int numberV, bool columnIsReadOnly);
			System::Void lengthGrid_RowsAdded(System::Object^ sender, System::Windows::Forms::DataGridViewRowsAddedEventArgs^ e);
			System::Drawing::Bitmap^ CreateGraphFromMatrix(List<Tuple<int, int>^>^ MSTEdges);
			System::Boolean AlgorithmByPrim();
			System::Void  TotalClearWithountType();
			System::Void primButton_Click(System::Object^ sender, System::EventArgs^ e);
			System::Void drawVertexButton_Click(System::Object^ sender, System::EventArgs^ e);
			System::Void typeInputRadioButton_1_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
			System::Void typeInputRadioButton_2_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
			System::Void deleteButton_Click(System::Object^ sender, System::EventArgs^ e);
			System::Void countVertexMatrixGridNumericUpDown_ValueChanged(System::Object^ sender, System::EventArgs^ e);
			System::Void matrixGrid_CellValueChanged(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
			System::Void stageButton_Click(System::Object^ sender, System::EventArgs^ e);
			System::Void momentButton_Click(System::Object^ sender, System::EventArgs^ e);
			System::Void selectButton_Click(System::Object^ sender, System::EventArgs^ e);
			System::Void ‚˚ıÓ‰ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
			System::Void matrixGrid_CellEnter(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);

			void traverse(int s, bool visited[], array<int, 2>^ graph, int NODE) {
				visited[s] = true; 
				std::queue<int> que;
				que.push(s);
				while (!que.empty()) {
					int u = que.front(); 
					que.pop();
					for (int i = 0; i < NODE; i++) {
						if (graph[i, u]) {

							if (!visited[i]) {
								visited[i] = true;
								que.push(i);
							}
						}
					}
				}
			}
			bool isConnected(array<int, 2>^ graph, int NODE) {
				bool* vis = new bool[NODE];
				for (int u = 0; u < NODE; u++) {
					for (int i = 0; i < NODE; i++)
						vis[i] = false;
					traverse(u, vis, graph, NODE);
					for (int i = 0; i < NODE; i++) {
						if (!vis[i])
							return false;
					}
				}
				return true;
			}


};

}
