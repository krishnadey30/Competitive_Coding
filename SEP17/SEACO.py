
def updateArray(arr, N):
    for  i in range(1,N):
        arr[i] = (arr[i]+arr[i - 1])
def printArr(arr, N):
    updateArray(arr, N);
    for i in range(0,N):
        print(arr[i]%1000000007,end=" ")
    print()

for x in range(int(input())):
    n,m = list(map(int, input().split()))
    C=[]
    for i in range(m):
        a=[int(j) for j in input().split()]
        C.append(a)
    #print(C[0][1])
    Ex=[0]*(m+1)
    Val=[0]*n
    sum=0
    for i in range(1,m):
        if(m-i+2<=m and C[m-i][0]==2):
            sum+=Ex[m-i+1]
        #print(Ex)
        if(C[m-i][0]==2):
            value=(sum+1)
            #value=1
            Ex[C[m-i][2]]+=value
            #print(Ex)
            Ex[C[m-i][1]-1]-=value
            #print(Ex)
    print(Ex)
    sum=1
    for i in range(m,-1,-1):
        sum+=Ex[i]
        if(C[i-1][0]==1):
            Ex[i]=sum
        print(Ex)
    #print(Ex)
    for i in range(0, m):
        if(C[i][0]==1):
            Val[C[i][1]-1] = Val[C[i][1]-1]+Ex[i+1]
            if(C[i][2]-1!=n-1):
                Val[C[i][2]] =(Val[C[i][2]]- Ex[i+1])
    printArr(Val,n)

    