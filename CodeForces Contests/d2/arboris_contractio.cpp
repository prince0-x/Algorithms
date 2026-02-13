#include <bits/stdc++.h>
using namespace std;
void solve()
{
      int n, maxi = INT_MIN;
      cin >> n;
      vector<vector<int>> adj(n + 1);
      vector<int> degree(n + 1, 0);
      for (int i = 0; i < n - 1; i++)
      {
            int u, v;
            cin >> u >> v;
            ++degree[u];
            ++degree[v];
            adj[u].push_back(v);
            adj[v].push_back(u);
      }
      if (n <= 3)
      {
            cout << 0 << "\n";
            return;
      }
      int cnt = 0;
      for (int i = 1; i <= n; i++)
      {
            cnt += (degree[i] == 1); // count leaf
      }
      for (int i = 1; i <= n; i++)
      {
            int mx = 0;
            for (auto j : adj[i])
            {
                  mx += (degree[j] == 1);
            }
            maxi = max(maxi, mx);
      }
      cout << cnt - maxi << endl;
}
int main()
{
      int t;
      cin >> t;
      while (t--)
      {
            solve();
      }
      return 0;
}