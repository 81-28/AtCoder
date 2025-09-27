// https://atcoder.jp/contests/abc425/tasks/abc425_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
const pii dir[4]={{-1,0},{0,-1},{1,0},{0,1}};
#define rep(i,n) for(int i=0;i<(int)(n);++i)

#define f first
#define s second
// pairの加算代入 (+=)
template<typename F,typename S> pair<F,S>& operator+=(pair<F,S>& a,const pair<F,S>& b){a.f+=b.f;a.s+=b.s;return a;}

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w;
    cin >> h >> w;
    v<string> st(h);
    cin >> st;
    // 確定
    v<v<bool>> b(h,v<bool>(w,0));
    // {i,j}
    queue<pii> q;
    int ans=0;
    rep(i,h)rep(j,w) {
        if (st[i][j]=='#') {
            ++ans;
            b[i][j]=1;
            rep(k,4) {
                pii p={i,j};
                p+=dir[k];
                if (0<=p.f&&p.f<h && 0<=p.s&&p.s<w && st[p.f][p.s]=='.') {
                    q.push(p);
                }
            }
        }
    }
    int pans=-1;
    while (ans!=pans) {
        pans=ans;
        map<pii,int> cnt;
        while (!q.empty()) {
            pii p=q.front();
            q.pop();
            ++cnt[p];
        }
        for (auto[p,num]:cnt) {
            if (num==1) {
                if (b[p.f][p.s]) continue;
                ++ans;
                rep(k,4) {
                    pii pp=p;
                    pp+=dir[k];
                    if (0<=pp.f&&pp.f<h && 0<=pp.s&&pp.s<w && !b[pp.f][pp.s]) {
                        q.push(pp);
                    }
                }
            }
            b[p.f][p.s]=1;
        }
    }
    print(ans);

    return 0;
}
