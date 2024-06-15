#include<bits/stdc++.h>
using namespace std;

/*
12 
0 0
1 -4
-1 -5
-5 -3
-3 -1
-1 -3
-2 -2
-1 -1
-2 -1
-1 1

*/

pair<int,int> mid;


vector<pair<int,int>> merger(vector<pair<int,int>> a, vector<pair<int,int>> b)
{
    int n1 = a.size();
    int n2 = b.size();

    int ia=0, ib=0;
    for(int i=1 ; i<n1 ; i++){
        
    }
}



vector<pair<int,int>> bruteHull(vector<pair<int,int>> a)
{
    set<pair<int,int>> s;
    for(int i=0 ; i<a.size() ; i++){
        for(int j=i+1 ; j<a.size() ; j++){
            int x1 = a[i].first;
            int y1 = a[i].second;

            int x2 = a[j].first;
            int y2 = a[j].second;

            int delX = x2-x1;
            int delY = y2-y1;
            int c = x1*y2 - y1*x2;

            int pos=0, neg=0;
            for(int k=0 ; k<a.size() ; k++){
                if(delY*a[k].first + delX*a[k].second + c  <=  0){
                    neg++;
                }
                if(delY*a[k].first + delX*a[k].second + c  >=  0){
                    pos++;
                }
            }

            if(pos==a.size() or neg==a.size()){
                s.insert(a[i]);
                s.insert(a[j]);
            }
        }
    }

    vector<pair<int,int>> ret;
    for(auto i: s){
        ret.push_back(i);
    }

    mid = {0,0};
    int n = ret.size();
    for(int i=0 ; i<n ; i++){
        mid.first += ret[i].first;
        mid.second += ret[i].second;

        ret[i].first *= n;
        ret[i].second *= n;
    }

    sort(ret.begin(), ret.end());
    for(int i=0 ; i<n ; i++){
        ret[i] = {ret[i].first/n, ret[i].second/n};
    }

    return ret;
}

vector<pair<int,int>> Solve(vector<pair<int,int>> a)
{
    if(a.size() < 6){
        return bruteHull(a);
    }

    
}


int main()
{
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    for(int i=0 ; i<n ; i++){
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end());
    vector<pair<int,int>> ans = Solve(a);

    for(auto i: ans){
        cout << i.first << " " << i.second << "\n";
    }

}

