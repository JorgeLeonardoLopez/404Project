#pragma once
#include <fstream>
#include "Node.h"

class BuildGraph
{
	vector<vector<int>> AllNodes;
	vector<Node*> Graph;
	vector<string> V;
	vector<Node*>Visited;
public:
	///Constructer
	BuildGraph() {};
	///This will read the file in to generate the graph
	void ReadFile();
	///This will Generate all the nodes of the graph individually
	void GenerateNodes();
	///This will fill the Node's map, the map is used to keep track of the weight of each edge 
	void FillNodeMap();
	///This will fill the Node's vector, the vector is used to tell the nodes which other nodes are it's neighbors
	void FillNodeVector();
	///This will run a simulation to find the nearest Node that has the requested vehicle
	void RunSimulation(int EmergencyZip, string RequestType);
};