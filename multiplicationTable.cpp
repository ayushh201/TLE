#include<bits/stdc++.h>
using namespace std;
long long n;
long long check(long long val){
    long long cnt=0;
    for(int i=1;i<=n;i++){
        cnt+=min(n,val/i);
    }
    return cnt;
}
int main()
{
    cin>>n;
    long long target=n*n/2 +1;
    long long l=0,r=n*n+1,ans=r;
    while(l<=r){
        long long mid=l+(r-l)/2;
        if(check(mid)>=target){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
