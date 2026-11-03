
#include<bits/stdc++.h>
using namespace std;

#define int long long

class DSU{
public:
    vector<int> par, rank;

    DSU(int n): par(n+1), rank(n+1,0){
        for(int i=0;i<=n;i++){
            par[i]=i;
        }
    }

    int findPar(int a){
        if(par[a]==a){
            return a;
        }

        return par[a]=findPar(par[a]);
    }

    void unite(int a, int b){

        a=findPar(a);
        b=findPar(b);

        if(a==b) return;

        if(rank[a]<rank[b]){
            swap(a,b);
        }

        par[b]=a;

        if(rank[a]==rank[b]){
            rank[a]++;
        }
    }
};

int32_t main(){

    int n,m;
    cin>>n>>m;

    vector<tuple<int,int,int>> adj;

    for(int i=0;i<m;i++){

        int u,v,w;
        cin>>u>>v>>w;

        adj.push_back({w,u,v});
    }

    sort(adj.begin(),adj.end());

    DSU ds(n);

    int ans=0;
    int edges=0;

    for(auto [w,u,v]:adj){

        if(ds.findPar(u)!=ds.findPar(v)){

            ans+=w;
            ds.unite(u,v);
            edges++;
        }
    }

    if(edges!=n-1){
        cout<<"IMPOSSIBLE";
        return 0;
    }

    cout<<ans<<endl;

    return 0;
}
