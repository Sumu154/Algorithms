#include<bits/stdc++.h>
using namespace std;


/*
6
a 5
b 9
c 12
d 13
e 16
f 45

output -> 
f: 0   
c: 100 
d: 101 
a: 1100
b: 1101
e: 111


*/

//huffman tree formation er code
class node{
public:
    char data;
    int freq;
    node* left;
    node* right;

    node(char data, int freq){
        this->data = data;
        this-> freq = freq;
        left = NULL;
        right = NULL;
    }
};




void printCode(node* root, string s)
{
    if(!root){
        return;
    }
    if(root->data != '$'){
        cout << root->data << ": " << s << "\n";
    }

    printCode(root->left, s+"0");
    printCode(root->right, s+"1");
}

//custom comparator function
class comp{                                   //comp function diye minheap emnvabe create korlam jate
public:                                       //jar freq kom she opore thakbe and age extract hbe
    bool operator()(node* l, node* r){
        return l->freq > r->freq;
    }
};

void HuffmanCode(vector<char> a, vector<int> f, int n)
{
    priority_queue<node*, vector<node*>, comp> pq;

    for(int i=0 ; i<n ; i++){
        pq.push(new node(a[i], f[i]));
    }

    while(pq.size() != 1){
        node* left = pq.top();
        pq.pop();

        node* right = pq.top();
        pq.pop();

        node* top = new node('$', left->freq+right->freq);

        top->left = left;
        top->right = right;
        pq.push(top);
    }

    printCode(pq.top(), "");  

}

int main()
{
    int n;
    cin >> n;
    vector<char> a(n);
    vector<int> f(n);    //kon character koto times ace seta hishab kore dea ace
    for(int i=0 ; i<n ; i++){
        cin >> a[i] >> f[i];
    }

    HuffmanCode(a, f, n);


}