/*
1.define state:
       stone(n) -> cost of reaching n-th stone from 1st one

2.eqn from smaller sub problem
     stone(i) = min (stone(i-1) + abs(h[i]-h[i-1]),
                     stone(i-2) + abs(h[i]-h[i-2])
                    )
3.define base case
     stone(1) = 0

dp[i] -> i stone e ashte min cost koto

4
10 30 40 20

output
30     <=|10-30|+|30-20|

*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int h[N];
int dp[N];


int main()
{
    int n;
    cin >> n;
    for(int i=1 ; i<=n ; i++){
        cin >> h[i];
    }

    //1.handle base case
    dp[1] = 0;

    //2.loop through the state and calculate
    for(int i=2 ; i<=n ; i++){
        //2.1.calculate the ans from smaller sub problems
        int ans1 = dp[i-1] + abs(h[i]-h[i-1]);
        if(i==2){
            dp[i] = ans1;
            continue;
        }
        int ans2 = dp[i-2] + abs(h[i]-h[i-2]);
        dp[i] = min(ans1, ans2);
    }

    cout << dp[n] << "\n";


}
