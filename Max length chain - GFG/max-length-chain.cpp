//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};


// } Driver Code Ends
/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

class Solution{
public:
static bool cmp(struct val p , struct val q){
    return p.second < q.second ;
}
    /*You are required to complete this method*/
    int maxChainLen(struct val p[],int n){
        //Your code here
        sort(p  , p + n , cmp) ;
        int i = 0 , j = 0 , cnt = 1;
        int last = p[0].second;
        while(j<n){
            if(last < p[j].first ){
                cnt++;
                last = p[j].second;
                // i = j; 
            }
            j++;
        }
        return cnt;
    }

    
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		Solution ob;
		cout<<ob.maxChainLen(p,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends