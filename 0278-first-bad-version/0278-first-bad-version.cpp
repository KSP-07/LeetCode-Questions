// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low=1,high=n;
        int mid= low +(high -low)/2;
        while(low<=high){
            if(isBadVersion(mid)){
                if(isBadVersion(mid-1)){
                    high=mid-1;
                    mid= low +(high -low)/2;
                }
                else return mid;
            }
            else{
                low=mid+1;
                mid= low +(high -low)/2;
            }
        }
        return -1;
        
    }
};