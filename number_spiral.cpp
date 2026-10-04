#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long x,y;
        cin>>x>>y;
        long long maxi=max(x,y);
        long long num= maxi*maxi- (maxi-1);
        long long left=1, top=-1;
        long long ans;
        if(maxi%2){
            swap(left,top);
        }
        if(x<maxi){
            ans= num+(maxi-x)*top;
        }
        else if(y<maxi){
            ans=num+(maxi-y)*left;
        }
        else{
            ans=num;
        }
        cout<<ans<<endl;
    }
}