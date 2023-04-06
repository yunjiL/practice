#include <iostream>
#include <vector>
using namespace std;

char c;
int row, col;
int map[10001][501];
bool visit_m[10001][501] = {false, };
bool check;
int dx[3] = {-1, 0, 1};
int dy[3] = {1, 1, 1};
int cnt = 0;

void dfs(int x, int y)
{
    visit_m[x][y] = true;
    if (y == col - 1)
    {
        cnt++;
        check = true;
        return;
    }
    for (int i = 0; i < 3; i++)
    {
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        if (next_x >= 0 && next_y >= 0 && next_x < row && next_y < col)
		{
			if (map[next_x][next_y] == 1 && !visit_m[next_x][next_y])
			{
				dfs(next_x, next_y);
				if (check) return;
			}
        }
    }
}

int main()
{
    cin >> row >> col;

    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
        {
            cin >> c;
            if (c == '.') map[i][j] = 1;
            else map[i][j] = 0;
            visit_m[i][j] = 0;
        }
    
    for (int i = 0 ; i < row; i++)
    {
        check = false;
        dfs(i, 0);
    }

    cout << cnt;

    return 0;
}