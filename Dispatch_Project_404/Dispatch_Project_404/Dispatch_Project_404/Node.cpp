#include "Node.h"

void Node::FillMap(int ConnectedZIP, int Distance)
{
	distances[ConnectedZIP] = Distance;
}

void Node::FillVector(Node* TempNode)
{
	connectedNodes.push_back(TempNode);
}

bool Node::isInMAP(int ZIPCODE)
{
	if (!distances[ZIPCODE])
		return false;
	else
		return true;
}

void Node::FindRequest(string RequestType, vector<Node*> Allvisited)
{
	visitedNeighbor = Allvisited;
	if (this->Vehicle == RequestType)
	{
		cout <<"Found it at: " << this->ZIP << endl;
		Allvisited.push_back(this);
		return;
	}
	else
	{
		for (int i = 0; i < connectedNodes.size(); i++)
		{
			if (!isInVisited(connectedNodes[i]->getZIP(), visitedNeighbor))
			{
				visitedNeighbor.push_back(connectedNodes[i]);
				Allvisited.push_back(connectedNodes[i]);
				cout << "Current Path: " << this->ZIP << " Cost: " << distances[connectedNodes[i]->ZIP] << " ";
				connectedNodes[i]->FindRequest(RequestType, Allvisited);
			}
		}
		cout << "Deadend, returning one step back" << endl;
	}
	return;
}

bool Node::isInVisited(int ZIPCODE, vector<Node*> visited)
{
	for (int i = 0; i < visited.size(); i++)
	{
		if (visited[i]->getZIP() == ZIPCODE)
			return true;
	}
	return false;
}
