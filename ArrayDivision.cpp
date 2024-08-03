#include<bits/stdc++.h>
using namespace std;
bool check(int target,vector<int> &a,int n,int k){
    int count=1;
    int currSum=0;
    for(int i=0;i<n;i++){
        if(currSum+a[i]>target){
            count++;
            currSum=0;
        }
        currSum+=a[i];
    }
    return count<=k;
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    int s=0,e=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        s=max(s,a[i]);
        e+=a[i];
    }
    int ans=-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(check(mid,a,n,k)){
            ans=mid;
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
