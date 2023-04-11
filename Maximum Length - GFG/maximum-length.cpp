//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int solve(int a, int b, int c) {
        // code here
        // int n = 6;
        // priority_queue<pair<int,char>> pq;
        // pq.push({a , 'a'});
        // pq.push({b ,'b'});
        // pq.push({c , 'c' });
        // int len = 0;
        // while(pq.size() >1){
        //     auto i = pq.top() ; pq.pop();
        //     int num1 = i.first;
        //     auto j =  pq.top() ; pq.pop();
        //     int num2 = j.first;
            
        //     if(num1>=2){
        //         len+=2;
        //         num1-=2;
        //     }
        //     else{
        //         len+= abs(0-num1);
        //         num1=0;
        //     }
        //     if(num2>=2){
        //         len+=2;
        //         num2-=2;
        //     }
        //     else{
        //         len+= abs(0-num2);
        //         num2=0;
        //     }
        //     // cout<<num1<<" "<<num2<<endl;
        //     if(num1>0) pq.push({num1 , i.second});
        //     if(num2>0) pq.push({num2 , j.second});
        //     // n--;
        //     // if(n==0) break;
        // }
        // if(pq.top().first >=3) return -1;
        // else if(!pq.empty()) len += pq.top().first;
        // return len;
        
        if((a > (b+c+1)*2) || (b > (c+a+1)*2)  || ( c >(a+b+1)*2)) return -1;
        return a+b+c;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;

        Solution ob;
        int ans = ob.solve(a, b, c);
     

        cout <<  ans << "\n";
    }
    return 0;
}
// } Driver Code Ends