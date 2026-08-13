// https://atcoder.jp/contests/abc192/tasks/abc192_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename S,typename T>
inline bool chmax(S& a,const T& b){if(a<b){a=b;return 1;}return 0;}

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


string x;
int m,l;
bool ok(int n) {
    int sm=0;
    for (char c:x) {
        if (sm>m/n) return 0;
        sm*=n;
        sm+=c-'0';
        if (sm>m) return 0;
    }
    return 1;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> x >> m;
    l=x.size();
    if (l==1) {
        print(x[0]-'0'<=m);
        return 0;
    }
    int d=0;
    for (char c:x) chmax(d,c-'0');
    int l=d,r=m+1;
    while (l+1<r) {
        int mid=(l+r)/2;
        if (ok(mid)) l=mid;
        else r=mid;
    }
    print(l-d);

    return 0;
}
