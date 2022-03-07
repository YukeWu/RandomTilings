//---------------------------------------------------------------
// File: tilings.h
// Purpose: Header file for random tilings
// Programming Language: C++
//---------------------------------------------------------------
#ifndef TILING_H
#define TILING_H

#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Define a structure to be used as the tree node
struct Point
{
    public:
        int     location[2]; // location we discussed, [0,0], [0,1], ...
    private:
        int     point_id; // unique id of a point
        int     directions[6]; // array of lines currently associated to this point
                               // all elements should be 0/1, indicating an association
        int     neighbors[6]; // array of point_id of a point's neightbors
                              // mainly for graphing purposes

    public:
        Point(int x, int y, int pid){
            location[0] = x;
            location[1] = y;
            point_id = pid;
            for (int i = 0; i < 6; i++){
                directions[i] = 1;
            }
        };
        bool isMinCube(){
            if (directions[0] == 1 && directions[2] == 1 && directions[4] == 1
            && directions[1] == 0 && directions[3] == 0 && directions[5] == 0){
                return true;
            }
            return false;
        }
        bool isMaxCube(){
            if (directions[0] == 0 && directions[2] == 0 && directions[4] == 0
            && directions[1] == 1 && directions[3] == 1 && directions[5] == 1){
                return true;
            }
            return false;
        }
        bool setToMaxCube(){
            if (isMinCube()){
                directions[0] = 0;
                directions[1] = 1;
                directions[2] = 0;
                directions[3] = 1;
                directions[4] = 0;
                directions[5] = 1;
                return true;
            }
            else{
                return false;
            }
        }
        bool setToMinCube(){
            if (isMaxCube()){
                directions[0] = 1;
                directions[1] = 0;
                directions[2] = 1;
                directions[3] = 0;
                directions[4] = 1;
                directions[5] = 0;
                return true;
            }
            else{
                return false;
            }
        }
        void setDirection(int index, int new_value){
            directions[index] = new_value;
        }        
        void setNeighbor(int index, Point *neignbor){
            neighbors[index] = neignbor->getID();
        }
        int getID(){
            return point_id;
        }        
        int getNeighbor(int index){
            return neighbors[index];
        }
        void printNeighbors(){
            for (int i = 0; i < 6; i++) 
                cout << neighbors[i];
            cout << endl;
        }
        void printDirections(){
            for (int i = 0; i < 6; i++) 
                cout << directions[i];
            cout << endl;
        }
        void printID(){
            cout << point_id << endl;
        }
};

class Graph
{
    private:
        Point *root; // the Point with location [0,0]

    public:
        int A;
        int B;
        int C;
        int size_of_graph; // number of points in graph
        Graph(int a, int b, int c);
        ~Graph();
        bool isEmpty();
        bool Insert(Point *newPoint);
        bool Insert(int x, int y, int pid);
        void PrintGraph();
    private:
        void ClearGraph(Point *P);
};

int getRandomX();
int getRandomY();
bool isValidPoint(int x, int y, int a, int b, int c);
void outputToPlot();

#endif
