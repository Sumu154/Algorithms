/*
https://leetcode.com/problems/house-robber/

1.define state
     Robber(n) -> max amount of money from 1 to n house

2.recursive eqn from smaller sub problem
     Robber(n) = max(Robber(n-1) + 0,
                     Robber(n-2) + house(n)
                     )

3.define base case
    Robber(0) = 0

4
1 2 3 1

output
4

5
2 7 9 3 1

output
12


*/

#include<bits/stdc++.h>
using namespace std;

const int N = 100;
int dp[N];  //n porjonto min cost rakhr jonno
int house[N];

int main()
{
    int n;
    cin >> n;
    for(int i=1 ; i<=n ; i++){
        cin >> house[i];
    }

    //1.handle base case
    dp[-1] = 0;
    dp[0] = 0;

    //2.loop through the state and calculate
    for(int i=1 ; i<=n ; i++){
        //2.1.calculate the ans from smaller sub problems
        int ans1 = dp[i-1] + 0;
        int ans2 = dp[i-2] + house[i];
        int ans = max(ans1, ans2);

         dp[i] = ans;
    }

    cout << dp[n];
}
