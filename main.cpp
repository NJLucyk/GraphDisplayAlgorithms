#include <iostream>
#include "graph.h"

using namespace std;

int main(int argc, char *argv[])
{
    const int NUM_OF_FILES = 2;
    const int TEXT_FILE_INDEX = 1;
    const int START_OF_DOMAIN = 1;
    const int INDEX_MAKER = -1;

    graph gr;
    gr.load("test.txt");
    cin.ignore();
    //gr.displayBFS(0);
    gr.displayDFS(1);
    cin.ignore();

    return 0;
}
