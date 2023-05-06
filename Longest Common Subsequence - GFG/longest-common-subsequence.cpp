//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

// function to find longest common subsequence

class Solution
{
    vector<vector<int>> dp;
    public:
    int func(int x, int y, string s1, string s2){
        if(x==0 || y==0){
            return 0;
        }
        if(dp[x][y]!=-1){
            return dp[x][y];
        }
        else if(s1[x-1]==s2[y-1]){
            return dp[x][y]= 1 +func(x-1,y-1,s1,s2);
        }
        else{
            return dp[x][y]=max(func(x,y-1,s1,s2) , func(x-1,y,s1,s2));
        }
    }
    //Function to find the length of longest common subsequence in two strings.
    /*
    int lcs(int x, int y, string s1, string s2)
    {
        dp.resize(x+1,vector<int>(y+1,-1));
        for(int i=0;i<=x;i++){
            for(int j=0;j<=y;j++){
                if(i==0){
                    dp[i][j]=0;
                }
                else if(j==0){
                    dp[i][j]=0;
                }
                else if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1 + dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        // return func(x,y,s1,s2);
        return dp[x][y];
        */
        // your code here
        int lcs(int x, int y, string text1, string text2)
    {  
        int n1=text1.size(),n2=text2.size();

        vector<int> current(n2+1,0);
        vector<int> next(n2+1,0);

        for(int i=n1-1;i>=0;i--){

            for(int j=n2-1;j>=0;j--){

                int ans=0;
                if(text1[i]==text2[j])
                    ans=1+next[j+1];
                else{                
                    int option1=next[j];
                    int option2=current[j+1];

                    ans=max(option1,option2);
                }

                current[j]=ans;
            }

            next=current;
        }

        return next[0];

        
    }
};

// function to find longest common subsequence




//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends