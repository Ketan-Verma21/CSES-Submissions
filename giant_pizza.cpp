#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> vis;
unordered_map<int, int> mapping;
unordered_map<int, vector<int>> adj, adj_r;
vector<int> topo;
int n, m;
int getOpp(int x)
{
    return x <= m ? x + m : x - m;
}
void dfs(int node)
{
    vis[node] = 1;
    for (int it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it);
        }
    }
    topo.push_back(node);
}
void dfs2(int node, int k)
{
    vis[node] = 1;
    for (int it : adj_r[node])
    {
        if (!vis[it])
        {
            dfs2(it, k);
        }
    }
    mapping[node] = k;
}
void make_graph(int i, int j)
{
    adj[getOpp(i)].push_back(j);
    adj[getOpp(j)].push_back(i);
    adj_r[j].push_back(getOpp(i));
    adj_r[i].push_back(getOpp(j));
}
int32_t main()
{
    cin >> n >> m;
    vis.resize(2 * m + 2, 0);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        char x, y;
        cin >> x >> a;
        cin >> y >> b;
        if (x == '-')
            a = getOpp(a);
        if (y == '-')
            b = getOpp(b);
        make_graph(a, b);
    }
    for (int i = 1; i < 2 * m + 1; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    fill(vis.begin(), vis.end(), 0);
    int k = 1;
    while (!topo.empty())
    {
        int node = topo.back();
        topo.pop_back();
        if (!vis[node])
        {
            dfs2(node, k);
            k++;
        }
    }
    vector<char> ans(m + 1);
    for (int i = 1; i <= m; i++)
    {
        if (mapping.find(i) != mapping.end())
        {
            int a = mapping[i];
            int b = mapping[getOpp(i)];
            if (a == b)
            {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
            if (a > b)
            {
                ans[i] = '-';
            }
            else
            {
                ans[i] = '+';
            }
        }
        else
        {
            ans[i] = '-';
        }
    }
    for (int i = 1; i < m + 1; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}