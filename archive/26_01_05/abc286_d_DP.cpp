// https://atcoder.jp/contests/abc286/tasks/abc286_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vb=v<bool>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,x;
    cin >> n >> x;
    // dp[i]:i円を払うことができるか
    vb dp(x+1,0);
    dp[0]=1;
    while (n--) {
        int a,b;
        cin >> a >> b;
        vb dpn=dp;
        rep(i,x) {
            if (!dp[i]) continue;
            rep1(j,b) {
                int k=i+j*a;
                if (k>x) break;
                dpn[k]=1;
            }
        }
        dp=dpn;
    }
    YesNo(dp[x]);

    return 0;
}
