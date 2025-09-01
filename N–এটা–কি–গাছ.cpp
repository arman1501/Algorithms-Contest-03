#include <bits/stdc++.h> // All header file.
using namespace std;

// Global adjacency list and visited array use.
vector<int> graph[10001];
bool visited[10001];
bool cycleFound = false; // Cycle track korar jonne.

// Void DFS function
void DFS(int u, int parent)
{
    visited[u] = true; // mark current node visited hbe.

    // Explore korbe sob gula neighbors er kase.
    for (int i = 0; i < graph[u].size(); i++)
    {
        int v = graph[u][i];
        if (!visited[v])
        {
            DFS(v, u); // Recursive DFS hbe.
        }
        else if (v != parent)
        {
            cycleFound = true; // When found a cycle then use.
        }
    }
}

int main() // Main function use.
{
    int node, edge;
    cin >> node >> edge; // Declear two variables & input from uesrs.

    // Tree hole edge hbe (node - 1)
    if (edge != node - 1)
    {
        cout << "NO" << endl;
        return 0;
    }

    // Read edges and build adjacency list
    int u, v;
    for (int i = 1; i <= edge; i++)
    {
        cin >> u >> v;         // Input from users.
        graph[u].push_back(v); // adjacency list fill kora.
        graph[v].push_back(u); // undirected graph korci.
    }

    DFS(1, 0); // Start DFS from node 1, parent = 0

    // Check if all nodes visited (connected)
    for (int i = 1; i <= node; i++)
    {
        if (!visited[i])
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    // Check if any cycle found then,
    if (cycleFound)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;

    return 0;
}
