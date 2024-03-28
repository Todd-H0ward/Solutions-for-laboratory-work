#include <iostream>
#include <cmath>

using namespace std;

const int N = 100; // Максимальное количество уравнений

int main()
{
    int n;
    cin >> n;
    double a[N][N], b[N], x[N];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
        cin >> b[i];
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = k + 1; i < n; i++)
        {
            double mult = a[i][k] / a[k][k];
            for (int j = 0; j < n; j++)
            {
                a[i][j] -= mult * a[k][j];
            }
            b[i] -= mult * b[k];
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        x[i] = b[i] / a[i][i];
        for (int j = i - 1; j >= 0; j--)
        {
            b[j] -= a[j][i] * x[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }
    return 0;
}