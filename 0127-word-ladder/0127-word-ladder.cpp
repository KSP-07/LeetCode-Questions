class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
      //using queue for the words and their level
        queue<pair<string,int>> q;
        
        //storing all the words in set for fast access to them
        unordered_set<string> st(wordList.begin() , wordList.end());
        
        //pushing the starting words from where we will begin
        q.push({beginWord , 1});
        
        //since first word is visited we do not want the future word to convert to curr word again
        st.erase(beginWord);
        
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            //agar target word milgya then bs steps return krdena hai
            if(word==endWord){
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
