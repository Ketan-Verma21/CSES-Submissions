
#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> edges;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    vector<long long> dist(n + 1, 0);
    vector<int> parent(n + 1, -1);

    int x = -1;

    for (int i = 0; i < n; i++) {
        x = -1;

        for (auto [u, v, w] : edges) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                x = v;
            }
        }
    }

    if (x == -1) {
        cout << "NO\n";
        return 0;
    }

    // Enter the cycle
    for (int i = 0; i < n; i++) {
        x = parent[x];
    }

    // Reconstruct one cycle
    vector<int> cycle;
    int cur = x;

    do {
        cycle.push_back(cur);
        cur = parent[cur];
    } while (cur != x);

    cycle.push_back(x);
    reverse(cycle.begin(), cycle.end());

    cout << "YES\n";
    for (int node : cycle) {
        cout << node << " ";
    }
    cout << "\n";

    return 0;
}
