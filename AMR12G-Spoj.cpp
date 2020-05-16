#include <bits/stdc++.h>
using namespace std;

bool comparator(pair<int,int> a,pair<int,int> b){
    if(a.second>b.second){
        return true;
    }
    return false;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        char a[n][m];
        vector<pair<int,int>> count(n);
        
        for(int i=0;i<n;i++){
            //for every row have a count on and off
            int on=0;
            for(int j=0;j<m;j++){
                cin>>a[i][j];
                if(a[i][j]=='*'){
                    on++;
                }
            }//one row finish
            count[i].first=on;
            count[i].second=m-on;
        }
        sort(count.begin(),count.end(),comparator);
        int mid=m/2;
        int need_to_reverse=0;
        for(int i=0;i<n;i++){
            if(count[i].first>mid){
                break;
            }
            need_to_reverse++;
        }
        //Time to take care of k
        if(k<need_to_reverse){
            for(int i=0;i<k;i++){
                swap(count[i].first,count[i].second);
            }
        }else{
            for(int i=0;i<n;i++){
                if(count[i].second>count[i].first){
                    swap(count[i].first,count[i].second);
                }
            }
            sort(count.begin(),count.end(),comparator);
            int remain=k-need_to_reverse;
            remain=remain%2;
            if(remain==1){
                swap(count[0].first,count[0].second);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=count[i].first;
        }
        cout<<ans<<endl;
    }
    return 0;
}