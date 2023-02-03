class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows == 1) return s;  //base case as if numRows==1 , there will be one column only
        
        int n = s.size();
        
        int sections = ceil ( n/(2*numRows -2.0) );   // each section will have numRowd and numRows-2 chars;
        int numCols = sections * (numRows-1);  //since each section had n-1 columns
        
        vector<vector<char>> matrix(numRows , vector<char>(numCols , ' '));    //creating a 2-D vector for simulating and storing in zigzag form
        
        int currRow =0 , currCol =0;
        int currStringIndex = 0;
        
        //Iterate in zig-zag pattern on matrix and fill it with string characters.
        
        while(currStringIndex < n){
            
            //Move Down
            while(currRow < numRows && currStringIndex< n){
                matrix[currRow][currCol] = s[currStringIndex];
                currRow++;
                currStringIndex++;
            }
            
            currRow-=2;    //since curr row reaches out of bound , we decrease one for that..and one more as to begin diagnolly 
            currCol++;
            
            //move up( with moving right also)
            while(currRow>0 && currCol < numCols && currStringIndex < n){
                matrix[currRow][currCol] = s[currStringIndex];
                currRow--;
                currCol++;
                currStringIndex++;
            }
        }
        
        string answer;
        
        for(auto row:matrix){
            for(auto character:row){
                if(character!=' '){
                    answer+=character;
                }
            }
        }
        
        return answer;
    }
};