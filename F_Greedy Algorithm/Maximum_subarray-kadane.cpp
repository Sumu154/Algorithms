#include<bits/stdc++.h>
using namespace std;

/*
8
-2 -2 4 -1 -2 1 5 -3

output -> 7

*/

int MaxSum(vector<int> a, int n)
{
    int maxSum = INT_MIN;
    int currSum = 0;

    for(int i=0 ; i<n ; i++){
        currSum += a[i];
        maxSum = max(maxSum, currSum);
        if(currSum<0){
            currSum = 0;
        }
    }
    return maxSum;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
    }

    int ans = MaxSum(a, n);
    cout << ans << "\n";
}
