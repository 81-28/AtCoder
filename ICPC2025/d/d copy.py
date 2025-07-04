from collections import defaultdict

while True:
    A,B = map(int,input().split())
    if (A,B) == (0,0):
        break
    ans = 0
    isPass = True
    tmpAns = 0
    tmpAnsLst = []
    for _ in range(A):
        txt = list(input())
        count = 0
        a = defaultdict(int)
        for i in range(B-1):
            if txt[i] == txt[i+1]:
                a[count] += 1
            else:
                count += 1
        al = len(a)-2
        if al <= 0:
            ans = 0
        else:
            lst = set()
            for i in range(al -1 ):
                if a[i] == a[i+1]:
                    tmp += 1
                else:
                    lst.add(tmp)
            if len(lst) == 0:
                ans = tmp
            else:
                ans = -1
        if isPass:
            isPass = False
            alst = a
        elif alst == a:
            tmpAns += 1
        else:
            tmpAnsLst.append(tmpAns)
    tALll = len(tmpAnsLst)
    if tALll == 1:
        if tmpAnsLst[0] <= ans:
            pass
        elif ans == 0:
            pass
        else:
            ans = -1
    elif tALll == 2:
        if max(tALll) <= ans:
            pass
        else:
            ans = -1
    else:
        for i in tmpAnsLst[1:-2]:
            if i == ans:
                pass
            else:
                ans = -1
                break
    print(ans)
