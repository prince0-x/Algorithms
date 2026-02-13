#include<bits/stdc++.h>
using namespace std;

int n, m, block_size, block_cnt;

vector<vector<int>>graph;
vector<int>height;
vector<int>euler, log_2, selective_euler;
void dfs_euler(int node, int parent, int hgt=1){
      euler.push_back(node);
      height[node]= hgt;
      for(auto nbr: graph[node]){
            if(nbr != parent){
                  dfs_euler(nbr, node, hgt +1);
                  euler.push_back(node);
            }
      }
}
int main(){
      // graph input and definition

      cin>>n >> m;
      graph.resize(n+1);
      height.resize(n+1);
      for(int i=0; i<m;i++){
            int u, v;
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
      }


      // preprocessing of euler tour and height of node

      dfs_euler(1, 1);  
      
      // effective selection for RMQ using sparsre table 
      int m = euler.size();
      log_2.reserve(m + 1);
      log_2.push_back(-1);
      for (int i = 1; i <= m; i++)
            log_2.push_back(log_2[i / 2] + 1);

      block_size = max(1, log_2[m] / 2);
      block_cnt = (m + block_size - 1) / block_size;

      // preprocessing smaller array 
      
      for(int i=0; i<block_cnt; i++){
            int ele = *min_element(euler.begin(), euler.end());
            selective_euler.push_back(ele);
      }

}