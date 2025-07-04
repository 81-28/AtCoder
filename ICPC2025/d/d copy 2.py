def check(lst: list, leng: int) -> list:
    ans = 1
    count = 0
    ansl = []
    lst.append('a')
    for i in range(leng):
        if lst[i] == lst[i+1]:
            count += 1
        else:
            ansl.append(count+1)
            count = 0
    return ansl

def diff(lst: list, A, B) -> int:
    clist = check(lst[0],B)
    for i in range(1,A):
        if clist != check(lst[i],B):
            return 0
    return 1

while True:
    A,B = map(int,input().split())
    Atf = 1
    Btf = 1
    if (A,B) == (0,0):
        break
    Al = []
    Bl = [['a' for _ in range(A)] for _ in range(B)]

    for i in range(A):
        intxt = list(input())
        Al.append(intxt)
        for j,k in zip(intxt,range(B)):
            Bl[k][i] = j
    