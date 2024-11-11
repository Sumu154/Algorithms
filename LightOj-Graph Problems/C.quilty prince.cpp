#include<bits/stdc++.h>
using namespace std;

const int N = 505;
char maze[N][N];
bool visited[N][N];
int n, m;

int dy[] = {1,-1,0,0};
int dx[] = {0,0,1,-1};

bool isValid(int x, int y)
{
    if(x>=0 and x<m and y>=0 and y<n and maze[x][y]!='#' and !visited[x][y]){
        return true;
    }
    return false;
}

int BFS(pair<int, int> src)
{
    queue<pair<int,int>> q;
    visited[src.first][src.second] = 1;
    q.push(src);
    int flag = 1;    //head ekta already visited hoice
    while(!q.empty()){
        pair<int, int> head = q.front();
        q.pop();

        int x = head.first;
        int y = head.second;

        for(int i=0 ; i<4 ; i++){
            int new_x = x+dx[i];
            int new_y = y+dy[i];

            if(isValid(new_x, new_y)){
                flag++;
                visited[new_x][new_y] = 1;
                q.push({new_x,new_y});
            }
        }
    }
    return flag;
}

int main()
{
    int t;
    cin >> t;
    pair<int, int> src;
    for(int i=1 ; i<=t ; i++){
        cin >> n >> m;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                cin >> maze[i][j];
                if(maze[i][j]=='@'){
                    src = {i,j};
                }
            }
        }
//        for(int i=0 ; i<m ; i++){
//            for(int j=0 ; j<n ; j++){
//                cout << maze[i][j];
//            }
//            cout << "\n";
//        }

        int flag = BFS(src);
        cout << "Case " << i << ": " << flag << "\n";

        flag = 0;
        memset(visited, false, sizeof(visited));
    }

}
