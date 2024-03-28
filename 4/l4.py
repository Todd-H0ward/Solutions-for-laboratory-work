# вариант 3
xyzt = ['x', 'y', 'z', 't']
def gMM(m,i,j):
    return [row[:j] + row[j+1:] for row in (m[:i] + m[i+1:])]
def gMD(m):
    if len(m) == 2:
        return (m[0][0] * m[1][1]) - (m[0][1] * m[1][0])
    det = 0
    for c in range(len(m)):
        det += ((-1) ** c) * m[0][c] * gMD(gMM(m,0,c))
    return det
m = [[4.8,12.5,-6.3,-9.7],
    [22, -31.7, 12.4, -8.7],
    [15, 21.1, -4.5, 14.4],
    [8.6, -14.4, 6.2, 2.8]]
b = [3.5,4.6,15,-1.2]
d = gMD(m)
print(f'Определитель первоначальной матрицы = {d}')
nm = list(m)
for i in range(4):
    for j in range(4):
        nm[j] = list(m[j])
        nm[j][i] = b[j]
    print(f'{xyzt[i]} = {gMD(nm) / d}')


