class Solution {
public:
    int strStr(string hay, string needle) {
        int n= hay.size();
        int m = needle.size();
        int i=0 , j=0 , k=0;
        while(j<n && k<m){
            // cout<<j<<endl;
            if(hay[j]==needle[k]){
                j++;
                k++;
            }
            else if(hay[j]!=needle[k]){
            // cout<<k<<endl;
                if(i==j){
                    i++;
                    j++;
                }
                else{
                    i++;
                    j=i;
                    k=0;                    
                }
            }
            if(k==m) return i;
        }
        return -1;
    }
};