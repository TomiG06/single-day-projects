#Sieve of Eratosthenes
#Check more about it here: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
#Briefly: Algorithm to find all prime numbers of a given range
import sys

limit = int(sys.argv[1])
ret = list(range(2, limit+1))

for n in ret:
    if n**2 < limit:
        num = 2*n
        while num <= max(ret):
            
            if num in ret: ret.remove(num)
            num+=n
    else:
        print(*ret)
        break
