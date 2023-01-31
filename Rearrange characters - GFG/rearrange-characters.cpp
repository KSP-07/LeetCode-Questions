//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

// } Driver Code Ends
class Solution
{
    public:
    
    //idea is to fill the string with most frquent letter first
    string rearrangeString(string str)
    {
        //code here
        unordered_map<char,int> mp;   //for storing frequency of characters
        for(auto i:str) mp[i]++;
        
        priority_queue<pair<int,char>> pq;    //pq of pair type, max heap coz first we will fill the most frequent ones to check overflow
        
        for(auto i:mp){
            pq.push({i.second , i.first});
        }
        
        int even =0 , odd =1 ;    //indexes to work upon from start
        int n=str.length();
        
        int index=even;   // index is the index where letters will get inserted
        if(pq.top().first > (n+1)/2) return "-1";   //edge case
        while(!pq.empty()){
            int count=pq.top().first;
            char c= pq.top().second;
            pq.pop();
            while(count--){
                if(index >=n) index=odd;   //fill krte krte last element pe pahuch gy ya bhr to ab odd se fill krna suru krna hai
                str[index]=c;
                index+=2;
            }
        }
        return str;
    }
    
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution ob;
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}
// } Driver Code Ends