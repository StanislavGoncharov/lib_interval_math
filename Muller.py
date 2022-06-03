#вещественные числа не дают нужного результата, поэтому сразу перехожу к дробям

import time
#import numpy as np
start_time = time.time()
from decimal import Decimal
#библиотека рациональных дробей
from fractions import Fraction
def Muller(y,z):
    return Fraction(108 - (815-1500/z)/y)

x = [Fraction(4), Fraction(4.25)]
for i in range(2, 100):
    x.append(Muller(x[i-1], x[i-2]))

for i in range(len(x)):
    print (i, "   ", Decimal.from_float(float(x[i])))
print("--- %s seconds ---" % (time.time() - start_time))
