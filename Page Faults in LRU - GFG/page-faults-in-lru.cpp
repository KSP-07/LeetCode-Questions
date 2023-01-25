//{ Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pageFaults(int n, int c, int pages[]){
        // code here
        unordered_set<int> s;    //memory size le rhee hai isme unique hi aayge hmesa , same aane pe add hua to frk nhi pdega
        unordered_map<int,int>mp; //element and its index, so that we can know the lru
        
        int pgfaults=0;
        
        
        for(int i=0;i<n;i++){
            //memory ki capacity jitni dii hue hai
            if(s.size()<c){
                
                if(s.find(pages[i])==s.end()){
                    
                    pgfaults++;   //suru mai jab page koi hoga hi nhi memory mai to page fault to hoge hii
                    s.insert(pages[i]);   //ab element ko memory mai le gyy
                    
                }
                // mp[pages[i]]=i; ye krna hiii hai hmesa toh last mai krdenge
            }
            else{   //mtlb memory full hai , to ab dekhna hai ki naya element phle se hai ya ni
                //ab lru algo use krna pdega agr page present nhi hai
            
                if(s.find(pages[i])==s.end()){
                    
                    pgfaults++;    //nhi mila hai to page fault to increase hoga re baba
                    
                    int lru=INT_MAX;   //min index nikal lenge...min index uska hoga jo phle aaya hoga...aur isse ab recently used banan hoga khali
                    int val=0;   //isme wo element daalenge jisko memory se hatan hai
                    
                    //set pe traverse krke dekhenge kiska index min hai
                    for(auto x:s){
                        if(mp[x] < lru){
                            lru=mp[x];
                            val=x;
                        }
                    }
                    s.erase(val);
                    s.insert(pages[i]);   //ab naya jo chiye wo mem mai leke jaarhe hai baba
                    // mp[pages[i]]=i;   //ab mem mai leke gaye toh uska index bhi update krne ko mangta hai re baba
                }
               
            }
            mp[pages[i]]=i;    //ye hrr baar update hoga kuki naya page aayga aur purana hua toh usse recent bnana hoga
        }
        return pgfaults;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}
// } Driver Code Ends