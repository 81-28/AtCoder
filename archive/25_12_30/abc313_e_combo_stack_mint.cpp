// https://atcoder.jp/contests/abc313/tasks/abc313_e

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

using pii=pair<int,int>;
using mint=modint998244353;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    // {数,個数}
    stack<pii> t;
    int cmb=1;
    rep(i,n-1) {
        if (s[i]!=s[i+1]) {
            t.push({s[i]-'0',cmb});
            cmb=0;
        }
        ++cmb;
    }
    t.push({s[n-1]-'0',cmb});
    mint ans=0;
    int numl=1,cntl=0;
    while (!t.empty()) {
        auto[num,cnt]=t.top();
        t.pop();
        if ((num>1)*cnt+(numl>1)*cntl>1) {
            print(-1);
            return 0;
        }
        ans+=cnt+ans*(numl-1);
        numl=num,cntl=cnt;
    }
    print((ans-1).val());

    return 0;
}
