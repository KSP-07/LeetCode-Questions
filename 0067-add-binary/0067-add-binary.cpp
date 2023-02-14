class Solution {
public:
    string addBinary(string a, string b) {
        int n=a.size()-1;
        int m = b.size()-1 ;
        
        string ans= "" ;
        int carry=0;
        
        while(n>=0 || m >=0){
            int sum = carry;
            
            if(n>=0) sum += a[n--] - '0';   //taking it as int to perform action on it
            if(m>=0) sum +=b[m--] -'0';
            
            carry = sum > 1 ? 1 : 0;
            // getting carry depend on the quotient we get by dividing sum / 2 that will be our carry. Carry could be either 1 or 0 
			// if sum is 0 res is 1 & then carry would be 0;
            // if sum is 1 res is 1 & carry would be 0
            // if sum is 2 res is 0 & carry would be 1
            // if sum is 3 res is 1 & carry would be 1
            
            ans+= to_string(sum%2);  // just moduling the sum so, we can get remainder and add it into our result
        }
        
        if(carry) ans+=to_string(carry);
        
        reverse(ans.begin() , ans.end());
        
        return ans;
    }
};