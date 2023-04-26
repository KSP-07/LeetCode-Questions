class Solution {
public:
    int addDigits(int number) {
        
        int n=0, num = number;
        while(num){
            int x = num%10;
            n+=x;
            num/=10;
            if(!num) {
                num = n;
                if(num==number) return num;
                number=n;
                n=0;
            }
            // if(n < 10) return n;
        }
        return 0;
    }
};