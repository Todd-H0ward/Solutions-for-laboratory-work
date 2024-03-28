#вариант 5
n1 = 6
n = 5
a = 0.2
b = 1.3 
h = (b - a) / 6
x = a
ai = [2.415, -2.243, 1.217, -0.143, -1.514, 0.853]
p = ai[0]
for i in range(n1):
    for j in range(n1):
        p += p * x + ai[j]
    x += h
    print(f'значение {p} в точке {i+1}')
