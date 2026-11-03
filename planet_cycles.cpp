
#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> vis, par;
vector<vector<int>> rev_par;
stack<int> topo;
vector<int> comp;

void dfs(int node){
    vis[node]=1;

    if(!vis[par[node]]){
        dfs(par[node]);
    }

    topo.push(node);
}

void dfs2(int node){
    vis[node]=1;
    comp.push_back(node);

    for(int v:rev_par[node]){
        if(!vis[v]){
            dfs2(v);
        }
    }
}

vector<int> ans;

void dfs3(int node, int parent){
    for(int v:rev_par[node]){

        if(ans[v]!=0) continue;

        ans[v]=ans[node]+1;
        dfs3(v,node);
    }
}

int32_t main(){

    int n;
    cin>>n;

    vis.resize(n+1,0);
    par.resize(n+1,0);
    rev_par.resize(n+1);

    for(int i=1;i<=n;i++){
        int a;
        cin>>a;

        par[i]=a;
        rev_par[a].push_back(i);
    }

    // First pass of Kosaraju
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }

    fill(vis.begin(),vis.end(),0);

    ans.resize(n+1,0);

    // Second pass
    while(!topo.empty()){

        int node=topo.top();
        topo.pop();

        if(vis[node]) continue;

        comp.clear();
        dfs2(node);

        // A cycle SCC has size > 1,
        // or is a self-loop SCC.
        bool isCycle = (comp.size()>1 || par[node]==node);

        if(isCycle){

            int sz=comp.size();

            // Assign cycle length
            for(int v:comp){
                ans[v]=sz;
            }

            // Propagate answers to incoming trees
            for(int v:comp){
                dfs3(v,v);
            }
        }
    }

    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }

    cout<<'\n';

    return 0;
}
