// https://atcoder.jp/contests/abc228/tasks/abc228_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n=1<<20;
    vi a(n,-1);
    // a[i]=-1であるようなi
    set<int> s;
    rep(i,n) s.insert(i);
    int q;
    cin >> q;
    while (q--) {
        int t,x;
        cin >> t >> x;
        if (t==1) {
            auto it=s.lower_bound(x%n);
            if (it==s.end()) it=s.lower_bound(0);
            a[*it]=x;
            s.erase(it);
        } else print(a[x%n]);
    }

    return 0;
}
