#include<bits/stdc++.h>
using namespace std;
#define int long long
unordered_map<int,vector<int>> adj, adj_r;
vector<int> vis;
void dfs(int node){
    vis[node]=1;
    for(int it: adj[node]){
        if(!vis[it]){
            dfs(it);
        }
    }
}
void dfs2(int node){
    vis[node]=1;
    for(int it:adj_r[node]){
        if(!vis[it]){
            dfs2(it);
        }
    }
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
    dfs(1);
    for(int i=1;i<n+1;i++){
        if(!vis[i]){
            cout<<"NO"<<endl;
            cout<<1<<" "<<i<<endl;
            return 0;
        }
    }
    fill(vis.begin(), vis.end(),0);
    dfs2(1);
    for(int i=1;i<n+1;i++){
        if(!vis[i]){
            cout<<"NO"<<endl;
            cout<<i<<" "<<1<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}