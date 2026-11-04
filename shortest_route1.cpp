#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n,m;
    cin>>n>>m;
    unordered_map<int,vector<tuple<int,int>>> adj;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    vector<int> dist(n+1,LLONG_MAX);
    dist[1]=0;
    priority_queue<tuple<int,int>,vector<tuple<int,int>>,greater<tuple<int,int>>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        auto [d,node]= pq.top();
        pq.pop();
        if(dist[node]!=d) continue;
        for(auto [v,w]: adj[node]){
            if(dist[v]> d+w){
                dist[v]=d+w;
                pq.push({d+w,v});
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    return 0;
}