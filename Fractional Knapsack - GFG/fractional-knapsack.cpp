//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

// struct cmp{
//     public:
//     bool operator()(Item a , Item b){
//         return (a.value/a.weight) > (b.value/b.weight);
//     }
// };

class Solution
{
    public:
    static bool cmp(Item a , Item b){
        return ((double)a.value/(double)a.weight) > ((double)b.value/(double)b.weight);
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        double wt=0;    //weight that is taken till now
        double profit=0;    //profit made till now;

        sort(arr , arr+n , cmp);   //sorting in desc order of p by w to get max value first
        for(int i=0;i<n;i++){
            if(wt>=W) break;
            if(wt<W){
                if(wt+ arr[i].weight< W){   //agr new weight add krke bhi kam hai to direct lia
                    profit+= (arr[i].value);   //adding profit directly as we can take it full
                    wt+=arr[i].weight;  //weight of current item is also added now
                }
                else{
                    //ab naye item ko todke lena pdega , aur double isliye kuki ITEM val aur weight int tha
                    profit+= ((double)arr[i].value/(double)arr[i].weight *( W -wt));    //weight ka jitna diff hoga usta hii add kr skte profit
                    // break;   //ab bag full to fayda nhi aage dekhne kaa
                    wt+=(W-wt);
                }
            }
        }
        return profit;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends