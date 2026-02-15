// https://atcoder.jp/contests/abc271/tasks/abc271_d

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,s;
    cin >> n >> s;
    map<int,string> dp={{0,""}};
    while (n--) {
        int a,b;
        cin >> a >> b;
        map<int,string> dpn;
        for (auto[num,t]:dp) {
            dpn[num+a]=t+'H';
            dpn[num+b]=t+'T';
        }
        dp=dpn;
    }
    bool ok=dp[s]!="";
    YesNo(ok);
    if (ok) print(dp[s]);

    return 0;
}
