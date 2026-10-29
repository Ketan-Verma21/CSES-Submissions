#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> vis;
vector<int> topo;
unordered_map<int,vector<int>> adj;
bool dfs(int node){
    vis[node]=1;
    for(int it:adj[node]){
        if(vis[it]==1){
            return true;
        }
        else if(vis[it]==0 && dfs(it)){
            return true;
        }
    }
    vis[node]=2;
    topo.push_back(node);
    return false;
}
int32_t main(){
    int n,m;
    cin>>n>>m;
    
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    vis.resize(n+1,0);
    for(int i=1;i<n+1;i++){
        if(!vis[i]){
            bool gg= dfs(i);
            if(gg){
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }
        }
    }
    for(int i=topo.size()-1;i>=0;i--){
        cout<<topo[i]<<" ";
    }
    cout<<endl;
    return 0;
}