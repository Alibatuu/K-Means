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
/// The values of each cluster are plotted in different colors on the graph. 
/// </summary>
class Graph
{
private:
	vector <Clustering> cluster;
public:
	/// <summary>
	/// Constructor of Graph Class.
	/// @param cluster The clusters which created.
	/// </summary>
	Graph(vector <Clustering> cluster);
	~Graph();
	/// <summary>
	/// Drawing the graph with the help of OpenCV. 
	/// @param cluster The clusters created.
	/// </summary>
	void drawGraph(vector <Clustering> cluster);
};

