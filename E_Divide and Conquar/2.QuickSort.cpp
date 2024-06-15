#include<bits/stdc++.h>
using namespace std;

vector<int> QuickSort(vector<int> a)
{
    //base case
    if(a.size() <= 1){
        return a;
    }

    int pivot= rand()%(a.size());
    vector<int> b;
    vector<int> c;

    for(int i=0 ; i<a.size() ; i++){
        if(i == pivot){
            continue;
        }
        else if(a[i] < a[pivot]){
            b.push_back(a[i]);
        }
        else{
            c.push_back(a[i]);
        }
    }

    vector<int> sorted_b= QuickSort(b);
    vector<int> sorted_c= QuickSort(c);
    vector<int> sorted_a;

    for(int i=0 ; i<sorted_b.size() ; i++){
        sorted_a.push_back(sorted_b[i]);
    }
    sorted_a.push_back(a[pivot]);
    for(int i=0 ; i<sorted_c.size() ; i++){
        sorted_a.push_back(sorted_c[i]);
    }

    return sorted_a;
}

int main()
{
    vector<int> a = {5, 7, 3, 8, 10, 34, 1, 0, 7};
    vector<int> sorted_a = QuickSort(a);
    for(int i=0 ; i<a.size() ; i++){
        cout << sorted_a[i] << " ";
    }  
}