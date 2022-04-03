#ifndef KMEANS_H
#define KMEANS_H
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
/// <summary>
/// This class inherits from the Clustering class and includes only functionalities for that specific machine learning approaches.
/// </summary>
class KMeans : public Clustering
{
private:
	vector<Clustering> clusters;
public:
	/// <summary>
	/// Constructor of KMeans Class.
	/// @see Clustering
	/// @see Node
	/// @see Graph
	/// @see Edge
	/// </summary>
	KMeans();
	~KMeans();
	/// <summary>
	/// Finds the nearest cluster center. 
	/// @param point Node type vector 
	/// returns Returns the ID of the nearest cluster center. 
	/// @see run()
	/// </summary>
	int getIDNearestCenter(Node point);
	/// <summary>
	/// Implementation of KMeans algorithm and finding clusters. 
	/// @param points Node type vector
	/// @see getIDNearestCenter()
	/// </summary>
	void run(vector<Node>& points);
	
protected:
};

#endif