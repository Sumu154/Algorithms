/*
https://www.spoj.com/problems/FARIDA/en/

1.define state
     Amount(n) -> max amount of coins from 1 to n monstars

2.recursive eqn from smaller sub problem
     Amount(n) = max(Amount(n-1) + 0,
                     Amount(n-2) + Coins(n)
                     )

3.define base case
    Amount(0) = 0

2
5
1 2 3 4 5
1
10

Output
Case 1: 9
Case 2: 10

*/

#include<bits/stdc++.h>
using namespace std;

const int N = 100;
int dp[N];  //n porjonto min cost rakhr jonno
int mons[N];

int main()
{
    int t;
    cin >> t;
    for(int k=1 ; k<=t ; k++){
        int n;
        cin >> n;
        for(int i=1 ; i<=n ; i++)
        {
            cin >> mons[i];
        }

        //1.handle base case
        dp[-1] = 0;
        dp[0] = 0;

        //2.loop through the state and calculate
        for(int i=1 ; i<=n ; i++){
            //2.1.calculate the ans from smaller sub problems
            int ans1 = dp[i-1] + 0;
            int ans2 = dp[i-2] + mons[i];
            int ans = max(ans1, ans2);

             dp[i] = ans;
        }


        cout <<"Case " << k << ": " << dp[n] << "\n";
    }
}