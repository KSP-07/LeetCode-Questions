//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool is_possible_to_get_seats(int n, int m, vector<int>& seats){
        // Write your code here.
        if(m==1){
            if(seats[0] == 0) return (1>=n);
            else return (0>=n);
        }
        int cnt = 0;
        for(int i = 0 ; i<m; i++){
            if(seats[i] == 1){
                i++;
                continue;
            }
            bool flag = 0;
            if(i-1 < 0 && ( seats[i] == 0 && seats[i + 1] == 0)){
                cnt++;
                seats[i] =1;
                continue;
            }
            if(i+1 >=m && (seats[i] == 0 && seats[i - 1] == 0)){
                cnt++;
                seats[i] =1;
                continue;
            }
            
            if(seats[i-1] == 0 && seats[i+1]==0 && seats[i] == 0) {
                cnt++;
                seats[i] =1;
                continue;
            }
        }
        // cout<<cnt<<endl;
        return (cnt>=n);
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<int> seats(m);
        for (int i = 0; i < m; i++) {
            cin >> seats[i];
        }
        Solution obj;
        if (obj.is_possible_to_get_seats(n, m, seats)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}

// } Driver Code Ends