#include<bits/stdc++.h>
using namespace std;

int MinSum(vector<int> a, int n)
{
    int minSum = a[0];
    int currSum = a[0];

    for(int i=1 ; i<n ; i++){
        currSum += a[i];
        minSum = min(minSum, currSum);
        if(currSum>0){
            currSum = 0;
        }
    }
    return minSum;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
    }

    int ans = MinSum(a, n);
    cout << ans << "\n";
}
