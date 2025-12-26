// https://atcoder.jp/contests/joi2009yo/tasks/joi2009yo_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

#define f first
#define s second

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    // {色,個数}
    v<pii> c;
    int cmb=1;
    rep(i,n-1) {
        if (a[i]!=a[i+1]) {
            c.pb({a[i],cmb});
            cmb=0;
        }
        ++cmb;
    }
    c.pb({a[n-1],cmb});
    int m=c.size();
    int ans=0;
    // 全ての書き換えを試す
    rep(i,m) {
        auto[col,num]=c[i];
        // 個数が1の場合、その区間が全て置き換わる
        if (num==1) {
            int j=i-1,k=i+1;
            if (j<0 || m<=k) continue;
            pii l=c[j],r=c[k];
            int sm=0;
            if (l.f==r.f) {
                sm+=l.s+r.s+1;
                if (sm<4) continue;
                while (0<=--j && ++k<m) {
                    l=c[j],r=c[k];
                    if (l.f!=r.f) break;
                    int add=l.s+r.s;
                    if (add<4) break;
                    sm+=add;
                }
                chmax(ans,sm);
            } else {
                ++l.s;
                if (l.s>=4) {
                    sm+=l.s;
                    --k;
                    while (0<=--j && ++k<m) {
                        l=c[j],r=c[k];
                        if (l.f!=r.f) break;
                        int add=l.s+r.s;
                        if (add<4) break;
                        sm+=add;
                    }
                    chmax(ans,sm);
                }
                j=i-1,k=i+1;
                l=c[j],r=c[k];
                sm=0;
                ++r.s;
                if (r.s>=4) {
                    sm+=r.s;
                    ++j;
                    while (0<=--j && ++k<m) {
                        l=c[j],r=c[k];
                        if (l.f!=r.f) break;
                        int add=l.s+r.s;
                        if (add<4) break;
                        sm+=add;
                    }
                    chmax(ans,sm);
                }
            }
        } else {
            // 個数が2以上の場合、両端を試す
            int j=i-1,k=i;
            if (j>=0) {
                pii l=c[j],r=c[k];
                int sm=0;
                ++l.s,--r.s;
                if (l.s>=4) {
                    sm+=l.s;
                    --j;
                    if (j>=0) {
                        l=c[j];
                        if (l.f==l.s) {
                            int add=l.s+r.s;
                            if (add>=4) {
                                sm+=add;
                                while (0<=--j && ++k<m) {
                                    l=c[j],r=c[k];
                                    if (l.f!=r.f) break;
                                    add=l.s+r.s;
                                    if (add<4) break;
                                    sm+=add;
                                }
                            }
                        }
                    }
                    chmax(ans,sm);
                }
            }
            j=i,k=i+1;
            if (k<m) {
                pii l=c[j],r=c[k];
                int sm=0;
                --l.s,++r.s;
                if (r.s>=4) {
                    sm+=r.s;
                    ++k;
                    if (k<m) {
                        r=c[k];
                        if (l.f==r.f) {
                            int add=l.s+r.s;
                            if (add>=4) {
                                sm+=add;
                                while (0<=--j && ++k<m) {
                                    l=c[j],r=c[k];
                                    if (l.f!=r.f) break;
                                    add=l.s+r.s;
                                    if (add<4) break;
                                    sm+=add;
                                }
                            }
                        }
                    }
                    chmax(ans,sm);
                }
            }
        }
    }
    print(n-ans);

    return 0;
}
