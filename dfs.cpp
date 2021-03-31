#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<int> color;
vector <int> order;
bool f = 1;

void DFS(int v)
{
    color[v] = 2;
    for (int i = 0; i < graph[v].size(); i++)
    {
        if (color[graph[v][i]] == 1)
            DFS(graph[v][i]);
        if (color[graph[v][i]] == 2)
            f = 0;
    }
    color[v] = 0;
    order.push_back(v);
};

int main()
{
    int n, m;
    cin >> n >> m;
    graph.resize(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u - 1].push_back(v - 1);
    }
    color.resize(n);
    for (int i = 0; i < n; i++)
        color[i] = 1;
    for (int i = 0; i < graph.size(); i++)
        if (color[i] == 1)
            DFS(i);
    if (f)
    {
        reverse(order.begin(), order.end());
        for (int v: order)
            cout << v + 1 << " ";
        cout << "\n";
    }
    else
        cout << "-1\n";
    return 0;
}
