#include<bits/stdc++.h>
using namespace std;

const int N = 104;
char maze[N][N];
bool visited[N][N];
int n,  m;
int flag;
int dx[] = {0,0,1,-1,1,1,-1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1};

bool isValid(int x, int y)
{
    if(x>=0 and x<n and y>=0 and y<m and maze[x][y]!='*' and !visited[x][y]){
        return true;
    }
    return false;
}

void BFS(pair<int, int> src)
{
    queue<pair<int, int>> q;
    visited[src.first][src.second] = true;
    q.push(src);
    while(!q.empty()){
        pair<int, int> head = q.front();
        q.pop();

        int x = head.first;
        int y = head.second;

        for(int i=0 ; i<8 ; i++){
            int newX = x+dx[i];
            int newY = y+dy[i];

            if(isValid(newX, newY)){
                visited[newX][newY] = true;
                q.push({newX, newY});
            }
        }
    }
}

pair<int, int> find_unvisited()
{
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(maze[i][j]!='*' and !visited[i][j]){
                return {i,j};
            }
        }
    }
    return {-1,-1};
}

int main()
{
    while(true){
        cin >> n >> m;
        if(n==0 and m==0){
            break;
        }
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                cin >> maze[i][j];
            }
        }

        pair<int, int> src;
        while(true){
            src = find_unvisited();
            if(src == pair<int, int> {-1,-1}){
                break;
            }
            BFS(src);
            flag++;
        }
        cout << flag << "\n";
        flag = 0;
        memset(visited, false, sizeof(visited));
    }
}

