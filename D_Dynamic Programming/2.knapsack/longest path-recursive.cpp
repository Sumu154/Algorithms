/*
1.define state:
       LongPath(n) -> longest distance from source to n

2.recursive eqn from smaller sub problem
       LongPath(n) = max({LongPath(p1),LongPath(p2)....LongPath(pm)) + 1
                     where p1 is the immediate parent of dst n

3.define base case
       LongPath(root) = 0


dst -> p1, p2...

4 4
1 3
3 4
1 4
4 2
1 2

output
3


time complexity -> O(V+E)
space complexity -> O(V)

*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<int> parent[N];
int dp[N];
int src, dst;

int LongPath(int dst)
{
    //1.handle base case
    if(dst == src){
        return 0;
    }

    //2.if current state is already solved,return the solved result
    if(dp[dst] != -1){
        return dp[dst];
    }

    //3.calculate the result from smaller sub problem
    int ans = 0;
    for(int i: parent[dst]){
        int dist = LongPath(i);
        ans = max(ans, dist);
    }
 
    dp[dst] = ans+1;
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i=0 ; i<m ; i++){
        int u, v;
        cin >> u >> v;

        parent[v].push_back(u);
    }

    memset(dp, -1, sizeof(dp));

    cin >> src >> dst;
    cout << LongPath(dst) << "\n";

}
