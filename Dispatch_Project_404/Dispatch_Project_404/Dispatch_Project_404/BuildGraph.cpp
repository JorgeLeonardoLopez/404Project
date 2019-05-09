#include "BuildGraph.h"

//This reads the file into a vector that will be used to build the nodes individually
void BuildGraph::ReadFile()
{
	ifstream File("ZipCodes.txt"); //Open the file
	if (!File.is_open()) { cout << "ERROR OPENING FILE" << endl; return; } //Check that it is open
	int FirstZIP, NumberOfConnections, TempZip, TempDistance; //These are assumptions being made about the file structure
	string Vehicle;
	while (File.good()) // While file is still readable
	{
		vector<int> NodeData; //Temp vector 
		File >> FirstZIP >> Vehicle >> NumberOfConnections; //Read in data
		//Add Initial ZipCode and number of connections to that zipcode
		NodeData.push_back(FirstZIP); 
		NodeData.push_back(NumberOfConnections);
		V.push_back(Vehicle);
		//Add the data of the ZipCodes connected to the inital
		for (int i = 0; i < NumberOfConnections; i++)
		{
			File >> TempZip >> TempDistance;
			NodeData.push_back(TempZip);
			NodeData.push_back(TempDistance);
		}
		AllNodes.push_back(NodeData);
	}
}

//This function will create individual nodes that have their Zipcode details and the number of connected Zipcodes
void BuildGraph::GenerateNodes()
{
	for (int i = 0; i < AllNodes.size(); i++)
	{
		int TempZip = AllNodes[i][0];
		int TempConnections = AllNodes[i][1];
		Node* TempNode = new Node(TempZip, TempConnections, V[i]);
		Graph.push_back(TempNode);
	}
}

//This will fill the Node's map which will have
// key = Connected zipcode
// value = cost to that zipcode
void BuildGraph::FillNodeMap()
{
	for (int i = 0; i < Graph.size(); i++)
	{
		for (int j = 2; j < AllNodes[i].size(); j+= 2) {
			Graph[i]->FillMap(AllNodes[i][j], AllNodes[i][j+1]);
		}
	}
}

//This will fill the vector of the Nodes
//Each node has a vector that will hold the Nodes it can travel to
void BuildGraph::FillNodeVector()
{
	for (int i = 0; i < Graph.size(); i++)
	{
		for (int j = 0; j < Graph.size(); j++) 
		{
			if (Graph[i]->isInMAP(Graph[j]->getZIP()))
			{
				Graph[i]->FillVector(Graph[j]);
			}
		}
	}
}

void BuildGraph::RunSimulation(int EmergencyZip, string RequestType)
{
	Node* temp;
	for (int i = 0; i < Graph.size(); i++)
	{
		if (Graph[i]->getZIP() == EmergencyZip)
		{
			temp = Graph[i];
			Visited.push_back(Graph[i]);
			if (temp != NULL && temp->getVehicle() != RequestType)
			{
				temp->FindRequest(RequestType, Visited);
			}
			break;
		}
	}
}