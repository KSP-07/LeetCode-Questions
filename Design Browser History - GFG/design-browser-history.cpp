//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class BrowserHistory {
    vector<string> visUrl;
    int currUrl , lastUrl;
public:
     // constructor to initialize object with homepage
    BrowserHistory(string homepage) {
        visUrl.push_back(homepage);
        currUrl = 0;
        lastUrl = 0;
    }
    
    // visit current url
    void visit(string url) {
        currUrl+=1;
        if(visUrl.size()>currUrl){
            visUrl[currUrl] =url;
        }
        else{
            visUrl.push_back(url);
        }
        lastUrl = currUrl;
    }
    
    // 'steps' move backward in history and return current page
    string back(int steps) {
        currUrl = max(0 , currUrl - steps);
        return visUrl[currUrl];
    }
    
    // 'steps' move forward and return current page
    string forward(int steps) {
        currUrl = min(lastUrl , steps+ currUrl);
        return visUrl[currUrl];
    }
};

//{ Driver Code Starts.

int main()
{
    string homepage;
    cin >> homepage;
    
    BrowserHistory obj(homepage);
    
    int total_queries;
    cin >> total_queries;
    while(total_queries--)
    {
        int query;
        cin >> query;
        
        // if query = 1, visit()
        // if query = 2, back()
        // if query = 3, forward()
        
        if(query == 1) {
            string url;
            cin >> url;
            obj.visit(url);
        }
        else if(query == 2) {
            int steps;
            cin >> steps;
            cout << obj.back(steps) << endl;
        }
        else {
            int steps;
            cin >> steps;
            cout << obj.forward(steps) << endl;
        }
    }
    return 0;
}
// } Driver Code Ends