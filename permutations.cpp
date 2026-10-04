#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n==2 || n==3){
        cout<<"NO SOLUTION";
    }
    else{
        int odd=1;
        int even=2;
        while(odd<= n || even<=n){
            if(even<=n){
                cout<<even<<" ";
                even+=2;
            }
            else{
                cout<<odd<<" ";
                odd+=2;
            }
        }
    }
    return 0;
}
