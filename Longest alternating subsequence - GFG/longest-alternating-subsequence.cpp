//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	
	/*
	Dynamic Programming solution(Longest Increasing Subsequence extension)
		int AlternatingaMaxLength(vector<int>&nums){
		    // Code here
		    int n = nums.size();
		    vector<vector<int>> las(n , vector<int> (2 , 1));
		    
		    int res = 1 ;
		    
		    for(int i = 1 ; i < n ; i++){
		        for(int j = 0 ; j < i ; j++){
		            if(nums[j] < nums[i] && las[i][1] < las[j][0] +1 ){
		                las[i][1] = las[j][0] + 1 ;
		            }
		            else if(nums[j] > nums[i] && las[i][0] < las[j][1] + 1){
		                las[i][0] = las[j][1] + 1 ;
		            }
		        }
		        res = max(res , max(las[i][0] , las[i][1]));
		    }
		    return res;
		}
		
		*/
		
		int AlternatingaMaxLength(vector<int>&arr){
		    int inc =1 , dec = 1;
		    int n = arr.size();
		    for(int i = 1 ; i<n ; i++){
		        if(arr[i] > arr[i-1]){
		            inc = dec + 1 ;
		        }
		        else if(arr[i] < arr[i-1]){
		            dec = inc + 1 ;
		        }
		    }
		    return max(inc , dec );
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.AlternatingaMaxLength(nums);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends