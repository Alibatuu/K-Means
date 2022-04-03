# K-Means

In this project, a class hierarchy has been applied to cluster the post offices of the city of Sydney. In the project, which consists of 5 classes and a driver code, additionally UML diagram and Doxygen documentation were created.

## Design

### Clustering

This class includes reading data from the file and printing the clusters obtained after the K-Means algorithm with their IDs. The coordinate values obtained in the file reading function were first transferred to a double type vector. Then, it is cast into a vector of the Node type called points, which also contains the identities of the coordinates. Thus, the data in the Node class could be kept as desired. In the file reading function, information such as the number of coordinates received from the user, how many dimensions the coordinates are (such as 2 in (x,y)), how many clusters they will be divided into, and the maximum number of steps the result is expected are kept in this class. This class also includes point deletion and addition functions to be used in the K-Means algorithm.

### Node

In this class, coordinate values and IDs read in the Clustering class are kept. These values can be accessed with the set and get functions it contains.

### KMeans

A machine learning algorithm works in the K-Means class. In this class, which is inherited from the Clustering class, the functions of the Clustering class are generally used. Coordinates are taken with the points vector taken by the run function. Classification process starts according to randomly given center points. This center point is one of the coordinates read from the txt file. Clustering works until the maximum number of iterations entered by the user. This algorithm essentially looks at the distances of the points from the center point. Classification is performed by looking at these distance values. More accurate results are obtained by changing the center point each time. In order to break the iteration, either the maximum iteration must be reached or there is no longer any data to be exchanged between clusters. As the number of iterations increases, the accuracy also increases. After the clustering process is finished, this data is sent to the Clustering class for printing. After this process, the objects of the Edge and Graph classes are created and the operations continue in those classes.

### Edge

In this class, the clusters and coordinates created after the K-Means algorithm are processed. These received data were first separated according to class IDs. The distances between the points of each cluster were calculated and printed on the screen. Afterwards, these data were sent into a vector.

### Graph

In this class, which was written using OpenCV, a coordinate system image was first created. Then, circles with different colors were drawn for each cluster element.

## Execution

This created project is started by creating an object of the KMeans class. First, the constructor of the KMeans class is opened. Here, the readPoints() function of the Clustering class is called and the file reading process starts in the Clustering class. The desired txt file to be read is selected, and then the coordinates of this file are read one by one. The number of coordinates, the dimensions of the coordinates, the number of clusters requested and the maximum number of iterations are obtained from the user. Coordinate data is written to points vector of type Node and values vector of type double. Then it is returned to the constructor of the KMeans class. Here, the run function is called with the points vector for the K-Means algorithm to work. After the necessary clustering is completed, the cluster results are printed on the screen by calling the printClusters(clusters) function, which is a function of the Clustering class. Then an object of the Edge class is created and the Edge constructor is called with the clusters data. Here, the findWeight(clusters) function is called to measure the distances of the points belonging to each cluster from each other. After these distances are measured, the last step, the graph drawing process, begins. An object of the Graph class is created and the constructor is called with the clusters data. Here the drawGraph(cluster) function is called and a white background is created. This background is converted to the coordinate plane. Circles are drawn on the coordinate plane in different colors according to the classes of the data. Thus, the classification process is visible to the naked eye.

## Anything A Person May Need To Know While Testing My Program

In the first place, the user is informed about which file will be processed. When the code is run, you will be prompted with a selection screen and information on which txt file to read. When a value other than 1 or 2 is entered here, a value will be requested again and this cycle will continue until you enter 1 or 2. You will then need to enter how many points the data has under the name total_points. After that, you will be asked to enter the total_values value, in this part you will need to write how many dimensions your coordinates are. Since the data has x and y values, the value 2 must be entered. Then you will need to enter the K value and how many clusters you want the data to be divided into. The written program gives results for every K value, but as you can see in the exception handling algorithm, if you do not give values between 1 and 4, you will not see the correct results in the graph.
However, clustering will be done correctly as a code output. As the last step, you will need to enter the maximum number of iterations. By taking this value, you should know that the clustering process will be done as much as this entered number. After performing these operations, the code will start to run. The center points of the clusters, the points that the clusters have and the positions of these points, and finally the distances of the points to each other will be printed on the screen. In the graph that opens on the side, you will be able to see the points on the coordinate plane and to which classes these points belong.
