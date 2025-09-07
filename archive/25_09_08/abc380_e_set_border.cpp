// https://atcoder.jp/contests/abc380/tasks/abc380_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    // 右端の数
    set<int> s;
    rep1(i,n) s.insert(i);
    // その数が属するまとまりの色
    vi c(n+1);
    rep1(i,n) c[i]=i;
    vi cnt(n+1,1);
    while (q--) {
        int m,x,nc;
        cin >> m >> x;
        if (m==1) {
            cin >> nc;
            auto it=s.lower_bound(x);
            int pc=c[*it];
            if (pc==nc) continue;
            int d=*it;
            if (it!=s.begin()) {
                --it;
                d-=*it;
                if (c[*it]==nc) s.erase(it);
            }
            cnt[pc]-=d;
            cnt[nc]+=d;
            it=s.lower_bound(x);
            auto itr=it;
            ++itr;
            if (itr!=s.end()) {
                if (c[*itr]==nc) {
                    s.erase(it);
                    continue;
                }
            }
            c[*it]=nc;
        } else print(cnt[x]);
    }

    return 0;
}
