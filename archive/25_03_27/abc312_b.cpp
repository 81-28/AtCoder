// https://atcoder.jp/contests/abc312/tasks/abc312_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
template<typename T>
using v=vector<T>;
using pii=pair<int,int>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}
template<typename F,typename S>
ostream &operator<<(ostream &os,const pair<F,S> &p){os<<p.first<<" "<<p.second;return os;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    v<string> s(n);
    cin >> s;
    v<pii> ans;
    bool ok;
    rep(i,n-8)rep(j,m-8) {
        ok=1;
        rep(y,4) {
            rep(x,4) {
                if (x==3||y==3) {
                    if (s[i+y][j+x]!='.'||s[i+8-y][j+8-x]!='.') {
                        ok=0;
                        break;
                    }
                } else {
                    if (s[i+y][j+x]!='#'||s[i+8-y][j+8-x]!='#') {
                        ok=0;
                        break;
                    }
                }
            }
            if (!ok) break;
        }
        if (ok) ans.pb({i+1,j+1});
    }
    for (pii p:ans) print(p);

    return 0;
}
