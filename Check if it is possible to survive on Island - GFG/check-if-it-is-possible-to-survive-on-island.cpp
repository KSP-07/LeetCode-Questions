//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimumDays(int S, int N, int M){
        // code here,
        
        int x = S/7;    //storing sundays that will come
        int y = S-x;    //storing number of days that food can be bought
        
        int req_food = S*M;  //the total food that will be required
        int days = req_food/N;   //the days food had to be bought to survive
        if(req_food%N != 0) days++;   //agr req food , ek din  ki khrid se jada hai toh ek aur din lena pdega
        if(days<=y) return days;
        return -1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}
// } Driver Code Ends