//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      static bool cmp(pair<int,pair <int,int>>a, pair<int,pair <int,int>>b){

      if(a.first==b.first) return a.second.first <b.second.first;   //agar do meet ka end time same hai toh start time jiska phle ho wo krlenge

        return a.first < b.first;

    }
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        
        vector<pair<int,pair<int ,int>>> v;
        for(int i=0;i<N;i++){
            v.push_back({{F[i]} ,{S[i] ,i+1}});   //ending time , aur start time with index ka pair of pair bana liaa
        }
        sort(v.begin() , v.end(),cmp);  //custom sort krdia end time ke acc , aur 
        
        //sbse phle khtm hone wali meet phle krlerhe
        vector<int> ans;
        ans.push_back(v[0].second.second);
        int endTime=v[0].first;
        
        //then first meet ke endtime se next meet compare krke...agr next wali ka tym baad mai hoga to wo leke endtime ab curr meet ke acc krdenge
        for(int i=1;i<N;i++){
            if(v[i].second.first >endTime){
                ans.push_back(v[i].second.second);
                endTime=v[i].first;
            }
        }
        
        sort(ans.begin() ,ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends