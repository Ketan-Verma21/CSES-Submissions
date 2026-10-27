
#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int n,m;
    cin>>n>>m;

    unordered_map<int,vector<int>> adj;

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<pair<int,int>> vis(n+1,{0,0});
    pair<int,int> ans;
    bool check=false;

    for(int start=1; start<=n && !check; start++){
        if(vis[start].first) continue;

        queue<pair<int,int>> q;
        q.push({start,-1});
        vis[start]={start,0};

        while(!q.empty() && !check){
            auto [node,par]=q.front();
            q.pop();

            for(int it:adj[node]){
                if(it==par) continue;

                if(!vis[it].first){
                    vis[it]={node,vis[node].second+1};
                    q.push({it,node});
                }
                else{
                    ans={node,it};
                    check=true;
                    break;
                }
            }
        }
    }

    if(!check){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }

    vector<int> a,b;

    int node1=ans.first, node2=ans.second;
    int l1=vis[node1].second, l2=vis[node2].second;

    if(l2>l1){
        swap(l1,l2);
        swap(node1,node2);
    }

    while(l1>l2){
        a.push_back(node1);
        node1=vis[node1].first;
        l1--;
    }

    while(node1!=node2){
        a.push_back(node1);
        b.push_back(node2);
        node1=vis[node1].first;
        node2=vis[node2].first;
    }

    a.push_back(node1);
    b.push_back(node1);

    reverse(b.begin(),b.end());

    int len=a.size()+b.size();
    cout<<len<<endl;

    for(int node:b) cout<<node<<" ";
    for(int node:a) cout<<node<<" ";

    return 0;
}
