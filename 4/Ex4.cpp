#include <bits/stdc++.h>

using namespace std;

// A utility function to find the vertex with the minimum
// distance value, from the set of vertices not yet included
// in the shortest path tree
int minDist(vector<int> &dist, vector<bool> &sptSet){
    int min = INT_MAX, idx = -1;
    for (int i = 0; i < dist.size(); i++)
        if (!sptSet[i] && dist[i] < min)
            min = dist[i], idx = i;
    return idx;
}

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented
// using adjacency matrix representation
void dijkstra(vector<vector<int>> &graph, int src){
    int V = graph.size();
    vector<int> dist(V, INT_MAX);  // The output array. dist[i] will hold
                                   // the shortest distance from src to i
    vector<bool> sptSet(V, false); // sptSet[i] will be true if vertex i
                                   // is included in shortest path tree

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (;;){

        // Pick the minimum distance vertex from the set of
        // vertices not yet processed.
        int u = minDist(dist, sptSet);
        if (u == -1)
            break; // If no valid vertex is found, stop.

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices
        // of the picked vertex
        for (int v = 0; v < V; v++)

            // Update dist[v] only if it is not in sptSet,
            // there is an edge from u to v, and total weight
            // of path from src to v through u is smaller
            // than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // Print the constructed distance array
    cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < V; i++)
        cout << i << " \t\t " << dist[i] << '\n';
}

int main(){
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> graph(V, vector<int>(V, 0));
    cout << "Enter each edge as: src dest weight\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        try {
            if (w < 0) {
                throw string ("Input Negative weight");
            }
        }catch (string e) {
            cout << e <<endl;
            return 0;
        }

        graph[u][v] = w;
        graph[v][u] = w;
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    dijkstra(graph, src);

    return 0;
}
