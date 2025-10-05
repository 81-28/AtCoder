// https://atcoder.jp/contests/abc306/tasks/abc306_e

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

    int n,k,q;
    cin >> n >> k >> q;
    vi a(n,0);
    multiset<int> r,l;
    int ans=0;
    rep(i,k) r.insert(a[i]);
    for (int i=k; i<n; ++i) l.insert(a[i]);
    while(q--) {
        int x,y;
        cin >> x >> y;
        --x;
        r.insert(y);
        ans+=y;
        int min_r=*r.begin();
        r.erase(r.find(min_r));
        ans-=min_r;
        l.insert(min_r);
        if (r.find(a[x])==r.end()) {
            l.erase(l.find(a[x]));
        } else {
            r.erase(r.find(a[x]));
            ans-=a[x];
            int max_l=*l.rbegin();
            l.erase(l.find(max_l));
            r.insert(max_l);
            ans+=max_l;
        }
        a[x] = y;
        print(ans);
    }

    return 0;
}