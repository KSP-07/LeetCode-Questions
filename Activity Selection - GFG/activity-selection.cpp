//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<pair<int,int>> v;
        
        //adding end time and start time as a pair , with end time as first
        for(int i=0;i<n;i++){
            v.push_back({end[i] , start[i]});
        }
        
        //sorting on the basis of first(end time)...as it would help us to check the next starting time of meeting
        sort(v.begin() , v.end());
        
        int end_time=v[0].first;      //counting and taking end time of first meeting  
        int count=1;
        
        //now will iterate in for n intervals and check that which meet has starting time greater than first , so it could be taken
        //jo meet sbse jada time legi wo last mai shift ho cuhki hogi sortine ke baad..to ab choti time ki meet aage hai
        //end time update kr denge jab koi new meet aaygi toh
        for(int i=1;i<n;i++){
            if(end_time < v[i].second){
                count++;
                end_time=v[i].first;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends