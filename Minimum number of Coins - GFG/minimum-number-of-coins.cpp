//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        // code here
        vector<int> deno(10);
        deno[0]=2000;
        deno[1]=500;
        deno[2]=200;
        deno[3]=100;
        deno[4]=50;
        deno[5]=20;
        deno[6]=10;
        deno[7]=5;
        deno[8]=2;
        deno[9]=1;
        
        vector<int> ans;
          for(int i=0;i<10;i++){   //itne hi notes hai use krne ko
            while(N>=deno[i]){    //agr curr val curr note ke equal sa bddi h , to note use kr skte
               int val=deno[i];
               ans.push_back(val);
                N=N-val;
            }
          }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends