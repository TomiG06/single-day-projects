#Sieve of Eratosthenes
#Check more about it here: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
#Briefly: Algorithm to find all prime numbers of a given range

import math

limit = int(input("Enter limit: "))
ret = [n for n in range(2, limit+1)]

for n in ret:
    if math.sqrt(n) < limit:
        for num in ret:
            if num%n==0 and n!=num:
                ret.remove(num)
    else:
        break
print(ret)
