#include <iostream>
#include <vector>
#include <locale>
using namespace std;

vector<vector<double>> getMatrixMinor(vector<vector<double>> m, int i, int j) {
    m.erase(m.begin() + i);
    for (int i = 0; i < m.size(); i++)
        m[i].erase(m[i].begin() + j);
    return m;
}

double getMatrixDeterminant(vector<vector<double>> m) {
    if (m.size() == 2)
        return m[0][0] * m[1][1] - m[0][1] * m[1][0];

    double det = 0;
    for (int c = 0; c < m.size(); c++)
        det += ((c % 2 == 0 ? 1 : -1) * m[0][c] * getMatrixDeterminant(getMatrixMinor(m, 0, c)));
    return det;
}

int main() {
    setlocale(LC_ALL, "Russian");
    vector<string> xyzt = {"x", "y", "z", "t"};
    vector<vector<double>> m = {
        {4.8, 12.5, -6.3, -9.7},
        {22, -31.7, 12.4, -8.7},
        {15, 21.1, -4.5, 14.4},
        {8.6, -14.4, 6.2, 2.8}
    };
    vector<double> b = {3.5, 4.6, 15, -1.2};
    double d = getMatrixDeterminant(m);
    cout << "Определитель первоначальной матрицы = " << d << endl;
    vector<vector<double>> nm = m;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            nm[j] = m[j];
            nm[j][i] = b[j];
        }
        cout << xyzt[i] << " = " << getMatrixDeterminant(nm) / d << endl;
    }
    return 0;
}