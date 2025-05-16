#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    for (int i = 0; i < graph.size(); ++i) {
        if (graph[node][i] && !visited[i])
            dfs(i, graph, visited);
    }
}

bool checkConnected(vector<vector<int>>& graph) {
    int n = graph.size();
    for (int i = 0; i < n; ++i) {
        vector<bool> visited(n, false);
        dfs(i, graph, visited);
        for (bool v : visited)
            if (!v) return false;
    }
    return true;
}

bool checkUnilateral(vector<vector<int>>& graph) {
    int n = graph.size();
    for (int i = 0; i < n; ++i) {
        vector<bool> visited(n, false);
        dfs(i, graph, visited);
        for (bool v : visited)
            if (!v) return false;
    }
    return true;
}

bool checkWeak(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> undirected(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (graph[i][j] || graph[j][i])
                undirected[i][j] = undirected[j][i] = 1;

    vector<bool> visited(n, false);
    dfs(0, undirected, visited);
    for (bool v : visited)
        if (!v) return false;
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> graph[i][j];

    if (checkConnected(graph))
        cout << "Strongly Connected";
    else if (checkUnilateral(graph))
        cout << "Unilaterally Connected";
    else if (checkWeak(graph))
        cout << "Weakly Connected";
    else
        cout << "Not Connected";

    return 0;
}