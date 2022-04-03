#ifndef NODE_H
#define NODE_H
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
/// This class store x and y coordinates of a post office as well as the identity.
/// </summary>
class Node
{
private:
	int id_point;
	vector <double> values;
	string name;
	int id_cluster;

public:
	/// <summary>
	/// Constructor of Node Class.
	/// @param idPoint ID of the point.
	/// @param Values Coordinates of the incoming point .
	/// @param Name The name of the point (default). 
	/// @see Clustering
	/// @see KMeans
	/// @see Graph
	/// @see Edge
	/// </summary>
	Node(int idPoint, vector<double>& Values, string Name = "");
	~Node();
	/// <summary>
	/// Setting point ID.
	/// @param idPoint This describes point's ID.
	/// @see get_id_point()
	/// </summary>
	void set_id_point(int idPoint);
	/// <summary>
	/// Setting name of points.
	/// @param Name This describes point's name.
	/// @see get_name()
	/// </summary>
	void set_name(string Name);
	/// <summary>
	/// Setting cluster ID for points vector.
	/// @param id_cluster This describes cluster's ID.
	/// @see getCluster()
	/// </summary>
	void setCluster(int id_cluster);
	/// <summary>
	/// Getting ID points.
	/// @returns Returns the ID of the point. 
	/// @see set_id_point()
	/// </summary>
	int get_id_point() const;
	/// <summary>
	/// Getting name of points.
	/// @returns Name of points.
	/// @see set_name()
	/// </summary>
	string get_name() const;
	/// <summary>
	/// According to the entered index, values are returned from the vector values. 
	/// @returns The value of the vector values at the entered index.
	/// @param index The location of the value to be retrieved from the values vector.
	/// </summary>
	double getValue(int index) const;
	/// <summary>
	/// Getting cluster ID for points vector.
	/// returns cluster's ID.
	/// @see setCluster()
	/// </summary>
	int getCluster() const;
};

#endif