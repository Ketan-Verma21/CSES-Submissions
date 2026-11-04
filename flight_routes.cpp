#include <bits/stdc++.h>
using namespace std;
unordered_map<int, vector<pair<int, int>>> adj;
#define int long long

int32_t main()
{
    int n,m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<vector<int>> ans(n + 1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (ans[u].size() >= k)
            continue;
        ans[u].push_back(d);
        for (auto [v, w] : adj[u])
        {
            pq.push({d + w, v});
        }
    }
    for(int i = 0; i < k; i++)
    {
        cout << ans[n][i] << " ";
    }
    cout<< endl;
    return 0;
}