#include <iostream>
using namespace std;

int main() {
    double n1, n, a, b, h, x, p;
    cin >> n1 >> n >> a >> b;

    h = (b - a) / 6;
    x = a;
    double ai[] = {2.415, -2.243, 1.217, -0.143, -1.514, 0.853};
    p = ai[0];

    for (int i = 0; i < n1; i++) {
        for (int j = 0; i < n1; j++) {
            p += p * x + ai[j];
        }
        x += h;
        cout << "Значение " << p << "в точке " << i + 1 << "\n";
    }

    return 0;
}