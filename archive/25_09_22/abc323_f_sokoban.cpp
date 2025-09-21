// https://atcoder.jp/contests/abc323/tasks/abc323_f

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
using pii=pair<int,int>;

#define f first
#define s second

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    pii a,b,c;
    cin >> a >> b >> c;
    pii d={c.f-b.f,c.s-b.s};
    if (d.f) {
        if (d.s) {
            pii e={d.f/abs(d.f),d.s/abs(d.s)};
            pii ab={abs(b.f-e.f-a.f)+abs(b.s-a.s),
                    abs(b.f-a.f)+abs(b.s-e.s-a.s)};
            print(min(ab.f,ab.s)+abs(c.f-b.f)+2+abs(c.s-b.s));
        } else {
            if (a.s==b.s) {
                if ((a.f<b.f&&b.f<c.f)||(c.f<b.f&&b.f<a.f)) {
                    print(abs(c.f-a.f)-1);
                } else {
                    print(1+abs(b.f-a.f)+2+abs(c.f-b.f));
                }
            } else {
                int e=d.f/abs(d.f);
                print(abs(b.f-e-a.f)+abs(b.s-a.s)+abs(c.f-b.f));
            }
        }
    } else {
        if (d.s) {
            if (a.f==b.f) {
                if ((a.s<b.s&&b.s<c.s)||(c.s<b.s&&b.s<a.s)) {
                    print(abs(c.s-a.s)-1);
                } else {
                    print(1+abs(b.s-a.s)+2+abs(c.s-b.s));
                }
            } else {
                int e=d.s/abs(d.s);
                print(abs(b.s-e-a.s)+abs(b.f-a.f)+abs(c.s-b.s));
            }
        } else {
            print(0);
        }
    }

    return 0;
}
