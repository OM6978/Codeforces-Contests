Test=input()
Test=int(Test)
i=0
for i in range(Test):
    A,N= input().split()
    N=int(N)
    N=N/2
    A=int(A)
    if A>=0:
        ans= A**N
    else:
        ans=1
    ans=ans%1000000007
    print("%.0f"%ans)
    i=i+1