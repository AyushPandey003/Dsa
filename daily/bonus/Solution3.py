def sumF(N):
    sumT=0
    for i in range(N):
        sumT+=i
    return sumT
T=int(input())
for i in range(T):
    N=int(input())
    print(sumF(N))