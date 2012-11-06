#include "graph.h"
#include "IntQueue.h"
#include "IntStack.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <boost/lexical_cast.hpp>//for int to string conversion

using namespace std;
graph::graph()
{
    range = 0;
}

graph::~graph()
{
    for(int i = 0; i < range; ++i)
        delete [] adjacencyMatrix[i];
    delete [] adjacencyMatrix;
}

void graph::load(string fileName)
{
    const int MIN_RANGE = 1;//Don't allow anything that doesn't have at least one vertex
    //open the file
    ifstream input;
    input.open(fileName.c_str());
    if(!input)
    {//check if the file is valid
        cout<<"Error opening file."<<endl;
        cin.ignore();
        exit(-1);
    }
    //get the range and check it for errors
    input>>range;
    if(range < MIN_RANGE)
    {
        cout<<"Error. No vertices found."<<endl;
        cin.ignore();
        exit(-1);//error
    }

    //set up the 2-d array
    adjacencyMatrix = new bool*[range];
    for(int i = 0; i < range; i++)
        adjacencyMatrix[i] = new bool[range];

        //initialize everything to false. There isn't any in yet.
    for(int row = 0; row < range; row++)
    {
        for(int column = 0; column < range; column++)
            adjacencyMatrix[row][column] = false;
    }

    //read the info in the file and put it into the struct arrays.
    int vertex1;
    int vertex2;
    while(input>>vertex1>>vertex2)
    {//file in format "int, int" for every line
        if( vertex1 < 0 || vertex2 < 0)
        {
            cout<<"Error. Negative vertices not allowed."<<endl;
            cin.ignore();
            exit(-1);//error
        }
        cout<<vertex1 <<"  "<< vertex2<<endl;
        //Non-directional graph
        adjacencyMatrix[vertex1][vertex2] = true;
        adjacencyMatrix[vertex2][vertex1] = true;
    }
}
void graph::display() const
{

}

void graph::displayDFS(int vertex)
{
    if(range > 0)
    {
        visitedOrder = " ";
        utilityDFS(vertex);
        cout<<"\tDFS Order\n" + visitedOrder<<endl;
    }
}

void graph::utilityDFS(int vertex)
{
    string currentVertex = "{";
    currentVertex +=  boost::lexical_cast<string>(vertex);
    currentVertex += "}";
    if(visitedOrder.find(currentVertex) == string::npos)
    {
        visitedOrder += currentVertex;
        cout<<visitedOrder<<"  "<<vertex;
    }
    for(int i=0; i < range; i++)
    {
        currentVertex = "{";
        currentVertex += boost::lexical_cast<string>(i);
        currentVertex += "}";
        if(adjacencyMatrix[vertex][i] && visitedOrder.find(currentVertex) == string::npos)
            utilityDFS(i);
    }
}

void graph::displayBFS(int vertex)
{
    if(range > 0)
    {
        visitedOrder = "";
        IntQueue q(range);
        int deQVertex;
        q.enqueue(vertex);
        //mark the vertex as visited
        string currentVertex = "{";
        currentVertex += vertex;
        currentVertex += "}";
        visitedOrder += currentVertex;
        while(!q.isEmpty())
        {
            q.dequeue(deQVertex);
            for(int i = 0; i < range; i++)
            {
                currentVertex = "{";
                currentVertex += i;
                currentVertex += "}";
                if(adjacencyMatrix[deQVertex][i] && visitedOrder.find(currentVertex) == string::npos)
                {
                        q.enqueue(i);
                        visitedOrder += currentVertex;
                }
            }
        }
        cout<<"\tBFS Order\n" + visitedOrder<<endl;
    }
}

