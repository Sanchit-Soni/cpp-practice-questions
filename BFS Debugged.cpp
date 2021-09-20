#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &store)
{
    store.push_back(node);
    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, adj, vis, store);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];
    vector<int> vis(n + 1, 0);
    vector<int> store1;
    vector<int> store;
    set<int> uniqueNodes;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        uniqueNodes.insert(u);
        uniqueNodes.insert(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i] && uniqueNodes.find(i) != uniqueNodes.end())
        {
            // dfs(i,adj,vis,store);

            queue<int> q;
            q.push(i);
            vis[i] = 1;

            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                store.push_back(node);

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

    for (auto s : store)
    {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
