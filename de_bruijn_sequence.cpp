#include<bits/stdc++.h>
using namespace std;
#define int long long
unordered_map<int,vector<tuple<int,char,int>>> adj;
int n;
int code;
vector<int> vis;
int mod;
string ans="";
vector<int> path;
void make_graph(int i){
    int a, b;
    a= (i*2+1)%mod;
    b= (i*2+0)% mod;
    adj[i].push_back({a,'1',code});
    adj[i].push_back({b,'0',code+1});
    code+=2;
}
void dfs(int node,char cc){
    while(!adj[node].empty()){
        auto [it,c,code]= adj[node].back();
        adj[node].pop_back();
        
        dfs(it,c);
    }
    
    ans.push_back(cc);
}
int32_t main(){
    int n;
    cin>>n;
    code=0;
    if(n==0){
        cout<<""<<endl;
        return 0;
    }
   
    int num= 1LL* (pow(2LL,n));
    mod= 1LL* (pow(2,n-1));
    for(int i=0;i<num;i++){
        make_graph(i);
    }
    
    dfs(0,'0');
    ans.pop_back();
    for(int i=0;i<n-1;i++){
        ans.push_back('0');
    }
    cout<<ans<<endl;
    cout<<endl;
}