/*
https://codeforces.com/contest/456/problem/C

1.define state
     Amount(n) -> max amount of coins from 1 to n array

2.recursive eqn from smaller sub problem
     Amount(n) = max(counted[n]*n + Points(n-2);,
                     Points(n-1)
                     )

3.define base case
    POints[0] = 0

9
1 2 1 3 2 2 2 2 3

output
10

*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1e7;
long long dp[N];
long long counted[N];   //kon value koita ace oitar count array

int main()
{
    int n;
    cin >> n;

    long long maxi = 0;
    for(int i=1 ; i<=n ; i++){
        long long a;
        cin >> a;
        counted[a]++;

        maxi = max(maxi, a);  //given arrayr max = maxi
    }

    //1.handle base case
    dp[-1] = 0;
    dp[0] = 0;

    //2.loop through the state and calculate
    for(int i=1 ; i<=maxi ; i++){
        //2.1.calculate the ans from smaller sub problems
        long long take = counted[i]*i + dp[i-2];
        long long avoid = dp[i-1];

        long long ans = max(take, avoid);
        dp[i] = ans;
    }

    cout << dp[maxi];
}
