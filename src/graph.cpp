#include "graph.h"
#include <iostream>
using namespace std;
bool Graph::isEmpty()
{
    if (Head == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Graph::isDirected()
{
    return directed;
}
void Graph::traverse()
{
    Node *traverseNode = Head;
    while (traverseNode != nullptr)
    {
        std::cout << " The vertex is: ";
        std::cout << traverseNode->value << endl;
        Node *neighbourTraverse = traverseNode->nextneighbour;
        if (neighbourTraverse == nullptr)
        {
            std::cout << traverseNode->value << " doesn't have any neighbour" << endl;
        }
        else
        {
            while (neighbourTraverse != nullptr)
            {

                std::cout
                    << "And the neighbours of " << traverseNode->value << " are: ";
                std::cout << neighbourTraverse->value << endl;
                neighbourTraverse = neighbourTraverse->nextneighbour;
            }
        }
        traverseNode = traverseNode->nextvertex;
    }
    cout << "A traverse is completed" << endl
         << endl;
}
void Graph::addVertex(int data)
{
    Node *newVertex = new Node(data);
    if (Head == nullptr)
    {
      
        newVertex->nextvertex = nullptr;
        newVertex->nextneighbour = nullptr;
         Head = newVertex;
    }
    // if(isEmpty()){
    //     return;
    // }
    else
    {
        newVertex->nextvertex = Head;
        Head = newVertex;
        Head->nextneighbour = nullptr;
    }
}
void Graph::addEdge(int data1, int data2)
{
    Node *searchNode1 = Head;
    Node *searchNode2 = Head;
    if (searchNode1 == nullptr || searchNode2 == nullptr)
    {
        return;
    }
    while (searchNode1->value != data1)
    {
        if (searchNode1->nextvertex == nullptr)
        {
            throw "Nothing found";
        }
        searchNode1 = searchNode1->nextvertex;
    }
    while (searchNode2->value != data2)
    {
        if (searchNode1->nextvertex == nullptr)
        {
            throw "Nothing found";
        }
        searchNode2 = searchNode2->nextvertex;
    }
    Node *copyNode = new Node(searchNode2->value);
    copyNode->nextneighbour = searchNode1->nextneighbour;
    searchNode1->nextneighbour = copyNode;
}
Node *Graph::removeVertex(int data)
{
    int flag = 0;
    int edgeRemove=0;
    if (Head == nullptr)
    {
        cout << "No any Vertex with data " << data << endl
             << endl;
        flag = 1;
    }
if(flag==0){
    Node *searchNode1 = Head;

    if(searchNode1->value==data){
        Head=searchNode1->nextvertex;
        flag=1;
    }
    if(flag==0){
    while (searchNode1 != nullptr)
    {
       

        if (searchNode1->nextvertex == nullptr)
        {
            // return;
            cout << "No any Vertex with data " << data << endl
                 << endl;
            flag = 1;
    edgeRemove=1;
            break;
            // throw "nothing found";
        }

        if (searchNode1->nextvertex->value == data)
        {
            flag = 0;
            break;
        }

        searchNode1 = searchNode1->nextvertex;
    }
    if (flag == 0)
    {
        searchNode1->nextvertex = searchNode1->nextvertex->nextvertex;
    }
if(edgeRemove==0){
    Node* edgedeleteNode=Head;
    while(edgedeleteNode!=nullptr){
        removeEdge(edgedeleteNode->value,data);
        edgedeleteNode=edgedeleteNode->nextvertex;
    }
}
    }
    }
}
Node *Graph::removeEdge(int data1, int data2)
{
    int flag = 0;
    Node *searchNode1 = Head;
    Node *searchNode2 = Head;
    while (searchNode1->value != data1)
    {
        if (searchNode1->nextvertex == nullptr)
        {
            cout << data1 << " isn't present in graph" << endl
                 << endl;
            flag = 1;
            break;
            // return ;
        }
        searchNode1 = searchNode1->nextvertex;
    }
    while (searchNode2->value != data2)
    {
        if (searchNode2->nextvertex == nullptr)
        {
            cout << data2 << " isn't present in graph" << endl
                 << endl;
            flag = 1;
            break;
            // return;
        }

        searchNode2 = searchNode2->nextvertex;
    }
    if (flag == 0)
    {
        while (searchNode1 != nullptr)
        {
            if (searchNode1->nextneighbour == nullptr)
            {
                flag = 1;
                cout << "The graph doesn't have an edge between " << data1 << " and " << data2 << endl
                     << endl;
                break;
                // return;
            }
            if (searchNode1->nextneighbour->value == data2)
            {
                flag = 0;
                break;
            }

            searchNode1 = searchNode1->nextneighbour;
        }
    }
    if (flag == 0)
    {
        searchNode1->nextneighbour = searchNode1->nextneighbour->nextneighbour;
    }
}
int Graph::numVertices()
{
    int count;
    Node *countNode = Head;
    if (countNode == nullptr)
    {
        throw "No such node is present";
    }
    while (countNode != nullptr)
    {
        count++;
        countNode = countNode->nextvertex;
    }
    return count;

    return 0;
}
int Graph::inDegree(int data)
{
    int flag = 0, count = 0;
    Node *searchNode1 = Head;

    if (searchNode1 == nullptr)
    {
        throw "No such node is present";
    }
    Node *neighbourNode = searchNode1;
    while (searchNode1 != nullptr)
    {

        while (neighbourNode != nullptr)
        {
            if (neighbourNode->value == data)
            {
                count++;
            }
            neighbourNode = neighbourNode->nextneighbour;
        }
        searchNode1 = searchNode1->nextvertex;
    }
    return count;
    // while(searchNode1->value!=data){
    //     if(searchNode1->nextvertex==nullptr){
    //         throw "No such node is present";
    //     }
    // searchNode1=searchNode1->nextvertex;
    // }
}
int Graph::outDegree(int data)
{
    int count = 0, flag = 0;
    Node *searchNode1 = Head;

    if (searchNode1 == nullptr)
    {
        throw "No such node is present";
    }
    while (searchNode1->value != data)
    {
        if (searchNode1->nextvertex == nullptr)
        {
            flag = 1;
            cout << data << " isn't present in graph" << endl;
            break;
        }
        searchNode1 = searchNode1->nextvertex;
    }
    if (flag == 0)
    {
        while (searchNode1->nextneighbour != nullptr)
        {
            count++;
            searchNode1 = searchNode1->nextneighbour;
        }
        return count;
    }
    else
    {
        return 0;
    }
}

int Graph::degree(int data)
{
    int in = inDegree(data);
    int out = outDegree(data);
    return in + out;
}
