#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
char maze[N][N];
int visited[N][N];
int n, m;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool isValid(int x, int y)
{
    if(x>=0 and x<n and y>=0 and y<m and !visited[x][y] and maze[x][y]!='#'){
        return true;
    }
    return false;
}

void BFS(pair<int,int> src)
{
    queue<pair<int,int>> q;
    visited[src.first][src.second] = 1;
    q.push(src);

    while(!q.empty()){
        pair<int,int> head = q.front();
        q.pop();

        int x = head.first;
        int y = head.second;

        for(int i=0 ; i<4 ; i++){
            int newX = x + dx[i];
            int newY = y + dy[i];

            if(isValid(newX, newY)){
                visited[newX][newY] = 1;
                q.push({newX,newY});
            }
        }


    }
}


int main()
{
    cin >> n >> m;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cin >> maze[i][j];            
        }
    }

    int count = 0;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(!visited[i][j] and maze[i][j]=='.'){
                BFS({i,j});
                count++;
            }
        }
    }
    cout << count << "\n";
}