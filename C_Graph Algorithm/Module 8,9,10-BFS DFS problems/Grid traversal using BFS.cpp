/*
5 8
########
#.A#...#
#.##.#B#
#......#
########

single line of string -> input
A (start), B (end)
. (floor), # (wall)

Output:
YES
9

                                             _x_______y_
(x,y) er 1.right cell -> (x, y+1)             0       1
         2.left cell  -> (x, y-1)             0      -1
         3.up cell    -> (x+1, y)             1       0
         4.down cell  -> (x-1, y)            -1       0

direction array
         dx[] = {0, 0, 1, -1}   //{r,l,u,d}
         dy[] = {1, -1, 0, 0}

1. is the cell within the maze
2. is the cell forbidden/wall
3. is the cell visited

 ei 4 ta case e ei 3 ta ques korbo
 true hole


 time complexity -> O(n*m)
 space complexity -> O(n*m)

*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1002;
char maze[N][N];  //matrix ta
int visited[N][N];
int level[N][N];
int n, m;
int dx[] = {0, 0, 1, -1};   //{r, l, u, d}
int dy[] = {1, -1, 0, 0};

bool isValid(int x, int y)
{
    if(x>=0 and x<n and y>=0 and y<m and maze[x][y]!='#' and !visited[x][y]){
        return true;
    }
    return false;
}

void BFS(pair<int, int> src)
{
    queue<pair<int, int>> q;
    q.push(src);
    visited[src.first][src.second] = true;
    level[src.first][src.second] = 0;

    while(!q.empty()){
        pair<int, int> head = q.front();
        q.pop();
        int x = head.first;
        int y = head.second;

        for(int i=0 ; i<4 ; i++){   //adja_list traverser moto adja_ghor gula traverse
            int new_x = x+dx[i];
            int new_y = y+dy[i];

            if(isValid(new_x, new_y)){
                visited[new_x][new_y] = true;
                level[new_x][new_y] = level[x][y]+1;
                q.push({new_x, new_y});
            }
        }
    }
}


int main()
{
    cin >> n >> m;
    pair<int, int> src, dst;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){ //maze[i][j] use kora jabe na kno
            cin >> maze[i][j];
            if(maze[i][j] == 'A'){
                src = {i,j};
            }
            else if(maze[i][j] == 'B'){
                dst = {i,j};
            }
        }
    }

    BFS(src);
    if(!visited[dst.first][dst.second])
        cout << "No\n";
    else
    {
        cout << "Yes\n" << level[dst.first][dst.second];
    }
}
