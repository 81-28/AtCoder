# https://2025domestic.jag-icpc.org/team/problems/12/text

from collections import defaultdict

chars = list("qazwsxedcrfvtgbyhnujmikolp") + ["if"]
e = list(map(str,input().split("_")))
nest = 0
nests = defaultdict(int)
el = defaultdict(int)
le = len(e)
if le == 1:
    ans=int(e[0])
else:
    i = 0
    while i < le:
        if e[i] == "if":
            i += 2
            nest += 1
        elif e[i] == "else":
            el[nest] = 1
        else:
            nests[nest] += int(e[i])
            if el[nest] == 1:
                el[nest] = 0
                nest -= 1
        i += 1
        # print(nest,nests)

    ans = 0
    maxnest = max(list(nests.keys())) + 1

    for i,j in nests.items():
        ans += (maxnest - i) * j
print(ans%998244353)