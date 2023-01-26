#include<bits/stdc++.h>
using namespace std;


//basically hum ye kr rhee...ki x axis aur y axis mai, tower ka gap nikal le rhee aur fir max gap leke multiply kr denge
//bamm ans aajayga
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int w , h , n;
        cin>>w>>h>>n;

        vector<int> co1 , co2;
        co1.push_back(0);
        co1.push_back(w+1);
        co2.push_back(0);
        co2.push_back(h+1);
        for(int i=0;i<n;i++){
            int x , y;
            cin>> x>>y;
            co1.push_back(x);
            co2.push_back(y);
        }
        sort(co1.begin() , co1.end());
        sort(co2.begin() , co2.end());

        int maxi1=0 , maxi2=0;
        
        for(int i=1;i<co1.size();i++){
            maxi1 = max(maxi1 , (co1[i]-co1[i-1] -1));   //-1 coz at ith pos tower will be placed
            maxi2 = max(maxi2 , (co2[i]-co2[i-1] -1));   //-1 coz at ith pos tower will be placed
        }

        cout<<maxi1*maxi2<<endl;
    }
}