#include "Node.h"
#include "Clustering.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;
Node::Node(int idPoint, vector<double>& values, string Name)
{
	set_id_point(idPoint);
	set_name(Name);
	for (int i = 0; i < values.size(); i++)
		this->values.push_back(values[i]);
	id_cluster = -1;
}

Node::~Node()
{
}

void Node::set_id_point(int idPoint)
{
	id_point = idPoint;
}

void Node::set_name(string Name)
{
	name = Name;
}

int Node::get_id_point() const
{
	return id_point;
}

string Node::get_name() const
{
	return name;
}

double Node::getValue(int index) const
{
	return values[index];
}

void Node::setCluster(int id_cluster)
{
	this->id_cluster = id_cluster;
}

int Node::getCluster() const
{
	return id_cluster;
}




