// https://atcoder.jp/contests/abc421/tasks/abc421_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

#define f first
#define s second
// pair同士の引き算
template<typename F,typename S> pair<F,S> operator-(const pair<F,S>& a,const pair<F,S>& b){return{a.f-b.f,a.s-b.s};}

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


void progress(pii& p,const char& c,const int& n) {
    if (c=='U') p.f-=n;
    if (c=='D') p.f+=n;
    if (c=='L') p.s-=n;
    if (c=='R') p.s+=n;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    pii a,b;
    int n,m,l;
    cin >> a >> b >> n >> m >> l;
    queue<pair<char,int>> qa,qb;
    rep(i,m) {
        pair<char,int> p;
        cin >> p;
        qa.push(p);
    }
    rep(i,l) {
        pair<char,int> p;
        cin >> p;
        qb.push(p);
    }
    int ans=0;
    // if (a==b) ++ans;
    while (!qa.empty() && !qb.empty()) {
        auto[c,i]=qa.front();
        auto[t,j]=qb.front();
        pii na=a,nb=b;
        int d=i;
        if (i==j) {
            qa.pop(),qb.pop();
            d=i;
        }
        if (i>j) {
            qb.pop();
            qa.front()={c,i-j};
            d=j;
        }
        if (i<j) {
            qa.pop();
            qb.front()={t,j-i};
            d=i;
        }
        progress(na,c,d);
        progress(nb,t,d);
        if (a==b) {
            if (c==t) ans+=d;
        } else {
            if (c!=t) {
                if (c=='U' && t=='D') {
                    if (a.s==b.s && a.f>b.f) {
                        int dif=a.f-b.f;
                        if (dif%2==0 && dif/2<=d) ++ans;
                    }
                } else if (c=='D' && t=='U') {
                    if (a.s==b.s && a.f<b.f) {
                        int dif=b.f-a.f;
                        if (dif%2==0 && dif/2<=d) ++ans;
                    }
                } else if (c=='L' && t=='R') {
                    if (a.f==b.f && a.s>b.s) {
                        int dif=a.s-b.s;
                        if (dif%2==0 && dif/2<=d) ++ans;
                    }
                } else if (c=='R' && t=='L') {
                    if (a.f==b.f && a.s<b.s) {
                        int dif=b.s-a.s;
                        if (dif%2==0 && dif/2<=d) ++ans;
                    }
                } else {
                    pii mid;
                    if (a.f==na.f && b.s==nb.s) mid={a.f,b.s};
                    if (a.s==na.s && b.f==nb.f) mid={b.f,a.s};
                    pii ma=mid-a;
                    pii mb=mid-b;
                    int da=abs(ma.f)+abs(ma.s);
                    int db=abs(mb.f)+abs(mb.s);
                    pii pa=na-a;
                    pii pb=nb-b;
                    if (da==db && da<=d) {
                        if (((ma.f>=0 && pa.f>=0) || (ma.f<=0 && pa.f<=0)) && ((ma.s>=0 && pa.s>=0) || (ma.s<=0 && pa.s<=0))) {
                            if (((mb.f>=0 && pb.f>=0) || (mb.f<=0 && pb.f<=0)) && ((mb.s>=0 && pb.s>=0) || (mb.s<=0 && pb.s<=0))) ++ans;
                        }
                    }
                }
            }
        }
        a=na,b=nb;
    }
    print(ans);

    return 0;
}
