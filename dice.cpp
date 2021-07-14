#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(){
    int T;
    cin>>T;
    while(T--){
        lli n;
        cin>>n;
        lli sum=0;
        sum=(n/4) * 44;
        int rem= n%4;
        if(n>=4){
            if(rem==0){
                sum+=16;
            }
            if(rem==1){
                sum+=32;
            }
            if(rem==2){
                sum+=44;
            }
            if(rem==3){
                sum+=55;
            }
            cout<<sum<<endl;
        }
        else{
             int t;
             if(rem==1){
                 t=20;
             }
             if(rem==2){
                 t=36;
             }
             if(rem==3){
                 t=51;
             }
             cout<<t<<endl;
        }
    }

    return 0;
}