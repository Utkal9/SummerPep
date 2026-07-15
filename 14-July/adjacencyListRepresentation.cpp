#include <bits/stdc++.h>
using namespace std;

int main() {

    int nodes;
    cin >> nodes;

    vector<vector<int>> graph(nodes, vector<int>(nodes, 0));

    int edges;
    cin >> edges;

    while (edges--) {

        int u, v;
        cin >> u >> v;

        graph[u][v] = 1;
        graph[v][u] = 1;      // Undirected Graph
    }

    cout << "Adjacency Matrix:\n\n";

    for (int i = 0; i < nodes; i++) {

        for (int j = 0; j < nodes; j++) {

            cout << graph[i][j] << " ";
        }

        cout << "\n";
    }

    return 0;
}