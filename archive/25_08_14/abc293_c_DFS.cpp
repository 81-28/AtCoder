// https://atcoder.jp/contests/abc293/tasks/abc293_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;

#define f first
#define s second

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

int h,w;
vvi a;
map<int,int> m;
int dfs(const pii& p) {
    if (p==pii(h-1,w-1))  return 1;
    int res=0;
    if (p.f+1<h && m[a[p.f+1][p.s]]==0) {
        ++m[a[p.f+1][p.s]];
        res+=dfs({p.f+1,p.s});
        --m[a[p.f+1][p.s]];
    }
    if (p.s+1<w && m[a[p.f][p.s+1]]==0) {
        ++m[a[p.f][p.s+1]];
        res+=dfs({p.f,p.s+1});
        --m[a[p.f][p.s+1]];
    }
    return res;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> h >> w;
    a=vvi(h,vi(w));
    cin >> a;
    ++m[a[0][0]];
    print(dfs({0,0}));

    return 0;
}
