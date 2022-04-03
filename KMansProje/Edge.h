#ifndef EDGE_H
#define EDGE_H
#include "KMeans.h"
#include "Clustering.h"
#include "Node.h"
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
/// <summary>
/// This class store the nodes of the edge, an identity, and the edge's weight.
/// </summary>
class Edge
{
private:
	vector <Clustering> cluster_1;
	vector <double> weight;
public:
	/// <summary>
	/// Constructor of Edge Class.
	/// @param cluster The clusters which created.
	/// </summary>
	Edge(vector <Clustering> clusters);
	~Edge();
	/// <summary>
	/// Find the distances between the points. 
	/// @param cluster The clusters which created.
	/// </summary>
	void findWeight(vector <Clustering> cluster); 
	/// <summary>
	/// Distances between points are printed. 
	/// </summary>
	void printWeight() const;
protected:
};

#endif