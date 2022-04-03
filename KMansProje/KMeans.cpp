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
#include "Edge.h"
#include "Graph.h"
using namespace std;
KMeans::KMeans()
{
	
		
	readPoints();
	run(points);
}

KMeans::~KMeans()
{
}

int KMeans::getIDNearestCenter(Node point)
{
	double sum = 0.0;
	double min_dist;
	int id_cluster_center = 0;

	for (int i = 0; i < get_total_values(); i++)
	{
		sum += pow(clusters[0].getCentralValue(i) - point.getValue(i), 2.0);
	}

	min_dist = sqrt(sum);
	for (int i = 1; i < get_K(); i++)
	{
		double dist;
		sum = 0.0;
		for (int j = 0; j < get_total_values(); j++)
		{
			sum += pow(clusters[i].getCentralValue(j) - point.getValue(j), 2);
		}
		dist = sqrt(sum);
		if (dist < min_dist)
		{
			min_dist = dist;
			id_cluster_center = i;
		}
	}
	return id_cluster_center;
}

void KMeans::run(vector<Node>& points)
{

	if (get_K() > get_total_points())
		return;
	vector<int> prohibited_indexes;
	vector <int>::iterator it;
	for (int i = 0; i < get_K(); i++)
	{

		while (true)
		{
			srand(time(NULL));
			int index_point = rand() % get_total_points();
			if (find(prohibited_indexes.begin(), prohibited_indexes.end(),
				index_point) == prohibited_indexes.end())
			{
				prohibited_indexes.push_back(index_point);
				points[index_point].setCluster(i);
				Clustering cluster(i, points[index_point]);
				clusters.push_back(cluster);

				break;
			}

		}

	}
	cout << "Cluster values: ";
	for (int i = 0; i < 2; i++) {


		for (int j = 0; j < get_total_values(); j++)
			cout << clusters[i].getCentralValue(j) << " ";
	}
	cout << endl;


	int iter = 1;
	while (true)
	{
		bool done = true;
		for (int i = 0; i < get_total_points(); i++)
		{
			int id_old_cluster = points[i].getCluster();
			int id_nearest_center = getIDNearestCenter(points[i]);
			if (id_old_cluster != id_nearest_center)
			{
				if (id_old_cluster != -1)
				{

					clusters[id_old_cluster].removePoint(points[i].getValue(0));
				}

				points[i].setCluster(id_nearest_center);
				clusters[id_nearest_center].addPoint(points[i]);

				done = false;
			}
		}
		if (done == true || iter >= get_max_iterations())
		{
			cout << "Break in iteration " << iter << "\n\n";
			break;
		}
		iter++;
	}
	printClusters(clusters);
	Edge e(clusters);
	Graph g(clusters);
}
