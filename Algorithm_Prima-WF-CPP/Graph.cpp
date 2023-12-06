#include "pch.h"
#include "Graph.h"
#include <string>

using namespace System::IO;

namespace ObjectNamespace {
    
        
        DrawGraph::DrawGraph() {

        }
        //Конструктор класса с параметрами ширины и высоты холста
        DrawGraph::DrawGraph(int width,int height) {
            bitmap = gcnew Bitmap(width, height);

            blackPen = gcnew Pen(Color::Black);
            blackPen->Width = 2;

            redPen = gcnew Pen(Color::Red);
            redPen->Width = 2;



            g = Graphics::FromImage(bitmap);

            fo = gcnew Font("Arial", 15);

            brushBlack = Brushes::Black;
            brushRed = Brushes::Red;
        }

        //Возвращение битовой карты внутреннего графа
        Bitmap^ DrawGraph::GetBitmap()
        {
            return bitmap;
        }
        //Установка битовой карты для внутреннего графа
        void DrawGraph::SetBitmap(Bitmap^ bitmapNew)
        {
            bitmap = bitmapNew;
            g = Graphics::FromImage(bitmap);

        }
        //Очистка холста
        void DrawGraph::ClearSheet()
        {
             g->Clear(Color::White);
        }
        //Метод рисования вершины
        void DrawGraph::DrawVertex(int x, int y, System::String ^number)
        {
            //Делаем заливку окружности
            g->FillEllipse(Brushes::White, (x - R), (y - R), 2 * R, 2 * R);
            //Делаем границу для окружности
            g->DrawEllipse(blackPen, (x - R), (y - R), 2 * R, 2 * R);
            point = PointF::PointF(x - 9, y - 9);
            //Пишем текст с номером вершины
            g->DrawString(number, fo, brushBlack, point);
        }
        //Метод рисования выбранной вершины
        void DrawGraph::DrawSelectedVertex(int x, int y)
        {
            //Делаем красную границу для окружности вершины
            g->DrawEllipse(redPen, (x - R), (y - R), 2 * R, 2 * R);
        }
        //Метод рисования грани
        void DrawGraph::DrawEdge(Vertex^ V1, Vertex^ V2, Edge^ E, String^ weight)
        {
            //Если одна и та же вершины, то петля
            if (E->V1 == E->V2)
            {
                //Рисуем дугу
                g->DrawArc(blackPen, (V1->X - 2 * R), (V1->Y - 2 * R), 2 * R, 2 * R, 90, 270);
                point = PointF::PointF(V1->X - (int)(2.75 * R), V1->Y - (int)(2.75 * R));
                //Рисуем длину ребра для дуги
                g->DrawString(weight, fo, brushBlack, point);
                //Рисуем повторно вершину
                DrawVertex(V1->X, V1->Y, (E->V1 + 1).ToString());
            }
            //Иначе обычное прямое ребро
            else
            {
                //Рисуем прямое ребро
                g->DrawLine(blackPen, V1->X, V1->Y, V2->X, V2->Y);
                point = PointF::PointF((V1->X + V2->X) / 2, (V1->Y + V2->Y) / 2);
                //Рисуем длину ребра для грани
                g->DrawString(weight, fo, brushBlack, point);
                //Перерисовываем обе вершины, которые соединены новой гранью
                DrawVertex(V1->X, V1->Y, (E->V1 + 1).ToString());
                DrawVertex(V2->X, V2->Y, (E->V2 + 1).ToString());
            }
        }

        //Перерисовка всего графа
        void DrawGraph::DrawALLGraph(List<Vertex^> ^V, List<Edge^> ^E,List<Tuple<int,int>^>^ MSTEdges)
        {
            for (int i = 0; i < E->Count; i++)
            {
                if (E[i]->V1 == E[i]->V2)
                {

                    g->DrawArc(blackPen, (V[E[i]->V1]->X - 2 * R), (V[E[i]->V1]->Y - 2 * R), 2 * R, 2 * R, 90, 270);
                    point = PointF::PointF(V[E[i]->V1]->X - (int)(2.75 * R), V[E[i]->V1]->Y - (int)(2.75 * R));
                    g->DrawString(E[i]->Weight.ToString(), fo, brushBlack, point);
                }
                else
                {
                    point = PointF::PointF((V[E[i]->V1]->X + V[E[i]->V2]->X) / 2, (V[E[i]->V1]->Y + V[E[i]->V2]->Y) / 2);
                    if (MSTEdges && (MSTEdges->Contains(gcnew Tuple<int, int>(E[i]->V1, E[i]->V2)) || MSTEdges->Contains(gcnew Tuple<int, int>(E[i]->V2, E[i]->V1)))) {
                        g->DrawLine(redPen, V[E[i]->V1]->X, V[E[i]->V1]->Y, V[E[i]->V2]->X, V[E[i]->V2]->Y);
                        g->DrawString(E[i]->Weight.ToString(), fo, brushRed, point);
                    }
                    else {
                        g->DrawLine(blackPen, V[E[i]->V1]->X, V[E[i]->V1]->Y, V[E[i]->V2]->X, V[E[i]->V2]->Y);
                        g->DrawString(E[i]->Weight.ToString(), fo, brushBlack, point);
                    }




                }
            }
            for (int i = 0; i < V->Count; i++)
            {
                DrawVertex(V[i]->X, V[i]->Y, (i+1).ToString());
            }
        }
        //Заполение двумерного массива matrix, который принимается из параметра, значениям веса рёбер из массива граней - E
        void DrawGraph::FillAdjacencyMatrix(int numberV, List<Edge^>^ E, List<List<System::Int32>^>^ matrix)
        {
            for (int i = 0; i < numberV; i++) {
                List<System::Int32> ^child = gcnew List<System::Int32>();
                for (int j = 0; j < numberV; j++) {
                    child->Add(0);
                }
                matrix->Add(child);

            }

            for (int i = 0; i < E->Count; i++)
            {
                List<System::Int32> ^childOne = matrix[E[i]->V1];
                List<System::Int32>^ childtwo = matrix[E[i]->V2];
                childOne[E[i]->V2] = E[i]->Weight;
                childtwo[E[i]->V1] = E[i]->Weight;
            }

        }
        void DrawGraph::VisualizeGraphByAdjacencyMatrix() {


        }

}