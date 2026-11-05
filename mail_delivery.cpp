#include<bits/stdc++.h>
using namespace std;
#define int long long
unordered_map<int,vector<tuple<int,int>>> adj;
vector<int> vis;
vector<int> path;
void dfs(int node){
    while(!adj[node].empty()){
        auto [it,code]= adj[node].back();
        adj[node].pop_back();
        if(vis[code]) continue;
        vis[code]=1;
        dfs(it);
    }
    path.push_back(node);
}
int32_t main(){
    int n,m;
    cin>>n>>m;
    vector<int> degree(n+1,0);
    vis.resize(m,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back({b,i});
        adj[b].push_back({a,i});
        degree[a]++;
        degree[b]++;
    }
    for(int i=1;i<n+1;i++){
        if(degree[i]%2==1){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
    }
    dfs(1);
    
        if(path.size()!=m+1){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
    for(int i=path.size()-1;i>=0;i--){
        cout<<path[i]<<" ";

    }
    cout<<endl;


    return 0;
}