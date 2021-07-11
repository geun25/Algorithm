#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    int cnt = 0;
    int x, y;
    

    cin >> n;

    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

        }
    }
    for (int i = 0; i < n; i++)
    {
        y = 0, x = i;
        for (int j = 0; j <= i; j++)
        {
            arr[y][x] = cnt++;
            y++, x--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i j++)
        {
            cout << arr[i][j];
        }
    }
}