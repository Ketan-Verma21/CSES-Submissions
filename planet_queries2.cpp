#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> par;
vector<int> len;
vector<int> vis;

int dfs(int node){
    if(len[node]!=-1) return len[node];
    if(vis[node]){
        return 0;
    }
    vis[node]=1;
    len[node]=dfs(par[node][0])+1;
    return len[node];
}
int findKanc(int node, int k){
    if(k<0) return -1;
    for(int i=0;i<=30;i++){
        if(k & (1LL<<i)){
            node= par[node][i];
        }
    }
    return node;
}
int32_t main(){
    int n,q;
    cin>>n>>q;
    par.resize(n+1,vector<int>(31));
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        par[i][0]=a;
    }
    for(int j=1;j<31;j++){
        for(int i=1;i<=n;i++){
            par[i][j]=par[par[i][j-1]][j-1];
        }
    }
    len.resize(n+1,-1);
    vis.resize(n+1,0);
    for(int i=1;i<n+1;i++){
        if(!vis[i]){
            dfs(i);
        }
    }

    for(int i=0;i<q;i++){
        int node1, node2;
        cin>>node1>>node2;
        int cycle_entry_point= findKanc(node1,len[node1]);
        if(findKanc(node1,(len[node1]-len[node2]))==node2){// if both nodes are in line
            cout<<(len[node1]-len[node2])<<endl;
        }
        else if(findKanc(cycle_entry_point, (len[cycle_entry_point]-len[node2]))==node2){// if both nodes are in cycle
            cout<<(len[cycle_entry_point]-len[node2]+len[node1])<<endl;
        }
        else if (len[node1]<len[node2] && cycle_entry_point==node2){ // this is for if the whole graph is cycle
            cout<<len[node1]<<endl;
        } 
        else{
            cout<<-1<<endl;
        }
    }

    return 0;
}