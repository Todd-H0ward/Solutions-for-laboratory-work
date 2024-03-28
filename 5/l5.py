mat_start = [[14.2, 3.2, -4.2, 6.5],
         [6.3, 14.3, 2.2, -5.8],
         [8.4, -2.3, -15.8, 4.1],
         [2.7, 3.7, 6.4, -12.7]]
b = [13.2, -4.4, 6.4, 8.5]
n = 4

def mat_copy(mat):
    m_copy = mat.copy()
    for i in range(len(mat)):
        m_copy[i] = mat[i].copy()
    return m_copy
    
m = mat_copy(mat_start)
for i in range(0,n-1):
    if m[i][i] == 0:
        m[i], m[i+1] = m[i+1], m[i]
    for k in range(i+1,n):
        c = m[k][i] / m[i][i]
        m[k][i] = 0
        for j in range(i+1,n):
            m[k][j] = m[k][j] - c * m[i][j]
        b[k] = b[k] - c * b[i]

x4 = b[3] / m[3][3] 
x3 = (b[2] - x4 * m[2][3]) / m[2][2]
x2 = (b[1] - (x4 * m[1][3] + x3 * m[1][2])) / m[1][1]
x1 = (b[0] - (x4 * m[0][3] + x3 * m[0][2] + x2 * m[0][1])) / m[0][0]

print(f't = {x4}')
print(f'z = {x3}')
print(f'y = {x2}')
print(f'x = {x1}')
nw = 0
for i in range(4):
    nw += (m[i][0] * x1 + m[i][1] * x2 + m[i][2] * x3 + m[i][3] * x4) - b[i]
print(nw / 4)
    

