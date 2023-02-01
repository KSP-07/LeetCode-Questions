class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        
        if(str1 + str2 != str2+ str1) return "";   //kisi bhi side se concatenate krne pe same aaygi tbbi to wo kisi string ki multiple hogi
        
        //getting GCD of the two length
        int gcdLength = gcd(str1.size() , str2.size());
        return str1.substr(0 , gcdLength);
    }
};