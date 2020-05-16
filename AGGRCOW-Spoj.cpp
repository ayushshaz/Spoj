#include<bits/stdc++.h>
using namespace std;
#define ll long long
int ans=1e9;
bool arrangementExist(int stalls[],int n,int cow,int space){
    cow--;
    int prev=0;
    for(int i=1;i<n;i++){
        if(stalls[i]-stalls[prev]>=space){
            cow--;
            prev=i;
        }
    }
    if(cow<=0){
        return true;
    }
    return false;
}
void arrangeCows(int stalls[],int n,int cow){
    int range=stalls[n-1]-stalls[0];
    int s=0;
    int e=range;
    while(s<=e){
        int mid=(s+e)>>1;
        if(arrangementExist(stalls,n,cow,mid)){
            ans=mid;
            s=mid+1;
        }else{
            e=mid-1;
        }
    }
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n,cow;
        cin>>n>>cow;
        int stalls[n];
        for(int i=0;i<n;i++){
            cin>>stalls[i];
        }
        sort(stalls,stalls+n);
        arrangeCows(stalls,n,cow);
        cout<<ans<<endl;
        ans=1e9;
    }    
    return 0;
}