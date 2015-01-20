#include <iostream>
#include <string>
#include <limits>
#include "Graph.h"
#include "PQHeap.h"

using namespace std;

void find_path(int start, int end, int* shortestPathParent,vector<int> distance)
{
    if(start==end){
        cout << start;
        return;
    }
    else{
        find_path(start,shortestPathParent[end-1],shortestPathParent,distance);
        cout << " -> " << end<< " (" << (distance[end-1]-distance[shortestPathParent[end-1]-1]) << ") ";
    }
}

vector<int> Djistras(Graph& g, PQHeap<int>& pqHeap,int st,Locator<int>*& locatorArray,int*& shortestPathParent, int& cnt){
    vector<int> distance;
    vector<Vertex*> vertList=g.getVertices();
    int max = numeric_limits<int>::max();
    
    for(int i=0; i<vertList.size();i++){
        if((vertList[i]->getID())== st){
            cnt += pqHeap.insertItem(0,vertList[i]->getID(),locatorArray[vertList[i]->getID()-1]);
            distance.push_back(0);
        }
        else{
            cnt += pqHeap.insertItem(max,vertList[i]->getID(),locatorArray[vertList[i]->getID()-1]);
            distance.push_back(max);
        }
    }
    while(!pqHeap.isEmpty()){
        int cur = pqHeap.minElement()-1;// find the min vertex
        cnt += pqHeap.removeKey();      // remove the vertex
        vector<Edge*> OutEdges = vertList[cur]->getOutEdges();
        if(distance[cur]>10000){ cerr <<"Error happened when extracting!"<<endl;break;}
        for(int i=0; i<OutEdges.size();i++){
            Vertex* vertex = OutEdges[i]->geteVertP();
            int newKey = distance[cur] + OutEdges[i]->getWeight();
            int key = distance[vertex->getID()-1];
            if( key > newKey){
                shortestPathParent[vertex->getID()-1] = cur+1;
                distance[vertex->getID()-1] = newKey;
                cnt += pqHeap.decreaseKey( locatorArray[vertex->getID()-1],newKey);
                cnt++;
            }
        }
    }
    return distance;
}

int main(int argc, char * argv[]){
//    string str("random_sparse.txt");
    string str("test.txt");

    Graph graph(str);
    graph.PrintGraph();
    Locator<int> *locatorArray=new Locator<int>[graph.getSize()];
    PQHeap<int> pqHeap;
    int* shortestPathParent=new int[graph.getSize()];
	int cnt=0;
    int source, destination;

    cout << "Please input source (between 1 and "<< graph.getSize()<<"): ";
    cin >> source;
    while (source<1 || source > graph.getSize()) {
        cout<< "Invalid range!"<<endl;
        cout << "Please input source (between 1 and "<< graph.getSize()<<"): ";
        cin >> source;
    }
    
    cout << "Please input destination (between 1 and "<< graph.getSize()<<"): ";
    cin >> destination;
    while (destination<1 || destination > graph.getSize()) {
        cout<< "Invalid range!"<<endl;
        cout << "Please input destination (between 1 and "<< graph.getSize()<<"): ";
        cin >> destination;
    }
    
    vector<int> distance = Djistras(graph, pqHeap, source, locatorArray, shortestPathParent, cnt);
    find_path(source,destination, shortestPathParent, distance);
    cout<< endl << "The total number of comparisions: "<< cnt << endl;
//  for(int i=0; i< distance.size(); i++){ cout << distance[i] << ' ';}cout<<endl;
//  for(int j=0; j< graph.getSize(); j++){cout << shortestPathParent[j]<<endl;}

    
    return 0;
}