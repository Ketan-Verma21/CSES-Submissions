#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9 + 7;

int32_t main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    vector<int> dist(n + 1, LLONG_MAX);
    vector<int> ways(n + 1, 0);
    vector<int> mini(n + 1, LLONG_MAX);
    vector<int> maxi(n + 1, LLONG_MIN);

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    dist[1] = 0;
    ways[1] = 1;
    mini[1] = 0;
    maxi[1] = 0;

    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();

        if (d != dist[node]) continue;

        for (auto [v, w] : adj[node]) {

            int nd = d + w;
            if (nd < dist[v]) {

                dist[v] = nd;
                ways[v] = ways[node];

                mini[v] = mini[node] + 1;
                maxi[v] = maxi[node] + 1;

                pq.push({nd, v});
            }

            else if (nd == dist[v]) {

                ways[v] = (ways[v] + ways[node]) % mod;

                mini[v] = min(mini[v], mini[node] + 1);
                maxi[v] = max(maxi[v], maxi[node] + 1);
            }
        }
    }

    cout << dist[n] << " "
         << ways[n] << " "
         << mini[n] << " "
         << maxi[n] << '\n';

    return 0;
}