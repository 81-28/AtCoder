# https://2025domestic.jag-icpc.org/team/problems/11/text

N = int(input())
ans = [")" for _ in range(N)]
i = 0
for _ in range(int(N/2)):
    print('?',i+1,i+2)
    a = int(input())
    ans[i] = '('
    if a == 0:
        ans[i+1] = '('
    i += a+1
ans = ["!"," "]+ans
print(*ans,sep='')