//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         // Code here
         
         stack<pair<int , int >> stk ;
         
         sort(intervals.begin() , intervals.end()) ;
         
         int n = intervals.size() ;
         
         for (int i = 0 ; i < n ; i++ ) {
             if ( stk.empty() || stk.top().second < intervals[i][0]) {
                 stk.push( {intervals[i][0] , intervals[i][1]} ) ;
             }
             else {
                 auto it = stk.top() ; stk.pop() ;
                 
                 stk.push( { it.first , max(it.second , intervals[i][1]) }) ;
             }
         }
         
         vector<vector<int>> ans(stk.size() , vector<int> (2)) ;
        
        for (int i = stk.size()-1 ; i>=0 ; i-- ){
            auto it = stk.top() ; stk.pop();
            
            ans[i][0] = it.first ;
            ans[i][1] = it.second ;
        }
        return ans ;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends