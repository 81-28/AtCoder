// https://atcoder.jp/contests/abc335/tasks/abc335_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
#define f first
#define s second
template<typename T>
using v=vector<T>;
using pii=pair<int,int>;

template<typename F,typename S>
ostream &operator<<(ostream &os,const pair<F,S> &p){os<<p.first<<" "<<p.second;return os;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    v<pii> pos(n);
    rep(i,n) pos[i] = {n-i,0};
    int idx=n;
    int m,p;
    char c;
    pii h;
    rep(i,q) {
        cin >> m;
        if (m==1) {
            h=pos[idx-1];
            cin >> c;
            if (c=='R') pos.pb({h.f+1,h.s});
            if (c=='L') pos.pb({h.f-1,h.s});
            if (c=='U') pos.pb({h.f,h.s+1});
            if (c=='D') pos.pb({h.f,h.s-1});
            idx++;
        }
        if (m==2) {
            cin >> p;
            print(pos[idx-p]);
        }
    }

    return 0;
}
