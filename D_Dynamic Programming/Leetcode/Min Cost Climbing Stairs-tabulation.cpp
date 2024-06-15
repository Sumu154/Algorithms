/*
https://leetcode.com/problems/min-cost-climbing-stairs/

1.define state:
     stair(cost[], n) -> min cost to climb n stair

2.recursive eqn from smaller sub problem
     Stair(n) = min(Stair(cost[], n-1),
                    Stair(cost[], n-2)
                   )

3.define base case
     Stair(0) = 0
     Stair(1) = 0
     Stair(2) = min(cost[0], cost[1])

*/

#include<bits/stdc++.h>
using namespace std;

const int N = 100;
int dp[N];  //n porjonto min cost rakhr jonno
vector<int> cost(N);

int Stair(int n)
{
    //1.handle base case
    if(n <= 1)
        return 0;
    if(n == 2)
        return min(cost[1], cost[2]);

    //2.if current state is already solved,return the solved result
    if(dp[n] != -1)
        return dp[n];

    //3.calculate the result from smaller sub problem
    int ans1 = Stair(n-1)+cost[n];
    int ans2 = Stair(n-2)+cost[n-1];
    int ans = min(ans1, ans2);

    dp[n] = ans;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    for(int i=1 ; i<=n ; i++){
        cin >> cost[i];
    }

    //1.handle base case
    dp[1] = 0;
    dp[2] = min(cost[1], cost[2]);

    //2.loop through the state and calculate
    for(int i=3 ; i<=n ; i++){
        //2.1.calculate the ans from smaller sub problems
        int ans1 = dp[i-1] + cost[i];
        int ans2 = dp[i-2] + cost[i-1];

        int ans = min(ans1, ans2);
        dp[i] = ans;
    }

    cout << dp[n];
}






