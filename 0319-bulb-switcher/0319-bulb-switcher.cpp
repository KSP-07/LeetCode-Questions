class Solution {
public:
    int bulbSwitch(int n) {
        if(n<=1) return n;
        if(n==2) return 1;
        long long i=2 , j=1;
        while(i*i <=n){
            i++;
        }
        return i-1;
    }
};