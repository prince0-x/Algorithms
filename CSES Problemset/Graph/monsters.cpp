#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;
vector<vector<int>> monster_time, human_time;
vector<vector<pair<int,int>>> parent;
vector<pair<int,int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};
vector<char> move_dir = {'R','D','U','L'};
queue<pair<int,int>> mq, hq;

bool in_bounds(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m;
}

void bfs_monsters() {
    while (!mq.empty()) {
        auto [r, c] = mq.front(); mq.pop();
        for (auto [dr, dc] : dirs) {
            int nr = r + dr, nc = c + dc;
            if (!in_bounds(nr, nc) || grid[nr][nc] == '#') continue;
            if (monster_time[nr][nc] != -1) continue;
            monster_time[nr][nc] = monster_time[r][c] + 1;
            mq.push({nr, nc});
        }
    }
}

bool bfs_human_escape() {
    pair<int,int> exit_cell = {-1,-1};

    while (!hq.empty()) {
        auto [r, c] = hq.front(); hq.pop();
        if ((r == 0 || r == n-1 || c == 0 || c == m-1) && grid[r][c] != '#') {
            exit_cell = {r,c};
            cout << "YES\n" << human_time[r][c] << "\n";
            string path;
            while (parent[r][c].first != -1) {
                auto [pr, pc] = parent[r][c];
                if (pr == r - 1 && pc == c) path.push_back('D');
                else if (pr == r + 1 && pc == c) path.push_back('U');
                else if (pr == r && pc == c - 1) path.push_back('R');
                else if (pr == r && pc == c + 1) path.push_back('L');
                r = pr; c = pc;
            }
            reverse(path.begin(), path.end());
            cout << path << "\n";
            return true;
        }

        for (int i = 0; i < 4; i++) {
            int nr = r + dirs[i].first, nc = c + dirs[i].second;
            if (!in_bounds(nr, nc) || grid[nr][nc] == '#') continue;
            if (human_time[nr][nc] != -1) continue;

            int next_time = human_time[r][c] + 1;
            if (monster_time[nr][nc] != -1 && monster_time[nr][nc] <= next_time) continue;

            human_time[nr][nc] = next_time;
            parent[nr][nc] = {r, c};
            hq.push({nr, nc});
        }
    }

    cout << "NO\n";
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    grid.resize(n);
    for (auto &row : grid) cin >> row;

    monster_time.assign(n, vector<int>(m, -1));
    human_time.assign(n, vector<int>(m, -1));
    parent.assign(n, vector<pair<int,int>>(m, {-1,-1}));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'M') {
                mq.push({i, j});
                monster_time[i][j] = 0;
            } else if (grid[i][j] == 'A') {
                hq.push({i, j});
                human_time[i][j] = 0;
            }
        }
    }

    bfs_monsters();
    bfs_human_escape();
    return 0;
}
