#ifndef GRAPH_H
#define GRAPH_H
#include <string>
#include "IntStack.h"
#include "IntQueue.h"
using namespace std;
class graph
{
    public:
        graph();
        ~graph();
        void load(string fileName);
        void displayBFS(int vertex);
        void displayDFS(int vertex);
        void display() const;
    protected:
    private:
        bool **adjacencyMatrix;
        int range;
        string visitedOrder;

        graph(const graph& other);
        graph& operator=(const graph& other);
        void utilityDFS(int vertex);

};

#endif // GRAPH_H
