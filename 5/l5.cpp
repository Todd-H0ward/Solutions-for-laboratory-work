#include <iostream>
#include <vector>

using namespace std;

vector<vector<double>> mat_copy(vector<vector<double>> mat) {
    vector<vector<double>> m_copy = mat;
    return m_copy;
}

int main() {
    vector<vector<double>> mat_start = {
        {14.2, 3.2, -4.2, 6.5},
        {6.3, 14.3, 2.2, -5.8},
        {8.4, -2.3, -15.8, 4.1},
        {2.7, 3.7, 6.4, -12.7}
    };

    vector<double> b = {13.2, -4.4, 6.4, 8.5};
    int n = 4;

    vector<vector<double>> m = mat_copy(mat_start);
    for(int i = 0; i < n-1; i++) {
        if(m[i][i] == 0) {
            swap(m[i], m[i+1]);
        }
        for(int k = i+1; k < n; k++) {
            double c = m[k][i] / m[i][i];
            m[k][i] = 0;
            for(int j = i+1; j < n; j++) {
                m[k][j] = m[k][j] - c * m[i][j];
            }
            b[k] = b[k] - c * b[i];
        }
    }

    double x4 = b[3] / m[3][3];
    double x3 = (b[2] - x4 * m[2][3]) / m[2][2];
    double x2 = (b[1] - (x4 * m[1][3] + x3 * m[1][2])) / m[1][1];
    double x1 = (b[0] - (x4 * m[0][3] + x3 * m[0][2] + x2 * m[0][1])) / m[0][0];

    cout << "t = " << x4 << endl;
    cout << "z = " << x3 << endl;
    cout << "y = " << x2 << endl;
    cout << "x = " << x1 << endl;

    double nw = 0;
    for(int i = 0; i < 4; i++) {
        nw += (m[i][0] * x1 + m[i][1] * x2 + m[i][2] * x3 + m[i][3] * x4) - b[i];
    }

    cout << nw / 4 << endl;

    return 0;
}
