#include<bits/stdc++.h>
using namespace std;
bool checker(double t,vector<pair<double,double>>&people){
    pair<double,double> curr={-1e18,1e18};
    for(auto i:people){
        double x=i.first;
        double speed=i.second;
        pair<double,double>range={x-speed*t,x+speed*t};
        curr={max(curr.first,range.first),min(curr.second,range.second)};
        if(curr.first>curr.second) return false;
    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    vector<pair<double,double>>people(n);
    for(int i=0;i<n;i++) cin>>people[i].first>>people[i].second;
    double left=0,right=1e9;
    for(int iteration=0;iteration<60;iteration++){
        double mid=(left+right)/2;
        if(checker(mid,people)){
            right=mid;
        }else{
            left=mid;
        }
    }
    cout<<setprecision(7)<<fixed<<right<<endl;
}
