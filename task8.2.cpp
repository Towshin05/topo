#include <iostream>
#include <list>
#include <stack>
#include <vector>

using namespace std;

class Graph {
    int V;            
    list<int>* adj;    

    
    void topologicalSortUtil(int v, bool visited[], stack<int>& Stack);

public:
    
    Graph(int V);

    
    void addEdge(int v, int w);

   
    void topologicalSort();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
   
    adj[v].push_back(w);
}


void Graph::topologicalSortUtil(int v, bool visited[], stack<int>& Stack) {
   
    visited[v] = true;

  
    for (int neighbor : adj[v]) {
        if (!visited[neighbor]) {
            topologicalSortUtil(neighbor, visited, Stack);
        }
    }

    
    Stack.push(v);
}


void Graph::topologicalSort() {
    stack<int> Stack;

    
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);

    
  
    while (!Stack.empty()) {
        cout << Stack.top() + 1 << " "; 
        Stack.pop();
    }

    delete[] visited;
}

int main() {
    int vertices, edges;

    
    //cout << "Enter the number of vertices: ";
    cin >> vertices;

   
    cin >> edges;

    
    Graph g(vertices);

    //cout << "Enter the edges (format: source destination):" << endl;
    for (int i = 0; i < edges; i++) {
        int source, destination;
        cin >> source >> destination;
        g.addEdge(source - 1, destination - 1); 
    }

    g.topologicalSort();

    return 0;
}







