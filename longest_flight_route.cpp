#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> vis;
unordered_map<int,vector<int>> adj;
vector<int> topo;
void dfs(int node){
    vis[node]=1;
    for(int it:adj[node]){
        if(!vis[it]){
            dfs(it);
        }
    }
    topo.push_back(node);
}
int32_t main(){
    int n,m;
    cin>>n>>m;
    vis.resize(n+1,0);
    
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    vector<int> dist(n+1,LONG_LONG_MIN);
    vector<int> par(n+1,-1);
    dfs(1);
    reverse(topo.begin(),topo.end());
    dist[1]=1;
    par[1]=1;
    for(int u:topo){
        if(dist[u]==LLONG_MIN)continue;
        for(int v:adj[u]){
            if(dist[v]<dist[u]+1){
                dist[v]=dist[u]+1;
                par[v]=u;
            }
        }
    }

    if(dist[n]==LONG_LONG_MIN){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    cout<<dist[n]<<endl;
    int cur=n;
    vector<int> route;
    while(par[cur]!=cur){
        route.push_back(cur);
        cur= par[cur];
    }
    route.push_back(1);
    for(int i=route.size()-1;i>=0;i--){
        cout<<route[i]<<" ";
    }
    cout<<endl;
    return 0;
}
