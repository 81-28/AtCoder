// https://atcoder.jp/contests/abc302/tasks/abc302_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define f first
#define s second
template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
const pii dir[8]={{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename F,typename S>
ostream &operator<<(ostream &os,const pair<F,S> &p){os<<p.first<<' '<<p.second;return os;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}

// pairの足し算
template<typename F,typename S>
pair<F,S> operator+(const pair<F,S>& a,const pair<F,S>& b){return{a.f+b.f,a.s+b.s};}
// pairの加算代入 (+=)
template<typename F,typename S>
pair<F,S>& operator+=(pair<F,S>& a,const pair<F,S>& b){a.f+=b.f;a.s+=b.s;return a;}
// pairと定数の割り算
template<typename F,typename S,typename T>
pair<F,S> operator/(const pair<F,S>& p,const T& a){return{p.f/a,p.s/a};}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w;
    cin >> h >> w;
    v<string> st(h);
    cin >> st;
    string sn="snuke";
    rep(i,h)rep(j,w) {
        if (st[i][j]!=sn[0]) continue;
        rep(k,8) {
            bool ok=1;
            pii p={i,j};
            rep1(l,4) {
                p+=dir[k];
                if ((0<=p.f&&p.f<h&&0<=p.s&&p.s<w) && st[p.f][p.s]==sn[l]) continue;
                ok=0;
                break;
            }
            if (ok) {
                v<pii> ans(5);
                ans[0]={i+1,j+1};
                ans[4]=p+dir[5];
                ans[2]=(ans[0]+ans[4])/2;
                ans[1]=(ans[0]+ans[2])/2;
                ans[3]=(ans[2]+ans[4])/2;
                rep(l,5) print(ans[l]);
                return 0;
            }
        }
    }

    return 0;
}
