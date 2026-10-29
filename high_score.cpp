#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edge;
    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edge.push_back({a, b, w});
        adj[a].push_back(b);
    }
    vector<int> dist(n + 1, LONG_LONG_MIN);
    dist[1] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (auto it : edge)
        {
            int a = it[0];
            int b = it[1];
            int w = it[2];
            if (dist[a] != LONG_LONG_MIN && dist[b] < dist[a] + w)
            {
                dist[b] = dist[a] + w;
            }
        }
    }
    set<int> cycle_nodes;
    for (auto it : edge)
    {
        int a = it[0];
        int b = it[1];
        int w = it[2];
        if (dist[a] != LONG_LONG_MIN && dist[b] < dist[a] + w)
        {
            cycle_nodes.insert(a);
            cycle_nodes.insert(b);
        }
    }
    if (cycle_nodes.empty())
    {
        cout << dist[n] << endl;
        return 0;
    }
    queue<int> q;
    for(auto it:cycle_nodes){
        q.push(it);
    }
    vector<int> vis(n+1,0);
    bool check=false;
    while(!q.empty()){
        int node= q.front();
        q.pop();
        if(node==n){
            check=true;
            break;
        }
        for(int it:adj[node]){
            if(!vis[it]){
                q.push(it);
                vis[it]=1;
            }
        }
    }
    if(check){
        cout<<-1<<endl;
        return 0;
    }
    cout<<dist[n]<<endl;

    return 0;
}
