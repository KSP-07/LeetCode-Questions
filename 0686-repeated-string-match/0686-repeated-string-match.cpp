class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n = a.size();
        int m = b.size();
        
        int x = m / n ;
        string s = a;
        int cnt=1;
        //looping till x +1 because , even string b is not evenly distributed, we will need one more to match it
        for(int i = 0 ; i<=x+1;i++){
            
            if( s.find( b ) != string::npos ){   //this is something new look into it
                return cnt;
            }
            s+=a;
            cnt++;
        }
        return -1;
    }
};


// class Solution{
    
//     public:
    
//     void lps(vector<int> &vec , int n , string b){
//         unordered_map<char, int> mp;
        
//         for(int i=0; i < n ; i++){
//             if(mp.find(b[i]) == mp.end()) {
//                 vec.push_back(0);
//             }
//             else{
//                 vec.push_back(mp[b[i]]);
//             }
//             mp[b[i]]=i+1;            
//         }
            
//     }
    
//     int repeatedStringMatch(string a, string b){
//         int n = b.size();
//         vector<int> vec(n,0);
//         lps(vec , n ,b);
        
//         // for(auto i: vec){
//         //     cout<< i <<" ";
//         // }
        
//         return 0;
//     }
// };