#include<bits/stdc++.h>
using namespace std;

const int N = 205;
char maze[N][N];
bool visited[N][N];
int fire[N][N];
int jane[N][N];
int n, m;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool isValid(int x, int y)
{
    if(x>=0 and x<n and y>=0 and y<m and maze[x][y]!='#' and !visited[x][y]){
        return true;
    }
    return false;
}

bool escape(int x, int y)
{
    if(x<0 or x>=n or y<0 or y>=m ){
        return true;
    }
    return false;
}

void reset()
{
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            fire[i][j] = INT_MAX;
            jane[j][j] = INT_MAX;
            visited[i][j] = 0;
        }
    }
}

void resetVisited()
{
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            visited[i][j] = 0;
        }
    }
}

void fireBFS(vector<pair<int, int>> fires)
{
    resetVisited();

    queue<pair<int, int>> q;
    for(auto i: fires){
        q.push(i);
        visited[i.first][i.second] = 1;
        fire[i.first][i.second] = 0;
    }

    while(!q.empty()){
        pair<int, int> head = q.front();
        q.pop();

        int x = head.first;
        int y = head.second;

        for(int i=0 ; i<4 ; i++){
            int newX = x+dx[i];
            int newY = y+dy[i];

            if(isValid(newX, newY)){
                fire[newX][newY] = fire[x][y]+1;
                visited[newX][newY] = 1;
                q.push({newX, newY});
            }
        }
    }
}

int janeBFS(pair<int, int> src)
{
    resetVisited();

    queue<pair<int, int>> q;
    q.push(src);
    visited[src.first][src.second] = 1;
    jane[src.first][src.second] = 0;
    while(!q.empty()){
        pair<int, int> head = q.front();
        q.pop();

        int x = head.first;
        int y = head.second;

        for(int i=0 ; i<4 ; i++){
            int newX = x+dx[i];
            int newY = y+dy[i];

            if(escape(newX, newY)){
                return jane[x][y]+1;
            }
            if(isValid(newX, newY)){
                if(fire[newX][newY] > jane[x][y]+1){
                    jane[newX][newY] = jane[x][y]+1;
                    visited[newX][newY] = 1;
                    q.push({newX, newY});
                }
            }
        }
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;
    for(int i=1 ; i<=t ; i++){
        cin >> n >> m;

        reset();
        vector<pair<int, int>> fires;
        pair<int, int> src;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                cin >> maze[i][j];

                if(maze[i][j]=='F'){
                    fires.push_back({i,j});
                }
                else if(maze[i][j]=='J'){
                    src = {i,j};
                }
            }
        }

        fireBFS(fires);
        int ans = janeBFS(src);
        cout << "Case " << i << ": ";
        if(ans==-1){
            cout << "IMPOSSIBLE\n";
        }
        else{
            cout << ans << "\n";
        }
    }
}
