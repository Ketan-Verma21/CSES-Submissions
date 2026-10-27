#include<bits/stdc++.h>
using namespace std;
#define int long long 
class DSU{
    public:
    vector<int> par, rank;
    DSU(int n): par(n), rank(n,0){
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }
    int findParent(int i){
        if(par[i]==i) return i;
        return par[i]= findParent(par[i]);
    }
    void unite(int i, int j){
        i= findParent(i);
        j= findParent(j);
        if(i!=j){
            if(rank[i]>=rank[j]){
                par[j]=i;
                rank[i]++;
            }
            else{
                par[i]=j;
                rank[j]++;
            }
        }
    }
};
int32_t main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        edges.push_back({a,b});
    }
    DSU ds(n+1);
    for(vector<int> it:edges){
        ds.unite(it[0],it[1]);
    }
    vector<tuple<int,int>> ans;
    for(int i=1;i<n;i++){
        int a= i;
        int b=i+1;
        a= ds.findParent(a);
        b= ds.findParent(b);
        if(a!=b){
            ans.push_back({a,b});
            ds.unite(a,b);
        }
    }
    cout<<ans.size()<<endl;
    if(ans.size()!=0){
        for(auto [a,b]:ans){
            cout<<a<<" "<<b<<endl;
        }
    }
    return 0;
}