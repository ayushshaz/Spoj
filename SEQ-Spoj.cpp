#include <bits/stdc++.h>
using namespace std;
#define mod 1000000000
#define ll long long int
void print_matrix(vector<vector<ll> > matrix){
     for(int i=1;i<=matrix.size()-1;i++){
            for(int j=1;j<=matrix[i].size()-1;j++){
              cout<<matrix[i][j]<<"   ";
            }
            cout<<endl;
        }
}
vector<vector<ll>> multiply(vector<vector<ll>> &matrix1, vector<vector<ll>> &matrix2){
    vector<vector<ll> > result(matrix1.size(),vector<ll>(matrix1[1].size())); 
     for(int i=1;i<=matrix1[1].size()-1;i++){
            for(int j=1;j<=matrix2.size()-1;j++){
              for(int k=1;k<=matrix1[1].size()-1;k++){
                  result[i][j]+=((matrix1[i][k]%mod)*(matrix2[k][j]%mod))%mod;
              }
            }
        }
    return result;
}
vector<vector<ll>> exponential_power(vector<vector<ll>> &matrix,int n){
    if(n==1){
        return matrix;
    }
    vector<vector<ll>> mult=exponential_power(matrix,n/2);
     mult=multiply(mult,mult);
    if(n&1){
       mult=multiply(mult,matrix);
    }
    return mult;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        vector<ll> b(k+1);
        for(int i=1;i<=k;i++){
            cin>>b[i];
        }
        vector<int> c(k+1);
        for(int i=1;i<=k;i++){
           cin>>c[i];
        }
        int n;
        cin>>n;
        //create a transformation matrix 
        vector<vector<ll>> transformation(k+1,vector<ll>(k+1));
        for(int i=1;i<=k;i++){
            for(int j=1;j<=k;j++){
                if(i==k){
                    transformation[i][j]=c[k-j+1];
                    continue;
                }
                if(j==i+1){
                    transformation[i][j]=1;
                }else{
                    transformation[i][j]=0; 
                }
            }
        }
      // print_matrix(transformation);
       vector<vector<ll>> expo;
       expo=exponential_power(transformation,n-1);
      //    print_matrix(expo);

      ll ans=0;
      for(int i=1;i<=k;i++){
          ans+=(expo[1][i]*b[i])%mod;
      }
      cout<<ans%mod<<endl;
     //per test case   
    }   
    return 0;
}