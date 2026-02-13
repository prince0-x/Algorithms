// #include<bits/stdc++.h>
// #define int long long
// using namespace std;
// int n, q, curr_pos;
// vector<vector<int>>adj;
// vector<int>seg, weights, depth, heavy, head, pos, parent, flat_arr;


// int dfs(int node){
//       int size = 1;
//       int max_c_size =0;
//       for(auto child : adj[node]){
//             if(child != parent[node]){
//                   parent[child] = node;
//                   depth[child] = depth[node]+1;
//                   int c_size = dfs(child);
//                   size += c_size;
//                   if(max_c_size< c_size){
//                         max_c_size = c_size;
//                         heavy[node] = child;
//                   }

//             }
//       }
//       return size;
// }

// void decompose(int node, int h){
//       head[node] = h;
//       pos[node] = curr_pos++;
//       if(heavy[node] != -1){
//             decompose(heavy[node], h);
//       }
//       for(auto child:adj[node]){
//             if(child != parent[node] && child != heavy[node]){
//                   decompose(child, child);
//             }
//       }
// }


// int query_seg(int node, int low, int high, int ql, int qr){
//       if (qr < low || high < ql) return INT_MIN;
//       if (ql <= low && high <= qr) return seg[node];

//       int mid = low + ((high - low) >> 1);
//       int left = query_seg(node << 1, low, mid, ql, qr);
//       int right = query_seg(node << 1 | 1, mid + 1, high, ql, qr);
//       return max(left, right);
// }
// int segment_tree_query(int l, int r){
//       return query_seg(1, 0, n-1, l, r);
// }
// int query(int a, int b) {
//     int res = INT_MIN;
//     for (; head[a] != head[b]; b = parent[head[b]]) {
//         if (depth[head[a]] > depth[head[b]])
//             swap(a, b);
//         int cur_heavy_path_max = segment_tree_query(pos[head[b]], pos[b]);
//         res = max(res, cur_heavy_path_max);
//     }
//     if (depth[a] > depth[b])
//         swap(a, b);
//     int last_heavy_path_max = segment_tree_query(pos[a], pos[b]);
//     res = max(res, last_heavy_path_max);
//     return res;
// }


// void update_seg(int node, int low, int high, int idx, int val) {
//     if(low == high) {
//         seg[node] = val;
//         return;
//     }
//     int mid = low + ((high - low) >> 1);
//     if(idx <= mid) update_seg(node<<1, low, mid, idx, val);
//     else update_seg(node<<1|1, mid+1, high, idx, val);
//     seg[node] = max(seg[node<<1], seg[node<<1|1]);
// }
// void update(int u, int val) {
//     update_seg(1, 0, n-1, pos[u], val);
// }



// void build(int node, int low, int high){
//       if(low == high){
//             seg[node] =flat_arr[low];
//             return;
//       }
//       int mid=low +((high-low)>>1);
//       build(node<<1, low, mid);
//       build(node<<1 |1, mid+1, high);
//       seg[node] = max(seg[node<<1], seg[node<<1 |1]);
// }




// int32_t main(){
//       ios::sync_with_stdio(false); cin.tie(nullptr);cout.tie(nullptr);
//       cin >> n>>q;


//       adj.resize(n+1);
//       weights.resize(n+1);
//       head.resize(n+1);
//       heavy.resize(n+1, -1);
//       pos.resize(n+1);
//       depth.resize(n+1, 0);
//       parent.resize(n+1);
//       flat_arr.resize(n+1);
//       curr_pos=0;



//       for(int i=1;i<=n;i++){
//             cin>>weights[i];
//       }
//       for(int i=1;i<n;i++){
//             int u, v;
//             cin >>u>>v;
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//       }
//       parent[1]=0;
//       dfs(1);
//       decompose(1, 1);
//       for(int i=1;i<=n;i++){
//             flat_arr[pos[i]] = weights[i];
//       }

//       seg.resize(4*(n+1));
//       build(1,0, n-1);
//       vector<int>answers;
//       while(q--){
//             int typ;
//             cin>>typ;
//             if(typ ==1){
//                   int node, new_val;
//                   cin>>node>>new_val;
//                   update(node, new_val);
//             }else{
//                   int node1, node2;
//                   cin>>node1>>node2;
//                   answers.push_back(query(node1, node2));
//             }
//       }
//       for (int ans : answers) cout << ans << " ";
//       return 0;

// }


#include "bits/stdc++.h"
using namespace std;

#define int long long
#define endl '\n'

const int mxN = 2e5+5;
vector<int> adj[mxN];
int dp[mxN], depth[mxN], par[mxN];
int heavy[mxN], head[mxN], id[mxN];
int seg[10*mxN];
int N;
int val[mxN];

void update(int k, int x) {
    k += N; seg[k] = x; k >>= 1;
    while (k > 0) {
        seg[k] = max(seg[2*k], seg[2*k+1]);
        k >>= 1;
    }
}

int query(int a, int b) {
    a += N, b += N;
    int s = 0;
    while (a <= b) {
        if (a & 1) {
            s = max(s, seg[a]);
            a++;
        }
        if (~b & 1) {
            s = max(s, seg[b]);
            b--;
        }
        a >>= 1, b >>= 1;
    }
    return s;
}

void dfs(int s, int p) {
    dp[s] = 1;
    int mx = 0;
    for (auto i: adj[s]) if (i != p) {
        par[i] = s;
        depth[i] = depth[s] + 1;
        dfs(i, s);
        dp[s] += dp[i];        
        if (dp[i] > mx)
            mx = dp[i], heavy[s] = i;
    }
}

int cnt = 0;
void hld(int s, int h) {
    head[s] = h;
    id[s] = ++cnt;
    update(id[s]-1, val[s]);
    if (heavy[s])
        hld(heavy[s], h);
    for (auto i: adj[s]) {
        if (i != par[s] && i != heavy[s])
            hld(i, i);
    }
}

int path(int x, int y){
    int ans = 0;
    while (head[x] != head[y]) {
        if (depth[head[x]] > depth[head[y]])
            swap(x, y);
        ans = max(ans, query(id[head[y]]-1, id[y]-1));
        y = par[head[y]];
    }
    if(depth[x] > depth[y]) 
        swap(x, y);
    ans = max(ans, query(id[x]-1, id[y]-1));
    return ans;
}


signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    
    int n, t; cin>>n>>t;
    N = 1 << (int) ceil(log2(n));
    for (int i = 1; i <= n; i++) 
        cin>>val[i];

    for (int i = 1; i < n; i++) {
        int x, y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 0);
    hld(1, 1);

    while (t--) {
        int ch; cin>>ch;
        if (ch == 1) {
            int k, x; cin>>k>>x;
            update(id[k]-1, x);
        }
        else {
            int x, y; cin>>x>>y;
            cout << path(x, y) << ' ';
        }
    }
}