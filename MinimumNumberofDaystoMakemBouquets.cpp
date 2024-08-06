class Solution {
public:
    bool possible(vector<int>& arr,int day,int m,int k){
        int cnt=0,noOfB=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=day){
                cnt++;
            }
            else{
                noOfB+=(cnt/k);
                cnt=0;
            }
        }
        noOfB+=(cnt/k);
        return (noOfB>=m);
    }
    int minDays(vector<int>& arr, int r, int b) {
        int n=arr.size();
        long long val = r*1LL*b*1LL;
        if(val>n) return -1;
        int mini=INT_MAX, maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[i]);
            mini=min(mini,arr[i]);
        }
        int low=mini,high=maxi;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(arr,mid,r,b)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
