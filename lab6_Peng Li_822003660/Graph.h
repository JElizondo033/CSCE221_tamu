#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Vertex.h"
#include "Edge.h"

using namespace std;

class Edge;
class Vertex;

class Graph{
    
private:
    vector<Vertex*> vertList;
    vector<Edge*> edgeList;
public:
    Graph(string filename) {
    //
    //  The vertex with ID x is stored at vertList[x-1]; 
    //  for example, vertex 1 in vertList[0], vertex 2 in vertList[1] and so on. 
    //
        ifstream ifs(filename.c_str());
        int vertnum;

        ifs>>vertnum;
        for(int i=0;i<vertnum;i++) // push all vertices into the vertex vector before assigning the in and out list
        {
            Vertex *vert = new Vertex(i+1);
            vertList.push_back(vert);
        }
        int svert,evert,weit;
        ifs>>svert;
        while(svert!=-1){
            ifs>>evert;
            while(evert!=-1){
                ifs>>weit; // one weight means one edge
                Edge *tempedge = new Edge(vertList[svert-1],vertList[evert-1],weit); // new edge
                edgeList.push_back(tempedge);
                vertList[svert-1]->outList.push_back(tempedge);
                vertList[evert-1]->inList.push_back(tempedge);
                ifs>>evert;
            }
            ifs>>svert;
        }
        ifs.close();
    }
    ~Graph() {
        for(int i = 0; i < vertList.size(); i++)
            delete vertList[i];
        for(int i = 0; i < edgeList.size(); i++)
            delete edgeList[i];
    }
    int getSize() {
        return vertList.size();
    }
    
    vector<Vertex*> getVertices() const {
        return vertList;
    }
    
    void PrintGraph() // print out all the edges and associated vertices in the entire graph
    {
        cout<<endl<<vertList.size()<<endl;
        for(int i=0;i<vertList.size();i++){
            cout<<i+1<<" ";
            for (int j=0; j<getVertices()[i]->getOutEdges().size(); j++){
                cout<<getVertices()[i]->getOutEdges()[j]->geteVertP()->getID()<<" ";
                cout<<getVertices()[i]->getOutEdges()[j]->getWeight()<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

};
#endif