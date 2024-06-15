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
3

*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<int> parent_list[N];
int dp[N];

int LongPath(int node)
{
    //1.handle base case
    if(parent_list[node].empty())
        return 0;

    //2.if current state is already solved,return the solved result
    if(dp[node] != -1)
        return dp[node];

    //3.calculate the result from smaller sub problem
    int ans = 0;
    for(int i:parent_list[node]){
        int dist = LongPath(i);
        ans = max(ans, dist);
    }
    ans++;
    dp[node] = ans;
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i=0 ; i<m ; i++){
        int u, v;
        cin >> u >> v;

        parent_list[v].push_back(u);
    }

    memset(dp, -1, sizeof(dp));

    int longest_path = 0;
    for(int i=1 ; i<=n ; i++){
        longest_path = max(longest_path, LongPath(i));
    }

    cout << longest_path;
}
