#include<bits/stdc++.h>
using namespace std;

#define ll long long

/*
problem: given n slots
         start and end time
         minimum hall/room to held slots


3
0 5
1 3 
1 10
output -> 3

3
1 3                ____
2 4                  ____
3 5                    ______
output -> 2

3
1 2
2 4
4 6


*/

int main()
{
    int n;
    cin >> n;
    vector<int> st(n), en(n);
    for(int i=0 ; i<n ; i++){
        cin >> st[i] >> en[i];
    }

    vector<pair<int,int>> a;
    for(int i=0 ; i<n ; i++){
        a.push_back({st[i], 1});        // Start of interval
        a.push_back({en[i], -1});       // End of interval
    }
    cout << a.size() << "\n";

    sort(a.begin(), a.end());

    int ans=0, sum=0;
    for(int i=0 ; i<n ; i++){
        sum += a[i].second;            // Update the count of overlapping intervals
        ans = max(ans, sum);
    }

    cout << ans << "\n";

}

