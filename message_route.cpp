#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t main(){
    int n,m;
    cin>>n>>m;
    unordered_map<int,vector<int>> adj;
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> vis(n+1,0), par(n+1);
    iota(par.begin(), par.end(), 0);
    queue<int> q;
    q.push(1);
    vis[1]=1;
    bool check=false;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        if(node==n) {
            check=true;
            break;
        }
        for(int it:adj[node]){
            if(!vis[it]){
                par[it]=node;
                q.push(it);
                vis[it]=1;
            }
        }
    }
    if(!check){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    vector<int> route;
    int a = n;
    while(par[a]!=a){
        route.push_back(a);
        a=par[a];
    }
    route.push_back(1);
    cout<<route.size()<<endl;
    for(int i=route.size()-1;i>=0;i--){
        cout<<route[i]<<" ";
    }
    cout<<endl;
    return 0;

}