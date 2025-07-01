// https://atcoder.jp/contests/abc406/tasks/abc406_d

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define f first
#define s second
template<typename T>
using v=vector<T>;
using pii=pair<int,int>;

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}

template<typename F,typename S>
pair<F,S>& operator--(pair<F,S>& p){--p.f;--p.s;return p;}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w,n;
    cin >> h >> w >> n;
    v<unordered_set<int>> r(h),c(w);
    pii p;
    rep(i,n) {
        cin >> p;
        --p;
        r[p.f].insert(p.s);
        c[p.s].insert(p.f);
    }
    int q;
    cin >> q;
    rep(i,q) {
        cin >> p;
        --p.s;
        if (p.f==1) {
            print(r[p.s].size());
            for (int val:r[p.s]) {
                auto it=c[val].find(p.s);
                if (it!=c[val].end()) c[val].erase(it);
            }
            r[p.s]=unordered_set<int>();
        }
        if (p.f==2) {
            print(c[p.s].size());
            for (int val:c[p.s]) {
                auto it=r[val].find(p.s);
                if (it!=r[val].end()) r[val].erase(it);
            }
            c[p.s]=unordered_set<int>();
        }
    }

    return 0;
}
