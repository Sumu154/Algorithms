/*
https://docs.google.com/document/d/1zKmlWls-sTuXYfoqcSy-9lyFDghHFH6qj_CHinyiVDI/edit

1.define state
     Operations(n) -> min operations to make 1 from n

2.recursive eqn from smaller sub problem
     Operations(n) = min(1 + operations(n-1),
                         1 + operations(n/2),
                         1 + operations(n/3)
                        )
3.define base case
     operations(1) = 0

11
output
4

*/

#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int dp[N];

int main()
{
    int n;
    cin >> n;

    //1.handle base case
    dp[1] = 0;

    //2.loop through the state and calculate
    for(int i=2 ; i<=n ; i++){
        //2.1.calculate the ans from smaller sub problems
        int ans = 1+dp[i-1];
        if(i%2 == 0)
            ans = min(ans, 1+dp[i/2]);
        if(i%3 == 0)
            ans = min(ans, 1+dp[i/3]);

        dp[i] = ans;
    }

    cout << dp[n];

}
