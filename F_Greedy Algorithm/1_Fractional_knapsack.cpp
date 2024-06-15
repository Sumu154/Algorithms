#include<bits/stdc++.h>
using namespace std;

/*
problem: given n products with profits.
         can take fractional value
         what is maximum profit


3 8
3 30
4 50
5 60

output -> 98


*/


int main()
{
    int n, cap;
    cin >> n >> cap;
    vector<int> wt(n), val(n);
    for(int i=0 ; i<n ; i++){
        cin >> wt[i] >> val[i];    
    }

    vector<pair<int,int>> a(n);
    for(int i=0 ; i<n ; i++){
        a[i] = {wt[i],val[i]};
    }

    sort(a.begin(), a.end(), [&](auto a, auto b){        //sort korlam heighest fraction wise               
        double v1 = (double)a.second/a.first;            //jar profit/weight beshi shei wise  
        double v2 = (double)b.second/b.first;

         return v1>v2;
    });

    int ans = 0;
    for(int i=0 ; i<n ; i++){
        if(cap >= a[i].first){
            ans += a[i].second;
            cap -= a[i].first;
        }
        else{
            double extra = (double)a[i].second/a[i].first;
            ans += extra*cap;        //cap erpor 0 hoye jabe
            //cap = 0;
            break;
        }
    }

    cout << ans << "\n";
}

