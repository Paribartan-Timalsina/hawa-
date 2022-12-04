#pragma once
class Node{
    public:
    int value;
    Node * nextvertex;
    Node * nextneighbour;
    public:
    Node(int value){
        this->value=value;
    }
};
class Graph{
    public:
    bool directed;
    Node * Head;
    public:
    Graph(){
        Head=nullptr;
        directed=true;
}
bool isEmpty();
bool isDirected();
void traverse();
void addVertex(int data);
void addEdge(int data1,int data2);
Node* removeVertex(int data);
Node* removeEdge(int data1,int data2);
int numVertices();
int inDegree(int data);
int outDegree(int data);
int degree(int data);
};