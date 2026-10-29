#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> vis;
vector<int> ans;
int last_num=-1;
unordered_map<int,vector<int>> adj;
bool dfs(int node, int par){
    vis[node]=1;
    ans.push_back(node);
    for(int it:adj[node]){
        if(vis[it]==1){
            last_num=it;
            ans.push_back(it);
            return true;
        }
        else if(vis[it]==0 && dfs(it,node)){
            return true;
        }
    }
    vis[node]=2;
    ans.pop_back();
    return false;
}
int32_t main(){
    int n,m;
    cin>>n>>m;
    ans.clear();
    vis.resize(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    bool gg=false;
    for(int i=1;i<n+1;i++){
        if(!vis[i] && !gg){
            gg= dfs(i,-1);
            if(gg) {
            break;}

        }
    }

    int sz= ans.size();
    if(gg){
        int j=0;
        for(int i=ans.size()-2;i>=0;i--){
            if(ans[i]==last_num){
                j=i; 
                break;
            }
            
        }
        cout<<sz-j<<endl;
        for(j;j<sz;j++){
            cout<<ans[j]<<" ";
        }
        return 0;
    }
    cout<<"IMPOSSIBLE"<<endl;

    return 0;
}