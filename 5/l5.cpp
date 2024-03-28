#include <iostream>
#include <cmath>

using namespace std;

const int N = 100; // Максимальное количество уравнений

int main() {
    int n;
    cin >> n;
    double a[N][N], b[N], x[N];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
        cin >> b[i];
    }
    for (int k = 0; k < n; k++) {
        for (int i = k + 1; i < n; i++) {
            double c = a[i][k] / a[k][k];
            for (int j = 0; j < n; j++) {
                a[i][j] -= c * a[k][j];
            }
            b[i] -= c * b[k];
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        double s = 0;
        for (int j = i + 1; j < n; j++) {
            s += a[i][j] * x[j];
        }
        x[i] = (b[i] - s) / a[i][i];
    }
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }
    return 0;
}
