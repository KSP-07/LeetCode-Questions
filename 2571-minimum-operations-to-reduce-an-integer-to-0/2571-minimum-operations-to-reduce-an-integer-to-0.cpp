class Solution {
public:
    int minOperations(int n) {
        if(n<=0) return 0;
        if(n==1) return 1;
        int x=1 , y=1;
        while(x*2 < n) x*=2;
        
        y = x*2 -n;
        x= n-x;
        int temp = min(x,y);
        return minOperations(temp)+1;
        
    }
};