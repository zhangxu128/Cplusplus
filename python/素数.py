from math import sqrt

for i in range(2,101):
    k=int(sqrt(i))
    b=k
    for j in range(2,k+1):
        if i%j==0:
            b-=1
            break
    if(b==k):
        print(i)
