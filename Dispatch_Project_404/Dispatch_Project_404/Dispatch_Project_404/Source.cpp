#include "BuildGraph.h"

int main()
{
	BuildGraph Graph;
	Graph.ReadFile();
	Graph.GenerateNodes();
	Graph.FillNodeMap();
	Graph.FillNodeVector();
	Graph.RunSimulation(64119, "Police");
	return 0;
}