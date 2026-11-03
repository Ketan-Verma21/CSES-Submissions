#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> vis;
unordered_map<int,vector<int>> adj, adj_r;
vector<int> topo;
unordered_map<int,int> mapp;
void dfs(int node){
    vis[node]=1;
    for(int it:adj[node]){
        if(!vis[it]){
            dfs(it);
        }
    }
    topo.push_back(node);
}
void dfs2(int node, int k){
    vis[node]=1;
    for(int it:adj_r[node]){
        if(!vis[it]){
            dfs2(it,k);
        }
    }
    mapp[node]=k;
}
int32_t main(){
    int n,m;
    cin>>n>>m;
    vis.resize(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj_r[b].push_back(a);
    }
    for(int i=1;i<n+1;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    fill(vis.begin(), vis.end(),0);
    int k=1;
    while(!topo.empty()){
        int node= topo.back();
        topo.pop_back();
        if(!vis[node]){
            dfs2(node,k);
            k++;
        }
    }
    cout<<k-1<<endl;
    for(int i=1;i<n+1;i++){
        cout<<mapp[i]<<" ";
    }
    cout<<endl;
    return 0;
}