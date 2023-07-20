//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        int cele = -1;
        for(int i = 0 ; i < n ; i++ ) {
            bool flag = true;
            
            for(int j = 0 ; j < n ; j++ ){
                if(i!=j && M[i][j] == 1 ) flag = false;   //for rows
                
                if(i!= j && M[j][i] == 0 ) flag = false;   //for cols
                
                if(!flag) break;
            }
            if(flag) cele = i;
            
            // for(int j )
        }
        
        // for(auto i : mp ){
        //     cout<<i.first<<" "<<i.second<<endl;
        //     if(i.second != n-1){
        //         mp[i.first] = 0;
        //         break;
        //     }
        //     for (int j = 0 ; j < n ; j++ ){
        //         if(M[i.first][j] == 1 ){
        //             mp[i.first] = 0;
        //             break;
        //         }
        //     }
        // }
        // // int cnt = 0;
        // for(auto i :mp ){
        //     if(i.second  > 0 ) return i.first;
        // }
        return cele ;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends