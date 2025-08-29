// https://atcoder.jp/contests/abc395/tasks/abc395_f

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

#define f first
#define s second
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

int x;
v<pii> p;
bool check(const int& h) {
    // 境目の下限,上限
    int l=0,r=h;
    for (auto[u,d]:p) {
        r=min({d,r+x,h});
        l=max({h-u,l-x,0LL});
        if (r<l) return 0;
    }
    return 1;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n >> x;
    p=v<pii>(n);
    int sm=0,l=0,r=LLONG_MAX;
    for (auto&[u,d]:p) {
        cin >> u >> d;
        sm+=u+d;
        chmin(r,u+d);
    }
    while (l<=r) {
        int m=(l+r)/2;
        if (check(m)) l=m+1;
        else r=m-1;
    }
    print(sm-r*n);

    return 0;
}
