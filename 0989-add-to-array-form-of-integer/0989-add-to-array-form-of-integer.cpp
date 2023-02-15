class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        if(k==0) return num;
        int n= num.size();
        int i=n-1 ;
        int carry =0;
        vector<int> ans;
        
        while(i>=0 || k>0 || carry){
            int sum = carry;
            if(k>0) {
                int remainder = k%10;
                
                sum+= remainder;
                
                k/=10;
            }
            if(i>=0){
                sum  += num[i];
            }
            carry = sum/10;
            ans.push_back(sum%10);
            i--;
            
        }
        reverse(ans.begin() ,ans.end());
        return ans;
    }
};