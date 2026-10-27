#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m;
vector<vector<char>> grid;
vector<vector<int>> vis;

vector<pair<int,int>> dir = {
    {-1, 0}, {0, -1}, {1, 0}, {0, 1}
};

string mp = "ULDR";

bool check(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m
           && grid[i][j] != '#';
}

int32_t main() {
    cin >> n >> m;

    grid.resize(n, vector<char>(m));
    vis.resize(n, vector<int>(m, 0));

    queue<tuple<int,int,int>> q;
    pair<int,int> cord;

    vector<vector<int>> monster_time(
        n, vector<int>(m, LLONG_MAX)
    );

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];

            if (grid[i][j] == 'A')
                cord = {i, j};

            if (grid[i][j] == 'M') {
                q.push({i, j, 0});
                monster_time[i][j] = 0;
            }
        }
    }

    // Task 1: Find the minimum time for monsters to reach each cell
    while (!q.empty()) {
        auto [r, c, t] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int new_r = r + dir[i].first;
            int new_c = c + dir[i].second;
            int new_t = t + 1;

            if (check(new_r, new_c) &&
                monster_time[new_r][new_c] > new_t) {

                monster_time[new_r][new_c] = new_t;
                q.push({new_r, new_c, new_t});
            }
        }
    }

    // Task 2: BFS for the person
    vector<vector<tuple<int,int,char>>> par(
        n, vector<tuple<int,int,char>>(m, {-1, -1, '#' })
    );

    while (!q.empty()) q.pop();

    q.push({cord.first, cord.second, 0});
    vis[cord.first][cord.second] = 1;

    bool found = false;
    pair<int,int> final_cord;

    while (!q.empty()) {
        auto [r, c, t] = q.front();
        q.pop();

        // Check whether the person has reached a boundary
        if (r == n - 1 || c == m - 1 || r == 0 || c == 0) {
            final_cord = {r, c};
            found = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int new_r = r + dir[i].first;
            int new_c = c + dir[i].second;
            int new_t = t + 1;

            if (check(new_r, new_c) &&
                !vis[new_r][new_c] &&
                new_t < monster_time[new_r][new_c]) {

                vis[new_r][new_c] = 1;
                par[new_r][new_c] = {r, c, mp[i]};

                q.push({new_r, new_c, new_t});
            }
        }
    }

    if (!found) {
        cout << "NO\n";
    } else {
        string s;

        while (final_cord != cord) {
            int a = final_cord.first;
            int b = final_cord.second;

            auto [x, y, c] = par[a][b];

            s.push_back(c);
            final_cord = {x, y};
        }

        reverse(s.begin(), s.end());

        cout << "YES\n";
        cout << s.length() << '\n';
        cout << s << '\n';
    }

    return 0;
}