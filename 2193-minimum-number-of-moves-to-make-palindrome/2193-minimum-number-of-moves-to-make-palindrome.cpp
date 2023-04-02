class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n = s.size();
        int ans =0;
        int left=0 , right = n-1;
        while(left < right){
            int l=left , r =right;
            while(s[l]!=s[r]) r--;
            if(l==r){
                //odd case
                swap(s[r] , s[r+1]);
                ans++;
                continue;
            }
            else{
                //normal element
                while(r <right){
                    ans++;
                    swap(s[r] , s[r+1]);
                    r++;
                }
            }
            left++; right--;
        }
        return ans;
    }
};