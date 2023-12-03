#pragma once
#include <string>
#include "Vertex.h"
#include "Edge.h"

using namespace System::Collections::Generic;
using namespace System::Drawing;
namespace ObjectNamespace {
    public ref class DrawGraph
    {
        Bitmap^ bitmap;
        Pen^ blackPen;
        Pen^ redPen;
        Graphics^ g;
        Font^ fo;
        Brush^ brushBlack;
        Brush^ brushRed;
        PointF point;

    public:        
        int R = 20;
        DrawGraph();
        DrawGraph(int width, int height);
        void ClearSheet();
        Bitmap^ GetBitmap();
        void SetBitmap(Bitmap^ bitmapNew);
        void DrawVertex(int x, int y, System::String ^number);
        void DrawSelectedVertex(int x, int y);
        void DrawEdge(Vertex^ V1, Vertex^ V2, Edge^ E, String^ weight);
        void DrawALLGraph(List<Vertex^>^ V, List<Edge^>^ E, List<Tuple<int, int>^>^ MSTEdges);
        void FillAdjacencyMatrix(int numberV, List<Edge^>^ E, List<List<System::Int32>^>^ matrix);
        void VisualizeGraphByAdjacencyMatrix();
    };
}


