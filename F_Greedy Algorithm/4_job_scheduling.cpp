#include<bits/stdc++.h>
using namespace std;


/*

problem: given n job/task
         with strict deadline(assume each job take one unit time)
         maximum profit you can get

5
100 2
19  1
27  2
25  1
15  1


output -> 2 127 
2 ta task 
profit -> 100+27
 

*/

int main()
{
    int n;
    cin >> n;
    vector<int> dead(n), val(n);
    for(int i=0 ; i<n ; i++){
        cin >> val[i] >> dead[i];
    }

    vector<pair<int,int>> a(n);
    for(int i=0 ; i<n ; i++){
        a[i] = {val[i], dead[i]}; 
    }

    sort(a.begin(), a.end(), [&](auto a, auto b){         //deadline wise sort korbo
        return a.second < b.second;
    });

    priority_queue<int, vector<int>, greater<int>> pq;   //minheap


    int curr = 1;         //current time
    for(int i=0 ; i<n ; i++){
        if(a[i].second >= curr){
            pq.push(a[i].first);
            curr++;
        }
        else{
            if(a[i].first > pq.top()){
                pq.push(a[i].first);
                pq.pop();
            }
        }
    }

    int ans = 0;
    int count = pq.size();
    while(!pq.empty()){
        ans += pq.top();
        pq.pop();
    }

    cout << count << " " << ans << "\n";

}

