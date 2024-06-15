/*
https://atcoder.jp/contests/dp/tasks/dp_g

1.define state:
       LongPath(n) -> longest distance from source to n

2.recursive eqn from smaller sub problem
       LongPath(n) = max({LongPath(p1),LongPath(p2)....LongPath(pm)) + 1
                     where p1 is the immediate parent of node n

3.define base case
       LongPath(root) = 0

6 3
2 3
4 5
5 6

output
2

*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<int> parent_list[N];
int dp[N];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i=0 ; i<m ; i++){
        int u, v;
        cin >> u >> v;

        parent_list[v].push_back(u);
    }

    memset(dp, 0, sizeof(dp));

    //1.handle base case
    dp[1] = 1;

     //2.loop through the state and calculate
     int longest_path = 0;
     for(int i=1 ; i<=n ; i++){
        //2.1.calculate the ans from smaller sub problems
        for(int j:parent_list[i])
        {
            dp[i] = max(dp[i], dp[j]++);
        }
        longest_path = max(longest_path, dp[i]);
    }

    cout << longest_path;



}

