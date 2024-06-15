/*
1.define state:
       fun(n, x) -> maximum happiness till day n
                    if we pick task x on day n

2.recursive eqn from smaller sub problem
     fun(n, x) = max(fun(n-1, y)+happiness[n][x]    where x!=y

3.define base case
     fun(1, x) = happiness(1, x)

3
10 40 70
20 50 80
30 60 90


output
210     <=70+50+90

*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int h[N][4];
int dp[N][4];

int Solve(int n, int x)    //n = day...x = task no
{
    //1.handle base case
    if(n==1){
        return h[n][x];
    }

    //2.if current state is already solved,return the solved result
    if(dp[n][x] != -1){
        return dp[n][x];
    }

    int max_profit = 0;

    //3.calculate the result from smaller sub problem
    for(int i=1 ; i<=3 ; i++){
        if(i != x){
            int candidate_profit = Solve(n-1, i) + h[n][x];
            max_profit = max(max_profit, candidate_profit);
        }
    }

    dp[n][x] = max_profit;
    return max_profit;
}

int main()
{
    int n;
    cin >> n;
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=3 ; j++){
            cin >> h[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    int ans1 = Solve(n, 1);
    int ans2 = Solve(n, 2);
    int ans3 = Solve(n, 3);

    cout << max({ans1, ans2, ans3});

}

