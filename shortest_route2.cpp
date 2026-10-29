#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t main(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<int>> dist(n+1,vector<int>(n+1,LONG_LONG_MAX));
    for (int i = 0; i < m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        dist[u][v]=min(w,dist[u][v]);
        dist[v][u]=min(w,dist[v][u]);
    }
    vector<tuple<int,int>> queries(q);
    for(int i=0;i<q;i++){
            int a,b;
            cin>>a>>b;
            queries[i]={a,b};
    }
    for(int i=1;i<n+1;i++){
        dist[i][i]=0;
    }
    for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][k] == LLONG_MAX ||
                dist[k][j] == LLONG_MAX)
                continue;

            dist[i][j] = min(
                dist[i][j],
                dist[i][k] + dist[k][j]
            );
        }
    }
}
    for(auto [a,b]:queries){
        int ans= dist[a][b]==LONG_LONG_MAX? -1:dist[a][b];
        cout<<ans<<endl;
    }

    
    return 0;
}