#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
vector<vector<char>> grid;
vector<vector<int>> vis;
bool check(int i, int j){
    return i>=0 && i<n && j>=0 && j<m && grid[i][j]!='#' && vis[i][j]==0;
}
int32_t main(){
    
    cin>>n>>m;
    grid.resize(n,vector<char>(m));
    queue<tuple<int, int, string>> qf, qb;
    bool b_check=false;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            if(grid[i][j]=='A') qf.push({i,j,""});
            if(grid[i][j]=='B') b_check=true;
        }
    }
    if(!b_check){
        cout<<"NO"<<endl;
        return 0;
    }
    vector<pair<int,int>> dir={{-1,0},{0,-1},{1,0},{0,1}};
    map<int, char> point = {
    {0, 'U'},
    {1, 'L'},
    {2, 'D'},
    {3, 'R'}
};
    vis.resize(n,vector<int>(m,0));
    auto [a,b,_]=qf.front();
    vis[a][b]=1;
    while(!qf.empty()){
        auto [i,j,str]= qf.front();
        qf.pop();
        if(grid[i][j]=='B'){
            cout<<"YES"<<endl;
            cout<<str.length()<<endl;
            cout<<str<<endl;
            return 0;
        }
        for(int k=0;k<4;k++){
            int new_i= i+dir[k].first;
            int new_j= j+dir[k].second;
            if(check(new_i,new_j)){
                vis[new_i][new_j]=1;
                qf.push({new_i,new_j,str+point[k]});
            }

        }
    }
    cout<<"NO"<<endl;
    return 0;
}