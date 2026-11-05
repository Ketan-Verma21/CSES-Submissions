#include<bits/stdc++.h>
using namespace std;
#define int long long

unordered_map<int,vector<int>> adj, adj_r;
vector<int> coins;
int n,m;

vector<int> dp;
vector<int> vis;
vector<int> topo;
vector<int> dag_coins;

unordered_map<int,int> mapping;

void dfs(int node){
    vis[node]=1;

    for(int it: adj[node]){
        if(!vis[it]){
            dfs(it);
        }
    }

    topo.push_back(node);
}

void dfs2(int node, int k){
    vis[node]=1;

    mapping[node]=k;
    dag_coins[k]+=coins[node];

    for(int it: adj_r[node]){
        if(!vis[it]){
            dfs2(it,k);
        }
    }
}

int dfsDP(int node, unordered_map<int,vector<int>>& dag){
    if(dp[node]!=-1) return dp[node];

    int ans=0;

    for(int it: dag[node]){
        ans=max(ans,dfsDP(it,dag));
    }

    return dp[node]=dag_coins[node]+ans;
}

int32_t main(){

    cin>>n>>m;

    coins.resize(n+1);
    vis.resize(n+1,0);

    for(int i=1;i<=n;i++){
        cin>>coins[i];
    }

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj_r[b].push_back(a);
    }

    // Step 1: First DFS to calculate finishing order
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }

    // Step 2: Find SCCs using reversed graph
    fill(vis.begin(),vis.end(),0);

    int x=0;
    dag_coins.resize(n,0);

    while(!topo.empty()){

        int node=topo.back();
        topo.pop_back();

        if(!vis[node]){
            dfs2(node,x);
            x++;
        }
    }

    // Step 3: Construct condensed DAG
    unordered_map<int,vector<int>> dag;

    for(int i=1;i<=n;i++){
        for(int it:adj[i]){

            int u=mapping[i];
            int v=mapping[it];

            if(u!=v){
                dag[u].push_back(v);
            }
        }
    }

    // Step 4: DP on condensed DAG
    dp.resize(x,-1);

    int ans=0;

    for(int i=0;i<x;i++){
        ans=max(ans,dfsDP(i,dag));
    }

    cout<<ans<<endl;

    return 0;
}