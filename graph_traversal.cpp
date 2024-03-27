#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<vector<int> > adj; // Adjacency list

public:
    Graph(int vertices) : V(vertices) {
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (int i : adj[v]) {
            if (!visited[i])
                DFSUtil(i, visited);
        }
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        DFSUtil(start, visited);
    }

    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            cout << v << " ";

            for (int i : adj[v]) {
                if (!visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
};

int main() {
    int vertices;
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    Graph g(vertices);

    int edges;
    cout << "Enter the number of edges: ";
    cin >> edges;

    cout << "Enter edges in format (u v):" << endl;
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int start_vertex;
    cout << "Enter the starting vertex for traversal: ";
    cin >> start_vertex;

    cout << "Depth First Search (DFS) starting from vertex " << start_vertex << ": ";
    g.DFS(start_vertex);
    cout << endl;

    cout << "Breadth First Search (BFS) starting from vertex " << start_vertex << ": ";
    g.BFS(start_vertex);
    cout << endl;

    return 0;
}
