#include<iostream>
#include<vector>
#include<queue>
 
using namespace std;
 
vector<int> graph[100000];
bool used[100000];
int dist[100000] = {-1};
 
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }
    queue<int> q;
    q.push(0);
    used[0] = true;
    dist[0] = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int neighbor: graph[cur])
            if (!used[neighbor])
            {
                q.push(neighbor);
                used[neighbor] = true;
                dist[neighbor] = dist[cur] + 1;
            }
    }
    for (int i = 0; i < n; i++)
        if (dist[i] != -1)
            cout << dist[i] << " ";
        else
            cout << "0 ";
}
