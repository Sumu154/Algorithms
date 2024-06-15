/*

dot deagula purata ekta ghor..ber korte hbe kotogula emn ghor ace

5 8
########
##.....#
##.#.#.#
##.....#
########

output -> 13

while there is empty cell
- find an empty unvisited cell
- run bfs or dfs from that cell

                                             _x_______y_
(x,y) er 1.right cell -> (x, y+1)             0       1
         2.left cell  -> (x, y-1)             0      -1
         3.up cell    -> (x+1, y)             1       0
         4.down cell  -> (x-1, y)            -1       0

direction array
         dx[] = {0, 0, 1, -1}
         dy[] = {1, -1, 0, 0}


*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1002;
char maze[N][N];
int visited[N][N];
int n, m;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};


bool isValid(int x, int y)
{
    if(x>=0 and x<n and y>=0 and y<m and maze[x][y]!='#' and !visited[x][y]){
        return true;
    }
    return false;
}


int BFS(pair<int, int> src)
{
    queue<pair<int,int>> q;
    visited[src.first][src.second] = 1;
    q.push(src);
    int count = 1;    //head ekta already visited hoice
    while(!q.empty()){
        pair<int, int> head = q.front();
        q.pop();

        int x = head.first;
        int y = head.second;

        for(int i=0 ; i<4 ; i++){
            int new_x = x+dx[i];
            int new_y = y+dy[i];

            if(isValid(new_x, new_y)){
                count++;
                visited[new_x][new_y] = 1;
                q.push({new_x,new_y});
            }
        }
    }
    return count;
}

pair<int, int> find_unvisited()
{
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(!visited[i][j] and maze[i][j]!='#')
                return {i,j};   //ekta pair return korlo
        }
    }
    return {-1, -1};   //jeta ekta valid pair na
}

int main()
{
    cin >> n >> m;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cin >> maze[i][j];
        }
    }

    int count;
    while(true){
        pair<int, int> src = find_unvisited();
        if(src == pair<int, int> {-1,-1}){
            break;
        }
        count = BFS(src);
    }
    cout << count;

}

