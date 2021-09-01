#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> store, vector<int> adj[], vector<int> &vis)
{
    store.push_back(node);
    vis[node] = 1;
    if (!vis[node])
    {
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, store, adj, vis);
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    vector<int> vis(n + 1, 0);
    vector<int> store;

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
            dfs(i, store, adj, vis);
        }
    }
    for (auto s : store)
    {
        cout << s << " ";
    }
    return 0;
}