#include<bits/stdc++.h>
using namespace std;
bool check(long long target,vector<int> &a,long long n,long long k){
    long long count=0;
    for(int i=0;i<n;i++){
        count=count+floor(target/a[i]);
        if(count>=k) return true;
    }
    return count>=k;
}
int main()
{
    long long n,k;
    cin>>n>>k;
    vector<int> a(n);
    int s=0,e=1e18;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long ans=1e18;
    while(s<=e){
        long long mid=s+(e-s)/2;
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
