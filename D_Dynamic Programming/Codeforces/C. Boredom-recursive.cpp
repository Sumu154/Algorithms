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

const int N = 2e6+5;
long long dp[N];
long long counted[N];   //kon value koita ace oitar count array

long long Points(int n)
{
    //1.handle base case
    if(n <= 0)
        return 0;


    //2.if current state is already solved,return the solved result
    if(dp[n] != -1)
        return dp[n];

    //3.calculate the result from smaller sub problem
    long long take = counted[n]*n + Points(n-2);
    long long avoid = Points(n-1);
    long long ans = max(take, avoid);

    dp[n] = ans;
    return ans;
}

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

    for(int i=1 ; i<=maxi ; i++){
        dp[i] = -1;
    }

    cout << Points(maxi);
}

