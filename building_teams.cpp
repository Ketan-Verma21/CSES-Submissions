#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t main(){
    int n,m;
    cin>>n>>m;
    unordered_map<int,vector<int>> adj;
    vector<int> color(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    map<int,int> opp={{1,2},{2,1}};
    for(int i=1;i<=n;i++){
        if(!color[i]){
            color[i]=1;
            queue<tuple<int,int>> q;
            q.push({i,1});
            while(!q.empty()){
                auto [node, col]= q.front();
                q.pop();
                for(int it:adj[node]){
                    if(color[it]==0){
                        color[it]=opp[col];
                        q.push({it,color[it]});
                    }
                    else if(color[it]!=0 && color[it]==col){
                        cout<<"IMPOSSIBLE"<<endl;
                        return 0;
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<color[i]<<" ";
    }
    cout<<endl;
    return 0;
}