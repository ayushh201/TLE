#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll maximumSubarraySum(vector<ll> &arr,int n)
{
    vector<ll> prefixSum(n);
    prefixSum[0]=arr[0];
    for(int i=1;i<n;i++){
        prefixSum[i]=prefixSum[i-1]+arr[i];
    }
    
    ll ans=0;
    ll minimumSoFar=0;
    
    for(int i=0;i<n;i++){
        ll bestSubarrayEndingHere=prefixSum[i]-minimumSoFar;
        minimumSoFar=min(minimumSoFar,prefixSum[i]);
        ans=max(ans,bestSubarrayEndingHere);
    }
    return ans;
}

void solve()
{
    int n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    ll result=maximumSubarraySum(arr,n);
    cout<<result<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
