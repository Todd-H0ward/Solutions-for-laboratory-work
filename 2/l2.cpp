#include <iostream>
#include <cmath>
using namespace std;

const double E = 0.001;

double f(double x) {
    return sqrt(x + 1);
}

int main() {
    double a, b, n, h, x, fa, fb, x1, x2, x3, I1, I2, I3, I4, E1 = 1;
    cin >> a >> b >> n;

    h = (b - a) / n;
    fa = f(a);
    fb = f(b);

    x1 = a + h;
    x2 = a + 2 * h;
    x3 = b - h;
    I4 = h * (fa + fb + 2 * f(x2) + 4 * (f(x1) + f(x3))) / 3;

    while (E1 > E) {
        I1 = I4;
        n = n * 2;
        h = h / 2;
        I2 = 0;
        I3 = 0;
        for (int i = 2; i <= n + 1; i += 2) {
            x = a + i * h;
            I2 += f(x);
        }
        for (int i = 1; i <= n; i += 2) {
            x = a + i * h;
            I3 += f(x);
        }
        I4 = h * (fa + fb + 2 * I2 + 4 * I3) / 3;
        E1 = abs(I4 - I1);
    }

    cout << I4 << "\n";
    cout << n;

    return 0;
}

