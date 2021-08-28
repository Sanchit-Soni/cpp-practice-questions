#include <bits/stdc++.h>

using namespace std;

bool checkForCycle(int s, int V, vector<int> adj[], vector<int> &visited)
{
    queue<pair<int, int>> q;
    visited[s] = 1;
    q.push({s, -1});

    while (!q.empty())
    {
        int node = q.front().first;
        int pre = q.front().second;
        q.pop();

        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                visited[it] = 1;
                q.push({it, node});
            }
            else if (pre != it)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n + 1, 0);
    bool ans = false;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (checkForCycle(i, n, adj, vis))
            {
                ans = true;
            }
        }
    }

    if (ans)
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }

    return 0;
}