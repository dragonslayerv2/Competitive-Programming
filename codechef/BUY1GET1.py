#!/usr/bin/python -tt
def main():
    t=input()
    for T in range(t):
        count=0
        d={}
        string=raw_input()
       
        for i in string:
            if i in d:
                del d[i]
            else:
                d[i]=0;
                count=count+1
        print count

main()
