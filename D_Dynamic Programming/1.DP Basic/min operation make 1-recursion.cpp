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

int Operations(int n)
{
    //1.handle base case
    if(n == 1)
        return 0;

    //2.if current state is already solved,return the solved result
    if(dp[n] != -1)
        return dp[n];

    //3.calculate the result from smaller sub problem
    int ans = 1+Operations(n-1);
    if(n%2 == 0)
        ans = min(ans, 1+Operations(n/2));
    if(n%3 == 0)
        ans = min(ans, 1+Operations(n/3));

    dp[n] = ans;
    return ans;
}

int main()
{
    int n;
    cin >> n;

    for(int i=1 ; i<=n ; i++){
        dp[i] = -1;
    }

    cout << Operations(n);
}


