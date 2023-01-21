//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    static bool cmp(Job a , Job b){
        return a.profit>b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        
        //arr ko uske profit ke according sort kr rhe kuki max profit phle lena hai
        sort(arr , arr+n , cmp);
        
        //ek array lerhe slots ki..kitne jobs le sktee hai
        bool done[n]={0};
        
        //total kitni jobs krii aur profit kitna mila
        int jobs=0 , profit=0;
        
        //array pe iterate kr rhee for n
        for(int i=0;i<n;i++){
            //yaha pe j hum min lerhe n aur deadline mai kuki...deadline for ex 9 bhi hoskti..n sirf 5 hua...
            //mtlb 9 wala aram se wait kr skta...pr slot to usko n ke size ke ander hii miljayga
            //hum deadline ki max timing se 0th slot ki side chlke dekh rhe kuki for ex 2 thi deadline
            //toh usko 2nd slot pe rkhdia...taaki first pe aur koi aa ske jiski deadline kam ho
            for(int j= min(n , arr[i].dead -1);j>=0;j--){
                if(done[j]==false){
                    jobs+=1;
                    profit+=arr[i].profit;
                    done[j]=true;    //slot milte hii true krke return krdenge
                    break;
                }
            }
        }
        return {jobs, profit};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends