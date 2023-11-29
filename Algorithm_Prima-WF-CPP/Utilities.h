#pragma once
#include "Edge.h"
using namespace ObjectNamespace;
namespace UtilitiesNamespace {
	public ref class EdgePredicate
	{
		Edge^ _searchEdge;
	public:
		EdgePredicate(Edge^ searchEdge) {
			_searchEdge = searchEdge;
		}
		bool Matched(Edge^ compareEdge) {
			return (_searchEdge->V1 == compareEdge->V1 && _searchEdge->V2 == compareEdge->V2) 
				|| (_searchEdge->V1 == compareEdge->V2 && _searchEdge->V2 == compareEdge->V1);
		}

	};
}


