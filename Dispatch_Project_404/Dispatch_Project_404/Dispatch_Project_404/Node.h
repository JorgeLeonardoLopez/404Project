#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
private:
	int ZIP, numberOfConnections;
	string Vehicle;
	map<int, int> distances;
	vector<Node*> connectedNodes;
	vector<Node*> visitedNeighbor;
public:
	///Default constructer
	Node() {};
	///Second constructer
	Node(int ZIPCODE, int NUMOFCONNECTIONS, string V) { ZIP = ZIPCODE; numberOfConnections = NUMOFCONNECTIONS; Vehicle = V; };
	///Returns the node's ZIP Code value
	int getZIP() { return ZIP; };
	///Returns the node's vehicle value
	string getVehicle() { return Vehicle; };
	///This will fill the Node's map, the map is used to keep track of the weight of each edge 
	void FillMap(int ConnectedZIP, int Distance);
	///This will fill the Node's vector, the vector is used to tell the nodes which other nodes are it's neighbors
	void FillVector(Node* TempNode);
	///This will check if a node's ZIP Code is in the current Node's map of neighbors
	bool isInMAP(int ZIPCODE);
	///This will Find all the nearest Nodes that have the requested vehicle
	void FindRequest(string RequestType, vector<Node*> visited);
	///This will check if a node has been visited, this will help in preventing going through all the nodes all the time
	bool isInVisited(int ZIPCODE, vector<Node*> visited);
};