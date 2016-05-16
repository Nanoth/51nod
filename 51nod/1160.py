
#大数开方,find x st. x=n//x
import math

if __name__ == '__main__':
    n=int(input())
    x=int(10 ** int(math.log10(n) // 2))
    while(not ((x)*(x)<=n and (x+1)*(x+1)>n)):
        x=(x+n//x)//2
    print x
