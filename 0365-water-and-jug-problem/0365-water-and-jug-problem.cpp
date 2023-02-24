class Solution {
public:
    bool canMeasureWater(int x, int y, int t) {
        //math solution
        if(x+y ==t || x==t || y==t) return true;
        if(x+y<t) return false;
        
        int d = gcd(x, y);
        // cout<<t<<" "<<d<<endl;
        return (t%d==0);
    }
};