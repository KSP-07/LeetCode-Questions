//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
//using bfs to optimize the brute force as level wise we can get the min steps
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        
        //using queue for the words and their level
        queue<pair<string,int>> q;
        
        //storing all the words in set for fast access to them
        unordered_set<string> st(wordList.begin() , wordList.end());
        
        //pushing the starting words from where we will begin
        q.push({startWord , 1});
        
        //since first word is visited we do not want the future word to convert to curr word again
        st.erase(startWord);
        
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            //agar target word milgya then bs steps return krdena hai
            if(word==targetWord){
                return steps;
            }
            
            //ab target word nhi mila toh fir curr word ke ek char ko pkad ke modify krenge agr word , wordlist mai hoga to usse check krne ke loye queue mai
            //aur sab krne ke baad(word ke ek char ko a to z modify krne ke baad) uska ko char pe work kr rhe the
            //usse waps original pe kr rhe kuki ab durse index ka char ko modify krna hai..aur ek baar mai ek hi change kr skte to phla wala original hona mangta
            for(int i=0;i<word.size();i++){
                char original = word[i];
                
                for(char ch ='a'; ch<='z';ch++){
                    word[i]=ch;
                    
                    //if new word exist in the set
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word , steps+1});
                    }
                }
                word[i]= original;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends