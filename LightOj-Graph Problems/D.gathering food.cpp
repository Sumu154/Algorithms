#include<bits/stdc++.h>
using namespace std;

const int N = 20;
char maze[N][N];
bool visited[N][N];
int n, food=0, flag;
pair<int, int> src;
char ch;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

bool isValid(int x, int y)
{
    if(isalpha(maze[x][y]) and maze[x][y]!=ch){
        return false;
    }
    else if(x>=0 and x<n and y>=0 and y<n and maze[x][y]!='#' and !visited[x][y]){
        return true;
    }
    return false;
}

int BFS(pair<int, int> src)
{
    ch = 'B';
    int count = 0;
    queue<pair<int,int>> q;
    visited[src.first][src.second] = 1;
    q.push(src);
    while(!q.empty() and food>0){
        pair<int, int> head = q.front();
        q.pop();

        int x = head.first;
        int y = head.second;

        for(int i=0 ; i<4 ; i++){
            int newX = x+dx[i];
            int newY = y+dy[i];

            if(isValid(newX, newY)){
                if(maze[newX][newY]==ch){
                    flag = 1;
                    food--;
                    ch++;
                }
                count++;
                visited[newX][newY] = 1;
                q.push({newX,newY});
            }
        }
    }
    return count;
}

int main()
{
    int t;
    cin >> t;
    for(int i=1 ; i<=t ; i++){
        cout << "Case " << i << ": ";
        cin >> n;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                cin >> maze[i][j];
                if(maze[i][j]=='A'){
                    src = {i,j};
                }
                else if(maze[i][j]>'A' and maze[i][j]<='Z'){
                    food++;
                }
            }
        }
//        for(int i=0 ; i<n ; i++){
//            for(int j=0 ; j<n ; j++){
//                cout << maze[i][j];
//            }
//            cout << "\n";
//        }
        //cout << food << "\n";

        if(food==0){
            cout << 0 << "\n\n";
        }
        else{
            int count = BFS(src);
            if(flag==0){
                cout << "Impossible\n\n";
            }
            else if(flag>0){
                cout << count << "\n\n";
            }

        }
        food = 0;
        flag = 0;
        memset(visited, false, sizeof(visited));
    }
}
