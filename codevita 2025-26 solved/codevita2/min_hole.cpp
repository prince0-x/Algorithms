#include <bits/stdc++.h>
using namespace std;
const int MAX_DIM = 255; 

int grid[MAX_DIM][MAX_DIM];
int region_map[MAX_DIM][MAX_DIM];
struct RegionInfo {
    int id;
    int min_r, max_r, min_c, max_c;
    int cell_count;
};

int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};


vector<vector<int>> adj;
vector<int> match;
vector<bool> vis;


bool dfs_match(int u) {
    for (int v : adj[u]) {
        if (vis[v]) continue;
        vis[v] = true;
        if (match[v] < 0 || dfs_match(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N_in, M_in, K;
    cin>>N_in>>M_in;

    int R_grid = 2 * N_in + 1;
    int C_grid = 2 * M_in + 1;


    for(int i=0; i<R_grid; ++i) {
        for(int j=0; j<C_grid; ++j) {
            region_map[i][j] = -1;
            if (i==0 || i==R_grid-1 || j==0 || j==C_grid-1) grid[i][j] = 1;
            else grid[i][j] = 0;
        }
    }
    cin >> K;
    while(K--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int r1 = 2 * x1;
        int c1 = 2 * y1;
        int r2 = 2 * x2;
        int c2 = 2 * y2;
        
        if (r1 == r2) { 
            for(int c=min(c1, c2); c<=max(c1, c2); ++c) grid[r1][c] = 1;
        } else { 
            for(int r=min(r1, r2); r<=max(r1, r2); ++r) grid[r][c1] = 1;
        }
    }

    vector<RegionInfo> regions;
    int region_count = 0;

    for(int i=1; i<R_grid; i+=2) {
        for(int j=1; j<C_grid; j+=2) {
            if (region_map[i][j] == -1 && grid[i][j] == 0) {
                RegionInfo reg;
                reg.id = region_count;
                reg.min_r = reg.max_r = i;
                reg.min_c = reg.max_c = j;
                reg.cell_count = 0;

                queue<pair<int,int>> q;
                q.push({i, j});
                region_map[i][j] = region_count;
                reg.cell_count++;

                while(!q.empty()) {
                    pair<int,int> curr = q.front(); q.pop();
                    int r = curr.first;
                    int c = curr.second;

                    reg.min_r = min(reg.min_r, r);
                    reg.max_r = max(reg.max_r, r);
                    reg.min_c = min(reg.min_c, c);
                    reg.max_c = max(reg.max_c, c);

                    for(int d=0; d<4; ++d) {
                        int wr = r + dr[d];     
                        int wc = c + dc[d];      
                        int nr = r + 2 * dr[d];   
                        int nc = c + 2 * dc[d];   
                        if (nr > 0 && nr < R_grid && nc > 0 && nc < C_grid) {
                            if (grid[wr][wc] == 0 && region_map[nr][nc] == -1) {
                                region_map[nr][nc] = region_count;
                                reg.cell_count++;
                                q.push({nr, nc});
                            }
                        }
                    }
                }
                regions.push_back(reg);
                region_count++;
            }
        }
    }

    for(const auto& reg : regions) {
        int h_cells = (reg.max_r - reg.min_r) / 2 + 1;
        int w_cells = (reg.max_c - reg.min_c) / 2 + 1;
        
        if (reg.cell_count != h_cells * w_cells) {
            cout << "Invalid" << endl;
            return 0;
        }

        for (int r = reg.min_r; r <= reg.max_r; r += 2) {
            for (int c = reg.min_c; c <= reg.max_c; c += 2) {
                if (c + 2 <= reg.max_c) {
                    if (grid[r][c+1] == 1) { 
                        cout << "Invalid" << endl;
                        return 0;
                    }
                }
                if (r + 2 <= reg.max_r) {
                    if (grid[r+1][c] == 1) {
                        cout << "Invalid" << endl;
                        return 0;
                    }
                }
            }
        }
    }

    adj.assign(region_count, vector<int>());
    for(int i=1; i<R_grid-1; ++i) {
        for(int j=1; j<C_grid-1; ++j) {
            if (grid[i][j] == 1) { 
                int r1 = -1, r2 = -1;
                
                if (i%2 == 0 && j%2 != 0) {
                    r1 = region_map[i-1][j];
                    r2 = region_map[i+1][j];
                } 
                else if (i%2 != 0 && j%2 == 0) {
                    r1 = region_map[i][j-1];
                    r2 = region_map[i][j+1];
                }

                if (r1 != -1 && r2 != -1 && r1 != r2) {
                    adj[r1].push_back(r2);
                    adj[r2].push_back(r1);
                }
            }
        }
    }
    
    for(int i=0; i<region_count; ++i) {
        sort(adj[i].begin(), adj[i].end());
        adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
    }

    match.assign(region_count, -1);
    int matching_size = 0;
    for(int i=0; i<region_count; ++i) {
        vis.assign(region_count, false);
        if (dfs_match(i)) matching_size++;
    }
    cout << region_count - (matching_size / 2) << endl;

    return 0;
}