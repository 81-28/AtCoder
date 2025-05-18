// https://atcoder.jp/contests/abc370/tasks/abc370_d

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

    int h,w,q;
    cin >> h >> w >> q;
    int ans=h*w;
    v<set<int>> r(h),c(w);
    rep(i,h)rep(j,w) {
        r[i].insert(j);
        c[j].insert(i);
    }
    pii p;
    auto itr=r[0].begin(),itc=c[0].begin();
    rep(i,q) {
        cin >> p;
        --p;
        itr=r[p.f].lower_bound(p.s);
        itc=c[p.s].lower_bound(p.f);
        if (itr!=r[p.f].end() && *itr==p.s) {
            r[p.f].erase(itr);
            c[p.s].erase(itc);
            --ans;
            continue;
        }
        if (itr!=r[p.f].begin()) {
            --itr;
            c[*itr].erase(p.f);
            itr=r[p.f].erase(itr);
            --ans;
        }
        if (itr!=r[p.f].end()) {
            c[*itr].erase(p.f);
            r[p.f].erase(itr);
            --ans;
        }
        if (itc!=c[p.s].begin()) {
            --itc;
            r[*itc].erase(p.s);
            itc=c[p.s].erase(itc);
            --ans;
        }
        if (itc!=c[p.s].end()) {
            r[*itc].erase(p.s);
            c[p.s].erase(itc);
            --ans;
        }
    }
    print(ans);

    return 0;
}
