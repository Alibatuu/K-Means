#include "KMeans.h"
#include "Clustering.h"
#include "Graph.h"
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
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace std;
using namespace cv;

Graph::Graph(vector <Clustering> cluster)
{
	drawGraph(cluster);
}
Graph::~Graph()
{
}
void Graph::drawGraph(vector <Clustering> cluster)
{
	cout << "Drawgraph" << endl;
	//Mat image = Mat::zeros(600, 600, CV_8UC3);
	Mat image(600, 600, CV_8UC3, Scalar(255, 255, 255));
	cv::Point p1(0, 0), p2(595, 595);
	cv::Point p3(0, 595);
	cv::line(image, p3, p2, Scalar(0, 0, 0), 6, 8);
	cv::line(image, p1, p3, Scalar(0, 0, 0), 6, 8);
	string for_x = "X(600,0)";
	string for_y = "Y(0,600)";
	cv::line(image, Point(460, 0), Point(460, 60), Scalar(0, 0, 0), 3, 8);
	cv::line(image, Point(460, 60), Point(560, 60), Scalar(0, 0, 0), 3, 8);
	cv::line(image, Point(560, 60), Point(560, 0), Scalar(0, 0, 0), 3, 8);
	cv::line(image, Point(460, 0), Point(560, 0), Scalar(0, 0, 0), 3, 8);
	cv::putText(image, for_y, cv::Point(20, 20), cv::FONT_HERSHEY_DUPLEX, 0.6, cv::Scalar(0, 0, 0), 0.6, false);
	cv::putText(image, for_x, cv::Point(510, 570), cv::FONT_HERSHEY_DUPLEX, 0.6, cv::Scalar(0, 0, 0), 0.6, false);
	circle(image, Point(480, 20), 4, Scalar(0, 0, 255), -1, 8);
	cv::putText(image, "Cluster 1", cv::Point(490, 20), cv::FONT_HERSHEY_DUPLEX, 0.3, cv::Scalar(0, 0, 0), 1, false);
	circle(image, Point(480, 30), 4, Scalar(255, 0, 0), -1, 8);
	cv::putText(image, "Cluster 2", cv::Point(490, 30), cv::FONT_HERSHEY_DUPLEX, 0.3, cv::Scalar(0, 0, 0), 1, false);
	circle(image, Point(480, 40), 4, Scalar(0, 255, 0), -1, 8);
	cv::putText(image, "Cluster 3", cv::Point(490, 40), cv::FONT_HERSHEY_DUPLEX, 0.3, cv::Scalar(0, 0, 0), 1, false);
	circle(image, Point(480, 50), 4, Scalar(120, 120, 120), -1, 8);
	cv::putText(image, "Cluster 4", cv::Point(490, 50), cv::FONT_HERSHEY_DUPLEX, 0.3, cv::Scalar(0, 0, 0), 1, false);
	for (int i = 0; i < cluster.size(); i++)
	{
		int total_points_cluster = cluster[i].get_total_points();
		for (int j = 0; j < total_points_cluster; j++)
		{
			std::string str2 = std::to_string(cluster[i].getPoint(j).get_id_point() + 1);
			string str1 = "Point";
			string str = str1 + str2;
			int l = 0;
			
			if (i == 0)
			{
				

				circle(image, Point(cluster[i].getPoint(j).getValue(l) / 100, 600 - cluster[i].getPoint(j).getValue(l + 1) / 100), 4, Scalar(0, 0, 255), -1, 8);
				cv::putText(image, str, cv::Point(cluster[i].getPoint(j).getValue(l) / 100-15 , 600 - cluster[i].getPoint(j).getValue(l + 1) / 100-5), cv::FONT_HERSHEY_DUPLEX, 0.3, cv::Scalar(0, 0, 0), 1, false);
			}
			else if(i==1)
			{
				circle(image, Point(cluster[i].getPoint(j).getValue(l) / 100, 600 - cluster[i].getPoint(j).getValue(l + 1) / 100), 4, Scalar(255, 0, 0), -1, 8);
				cv::putText(image, str, cv::Point(cluster[i].getPoint(j).getValue(l) / 100-15 , 600 - cluster[i].getPoint(j).getValue(l + 1) / 100-5), cv::FONT_HERSHEY_DUPLEX, 0.3, cv::Scalar(0, 0, 0), 1, false);
			}
			else if (i == 2)
			{
				circle(image, Point(cluster[i].getPoint(j).getValue(l) / 100, 600 - cluster[i].getPoint(j).getValue(l + 1) / 100), 4, Scalar(0, 255, 0), -1, 8);
				cv::putText(image, str, cv::Point(cluster[i].getPoint(j).getValue(l) / 100-15 , 600 - cluster[i].getPoint(j).getValue(l + 1) / 100-5), cv::FONT_HERSHEY_DUPLEX, 0.3, cv::Scalar(0, 0, 0), 1, false);
			}
			else if (i == 3)
			{
				circle(image, Point(cluster[i].getPoint(j).getValue(l) / 100, 600 - cluster[i].getPoint(j).getValue(l + 1) / 100), 4, Scalar(120, 120, 120), -1, 8);
				cv::putText(image, str, cv::Point(cluster[i].getPoint(j).getValue(l) / 100-15 , 600 - cluster[i].getPoint(j).getValue(l + 1) / 100-5), cv::FONT_HERSHEY_DUPLEX, 0.3, cv::Scalar(0, 0, 0), 1, false);
			}
			l++;
			imshow("Image", image);
			
			
		}
		
		
	}
	waitKey(0);
	return;
		
	

}