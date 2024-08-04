#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long w,h,n;
    cin>>w>>h>>n;
    long long left=1, right=1e18;
    long long ans=1e18;
    while(left<=right)
    {
        long long mid=(left+right)/2;
        long long rows=mid/h;
        long long cols=mid/w;
        if(cols>0 && rows>=(n+cols-1)/cols){
            ans=min(ans,mid);
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    cout<<ans<<endl;
}
