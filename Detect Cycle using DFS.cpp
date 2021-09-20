#include <bits/stdc++.h>
using namespace std;

bool cycleDfs(int node, int parent, vector<int> adj[], vector<int> &vis)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (vis[it] == 0)
        {
            if (cycleDfs(it, node, adj, vis))
                return true;
        }
        else if (it != parent)
            return true;
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    vector<int> vis(n + 1, 0);
    bool ans = false;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {

            if (cycleDfs(i, -1, adj, vis))
            {
                ans = true;
            }
        }
    }
    if (ans == true)
    {
        cout << "Cycle Exist";
    }
    else
        cout << "No Cycle";

    return 0;
}