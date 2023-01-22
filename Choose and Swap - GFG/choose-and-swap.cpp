//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    string chooseandswap(string a){
        // Code Here
        set<char> s;
        for(auto x:a) s.insert(x);
        for(int i=0;i<a.size();i++){
            s.erase(a[i]);     //cur elememt set se hata de rhe...to wo kabi smallest mai count nhi hoga...
            if(s.empty()) break;   //agr set empty hai to break hii krdenge..kuki ab replace kisi se krne ke liye hai hii nhi koi
            char small = *s.begin();   //abb smallest char miljayga 
            if(small < a[i]){
                char ch=a[i];
                for(int j=0;j<a.size();j++){
                    if(a[j]==small) a[j]=ch;    //agr char smallest ke equal hua to req replace krne wale char se replace kr rhe
                    else if(a[j]==ch) a[j]=small;  //agr curr char replace krne wale char ke equal hai toh usse smallest se replace kr rhe
                }
                break;    //agr pehla element set ka smallest nhi toh koi nhi hoga..isliye break krdenge
            }
        }
        return a;
    }
    
}; 


//{ Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}

// } Driver Code Ends