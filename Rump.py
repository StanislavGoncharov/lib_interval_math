import time
import numpy as np
start_time = time.time()

#Rump стандартными средствами Python
def Rump(a, b):
    return 333.75 * (b**6) + (a**2) * (11 * (a**2) * 
(b**2) - (b**6) - 121 * (b**4) - 2) + 5.5 * (b**8) + a/(2*b)
print("\n--- Решение через ВЕЩЕСТВЕННЫЕ ЧИСЛА ---")
print (Rump(77617.0, 33096.0))
print("--- %s seconds ---" % (time.time() - start_time))
#рациональные дроби
from decimal import Decimal
#библиотека рациональных дробей
from fractions import Fraction
def Rump_fraction(a, b):
    k1 = Fraction(333.75)
    k2 = Fraction(11)
    k3 = Fraction(121)
    k4 = Fraction(5.5)
    k5 = Fraction(2)
    return k1 * (b**6) + (a**2) * (k2 * (a**2) * (b**2) - 
(b**6) - k3 * (b**4) - k5) + k4 * (b**8) + (a / (k5 * b))
start_time = time.time()
a = Fraction(77617.0)
b = Fraction(33096.0)

print("\n--- Решение через РАЦИОНАЛЬНЫЕ ДРОБИ ---")
print (Rump_fraction(a,b))
print (float(Rump_fraction(a,b)))
print (Decimal.from_float(float(Rump_fraction(a,b))))
print("--- %s seconds ---" % (time.time() - start_time))
print()
