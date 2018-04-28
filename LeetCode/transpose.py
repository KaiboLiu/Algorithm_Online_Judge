from random import randint
M,N = 10,30
#for _ in range(N):
#    print(' '.join([str(randint(0,1000)) for _ in range(M)]))
print(' '.join([str(randint(0,1000)) for _ in range(M)]))
print((randint(0,1000) for _ in range(M)))
print(*(randint(0,1000) for _ in range(M)))
a = (randint(0,1000) for _ in range(M))
b = (randint(0,1000) for _ in range(M))
c = zip(a,b)
print(c)
print(list(c))
print(c)
print(list(c))
