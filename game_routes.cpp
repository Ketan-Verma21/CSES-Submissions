#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;
vector<int> dp;
unordered_map<int,vector<int>> adj;

int dfs(int node){
    if(dp[node]!=-1){
        return dp[node]%mod;
    }
    int ans=0;
    for(int it:adj[node]){
        ans=(ans%mod+ dfs(it)%mod)%mod;
    }
    return dp[node]=ans;

}
int32_t main(){
    int n,m;
    cin>>n>>m;
    dp.resize(n+1,-1);
    dp[n]=1;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    dfs(1);
    int ans= dp[1]==-1 ? 0: dp[1];
    cout<< ans<<endl;
    return 0;
}