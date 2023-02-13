class Solution {
public:
    int countOdds(int low, int high) {
       if (low== high && low&1) return 1;
        int cnt=0;
        
        if(low&1 || high&1){
            cnt = (high -low)/2 +1;
        }
        else cnt = (high -low)/2;
        
        return cnt;
    }
};