class Solution {
public:
    //using bfs algo..
//stored the initial color of src , then from that node visited all childs and marked the newcolor if they had inital same

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        
        int N = image.size();
        int M=image[0].size();
        
        //visted array so we donot visit one coordinate again and again 
        vector<vector<int>> vis(N , vector<int>(M,0));
        
        //storing all possible movements form current coordinates
        int xmove[] = { 1 , -1 , 0 , 0};
        int ymove[] = { 0 ,  0 , 1 ,-1};
        
        //using pair q for x and y coordinate and pushing inital cor and also marking it visited
        queue<pair<int ,int>> q;
        q.push({sr , sc});
        vis[sr][sc]=1;
        
        int in_colour=image[sr][sc];  //storing initail color so that we could always compare the color then update new if had same
        
        //classic bfs traversal
        while(!q.empty()){
            auto it= q.front();
            q.pop();
            
            int x=it.first;
            int y= it.second;
            
            //updating curr coordinates with new color as they were pushed in queue coz they had the req conditions met
            image[x][y]=newColor;
            
            //since, i can move in 4 directions and to avoid writing it manually , i made xmove ymove array that has all 4 possible
            //movements, thus simply using loop to check the new coordinates 
            for(int i=0;i<4;i++){
                int nx = x + xmove[i];
                int ny = y + ymove[i];
                
                //these are the conditions that must be true to get the new color
                if(nx>=0 && ny>=0 && nx<N && ny<M && !vis[nx][ny] && image[nx][ny]==in_colour ){
                    image[nx][ny]=newColor;
                    q.push({nx , ny});
                    vis[nx][ny]=1;
                }
                
            }
        }
        return image;
    }
};