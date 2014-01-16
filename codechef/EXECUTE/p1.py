import sys

def iscorrect(a,m,n):
    pos=0
    while n>1:
        del a[pos];
        n=n-1
        pos=(pos+(m-1))%n

    if(a[0]==13):
        return True
    else:
        return False
    

def init(n):
    a=[]
    for i in range(n):
        a.append(i+1);
    return a

def check(n):
    i=1
    if(n<13):
        return 0
    while True:
        if iscorrect(init(n),i,n):
            return i
        i=i+1
        
def main():
    t=input()
    for i in range(t):
        n=input()
        print check(n)

##if __name__=='__main__':
  ##  main()
