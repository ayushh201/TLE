#include<bits/stdc++.h>
using namespace std;

long double maximumSum(vector<long double>& arr, int d, int n){
    vector<long double> prefix(n);
    prefix[0] = arr[0];
    for(int i = 1; i < n; i++){
        prefix[i] = arr[i] + prefix[i - 1];
    }
    long double ans = -1e18;
    long double minSoFar = 0;
    for(int right = d - 1; right < n; right++){
        long double bestSubarrayEndingHere = prefix[right] - minSoFar;
        minSoFar = min(minSoFar, prefix[right - d + 1]);
        ans = max(ans, bestSubarrayEndingHere);
    }
    return ans;
}

pair<int,int> anySubarrayWithPositiveSum(vector<long double> &arr,int d,int n)
{
    vector<long double> prefix(n);
    prefix[0]=arr[0];
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+arr[i];
    }
    long double ans=-1e18;
    long double minSoFar=0;
    int bestLeft=-1;
    for(int right=d-1;right<n;right++){
        long double bestSubarrayEndingHere=prefix[right]-minSoFar;
        ans=max(ans,bestSubarrayEndingHere);
        if(ans>=0){
            return make_pair(bestLeft+1,right);
        }
        if(minSoFar>prefix[right-d+1]){
            minSoFar=prefix[right-d+1];
            bestLeft=right-d+1;
        }
    }
    return {-1,-1};
}
bool checker(long double x,vector<long double> &arr,int d,int n)
{
    vector<long double> transformedArr(n);
    for(int i=0;i<n;i++){
        transformedArr[i]=arr[i]-x;
    }
    return (maximumSum(transformedArr,d,n)>=0);
}


pair<int,int> bestSubarray(long double x,vector<long double> &arr,int d,int n)
{
    vector<long double> transformedArr(n);
    for(int i=0;i<n;i++){
        transformedArr[i]=arr[i]-x;
    }
    return anySubarrayWithPositiveSum(transformedArr,d,n);
}

void solve()
{
    int n,d;
    cin>>n>>d;
    vector<long double> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    
    long double low=0,high=100;
    int iteration=100;
    for(int i=1;i<=iteration;i++)
    {
        long double mid=low+(high-low)/2;
        if(checker(mid,arr,d,n)){
            low=mid;
        }else{
            high=mid;
        }
    }

    pair<int,int> ans=bestSubarray(low,arr,d,n);
    cout<<ans.first+1<<" "<<ans.second+1<<endl;
}

int main()
{
    solve();
    return 0;
}
