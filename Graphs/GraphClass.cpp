//
// Created by Pablo Chávez on 21/08/26.
//
#include <unordered_map>
#include <unordered_set>
#include <string>

using std::string;

class Graph
{
private:
    std::unordered_map<string, std::unordered_set<string>> adjList;

public:
    void printGraph()
    {
        for (auto [vertex, edges] : adjList)
        {
            std::cout << vertex << ": [ ";
            for (auto edge : edges)
            {
                std::cout << edge << " ";
            }
            std::cout << "]" << std::endl;
        }
    }
    bool addVertex(string vertex)
    {
        if (adjList.count(vertex) == 0)
        {
            adjList[vertex];
            return true;
        }
        return false;
    }
    bool addEdge(string vertex1, string vertex2)
    {
        if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0)
        {
            adjList.at(vertex1).insert(vertex2);
            adjList.at(vertex2).insert(vertex1);
            return true;
        }
        return false;
    }
    bool removeEdge(string vertex1, string vertex2)
    {
        if (adjList.count(vertex1) != 0 & adjList.count(vertex2) != 0)
        {
            adjList.at(vertex1).erase(vertex2);
            adjList.at(vertex2).erase(vertex1);
            return true;
        }
        return false;
    }
    bool removeVertex(string vertex)
    {
        if (adjList.count(vertex) == 0) return false;
        for (auto otherVertex : adjList.at(vertex))
        {
            adjList.at(otherVertex).erase(vertex);
        }
        adjList.erase(vertex);
        return true;
    }
};

int main()
{
    Graph* myGraph = new Graph();
    myGraph->addVertex("A");
    myGraph->addVertex("B");
    myGraph->addVertex("C");
    myGraph->addVertex("D");
    myGraph->printGraph();
    myGraph->addEdge("A", "B");
    myGraph->addEdge("A", "C");
    myGraph->addEdge("A", "D");
    myGraph->addEdge("B", "C");
    myGraph->addEdge("B", "D");
    myGraph->addEdge("C", "D");
    myGraph->printGraph();
    // myGraph->removeEdge("A", "B");
    myGraph->removeVertex("D");
    myGraph->printGraph();
}