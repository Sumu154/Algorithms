#include<bits/stdc++.h>
using namespace std;

const int N = 505;
char maze[N][N];
int visited[N][N];
int n, m, k;
int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};

bool isValid(int x, int y)
{
    if(x>=0 and y>=0 and x<n and y<m and !visited[x][y] and maze[x][y]=='.'){
        return true;
    }
    return false;
}

void dfs(int x, int y)
{
    visited[x][y] = 1;
    for(int i=0; i<4; i++){
        int newX = x+dx[i];
        int newY = y+dy[i];

        if(isValid(newX, newY)){
            dfs(newX, newY);
        }
    }

    if(k>0){
        maze[x][y] = 'X';
        k--;
    }
}

int main()
{
    cin >> n >> m >> k;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> maze[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(maze[i][j]=='.' && visited[i][j]==0){
                dfs(i, j);
            }
        }
    }


    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << maze[i][j];
        }
        cout << endl;
    }
}
