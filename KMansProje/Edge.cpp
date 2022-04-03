#include "Edge.h"
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
Edge::Edge(vector <Clustering> clusters)
{
	findWeight(clusters);
}

Edge::~Edge()
{
}


void Edge::findWeight(vector <Clustering> clusters)
{

	double value_weight = 0.0;
	for (int j = 0; j < clusters.size(); j++)
	{
		cout << "\n\nWeights for Cluster " << j + 1 << endl;
		weight.clear();
		//int id_edge = 0;
		for (int id_edge = 0; id_edge < clusters[j].get_total_points(); id_edge++)
		{
			int total_points = clusters[j].get_total_points();
			for (int i = id_edge + 1; i < total_points; i++)
			{
				value_weight = sqrt(pow(clusters[j].getPoint(id_edge).getValue(0) - clusters[j].getPoint(i).getValue(0), 2) + pow(clusters[j].getPoint(id_edge).getValue(1) - clusters[j].getPoint(i).getValue(1), 2));

				if (value_weight != 0)
				{
					cout << "Weight for " << clusters[j].getPoint(id_edge).get_id_point() + 1 << " and " << clusters[j].getPoint(i).get_id_point() + 1 << " is " << value_weight << endl;
					weight.push_back(value_weight);
				}

			}
			//id_edge +=id_edge;
		}

		//printWeight();	

	}

}

void Edge::printWeight() const
{
	for (int i = 0; i < weight.size(); i++)
	{
		cout << weight[i] << endl;
	}
	cout << endl << endl;
}