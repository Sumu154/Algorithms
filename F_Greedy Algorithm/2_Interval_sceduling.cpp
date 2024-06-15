#include<bits/stdc++.h>
using namespace std;

/*
problem: given n activity
         start and end time
         maximum event you can participate

3                                  
10 20                           10__________20
12 15                             12___15
20 30                                      20_________30

output -> 2


*/

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a;
    for(int i=0 ; i<n ; i++){
        int st, en;
        cin >> st >> en;
        a.push_back({st, en});  
    }
    sort(a.begin(), a.end(), [&](auto &u, auto &v){
        return u.second < v.second;
    });

    int count = 1;
    int end = a[0].second;
    for(int i=1 ; i<n ; i++){
        if(a[i].first >= end){
            count++;
            end = a[i].second;
        }
    }
    cout << count << "\n";
}