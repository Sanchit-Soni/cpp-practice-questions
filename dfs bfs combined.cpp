#include <bits/stdc++.h>

using namespace std;

void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs)
{
    storeDfs.push_back(node);
    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, vis, adj, storeDfs);
        }
    }
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
    vector<int> storeDfs;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            // dfs(i,vis,adj,storeDfs);
            queue<int> q;
            q.push(i);
            vis[i] = 1;

            while (!q.empty())
            {
                int node = q.front();
                storeDfs.push_back(node);
                q.pop();

                for (auto it : adj[node])
                {
                    if (!vis[it])
                    {
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }
        }
    }

    for (auto s : storeDfs)
    {
        cout << s << " ";
    }

    return 0;
}