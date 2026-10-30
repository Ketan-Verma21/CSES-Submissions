#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> ans;
int findKans(int node, int k){
    for (int i = 0; i <=30; i++) {
        
        if (k & (1LL << i)) {
            node = ans[node][i];
        }
    }
    return node;
}
int32_t main(){
    int n,q;
    cin>>n>>q;
    ans.resize(n+1,vector<int>(31));
    for(int i=1;i<n+1;i++){
        int a;
        cin>>a;
        ans[i][0]=a;
    }
    for(int j=1;j<=30;j++){
        for(int i=1;i<n+1;i++){
            ans[i][j]=ans[ans[i][j-1]][j-1];
        }
    }
    for(int i=0;i<q;i++){
        int node,k;
        cin>>node>>k;
        int anc= findKans(node,k);
        cout<<anc<<endl;
    }

    return 0;
}