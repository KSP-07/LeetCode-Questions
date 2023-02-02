#include<bits/stdc++.h>
using namespace std;

class graph{
    public:

    unordered_map<int , list<int>> adj; //using map here also can use vector by vecot<vector<int>>


    void addEdge(int u , int v , bool direction){
        //direction = 0 -> undirected
        //direction =1 -> directed

        //create an edge from u to v
        adj[u].push_back(v);

        if(direction==0) adj[v].push_back(u);   //if it's a undirected graph
    }
    //for printin grpah 
    void printAdjList(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<',';
            }
            cout<<endl;
        }
    }
};

int main(){

    int n , m;
    cout<<"Enter the number of Nodes :";
    cin>>n;

    cout<<"Enter the number of edges :";
    cin>>m;

    //creating a grapg using graph class
    graph g;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        //creating an undirected graph
        g.addEdge(u , v , 0);
    }
    cout<<endl;
    //printing graph
    g.printAdjList();
    return 0;
}