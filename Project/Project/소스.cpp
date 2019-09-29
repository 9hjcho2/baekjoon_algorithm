#include <iostream>

using namespace std;

int matrix[60][60];
int order[60][60];
bool visited[60][60];

int row, col;
int count_num = 0;

int dx[] = { -1, 0, 1, 0 };//왼쪽 방향으로 이동
int dy[] = { 0, 1, 0, -1 };

int bx[] = { 1, 0, -1, 0 };//후진 이동
int by[] = { 0, -1, 0, 1 };

int cleanning(int x, int y, int dir)
{
	visited[x][y] = true;

	int cur_x = x;
	int cur_y = y;

	int next_x = 0;
	int next_y = 0;

	int count = 0;
	count_num++;
	order[x][y] = count_num;

	if (dir == 0)
	{
		dir = 3;
	}
	else if (dir == 1)
	{
		dir = 0;
	}
	else if (dir == 2)
	{
		dir = 1;
	}
	else
	{
		dir = 2;
	}

	while (1)
	{
		//cout << cur_x << " " << cur_y << " " << next_x << " " << next_y << endl;
		cout << endl;
		/*for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cout << order[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << endl;*/

		next_x = cur_x + dx[dir];
		next_y = cur_y + dy[dir];

		cout << cur_x << " " << cur_y << " " << next_x << " " << next_y << endl;

		if (!visited[next_x][next_y] && matrix[next_x][next_y] != 1)
		{
			// cout << cur_x << ' ' << cur_y << '\n';
			// cout << next_x << ' ' << next_y << '\n';
			cur_x = next_x;
			cur_y = next_y;
			visited[next_x][next_y] = true;
			count = 0;
			count_num++;
			order[next_x][next_y] = count_num;
			if (dir == 0)
			{
				dir = 3;
				continue;
			}
			else if (dir == 1)
			{
				dir = 0;
				continue;
			}
			else if (dir == 2)
			{
				dir = 1;
				continue;
			}
			else
			{
				dir = 2;
				continue;
			}
		}
		else if ((count < 4) && (visited[next_x][next_y] || matrix[next_x][next_y] == 1))
		{
			count++;
			if (count == 4)
				continue;
			if (dir == 0)
			{
				dir = 3;
				continue;
			}
			else if (dir == 1)
			{
				dir = 0;
				continue;
			}
			else if (dir == 2)
			{
				dir = 1;
				continue;
			}
			else
			{
				dir = 2;
				continue;
			}
		}
		else if (count == 4)
		{

			//cout << next_x << " " << next_y << " " << cur_x << " " << cur_y << endl;

			//if (dir == 0)
			//{
			//	dir = 3;
			//	//continue;
			//}
			//else if (dir == 1)
			//{
			//	dir = 0;
			//	//continue;
			//}
			//else if (dir == 2)
			//{
			//	dir = 1;
			//	//continue;
			//}
			//else
			//{
			//	dir = 2;
			//	//continue;
			//}
			next_x = cur_x + bx[dir];
			next_y = cur_y + by[dir];

			
			// cout << "dir : " << dir;

			if (matrix[next_x][next_y] != 1)
			{
				// cout << "if\n";
				// cout << cur_x << ' ' <<  cur_y << '\n';
				// cout << next_x << ' ' << next_y << '\n';
				cur_x = next_x;
				cur_y = next_y;
				count = 0;
				if (dir == 0)
				{
					dir = 3;
					//continue;
				}
				else if (dir == 1)
				{
					dir = 0;
					//continue;
				}
				else if (dir == 2)
				{
					dir = 1;
					//continue;
				}
				else
				{
					dir = 2;
					//continue;
				}
				continue;
			}
			else
			{
				// cout << "else\n";
				// cout << cur_x << ' ' <<  cur_y << '\n';
				// cout << next_x << ' ' << next_y << '\n';
				return count_num;
			}
		}
	}
}

int main()
{
	int x, y, dir;

	cin >> row >> col;

	cin >> x >> y >> dir;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> matrix[i][j];
			visited[i][j] = false;
			order[i][j] = 0;
		}
	}
	cout << cleanning(x, y, dir);
	// for(int i = 0; i < row; i++)
	// {
	//     for(int j = 0; j < col; j++)
	//     {
	//         cout << visited[i][j] << ' ';
	//     }
	//     cout << '\n';
	// }
	cout << '\n';
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << order[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}