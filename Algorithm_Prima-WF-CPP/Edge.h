#pragma once
using namespace System;
using namespace System::Runtime::InteropServices;
namespace ObjectNamespace {
    public ref class Edge
	{
    public:
        int V1, V2,Weight;

        Edge() {

        }
        Edge(int v1, int v2, [OptionalAttribute]Nullable<int>^ weight)
        {
            if (weight == nullptr)
                Weight = 0;
            else if (weight->HasValue)
                Weight = weight->Value;
            V1 = v1;
            V2 = v2;

        }

	};
}

