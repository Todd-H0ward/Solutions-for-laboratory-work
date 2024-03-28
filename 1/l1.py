
import math
a = 0.4
b = 1.2
n = int(input())
h = (b - a) / n
x1 = a
x2 = a + h
x3 = a + 0.5 * h
def f(x):
    f = (math.sin(1.5 * x + 0.3)) / (2.3 + math.cos(0.4 * x ** 2 + 1))
    return f 
s1 = 0
s2 = 0
s3 = 0
for i in range(n):
    s1 += h * f(x1)
    x1 += h
    s2 += h * f(x2)
    x2 += h
    s3 += h * f(x3)
    x3 += h
s = (s1 + s2 + s3) / 3
print('левая', s1, 'погрешность = ', abs(s - s1))
print('правая', s2, 'погрешность = ', abs(s - s2))
print('средняя', s3, 'погрешность = ', abs(s - s3))
