#ifndef CLUSTERING_H
#define CLUSTERING_H
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
#include "Node.h"
using namespace std;
/// <summary>
/// This class reads data from txt file. It also contains some functions for clustering operations. 
/// </summary>
class Clustering
{
private:
	//! Numbers of coordinates
	int total_points;
	//! How many values a coordinate takes 
	int total_values;
	//! Cluster numbers
	int K;
	//! Max iterations
	int max_iterations;
	//! Point name
	int point_name;
	//! Cluster ID
	int id_cluster1;
	//! Hold x,y coordinates
	vector<double> values;

public:
	Clustering();
	/// <summary>
	/// Constructor of Clustering Class
	/// @param a Cluster's ID:
	/// @param b Node type vector. 
	/// @see Node
	/// @see KMeans
	/// @see Graph
	/// @see Edge
	/// </summary>
	Clustering(int a, Node b);
	~Clustering();
	/// <summary>
	/// Reading data from txt file.
	/// </summary>
	void readPoints();    
	/// <summary>
	/// The number of coordinates in the txt file is set. 
	/// @param total_points This describes total points.
	/// @see get_total_points()
	/// </summary>
	void set_total_points(int total_points);
	/// <summary>
	/// How many parameters are in a coordinate, that number is set. 
	/// @param total_values This describes total values.
	/// @see get_total_values()
	/// </summary>
	void set_total_values(int total_values);  
	/// <summary>
	/// Setting number of clusters.
	/// @param K This describes number of clusters.
	/// @see get_K()
	/// </summary>
	void set_K(int K);     
	/// <summary>
	/// The maximum number of steps determined to separate the clusters is set. 
	/// @param max_iterations This describes maximum iterations.
	/// @see get_max_iterations()
	/// </summary>
	void set_max_iterations(int);
	/// <summary>
	/// Setting cluster ID.
	/// @param a This describes cluster's ID.
	/// @see getIDCluster()
	/// </summary>
	void setIDCluster(int a);
	/// <summary>
	/// Setting central values of clusters.
	/// @param index This describes index of central value.
	/// @param value This describes value to insert index of central value.
	/// @see getCentralValue()
	/// </summary>
	void setCentralValue(int index, double value);
	/// <summary>
	/// Getting total points.
	/// returns number of coordinates.
	/// @see set_total_points()
	/// </summary>
	int get_total_points() const;    
	/// <summary>
	/// How many parameters are in a coordinate, that number is get.
	/// returns number of values.
	/// @see set_total_values()
	/// </summary>
	int get_total_values() const;
	/// <summary>
	/// Getting number of clusters.
	/// returns number of clusters.
	/// @see set_K()
	/// </summary>
	int get_K() const;
	/// <summary>
	/// The maximum number of steps determined to separate the clusters is get. 
	/// returns maximum iterations.
	/// @see set_max_iterations
	/// </summary>
	int get_max_iterations() const;
	/// <summary>
	/// Getting cluster ID
	/// returns ID of cluster
	/// @see setIDCluster()
	/// </summary>
	int getIDCluster() const;
	/// <summary>
	/// According to the entered index value, the value is returned from the central values vector. 
	/// returns A value from central_values vector.
	/// @param index The index of the point to be taken from the central values vector 
	/// @see setCentralValue()
	/// </summary>
	double getCentralValue(int index) const;
	/// <summary>
	/// Remove values from points vector.
	/// returns true Remove complete
	/// returns false No remove operation
	/// @param a x coordinate of the point to be deleted.
	/// </summary>
	bool removePoint(double a);    
	/// <summary>
	/// It assigns a value to the points vector. 
	/// @param point Value to add.
	/// </summary>
	void addPoint(Node point);  
	/// <summary>
	/// According to the entered index, the value of the points vector is taken. 
	/// @returns In the node type, the points vector is returned. 
	/// @param index The index of the data to be taken from the points vector.
	/// @see Node
	/// </summary>
	Node getPoint(int index);   
	/// <summary>
	/// Prints the elements and center points of the sets. 
	/// @param clusters The clusters which created.
	/// @see KMeans
	/// </summary>
	void printClusters(vector<Clustering> clusters) const;
protected:
	/// <summary>
	/// A vector named points of type Node. 
	/// </summary>
	vector<Node> points;
	/// <summary>
	/// A vector called central_values holding the center points of clusters. 
	/// </summary>
	vector<double> central_values;

};

#endif