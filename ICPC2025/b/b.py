while True:
    num = int(input())
    if num == 0:
        break
    txt = input()
    k = 0
    for i,j in zip(txt,txt[::-1]):
        if i == j:
            k += 1
            pass
        else:
            break
    ans = txt+txt[k:]
    if len(ans) == len(txt):
        ans += txt[-1]
    print(ans)