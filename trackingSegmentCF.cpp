#include<bits/stdc++.h>
using namespace std;
bool possible(int numQueries,vector<pair<int,int>>&segments,vector<int>&queries,int arrSize,int numSegments){
    vector<int>arr(arrSize,0);
    for(int i=0;i<numQueries;i++){
        arr[queries[i]]=1;
    }
    vector<int>prefixSum(arrSize);
    prefixSum[0]=arr[0];
    for(int i=1;i<arrSize;i++){
        prefixSum[i]=prefixSum[i-1]+arr[i];
    }
    for(int i=0;i<numSegments;i++){
        int l=segments[i].first;
        int r=segments[i].second;
        int segmentSize=r-l+1;
        int numOnes=prefixSum[r]-(l>0? prefixSum[l-1]:0);
        if(numOnes>segmentSize/2) return true;
    }
    return false;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>> segments(m);
        for(auto &i:segments){
            cin>>i.first>>i.second;
            i.first--;
            i.second--;
        }
        int q;
        cin>>q;
        vector<int> queries(q);
        for(auto &i:queries){
            cin>>i;
            i--;
        }
        int start=0,end=q;
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(possible(mid,segments,queries,n,m)){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        cout<<ans<<endl;
    }
    
}
