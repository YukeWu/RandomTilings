#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <climits>
#include <fstream>
#include <map>
#include "tilings.h"

const int	edge_A = 2;
const int	edge_B = 2;
const int	edge_C = 2;

map<int, Point *> map_id_to_point; 
map<Point *, int> map_point_to_id; 

/**
 * @brief Construct a new Graph:: Graph object
 * 
 * @param a the length of A of the graph
 * @param b the length of B of the graph
 * @param c the length of C of the graph
 */
Graph::Graph(int a, int b, int c){
    A = a;
    B = b;
    C = c;
    root = NULL;
    return;
}

/**
 * 
 * @brief Destroy the Graph:: Graph object
 * 
 */
Graph::~Graph(){
    ClearGraph(root);
    return;
}

/**
 * TODO: Yuke will complete it.
 * 
 * @brief Clears the points in the graph and delete the graph object
 * 
 * @param P the root of the graph
 */
void Graph::ClearGraph(Point *P){
    return;
}

/**
 * @brief If graph is empty or not. Can be used during Insert.
 * 
 * @return true graph is empty, no point in it
 * @return false graph has at least 1 point
 */
bool Graph::isEmpty(){
    if (root == NULL && size_of_graph == 0){
        return true;
    }
    return false;
}

/**
 * TODO: Yuke will complete this.
 * @brief Get the random x coordinate to add/remove cube.
 * 
 * @return int 
 */
int getRandomX(){
    return -1;
}

/**
 * TODO: Yuke will complete this.
 * @brief Get the random y coordinate to add/remove cube.
 * 
 * @return int 
 */
int getRandomY(){
    return -1;
}

/**
 * TODO: Yuke will complete this.
 * @brief If the random (x,y) is a valid point to operate on in current graph
 * 
 * @param x random x generated
 * @param y random y generated
 * @return true 
 * @return false 
 */
bool isValidPoint(int x, int y, int a, int b, int c){
    return false;
}

/**
 * TODO: Yuke will complete this. Ask Team how they will like to see it.
 * @brief Print the graph
 * 
 */
void Graph::PrintGraph(){
    cout << "This is print graph" << endl;
}

/**
 * TODO: Yuke will do this.
 * @brief Output to a csv file for Luca's implementation for graph in Python
 * 
 */
void outputToPlot(){
    // https://stackoverflow.com/questions/25201131/writing-csv-files-from-c
    ofstream outfile;
    outfile.open ("out.csv");
    outfile << "column1, column2,\n";
    outfile.close();
}

/**
 * 
 * TODO: Arden will complete it.
 * 
 * @brief Initialize the new point and call Insert(new_point)
 *        to have it inserted in to the graph
 * 
 * @param x x position of the new point added
 * @param y y position of the new point added
 * @param pid unique id of the point in the graph
 * @return true add successfully
 * @return false add failed
 */
// Yuke recommend Arden this link:
// https://www.cplusplus.com/reference/map/map/
bool Graph::Insert(int x, int y, int pid){
    Point * new_point;
    new_point = new Point(x, y, pid);
    // TODO: set the neighbors of the new_point using the map_id_to_point
    // something like:
    for (int i = 0; i < 6; i++){
        //https://www.cplusplus.com/reference/map/map/operator[]/
        new_point->setNeighbor(i, map_id_to_point[12345]); // replace 12345 with real neighbor's id
    }
    return Insert(new_point);
}

/**
 * TODO: Arden will complete it.
 * 
 * @brief Insert the new point to the graph
 * 
 * @param newPoint the new_point from the Insert above 
 * @return true add successfully
 * @return false add failed
 */
bool Graph::Insert(Point *newPoint){
    return false;
}

int main(){
    cout << "This is main" << endl;
    Graph graph = Graph(edge_A, edge_B, edge_C);
    cout << graph.A << endl;
}
