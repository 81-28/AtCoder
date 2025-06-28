# https://2025domestic.jag-icpc.org/team/problems/8/text

while True:
    N = int(input())
    if N == 0:
        break
    A = list(map(int,input().split()))
    Ai = list(range(1,100))
    # print(A)
    # print(Ai)
    ans = A[-1] + 1
    for i,j in zip(A,Ai):
        if i != j:
            ans = j
            break
    print(ans)