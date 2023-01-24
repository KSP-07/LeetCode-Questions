//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        //ye kitne stocks khride usse count krne ke liye
        int stocks=0;
        
        //price ko pair vec mai leke price ke acc sort krdo , pair isliye kuki ek stock ki limit uski curr index hia
        //to wo bhi chiye hogi limit pata krne ke liye
        
        vector<pair<int,int>> v;
        
        for(int i=0;i<n;i++){
            v.push_back({price[i] , i});
        }
        
        //sort isliye kr rhe ki min stock price wale jada se jada le paay
        sort(v.begin() ,v.end());
        
        //ab bss traverse krke khridari suru
        for(int i=0;i<n;i++){
            int j=v[i].second +1;   //max stock lene ki limit hai ye..means index stock ki original array mai
            while(j>0){   //max kitne le ske se min ki side jaarhe
                if(v[i].first <=k){   //budget dekh rhe le skte ki nhi 
                    stocks++;
                    k-=v[i].first;
                }
                j--;    //le paay ya nhi , limit 0 ki side to move krti jaygi na kuki le lia , to ab limit -1 aur le skte , aur nhi lia to ab limit-1 mai dekhenge
            }
        }
        return stocks;
    }
    
    //ki ith day pe kitne stocks khrid skte,,,different i ki values ke according hoga
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends