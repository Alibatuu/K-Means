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
Clustering::Clustering()
{

}
Clustering::Clustering(int a, Node b)
{
	this->id_cluster1 = a;
	set_total_values(2);
	//set_total_points(20);
	for (int i = 0; i < get_total_values(); i++)
	{
		central_values.push_back(b.getValue(i));
	}

	points.push_back(b);

}
Clustering::~Clustering()
{
}

void Clustering::readPoints()
{
	int data;
	cout << "Choose 1 or 2 for reading file" << endl;
	cout << "1. 20.txt" << endl;
	cout << "2. 50.txt" << endl;
	cin >> data;
	while (!((data == 1) || (data == 2)))
	{
		cout << "Choose 1 or 2 for reading file" << endl;
		cout << "1. 20.txt" << endl;
		cout << "2. 50.txt" << endl;
		cin >> data;
	}
	cout << "Reading data" << endl;
	cout << "Enter total points" << endl;
	cin >> total_points;
	set_total_points(total_points);
	cout << "Enter total values(if your coordinates 2D, enter 2)" << endl;
	cin >> total_values;
	set_total_values(total_values);
	cout << "Enter the number of clusters between [1,4]  " << endl;
	cin >> K;
	try
	{
		set_K(K);
	}
	catch (invalid_argument& e)
	{
		cout << "\nException: " << e.what() << endl << endl;
	}	
	cout << "Enter max iterations" << endl;
	cin >> max_iterations;
	set_max_iterations(max_iterations);


	string point_name;

	string line;
	ifstream myfile;
	if (data == 1)
	{
		myfile.open("20.txt");
	}
		
	else if (data == 2)
	{
		myfile.open("50.txt");
	}
		
	string first_token;
	string second_token;
	if (!myfile) //Always test the file open.
	{
		cout << "Error opening output file" << endl;
		system("pause");
		return;
	}
	int i = 0;
	int j = 0;
	int e = 0;

	while (getline(myfile, line) && e < total_points)
	{
		values.clear();
		cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
		string s = line;
		first_token = s.substr(0, s.find(' '));
		first_token = s.substr(0, s.find(' '));
		stringstream geek(first_token);
		double number_1 = stold(first_token);

		values.push_back(number_1);
		second_token = s.substr(s.find(' ') + 1, s.find(' '));

		double number_2 = stold(second_token);
		values.push_back(number_2);


		Node p(e, values);
		points.push_back(p);


		i++;
		j += 2;
		e++;

	}

}

void Clustering::setCentralValue(int index, double value)
{
	central_values[index] = value;
}

double Clustering::getCentralValue(int index) const
{
	return central_values[index];
}


bool Clustering::removePoint(double a)
{
	for (int i = 0; i < get_total_points(); i++)
	{
		if (points[i].getValue(0) == a)
		{
			points.erase(points.begin() + i);
			return true;
		}
	}
	return false;
}

void Clustering::addPoint(Node point)
{
	points.push_back(point);
}
Node Clustering::getPoint(int index)
{

	return points[index];
}


void Clustering::set_K(int K)
{
	if (K > 0 && K < 5)
		this->K = K;
	else
	{
		throw invalid_argument("K must be [1,4].You cannot get the correct result on the chart!!");
	}
		
}

int Clustering::get_K() const
{
	return K;
}

void Clustering::set_total_points(int total_points)
{
	this->total_points = total_points;
}

void Clustering::set_total_values(int total_values)
{
	this->total_values = total_values;
}

int Clustering::get_total_values() const
{
	return total_values;
}

int Clustering::get_total_points() const
{
	return points.size();
}

void Clustering::set_max_iterations(int max_iterations)
{
	this->max_iterations = max_iterations;
}

int Clustering::get_max_iterations() const
{
	return max_iterations;
}

void Clustering::setIDCluster(int a)
{
	this->id_cluster1 = a;
}

int Clustering::getIDCluster() const
{
	return id_cluster1;
}

void Clustering::printClusters(vector<Clustering> clusters) const
{
	for (int i = 0; i < get_K(); i++)
	{
		int total_points_cluster = clusters[i].get_total_points();

		cout << "Cluster " << clusters[i].getIDCluster() + 1 << endl;

		for (int j = 0; j < total_points_cluster; j++)
		{
			int l = 0;
			cout << "Point " << clusters[i].getPoint(j).get_id_point() + 1 << ": ";
			for (int p = 0; p < get_total_values(); p++)
			{
				cout << clusters[i].getPoint(j).getValue(p) << " ";

			}


			string point_name = clusters[i].getPoint(j).get_name();

			if (point_name != "")
				cout << "- " << point_name;

			cout << endl;
		}

		cout << "Cluster values: ";

		for (int j = 0; j < get_total_values(); j++)
			cout << clusters[i].getCentralValue(j) << " ";

		cout << "\n\n";

	}
}