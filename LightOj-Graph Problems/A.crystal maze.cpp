#include<bits/stdc++.h>
using namespace std;

const int N = 502;
char maze[N][N];
bool visited[N][N];
int n, m;
int flag = 0;
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

map<pair<int, int>, int> mp;
vector<pair<int, int>> a;

bool isValid(int x, int y)
{
    if(x>0 and x<=n and y>0 and y<=m and !visited[x][y] and maze[x][y]!='#'){
        return true;
    }
    return false;
}

void BFS(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x,y});
    visited[x][y] = true;
    while(!q.empty()){
        pair<int, int> head = q.front();
        q.pop();

        x = head.first;
        y = head.second;
        for(int i=0 ; i<4 ; i++){
            int newX = x+dx[i];
            int newY = y+dy[i];
            if(isValid(newX, newY)){
                visited[newX][newY] = true;
                q.push({newX, newY});
                a.push_back({newX, newY});
                if(maze[newX][newY]=='C'){
                    flag++;
                }
            }
        }
    }
}

int main()
{
    int test, q, cs;
    cin >> test;

    while(test--){
        cin >> n >> m >> q;

        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=m ; j++){
                cin >> maze[i][j];
                visited[i][j] = false;
            }
        }

        cout << "Case " << cs++ << ":\n";
        while(q--)
        {
            int x, y;
            cin >> x >> y;

            a.push_back({x,y});
            if(!visited[x][y]){
                BFS(x, y);
                cout << flag << "\n";

                for(auto i: a){
                    mp[i] = flag;
                }
            }
            else{
                cout << mp[{x,y}] << "\n";
            }
            flag = 0;
            a.clear();
        }

    }
}
