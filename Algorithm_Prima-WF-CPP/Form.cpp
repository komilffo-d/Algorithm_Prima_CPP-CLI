#include "pch.h"
#include "Form.h"
#include "Utilities.h";
#include "Form_1.h"
#include "Form_2.h"
using namespace Microsoft::VisualBasic;
using namespace System::Windows::Forms;
using namespace UtilitiesNamespace;
using namespace System::Runtime::InteropServices;

//События клика на кнопку рисования вершин
System::Void FormNamespace::Form::drawVertexButton_Click(System::Object^ sender, System::EventArgs^ e) {
	selectButton->Enabled = true;
	drawVertexButton->Enabled = false;
	drawEdgeButton->Enabled = true;
	deleteButton->Enabled = true;
	clearButton->Enabled = true;
	G->ClearSheet();
	G->DrawALLGraph(V, E, nullptr);
	sheet->Image = G->GetBitmap();
}
//События клика на кнопку рисования рёбер
System::Void FormNamespace::Form::drawEdgeButton_Click(System::Object^ sender, System::EventArgs^ e) {
	selectButton->Enabled = true;
	drawVertexButton->Enabled = true;
	drawEdgeButton->Enabled = false;
	deleteButton->Enabled = true;
	clearButton->Enabled = true;
	selectedOne = -1;
	selectedTwo = -1;
	G->ClearSheet();
	G->DrawALLGraph(V, E, nullptr);
	sheet->Image = G->GetBitmap();
}
//События клика на кнопку удаления вершин или рёбер
System::Void FormNamespace::Form::deleteButton_Click(System::Object^ sender, System::EventArgs^ e) {
	selectButton->Enabled = true;
	drawVertexButton->Enabled = true;
	drawEdgeButton->Enabled = true;
	deleteButton->Enabled = false;
	clearButton->Enabled = true;
	G->ClearSheet();
	G->DrawALLGraph(V, E, nullptr);
	sheet->Image = G->GetBitmap();
}
//События клика на кнопку выбора вершины
System::Void FormNamespace::Form::selectButton_Click(System::Object^ sender, System::EventArgs^ e) {
	selectButton->Enabled = false;
	drawVertexButton->Enabled = true;
	drawEdgeButton->Enabled = true;
	deleteButton->Enabled = true;
	clearButton->Enabled = true;

}
//События клика на холст
System::Void FormNamespace::Form::sheet_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	//Если холст можно изменять вручную
	if (sheet->Enabled) {
		//Если кнопка выбора вершины включена
		if (selectButton->Enabled == false) {
			for (int i = 0; i < V->Count; i++)
			{
				//Если координаты нажатия совпадают в площадью вершины
				if (Math::Pow((V[i]->X - e->X), 2) + Math::Pow((V[i]->Y - e->Y), 2) <= G->R * G->R)
				{
					if (selectedOne != -1)
					{
						selectedOne = -1;
						G->ClearSheet();
						G->DrawALLGraph(V, E,nullptr);
						sheet->Image = G->GetBitmap();
					}
					if (selectedOne == -1)
					{
						G->DrawSelectedVertex(V[i]->X, V[i]->Y);
						selectedOne = i;
						choicedVertexTextBox->Text= (i+1).ToString();
						sheet->Image = G->GetBitmap();
					}
				}
			}
		}
		//Если кнопка рисования вершин включена
		else if (drawVertexButton->Enabled == false)
		{
			if (V->Count >= maxCountVertex)
				
				MessageBox::Show("Достигнуто максимальное количество точек (" + maxCountVertex + ")");
			else {
				V->Add(gcnew Vertex(e->Location.X, e->Location.Y));
				G->DrawVertex(e->Location.X, e->Location.Y, (V->Count).ToString());

				sheet->Image = G->GetBitmap();
			}
			FillMatrixGrid(V->Count, true);

		}
		//Если кнопка рисования граней включена
		else if (drawEdgeButton->Enabled == false) {
			if (e->Button == System::Windows::Forms::MouseButtons::Left)
			{

				for (int i = 0; i < V->Count; i++)
				{
					//Если координаты нажатия совпадают в площадью вершины
					if (Math::Pow((V[i]->X - e->Location.X), 2) + Math::Pow((V[i]->Y - e->Location.Y), 2) <= G->R * G->R)
					{
						//Если первая вершина не выбрана
						if (selectedOne == -1)
						{
							G->DrawSelectedVertex(V[i]->X, V[i]->Y);
							selectedOne = i;
							sheet->Image = G->GetBitmap();
							break;
						}
						//Если вторая вершина не выбрана
						if (selectedTwo == -1)
						{

							selectedTwo = i;
							Edge^ edgeNew = gcnew Edge(selectedOne, selectedTwo, nullptr);
							if (E->Find(
								gcnew Predicate<Edge^>(gcnew EdgePredicate(edgeNew), &EdgePredicate::Matched)
							) ==nullptr) {

								String^ input =
									Interaction::InputBox("Введите вес указанного ребра:", "Ввод веса", nullptr, this->Left + (this->Width / 2) - 200, this->Top + (this->Height / 2) - 100);
								int result;
								if (System::Int32::TryParse(input, result) && result >= minLengthEdge && result <= maxLengthEdge) {

									G->DrawSelectedVertex(V[i]->X, V[i]->Y);
									E->Add(gcnew Edge(selectedOne, selectedTwo, (Nullable<int>)result));
									G->DrawEdge(V[selectedOne], V[selectedTwo], E[E->Count - 1], result.ToString());
								}
								else 
									MessageBox::Show("Введёное значение не является числом или выходит за пределы диапазона (to 0 from 1000)!");
								

								
							}
							else
								MessageBox::Show("Ребро между вершинами уже назначено!");
								
							selectedOne = -1;
							selectedTwo = -1;
							G->DrawALLGraph(V, E, nullptr);
							sheet->Image = G->GetBitmap();
							break;

						}
					}
				}
				FillLengthGrid();
			}
		}
		//Если кнопка удаления вершин и граней включена
		else if (deleteButton->Enabled == false)
		{
			bool flag = false; 
			for (int i = 0; i < V->Count; i++)
			{
				if (Math::Pow((V[i]->X - e->Location.X), 2) + Math::Pow((V[i]->Y - e->Location.Y), 2) <= G->R * G->R)
				{
					for (int j = 0; j < E->Count; j++)
					{
						if ((E[j]->V1 == i) || (E[j]->V2 == i))
						{
							E->RemoveAt(j);
							j--;
						}
						else
						{
							if (E[j]->V1 > i) E[j]->V1--;
							if (E[j]->V2 > i) E[j]->V2--;
						}
					}
					V->RemoveAt(i);
					flag = true;
					break;
				}
			}
			//Если вершина не была удалена, проверяем среди граней
			if (!flag)
			{
				for (int i = 0; i < E->Count; i++)
				{
					if (E[i]->V1 == E[i]->V2) 
					{
						if ((Math::Pow((V[E[i]->V1]->X - G->R - e->X), 2) + Math::Pow((V[E[i]->V1]->Y - G->R - e->Y), 2) <= ((G->R + 2) * (G->R + 2))) &&
							(Math::Pow((V[E[i]->V1]->X - G->R - e->X), 2) + Math::Pow((V[E[i]->V1]->Y - G->R - e->Y), 2) >= ((G->R - 2) * (G->R - 2))))
						{
							E->RemoveAt(i);
							flag = true;
							break;
						}
					}
					else 
					{
						if (((e->X - V[E[i]->V1]->X) * (V[E[i]->V2]->Y - V[E[i]->V1]->Y) / (V[E[i]->V2]->X - V[E[i]->V1]->X) + V[E[i]->V1]->Y) <= (e->Y + 4) &&
							((e->X - V[E[i]->V1]->X) * (V[E[i]->V2]->Y - V[E[i]->V1]->Y) / (V[E[i]->V2]->X - V[E[i]->V1]->X) + V[E[i]->V1]->Y) >= (e->Y - 4))
						{
							if ((V[E[i]->V1]->X <= V[E[i]->V2]->X && V[E[i]->V1]->X <= e->X && e->X <= V[E[i]->V2]->X) ||
								(V[E[i]->V1]->X >= V[E[i]->V2]->X && V[E[i]->V1]->X >= e->X && e->X >= V[E[i]->V2]->X))
							{
								E->RemoveAt(i);
								flag = true;
								break;
							}
						}
					}
				}
			}
			//Если что-то было удалено - перерисовываем холст
			if (flag)
			{
				G->ClearSheet();
				G->DrawALLGraph(V, E, nullptr);
				sheet->Image = G->GetBitmap();
			}
			FillLengthGrid();
			FillMatrixGrid(V->Count, true);
		}
	}
}
//Очистка холста
System::Void FormNamespace::Form::clearButton_Click(System::Object^ sender, System::EventArgs^ e) {

	String^ message = "Вы действительно хотите полностью удалить граф?";
	String^ caption = "Удаление";
	auto MBSave = MessageBox::Show(message, caption, MessageBoxButtons::YesNo, MessageBoxIcon::Question);
	if (MBSave == ::DialogResult::Yes)
	{
		TotalClearWithountType();
	}
}
//Выбор создания графа по матрице
System::Void FormNamespace::Form::typeInputRadioButton_1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	RadioButton ^radioButton =(RadioButton^)(sender);
	if (radioButton->Checked) {
		drawVertexButton->Enabled = false;
		drawEdgeButton->Enabled = false;
		deleteButton->Enabled = false;
		selectButton->Enabled = false;

		sheet->Enabled = false;
		InfoMatrixGridLabel->Visible = false;
		InfoChoicedVertexLabel->Visible = true;
		countVertexMatrixGridNumericUpDown->Enabled = true;
		countVertexMatrixGridNumericUpDown->Value = 0;
		TotalClearWithountType();
	}
}
//Выбор создания графа по холсту
System::Void FormNamespace::Form::typeInputRadioButton_2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	RadioButton^ radioButton = (RadioButton^)(sender);
	if (radioButton->Checked) {
		drawVertexButton->Enabled = true;
		drawEdgeButton->Enabled = true;
		deleteButton->Enabled = true;
		selectButton->Enabled = true;

		sheet->Enabled = true;

		InfoMatrixGridLabel->Visible = true;
		InfoChoicedVertexLabel->Visible = false;
		countVertexMatrixGridNumericUpDown->Value = 0;
		countVertexMatrixGridNumericUpDown->Enabled = false;
		TotalClearWithountType();
	}
}
//Очистка состояния приложения
System::Void  FormNamespace::Form::TotalClearWithountType() {
	matrixGrid->DataSource = nullptr;
	matrixGrid->Rows->Clear();
	lengthGrid->Rows->Clear();
	edgesPrimListBox->Items->Clear();
	G->ClearSheet();
	sheet->Image = G->GetBitmap();
	E->Clear();
	V->Clear();
	stageMST = 0;
	typeMSTMoveGroupBox->Visible = false;
	typeMSTMoveGroupBox->Enabled = false;
	choicedVertexTextBox->Text = "";

}
//События добавления строки в матрицу длин рёбер - нужно для динамического помещения данных в матрицу смежности
System::Void FormNamespace::Form::lengthGrid_RowsAdded(System::Object^ sender, System::Windows::Forms::DataGridViewRowsAddedEventArgs^ e) {
	if (V != nullptr)
		FillMatrixGrid(V->Count, true);
}
//Событие изменения значения ячейки в матрице смежности
System::Void FormNamespace::Form::matrixGrid_CellValueChanged(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	this->matrixGrid->CellValueChanged -= gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &FormNamespace::Form::matrixGrid_CellValueChanged);
	int valueLengthCell;
	bool validateValueType = System::Int32::TryParse(matrixGrid->CurrentCell->Value->ToString(), valueLengthCell);
	if (validateValueType == true && valueLengthCell >= minLengthEdge && valueLengthCell <= maxLengthEdge){
		matrixGrid->CurrentCell->Value = valueLengthCell;
		matrixGrid->Rows[matrixGrid->CurrentCell->ColumnIndex]->Cells[matrixGrid->CurrentCell->RowIndex]->Value = valueLengthCell;
	}
	else {
		matrixGrid->CurrentCell->Value = 0;
		matrixGrid->Rows[matrixGrid->CurrentCell->ColumnIndex]->Cells[matrixGrid->CurrentCell->RowIndex]->Value = 0;
	}

	this->matrixGrid->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &FormNamespace::Form::matrixGrid_CellValueChanged);
	G->SetBitmap(CreateGraphFromMatrix(nullptr));
	sheet->Image = G->GetBitmap();

}
//События изменения значения количества вершин на матрице смежности
System::Void FormNamespace::Form::countVertexMatrixGridNumericUpDown_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	NumericUpDown^ numericUpDown = (NumericUpDown^)(sender);
	FillMatrixGrid(System::Convert::ToInt32(numericUpDown->Value),false);
}
//Заполнение матрицы длин рёбер по массиву граней - E
System::Void FormNamespace::Form::FillLengthGrid() {
	lengthGrid->Rows->Clear();
	for (int i = 0; i < E->Count; i++)
	{
		lengthGrid->Rows->Add(E[i]->V1 + 1, E[i]->V2 + 1, E[i]->Weight);
	}
}
//Заполенение матрицы смежности по массиву граней - E
System::Void FormNamespace::Form::FillMatrixGrid(int numberV, bool columnIsReadOnly) {
	List<List<System::Int32>^> ^matrix = gcnew List<List<System::Int32>^>();
	G->FillAdjacencyMatrix(numberV, E, matrix);
	DataTable ^table = gcnew DataTable();
	this->matrixGrid->CellValueChanged -= gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &FormNamespace::Form::matrixGrid_CellValueChanged);

	for (int i = 0; i < matrix->Count; i++)
	{
		DataColumn^ column = gcnew DataColumn((i+1).ToString());
		
		table->Columns->Add(column);
	}
	for each(List<System::Int32> ^child in matrix)
	{
		DataRow^ row = table->NewRow();
		List<System::Object^>^ arrayLength = gcnew List<System::Object^>{};
		for each (int lengthEdge in child)
			arrayLength->Add(lengthEdge);
		row->ItemArray = arrayLength->ToArray();
		table->Rows->Add(row);
	}
	matrixGrid->DataSource = table;	
	for each (DataGridViewColumn ^ column in matrixGrid->Columns)
	{
		column->SortMode = DataGridViewColumnSortMode::NotSortable;
		column->ReadOnly = columnIsReadOnly;
	}
	for each (DataGridViewRow ^ row in matrixGrid->Rows)
		row->HeaderCell->Value = (row->Index + 1).ToString();

	matrixGrid->Refresh();
	this->matrixGrid->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &FormNamespace::Form::matrixGrid_CellValueChanged);
}

//Рисование графа по матрицу смежности - применяется библиотека MSAGL
System::Drawing::Bitmap^ FormNamespace::Form::CreateGraphFromMatrix(List<Tuple<int, int>^>^ MSTEdges)
{
	Microsoft::Msagl::Drawing::Graph^ graph = gcnew Microsoft::Msagl::Drawing::Graph("graph");
	
	array<double, 2>^ adjacencyMatrix = gcnew array<double, 2>(matrixGrid->RowCount, matrixGrid->ColumnCount);
	for each(DataGridViewRow^ i in matrixGrid->Rows)
	{
		for each(DataGridViewCell ^j in i->Cells)
		{
			adjacencyMatrix[j->RowIndex,j->ColumnIndex] = System::Int32::Parse(j->Value->ToString());
		}
	}
	int numVertices = adjacencyMatrix->GetLength(0);

	for (int i = 0; i < numVertices; i++)
	{
		Microsoft::Msagl::Drawing::Node ^node = gcnew Microsoft::Msagl::Drawing::Node((i+1).ToString());
		node->Attr->Shape = Microsoft::Msagl::Drawing::Shape::Circle;
		node->Attr->FillColor = Microsoft::Msagl::Drawing::Color::Transparent;
		graph->AddNode(node);

	}

	for (int i = 0; i < numVertices; i++)
	{
		for (int j = 0; j < numVertices; j++)
		{
			if (adjacencyMatrix[i,j] > 0) {
				int h = 0;

				for each (Microsoft::Msagl::Drawing::Edge^ edge1 in graph->Edges) {
					auto k = (i + 1).ToString() + "-" + (j + 1).ToString();
					auto k1 = (j + 1).ToString() + "-" + (i + 1).ToString();
					if ((edge1->Attr->Id==k) || (edge1->Attr->Id == k1)) {
						h++;
						break;
					}

				}
				if (h > 0)
					continue;



				String^ label = (i+1).ToString() + "-" + (j+1).ToString();
				Microsoft::Msagl::Drawing::Edge ^edge = graph->AddEdge((i+1).ToString(), (j + 1).ToString());
				if (MSTEdges && (MSTEdges->Contains(gcnew Tuple<int,int>(i,j)) || MSTEdges->Contains(gcnew Tuple<int, int>(j, i)))) {
					edge->Attr->Color = Microsoft::Msagl::Drawing::Color::Red;
				}
				
				edge->Attr->Weight = adjacencyMatrix[i, j];
				edge->Attr->Id = label;
				edge->Attr->ArrowheadAtTarget = Microsoft::Msagl::Drawing::ArrowStyle::None;
			}
		}
	}
	Microsoft::Msagl::Layout::MDS::MdsLayoutSettings();

	Microsoft::Msagl::GraphViewerGdi::GraphRenderer^ renderer = gcnew Microsoft::Msagl::GraphViewerGdi::GraphRenderer(graph);
	renderer->CalculateLayout();

	int width = sheet->Width;
	int height = sheet->Height;

	Bitmap^ bitmap = gcnew Bitmap(width,height , System::Drawing::Imaging::PixelFormat::Format32bppPArgb);
	renderer->Render(bitmap);


	return bitmap;
}
//Реализация алгоритма Прима
System::Boolean FormNamespace::Form::AlgorithmByPrim()
{
	array<int, 2>^ G = gcnew array<int, 2>(matrixGrid->RowCount, matrixGrid->ColumnCount);
	for each (DataGridViewRow ^ i in matrixGrid->Rows)
	{

		for each (DataGridViewCell ^ j in i->Cells)
		{
			G[j->RowIndex, j->ColumnIndex] = System::Int32::Parse(j->Value->ToString());
		}
	}

	if (G->GetLength(0)==0) {
		MessageBox::Show("Матрица пустая. Заполните матрицу значениями!");
		return false;
	}
	if (G->GetLength(0) == 1) {
		MessageBox::Show("Должно быть минимум 2 вершины!");
		return false;
	}
	if (choicedVertexTextBox->TextLength == 0) {
		MessageBox::Show("Начальная вершина не выбрана!");
		return false;
	}
	if (System::Int32::Parse(choicedVertexTextBox->Text) > G->GetLength(0)) {
		MessageBox::Show("Начальная вершина больше количества!");
		return false;
	}
	if (!isConnected(G, G->GetLength(0))) {
		MessageBox::Show("Граф не является связанным.Соедините вершины между собой и назначьте вес!");
		return false;
	}
	else {
		std::vector<int> selected(G->GetLength(0));
		MST = gcnew List<Tuple<int, int>^>();
		std::fill(selected.begin(), selected.end(), false);

		int no_edge = 0;


		selected[System::Int32::Parse(choicedVertexTextBox->Text) - 1] = true;

		int x;            
		int y;            


		edgesPrimListBox->Items->Clear();
		edgesPrimListBox->Items->Add("Минимальные рёбра: ");
		while (no_edge < G->GetLength(0) - 1) {

			int min = 9999999;
			x = 0;
			y = 0;

			for (int i = 0; i < G->GetLength(0); i++) {
				if (selected[i]) {
					for (int j = 0; j < G->GetLength(0); j++) {
						if (!selected[j] && G[i, j]) { 
							if (min > G[i,j]) {
								min = G[i,j];
								x = i;
								y = j;
							}

						}
					}
				}
			}
			selected[y] = true;
			no_edge++;
			MST->Add(gcnew Tuple<int,int>(x,y));
			edgesPrimListBox->Items->Add((x+1).ToString() + "->" + (y + 1).ToString() + " (" + G[x, y].ToString() + ")");

		}
		int summa = 0;
		for each (auto edge in MST) {
			summa += G[edge->Item1, edge->Item2];
		}
		edgesPrimListBox->Items->Add("Общая сумма: " + summa);
		return true;
	}


}
//Нажатие на кнопку "Алгоритм Прима"
System::Void FormNamespace::Form::primButton_Click(System::Object^ sender, System::EventArgs^ e) {
	edgesPrimListBox->Items->Clear();
	if (AlgorithmByPrim()) {
		G->ClearSheet();
		if (MST->Count > 0) {
			typeMSTMoveGroupBox->Visible = true;
			typeMSTMoveGroupBox->Enabled = true;
		}
		if (typeInputRadioButton_1->Checked == true) {

			G->SetBitmap(CreateGraphFromMatrix(nullptr));
			stageMST = 0;
		}
		else if (typeInputRadioButton_2->Checked == true) {

			G->DrawALLGraph(V, E, nullptr);
			stageMST = 0;
		}
		sheet->Image = G->GetBitmap();
	
	}
	else {
		typeMSTMoveGroupBox->Visible = false;
		typeMSTMoveGroupBox->Enabled = false;
	}

}
//Соьытия выбора ячейки на матрице смежности - нужно, чтобы назначалась выбранная вершина в режиме "создания графа по матрице"
System::Void FormNamespace::Form::matrixGrid_CellEnter(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	if (typeInputRadioButton_1->Checked == true) {
		choicedVertexTextBox->Text = (e->RowIndex + 1).ToString();
	}
}
//Нажатие на кнопку "Далее" для подробного изучения Алгоритма Прима
System::Void FormNamespace::Form::stageButton_Click(System::Object^ sender, System::EventArgs^ e) {
	G->ClearSheet();
	if (typeInputRadioButton_1->Checked == true) {

		G->SetBitmap(CreateGraphFromMatrix(MST->GetRange(0, stageMST + 1)));

		stageMST++;

	}
	else if (typeInputRadioButton_2->Checked == true) {

		G->DrawALLGraph(V, E, MST->GetRange(0, stageMST + 1));
		stageMST++;
	}
	if (stageMST == MST->Count) {
		stageMST = 0;
		typeMSTMoveGroupBox->Visible = false;
		typeMSTMoveGroupBox->Enabled = false;

	}
	sheet->Image = G->GetBitmap();
}
//Нажатия на кнопку "Моментально" для явной визуализации результата Алгоритма Прима
System::Void FormNamespace::Form::momentButton_Click(System::Object^ sender, System::EventArgs^ e) {
	G->ClearSheet();
	if (typeInputRadioButton_1->Checked == true)
		G->SetBitmap(CreateGraphFromMatrix(MST));
	else if (typeInputRadioButton_2->Checked == true) 
		G->DrawALLGraph(V, E, MST);

	stageMST = 0;
	typeMSTMoveGroupBox->Visible = false;
	typeMSTMoveGroupBox->Enabled = false;
	sheet->Image = G->GetBitmap();
}
//Пункт меню "Выход"
System::Void FormNamespace::Form::выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
//Пункт меню "1"
System::Void FormNamespace::Form::panelControlMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
	FormNamespace::Form_1^ form_1 = gcnew FormNamespace::Form_1();
	form_1->Show();
}
//Пункт меню "2"
System::Void FormNamespace::Form::panelControlMenuItem2_Click(System::Object^ sender, System::EventArgs^ e) {
	FormNamespace::Form_2^ form_2 = gcnew FormNamespace::Form_2();
	form_2->Show();
}