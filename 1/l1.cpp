#include <iostream>
#include <cmath>
#include <locale>

using namespace std;

double f(double x) {
    return (sin(1.5 * x + 0.3)) / (2.3 + cos(0.4 * pow(x, 2) + 1));
}

int main() {
    setlocale(LC_ALL, "Russian");
    double a, b, n, h, x1, x2, x3, s, s1 = 0, s2 = 0, s3 = 0;

    cin >> a >> b >> n;

    h = (b - a) / n;
    x1 = a;
    x2 = a + h;
    x3 = a + 0.5 * h;

    for (int i = 0; i < n; i++) {
        s1 += h * f(x1);
        x1 += h;
        s2 += h * f(x2);
        x2 += h;
        s3 += h * f(x3);
        x3 += h;
    }

    s = (s1 + s2 + s3) / 3;

    cout << "Левая" << s1 << "погрешность = " << abs(s - s1) << "\n";
    cout << "Правая" << s2 << "погрешность = " << abs(s - s2) << "\n";
    cout << "Средняя" << s3 << "погрешность = " << abs(s - s3);

    return 0;
}