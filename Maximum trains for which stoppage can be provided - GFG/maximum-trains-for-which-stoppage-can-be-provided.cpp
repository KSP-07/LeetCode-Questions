//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends
class Solution {
  public:
    int maxStop(int n, int m, vector<vector<int>> &trains) {
        // code here
        vector<int>platform(n+1,0);
        vector<pair<int,int>> v;
        
        for(int i=0;i<trains.size();i++){
            //   cout<<t[i][1]<<" "<<i<<endl;
            v.push_back({trains[i][1],i});   //ye departure time aur array ki index leli train vector ki
        }
        sort(v.begin(),v.end());
        int ans=0;
        
        for(int i=0;i<v.size();i++){
           // t[v[i].second][2] ye platform number bata raha hai..departure ke according ab index bhi aayge...[2] se platform milra aur t wale se index
           //agar let's say x platform ki value..mtlb departure time , ab curr element ke arrival se kam hai ya equal..to new aa skti train
           //0->arrival , 1->departure , 2->platform
            if(platform[trains[v[i].second][2]] <=trains[v[i].second][0]){   //v[i].second v vec ka second part yani index hai
                //   cout<<plat[t[v[i].second][2]]<<" "<<t[v[i].second][2]<<" "<<t[v[i].second][0]<<endl;
                ans++;
                platform[trains[v[i].second][2]] = v[i].first;  //departure time insert kr rhee platform number pe ab new train ka
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> trains(m, vector<int>(3));
        Matrix::input(trains,m,3);
        
        Solution obj;
        int res = obj.maxStop(n, m, trains);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends