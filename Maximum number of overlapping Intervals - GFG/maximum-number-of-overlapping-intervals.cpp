//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
//User function Template for C++
// class Solution{
//     public:
//     //ek vector mai strt interval ko x se store kr rhee , aur end interval lo y se , fir sort krdenge
//     //to ab max x kitne baar ek sath aaya , mtlb kitne interval ek sath aayge kisi ending time ke aane se phle
//     //kuki jab ending time aayga toh fir toh count descrease hone lagega, to ek baar mai maximum kinte conflict kr rhe nikal aayga
//     int overlap(vector<pair<int,int>>intervals, int n){
//       int ans = 0;
//     int count = 0;
//     vector<pair<int, char> > data;
 
//     // storing the x and y
//     // coordinates in data vector
//     for (int i = 0; i < intervals.size(); i++) {
 
//         // pushing the x coordinate
//         data.push_back({ intervals[i].first, 'x' });
 
//         // pushing the y coordinate
//         data.push_back({ intervals[i].second, 'y' });
//     }
 
//     // sorting of ranges
//     sort(data.begin(), data.end());
 
//     // Traverse the data vector to
//     // count number of overlaps
//     for (int i = 0; i < data.size(); i++) {
//         // cout<<data[i].first<<" " <<data[i].second<<endl;
//         // if x occur it means a new range
//         // is added so we increase count
//         if (data[i].second == 'x')
//             count++;
 
//         // if y occur it means a range
//         // is ended so we decrease count
//         if (data[i].second == 'y')
//             count--;
 
//         // updating the value of ans
//         // after every traversal
//         ans = max(ans, count);
//     }
 
//     // printing the maximum value
//     // cout << ans << endl;
//     return ans;
// }
// };


//Map se krne ka tarika

class Solution{
    public:
    int overlap(vector<pair<int,int>>intervals, int n){
        //Write your code here
        map<int, int> m;
        for(auto p : intervals) m[p.first]++, m[p.second+1]--;    //kisika ending time aur begin time same mai conflict na ho isliye ending time ek bdda dia, kuku same hoga to vaise wo overlap nhi krega na
        //aur jaise upr wali approach mai sorting mai end time baad mai consider kr rhe thee uske liye , kuki fir max tkk nhi jayga agr say 5 end time aake -1 hogya aur fir srt mai aaya to 0 hoga sirf
        int ans = 0, s = 0;
        for(auto i : m) {
            s += i.second;
            if(s < 0) s = 0;
            ans = max(ans, s);
        }
        return ans;
    }
};




//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<pair<int,int>>intervals;
	    for(int i = 0; i < n; i++){
	        int a, b;
	        cin >> a >> b;
	        intervals.push_back({a, b});
	    }
	    Solution ob;
	    int ans = ob.overlap(intervals, n);
	    cout << ans <<endl;
	}
	return 0;
}

// } Driver Code Ends