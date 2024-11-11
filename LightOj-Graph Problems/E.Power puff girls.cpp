#include<bits/stdc++.h>
using namespace std;

const int N = 20;
char maze[N][N];
int level[N][N];
bool visited[N][N];
int n, m;
pair<int, int> a, b, c;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

bool isValid(int x, int y)
{
    if(x>=0 and x<n and y>=0 and y<m and !visited[x][y] and maze[x][y]!='#' and maze[x][y]!='m'){
        return true;
    }
    return false;
}

int BFS(pair<int, int> src)
{
    queue<pair<int, int>> q;
    visited[src.first][src.second] = 1;
    level[src.first][src.second] = 0;
    q.push(src);
    while(!q.empty()){
        pair<int, int> head = q.front();
        q.pop();

        int x = head.first;
        int y = head.second;
        for(int i=0 ; i<4 ; i++){
            int newX = x+dx[i];
            int newY = y+dy[i];

            if(isValid(newX, newY)){
                level[newX][newY] = level[x][y]+1;
                if(maze[newX][newY]=='h'){
                    return level[newX][newY];
                }
                visited[newX][newY] = 1;
                q.push({newX, newY});
            }
        }
    }

}

int main()
{
    int t;
    cin >> t;
    for(int i=1 ; i<=t ; i++){
        cout << "Case " << i << ": ";
        cin >> n >> m;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                cin >> maze[i][j];
                if(maze[i][j]=='a'){
                    a = {i,j};
                }
                else if(maze[i][j]=='b'){
                    b = {i,j};
                }
                else if(maze[i][j]=='c'){
                    c = {i,j};
                }
            }
        }
        int al = BFS(a);
        memset(visited, 0, sizeof(visited));
        memset(level, 0, sizeof(level));
        int bl = BFS(b);
        memset(visited, 0, sizeof(visited));
        memset(level, 0, sizeof(level));
        int cl = BFS(c);
        memset(visited, 0, sizeof(visited));
        memset(level, 0, sizeof(level));
        cout << max({al,bl,cl}) << "\n";

    }
}
