//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
//last element ko del krke dekhte jayge palindrome aara ki nhi - O(n^2)
//last element se first equal nhi aaya toh fir i waps 0 se krdenge , to hrr baar alag se check nhi krna pdega
    int addMinChar(string str){    
        int n =  str.size();
        int i = 0 , j = n-1;
        
        int last_index = n-1;
        while(i<=j){
            if(str[i] == str[j]){
                i++;
                j--;
            }
            else{
                last_index--;
                i = 0;
                j = last_index;
            }
        }
        int ans = n-1 - last_index;    //suru mai dono equal the...fir last index utna move kr jayga jitna wo front se eqaul nhi hua
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
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends