#include <bits/stdc++.h>
using namespace std;
int dp[500][500];
int cumsum(int arr[],int i,int j){
    int sum=0;
    for(int k=i;k<=j;k++){
        sum+=arr[k];
        sum=sum%100;
    }
    return sum;
}
int solveTheProblem(int arr[],int prefix[],int i,int j){
    if(i>=j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    dp[i][j]=INT_MAX;
    for(int k=i;k<j;k++){
        dp[i][j]=min(dp[i][j],solveTheProblem(arr,prefix,i,k)+solveTheProblem(arr,prefix,k+1,j)+(cumsum(arr,i,k)*cumsum(arr,k+1,j)));
    }
    return dp[i][j];
}
int main() {
    int n;
    while(scanf("%d",&n)!=EOF){
        memset(dp,-1,sizeof dp);
        int arr[n],prefix[n+1]={0};
        // int sum=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            // sum+=arr[i];
            // prefix[i+1]=sum%100; // 1 based indexing
        }
        cout<<solveTheProblem(arr,prefix,0,n-1)<<endl;
    }
    return 0;
}