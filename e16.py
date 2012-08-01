a = pow(2, 1000)
sum_var = 0

while a != 0:
        sum_var = sum_var + (a % 10)
        a = a / 10
        
print sum_var
