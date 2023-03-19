//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
  //using greedy approach
  //ek element pe khde hoke dekh lenge ki waha se kaha tkk jaaskte , aur jaake max dekh lenge uske aage ka , 
  //fir jab ek baar reach khtm hojaygi toh fir max wali jump laga denge
    int minJumps(int arr[], int n){
        // Your code here
        //base case
        if(arr[0]==0 && n>1) return -1;
        int currmove = arr[0];
        int maxMove = currmove;
        int steps = 1;
        for(int i=1 ; i< n-1; i++){
            currmove--;
            maxMove = max(maxMove , arr[i] + i);
            if(currmove == 0) {
                currmove = maxMove - i; //ab itna aage aur move kr sktee
                if(currmove <= 0) return -1;   // agar 0 aata hai as a element then  , maxmove -i 0 hoskta ya -ve , iska mtlb ab move nhi kr skte
                steps++;
            }
        }
        return steps;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends