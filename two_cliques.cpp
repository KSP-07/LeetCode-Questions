#include<bits/stdc++.h>
using namespace std;

int f=0;
void bipartite(int src, int par , int col , vector<int>&color ,vector<int> g[]){
    color[src]=col;
    for(auto x: g[src]){
        if(!color[x]){
            bipartite(x , src , 3-col , color , g);   //3-col krne se 1-2 mai hii rhega col
        }
        else if(x!=par and col == color[x]){
            f=1;
            break;
        }
    }
}

void solve(){
    int v ,e;
    cin>>v>>e;
    vector<int> g[v];

    //making a graph here(adj list)
    for(int i=0; i<e;i++){
        int x , y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    //creating a reverse graph
    vector<int> reverse[v];
    vector<int> dummy(v ,0);
    for(int i=0;i<v;i++){
        //jitne log connected thee curr node seunhe 1 kr rhee dummy mai , taaki hum 0 wale ko curr node ke adj bana sake
        dummy[i] =1;
        for(auto x: g[i]){
            dummy[x] =1;
        }
        for(int j=0; j<v;j++){
            if(dummy[j]==0){
                reverse[i].push_back(j);
                reverse[j].push_back(i);
            }
        }
        dummy.clear();
    }

    vector<int> color(v,0);
    bipartite(0 , 0 , 1 , color , reverse);
    if(!f) cout<<"Two Clique";
    else cout<<"Not Possible";
}