#include "graph.h"
#include <iostream>
using namespace std;

// int main()
// {
//     Graph g1;
//     cout << g1.isEmpty() << endl;
//     cout << g1.isDirected() << endl;
//    g1.removeVertex(300);
//     g1.addVertex(10);
//     g1.removeVertex(200);
//     g1.addVertex(20);
//     g1.addVertex(30);
//     g1.addVertex(40);
//     g1.traverse();
//     g1.addEdge(30, 10);
//     g1.addEdge(30, 20);
//    g1.addEdge(30, 40);
//    g1.traverse();
//    g1.removeEdge(30, 40);
//    g1.removeEdge(30, 20);
//    g1.removeEdge(30, 100);
//     g1.traverse();
//     g1.removeVertex(10);
//      g1.removeVertex(100);
//      g1.removeVertex(90);
//    g1.traverse();
//   cout<<"The total number of vertices are: "<< g1.numVertices()<<endl;
//    cout<<g1.inDegree(40)<<endl;
//     cout<<g1.outDegree(30)<<endl;
//    cout<<g1.degree(30)<<endl;
// }
int main()
{
    int num;
    Graph g1;
    while (num != 15)
    {
       
        cout << "\n\n1.Is Empty \n2.Is Directed \n3.Add  New Vertex \n4.Add New Edge \n5.Remove given  Vertex \n6.Remove given Edge \n7.Traverse\n8.Number of Vertices \n9.Number of Edges \n10.Indegree \n11.Outdegree \n12.Degree \n13. Neighbours of a Vertex \n14.Are Neighbours?\n15.Exit" << endl; // input from user to perform   desired action
        cin >> num;
        switch (num)
        {
        case 1: // checks if graph is empty
        {
            if (g1.isEmpty())
            {
                cout << "The graph is empty." << endl;
            }
            else
            {
                cout << "The graph is not empty." << endl;
            }
            break;
        }
        case 2: // checks if graph is directed
        {
            if (g1.isDirected())
            {
                cout << "The graph is directed." << endl;
            }
            else
            {
                cout << "The graph is not directed." << endl;
            }
            break;
        }
        case 3: // adds vertex to the graph
        {
            
            int data;
            cout << "Enter the data  of vertex to insert in Graph:" << endl;
            cin >> data;
            g1.addVertex(data);
            break;
        }
        case 4: 
        {
           
            int data1, data2;
            cout << "Enter the data of staring vertex  in Graph:" << endl;
            cin >> data1;
            cout << "Enter the data of ending vertex in Graph:" << endl;
            cin >> data2;
            g1.addEdge(data1, data2);
            break;
        }
        case 5: // to remove the vertex
        {
            int data;
            cout << "Enter the data to remove from the Graph:" << endl;
            cin >> data;
            g1.removeVertex(data);
            break;
        }
        case 6: // remove edge from graph
        {
            int vertexData, edgeData;
            cout << "Enter the data of staring vertex  to remove in Graph:" << endl;
            cin >> vertexData;
            cout << "Enter the data of ending vertex  to remove in Graph:" << endl;
            cin >> edgeData;
            g1.removeEdge(vertexData, edgeData);
            break;
        }
        case 7: // traverse
        {
            g1.traverse();
            break;
        }
        case 8: // number of vertices in a graph
        {
            cout<<"The  total Number of vertex in Graph are:"<<endl;
           cout<< g1.numVertices();
            break;
        }
        
        case 10: // Indegree
        {
            int vertexData;
            cout<<"Enter the vertex  data to find  indegree :"<<endl;
            cin>>vertexData;
            cout << "The indegree of the given vertex are:"<<endl;
           cout<< g1.inDegree(vertexData);
            break;
        }
        case 11: // outdegree
        {
            int vertexData;
            cout<<"Enter the vertex data to find outdegree :"<<endl;
            cin>>vertexData;
            cout << "The outdegree of the given vertex are:"<<endl;
            cout<<g1.outDegree(vertexData);
            break;
        }
        case 12: // degree
        {
            int vertexData;
            cout<<"Enter the vertex data to find total degree:"<<endl;
            cin>>vertexData;
            cout << "The degree of the given vertex are:"<<endl;
            cout<<g1.degree(vertexData);
        }
        // case 13: // neighbours of vertex
        // {
        //     int vertex;
        //     cout<<"Enter the vertex for which neighbours to be found:"<<endl;
        //     cin>>vertex; 
        //     int* neighbours = g1.neighbours(vertex);
        //     int i = 0;
        //     cout << "The neighbours of the given vertices are:"<<endl;
        //     while (*(neighbours + i) != -1 || i < 20) {
        //     cout << *(neighbours + i) <<endl;
        //     }
        //     cout <<endl;
        //     break;
        // }
        
        default:
            break;
        }
    };
}