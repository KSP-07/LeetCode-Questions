/* stack approach
// class BrowserHistory {
//     stack<string> history , future;
//     string current;
// public:
//     BrowserHistory(string homepage) {
//         //homepage is the first visited url
//         current = homepage;
//     }
    
//     void visit(string url) {
//         //pushing 'current' in history stack and mark 'url' as 'current'
//         history.push(current);
//         current = url;
//         //we need to delete all entries from 'future' stack
//         future = stack<string>();
//     }
    
//     string back(int steps) {
//         //poping elements from 'history' stack , and push elements in 'future' stack
//         while(steps>0 && !history.empty()){
//             future.push(current);
//             current = history.top();
//             history.pop();
//             steps--;
//         }
//         return current;
//     }
    
//     string forward(int steps) {
//         //pop elements from future stack and push elements in history stack
        
//         while(steps>0 && !future.empty()){
//             history.push(current);
//             current = future.top();
//             future.pop();
//             steps--;
//         }
//         return current;
//     }
// };

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

/* dynamic array approach */
class BrowserHistory {
vector<string> visitedURLs;
    int currUrl , lastUrl;
public:
    BrowserHistory(string homepage) {
        //'homepage' is the first visited url
        visitedURLs.push_back(homepage);
        currUrl =0;
        lastUrl =0;
    }
    
    void visit(string url) {
        currUrl+=1;
        if(visitedURLs.size() > currUrl){
            //we have enough space in our array to overwrite an old 'url' entry with new one
            visitedURLs[currUrl] = url;
        }
        else{
            //we have to insert a new 'url' entry at the end
            visitedURLs.push_back(url);
        }
        //this 'url' will be last url if we try to go forward
        lastUrl = currUrl;
    }
    
    string back(int steps) {
        //move 'currURL' pointer in left direction
        currUrl = max(0 , currUrl-steps);   //by this we reduced back traversal time
        return visitedURLs[currUrl];
    }
    
    string forward(int steps) {
        //move 'currUrl' pointer in right direction
        currUrl= min(lastUrl , currUrl + steps);
        return visitedURLs[currUrl];
    }
};


