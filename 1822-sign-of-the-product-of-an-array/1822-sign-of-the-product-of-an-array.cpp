class Solution {
public:
    int arraySign(vector<int>& nums) {
        int pos = 0 , neg = 0 ;
        for(auto i: nums){
            if(i==0) return 0;
            if(i < 0) neg++;
            else pos++;
        }
        if(neg&1) return -1;
        else return 1;
    }
};