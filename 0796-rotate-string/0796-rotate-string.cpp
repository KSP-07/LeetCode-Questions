class Solution {
public:
    bool rotateString(string s, string goal) {
        int n =s.size();
        int m = goal.size();
        
        if(n!=m) return 0;
        string main = s + s;
        
        int cnt=0;
        cout<<main<<endl<<goal;
        for(int i=0,j=0;i<main.size();i++){
            if(main[i] == goal[j]){
                while(main[i]==goal[j] && j<m ){
                    cnt++;
                    j++;
                    i++;
                }
                j=0;
                if(cnt== m) return true;
                else cnt=0;
                i--;
            }
        }
        return false;
    }
};