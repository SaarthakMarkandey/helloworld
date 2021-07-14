#include <iostream>
#include <array>
#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

lli fun( vector <vector<lli>> matrix,lli N,lli M,lli K,lli order){
    lli count=0;
    while(order< N+1){
        lli i=order,j=M;
        while(i<N+1){
            lli x=i-order+1,y=j-order+1;
            lli z=matrix[i][j]-matrix[x-1][j]-matrix[i][y-1]+matrix[x-1][y-1];
            if(z<(K*order*order)){
                i+=1;
            }
            else{
                lli start =order,ans;
                lli end=M;
                while(start<=end){
                    lli mid=(start+end)/2;
                    x=i-order+1;
                    y=mid-order+1;
                    z=matrix[i][mid]-matrix[x-1][mid]-matrix[i][y-1]+matrix[x-1][y-1];
                    if(z<(K*order*order)){
                        start = mid+1;

                    }
                    else{
                        ans=mid;
                        end=mid-1;
                    }
                }
                count+=M-ans+1;
                i+=1;

            }
        }
        order+=1;

    }
    matrix.clear();
    return count;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        lli N,M,K,in;
        cin>>N>>M>>K;
        // lli arr[N][M];lli sum[N][M];
        // vector<vector<lli>> arr;
        vector<vector<lli>> sum;
        vector<lli> v;
        for(int i=0;i<=M;i++){
            v.push_back(0);
        }
        sum.push_back(v);
        for(int i=0;i<N;i++){
            //  vector<lli> v1;
             vector<lli> v2;
             v2.push_back(0);
            for(int j=0;j<M;j++){
                cin>>in;
                // v1.push_back(in);
                v2.push_back(in);
            }
            // arr.push_back(v1);
            sum.push_back(v2);
        }
        for(int i=2;i<=M;i++){
            for(int j=1;j<=N;j++){
                sum[j][i]+=sum[j][i-1];
            }
        }
        for(int i=2;i<=N;i++){
            for(int j=1;j<=M;j++){
                sum[i][j]+=sum[i-1][j];
            }
        }
        for(int i=0;i<=N;i++){
            for(int j=0;j<=M;j++){
                cout<<sum[i][j];
                //sum[i][j]=arr[i][j];
            }
            cout<<endl;
        }
        lli ans =fun(sum,N,M,K,1);
        cout<<ans<<endl;
        sum.clear();
    }
    return 0;
}