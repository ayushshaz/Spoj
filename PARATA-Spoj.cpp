#include<bits/stdc++.h>
using namespace std;
bool ParathaBana(int rank[],int l,int minute,int paratha){
    int totalParatha=0;
    for(int i=0;i<l;i++){
        int currentRank=rank[i];
        int time=0;
        int currentParatha=0;
        int k=1;
        while(time<=minute){
            time+=k*currentRank;
            currentParatha++;
            k++;
        }
        currentParatha--;
        totalParatha+=currentParatha;
        if(totalParatha>=paratha){
            return true;
        }
    }
    return false;
}
int main() {
    int t;
    cin>>t;
    while(t--){
            int paratha;
            cin>>paratha;
            int l;
            cin>>l;
            int rank[l];
            for(int i=0;i<l;i++) cin>>rank[i];
            int ans=1e8;
            int left=0,right=ans;
            while(left<=right){
                int mid=(left+right)/2;
                if(ParathaBana(rank,l,mid,paratha)){
                    ans=mid;
                    right=mid-1;
                }else{
                    left=mid+1;
                }
            }
            cout<<ans<<endl;
    }
    return 0;
}