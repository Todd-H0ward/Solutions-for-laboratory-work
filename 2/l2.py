#вариант 10
import math as m

a = 0.2
b = 1.8
E = 0.001
n = 4
h = (b - a) / n
def f(x):
    return m.sqrt(x + 1)
fa = f(a)
fb = f(b)
x1 = a + h
x2 = a + 2 * h
x3 = b - h
I4 = h * (fa + fb + 2 * f(x2) + 4 *(f(x1) + f(x3))) / 3
E1 = 1
while E1 > E:
    I1 = I4 
    n = n * 2
    h = h / 2
    I2 = 0
    I3 = 0
    for i in range(2,n+1,2):
        x = a + i * h
        I2 += f(x)
    for i in range(1,n,2):
        x = a + i * h
        I3 += f(x)
    I4 = h * (fa + fb + 2 * I2 + 4 * I3) / 3
    E1 = abs(I4 - I1)
print(I4)
print(n)

