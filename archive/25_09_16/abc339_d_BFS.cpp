// https://atcoder.jp/contests/abc339/tasks/abc339_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;
const pii dir[4]={{-1,0},{0,-1},{1,0},{0,1}};
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

#define f first
#define s second
// pairの足し算
template<typename F,typename S> pair<F,S> operator+(const pair<F,S>& a,const pair<F,S>& b){return{a.f+b.f,a.s+b.s};}
// pairの加算代入 (+=)
template<typename F,typename S> pair<F,S>& operator+=(pair<F,S>& a,const pair<F,S>& b){a.f+=b.f;a.s+=b.s;return a;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    v<string> st(n);
    cin >> st;
    v<string> str(n+2);
    str[0]=string(n+2,'#');
    rep1(i,n) str[i]='#'+st[i-1]+'#';
    str[n+1]=string(n+2,'#');
    v<pii> p;
    rep1(i,n)rep1(j,n) {
        if (str[i][j]=='P') {
            p.pb({i,j});
            str[i][j]='.';
        }
    }
    const int inf=INT_MAX;
    v<v<vvi>> d(n+1,v<vvi>(n+1,vvi(n+1,vi(n+1,inf))));
    queue<pair<pii,pii>> q;
    d[p[0].f][p[0].s][p[1].f][p[1].s]=0;
    q.push({p[0],p[1]});
    while (!q.empty()) {
        auto[p1,p2]=q.front();
        q.pop();
        int dist=d[p1.f][p1.s][p2.f][p2.s];
        rep(i,4) {
            rep1(j,3) {
                pii pp1=p1,pp2=p2;
                pii ppp1=p1+dir[i];
                pii ppp2=p2+dir[i];
                if (j%2) pp1+=dir[i];
                if (str[pp1.f][pp1.s]=='#' || (!(j%2) && str[ppp1.f][ppp1.s]=='.')) continue;
                if (j>>1) pp2+=dir[i];
                if (str[pp2.f][pp2.s]=='#' || (!(j>>1) && str[ppp2.f][ppp2.s]=='.')) continue;
                if (pp1==pp2) {
                    print(dist+1);
                    return 0;
                }
                if (chmin(d[pp1.f][pp1.s][pp2.f][pp2.s],dist+1)) q.push({pp1,pp2});
            }
        }
    }
    print(-1);

    return 0;
}
