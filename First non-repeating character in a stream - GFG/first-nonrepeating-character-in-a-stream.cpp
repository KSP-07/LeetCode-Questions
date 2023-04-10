//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	
	//isme basicaly ye dekhna ki agr koi naya character aaya wo immediate purane se same hai to fir jitni ans string hogi , 
	//usme se wo phla character le aayga jiski count 1 ho
	// aur jo nhi mila koi to 3 lgane hai , aur counter ke liye repeat hone wala aaya to badhana hai nhi toh fir uska hii phla 0 mil jayga
		string FirstNonRepeating(string A){
		    // Code here
		    vector<int> vis(26,0);
		    vector<char> v;
		    
		    int n = A.size();
		    
		    string ans = "";
		    
		    for(int i = 0 ; i < n ;i++){
		        if(!vis[A[i] - 'a']) v.push_back(A[i]);
		        vis[A[i] -'a']++;
		        
		        int f = 0 ;
		        int m = v.size();
		        for(int j =0 ; j<m; j++){
		            if(vis[v[j] - 'a'] == 1){
		                ans.push_back(v[j]);
		                f=1;
		                break;
		            }
		        }
		        if(f==0) ans.push_back('#');
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends