#include<bits/stdc++.h>
using namespace std;
#define int long long
class DSU{
    vector<int> par, size;
    public:
    int maxi;
    DSU(int n): par(n+1), size(n+1,1){
        for(int i=0;i<n+1;i++){
            par[i]=i;
        }
        maxi=1;
    }
    int findPar(int a){
        if(par[a]==a){
            return a;
        }
        return par[a]=findPar(par[a]);
    }
    void unite(int a, int b){
        a= findPar(a);
        b= findPar(b);
        if(a!=b){
            if(size[b]>size[a]){
                swap(a,b);
            }
            if(size[a]>=size[b]){
                par[b]=a;
                size[a]+=size[b];
                maxi=max(maxi,size[a]);
            }
        }
    }

};
int32_t main(){
    int n,m;
    cin>>n>>m;
    vector<tuple<int,int>> adj;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj.push_back({a,b});
    }
    DSU ds(n);
    int x=n;
    for(auto [u,v]:adj){
        u= ds.findPar(u);
        v= ds.findPar(v);
        if(u!=v){
            ds.unite(u,v);
            x--;
        }
        cout<<x<<" "<<ds.maxi<<endl;
    }
    return 0;
}