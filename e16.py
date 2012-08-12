# 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
#
# What is the sum of the digits of the number 2^1000?

a = pow(2, 1000)
sum_var = 0

while a != 0:
        sum_var = sum_var + (a % 10)
        a = a / 10
        
print sum_var
