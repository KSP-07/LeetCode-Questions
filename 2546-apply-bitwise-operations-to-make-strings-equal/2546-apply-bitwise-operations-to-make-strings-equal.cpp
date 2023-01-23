/*We can change 1 to 0 and 0 to 1 if there is at least one 1 in the string:

we cannot make a string to be all zeros (one 1 will remain).
we cannot modify all-zeros string.
Therefore, we can make s into any t, providing both s and t contain at least one 1.

An edge case is when both s and t are all-zeros.
*/

class Solution {
public:
    bool makeStringsEqual(string s, string target) {
       int oneIns=0;
        int oneInt=0;
        for(auto x:s) oneIns+=(x-'0');    //since string is onyly binary , it will count 1
        for(auto x:target) oneInt+=(x-'0');
        if(oneIns >0 && oneInt>0 || (oneIns==oneInt)) return true;
        return false;
        
        /* above code in one line
        
        return (count(begin(s), end(s), '1') > 0) == (count(begin(t), end(t), '1') > 0);
        */
    }
};