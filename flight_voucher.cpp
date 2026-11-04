#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, m;
    cin >> n >> m;
 
    vector<vector<pair<int, int>>> adj(n + 1);
 
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
 
    // dist[node][voucherUsed]
    vector<vector<long long>> dist(n + 1, vector<long long>(2, LLONG_MAX));
 
    // {cost, node, voucherUsed}
    priority_queue<
        tuple<long long, int, int>,
        vector<tuple<long long, int, int>>,
        greater<tuple<long long, int, int>>
    > pq;
 
    dist[1][0] = 0;
    pq.push({0, 1, 0});
 
    while (!pq.empty()) {
        auto [cost, node, voucherUsed] = pq.top();
        pq.pop();
 
        if (cost != dist[node][voucherUsed]) continue;
 
        if (node == n) {
            cout << cost << '\n';
            return 0;
        }
 
        for (auto [next, edgeCost] : adj[node]) {
            long long newCost = cost + edgeCost;
 
            if (newCost < dist[next][voucherUsed]) {
                dist[next][voucherUsed] = newCost;
                pq.push({newCost, next, voucherUsed});
            }
 
            if (!voucherUsed && cost + edgeCost/2 < dist[next][1]) {
                dist[next][1] = cost + edgeCost/2;
                pq.push({cost + edgeCost/2, next, 1});
            }
        }
    }
 
    cout << -1 << '\n';
    return 0;
}