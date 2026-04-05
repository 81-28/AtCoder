// https://atcoder.jp/contests/abc265/tasks/abc265_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using pii=pair<int,int>;

#define f first
#define s second

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w;
    cin >> h >> w;
    v<string> g(h);
    cin >> g;
    set<pii> st;
    pii p={0,0};
    while (1) {
        st.insert(p);
        auto&[x,y]=p;
        if (g[x][y]=='U') {
            if (x==0) break;
            --x;
        }
        if (g[x][y]=='D') {
            if (x==h-1) break;
            ++x;
        }
        if (g[x][y]=='L') {
            if (y==0) break;
            --y;
        }
        if (g[x][y]=='R') {
            if (y==w-1) break;
            ++y;
        }
        if (st.find(p)!=st.end()) {
            print(-1);
            return 0;
        }
    }
    print(p.f+1,p.s+1);

    return 0;
}
