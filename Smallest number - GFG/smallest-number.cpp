//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int S, int D){
        // code here 
        if(9*D < S) return "-1";    //ex for 4 digits...max sum can only be 36 by nums 9 9 9 9
        
        string ans="";
        //last se iterate krenge , aur agr sum 9 se bada hai toh last mai ek 9 krdia..kuki max element last mai krdenge to sum min hojayga
        for(int i=D-1;i>=0;i--){
            if(S>9){
                ans='9' + ans;
                S-=9;
            }else{
                if(i==0){
                    //ab agr first pe aagy to bcha hua sum leke ans bann jayga
                    ans = to_string(S) + ans;
                }
                else{
                    //ab agr num 9 se kaam hai aur abi slots hai enter krne ke liye
                    //toh fir to sum bacha hai , uss se ek bcha lenge suru mai rkne ke liye aur baki 
                    //cur slot pe rkh denge aur first slot tkk 0's
                    ans=to_string(S-1) + ans;
                    i--;
                    
                    while(i>0){
                        ans = '0' + ans;
                        i--;
                    }
                    ans = '1' + ans;
                    break;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends