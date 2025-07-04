def change(lst,B):
    lst.append('a')
    count = 1
    ans = []
    for i in range(B):
        if lst[i] == lst[i+1]:
            count += 1
        else:
            ans.append(count)
            count = 1
    return ans

while True:
    A,B = map(int,input().split())
    if (A,B) == (0,0):
        break
    txt = list(input())
    check = change(txt,B)
    other = []
    ans = 1
    for _ in range(A-1):
        txt = list(input())
        txtc = change(txt,B)
        if ans == -1:
            pass
        if txtc != check:
            ans = -1
        other[txt[0]]
    other = change(other,A)
    ot = len(check)
    ol = len(other)
    if ans != -1:
        if ot <= 2 and ol <= 2:
            ans *= 0
        elif ot <= 2:
            
        elif ol <= 2:

        
        if ot >= :
            for i in range(1,len(check) - 2):
                if check[i] != check[i+1]:
                    ans = -1
            if check[0] > check[1] and check[-2] < check[-1]:
                ans = -1
            if ans == -1:
                v = 0
            else:
                v = check[1]

        if ol >= 3:
            for i in range(1,len(check) - 2):
                if check[i] != check[i+1]:
                    ans = -1
            if check[0] > check[1] and check[-2] < check[-1]:
                ans = -1
            if ans == -1:
                v = 0
            else:
                v = check[1]

    print(ans)