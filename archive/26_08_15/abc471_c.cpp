// https://atcoder.jp/contests/abc471/tasks/abc471_c

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    set<pii> s;
    rep(i,n) {
        int a;
        cin >> a;
        s.insert({a,i});
    }
    int pos=0,ans=0;
    while (!s.empty()) {
        bool b=0;
        auto itr=s.upper_bound({pos,0});
        auto[r,i]=*itr;
        int dr=r-pos;
        auto itl=s.lower_bound({pos,0});
        if (itl!=s.begin()) {
            --itl;
            b=1;
        }
        auto[l,j]=*itl;
        int dl=pos-l;
        if (itr!=s.end()) {
            if (b) {
                if (dl==dr) {
                    ans+=dl;
                    pos=l;
                    s.erase(itl);
                } else {
                    if (dl>dr) {
                        ans+=dr;
                        pos=r;
                        s.erase(itr);
                    } else {
                        ans+=dl;
                        pos=l;
                        s.erase(itl);
                    }
                }
            } else {
                ans+=dr;
                pos=r;
                s.erase(itr);
            }
        } else {
            if (b) {
                ans+=dl;
                pos=l;
                s.erase(itl);
            }
        }
    }
    print(ans);

    return 0;
}
