// https://atcoder.jp/contests/arc164/tasks/arc164_c

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
#define rep(i,n) for(int i=0;i<(int)(n);++i)

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    multiset<int> a,b;
    int sm=0;
    rep(i,n) {
        int x,y;
        cin >> x >> y;
        sm+=x;
        a.insert(y-x);
    }
    rep(i,n) {
        int c;
        if (b.size()) c=*b.rbegin();
        if (b.size() && (!a.size() || c>=0)) {
            a.insert(c);
            b.erase(b.find(c));
        } else {
            b.insert(*a.begin());
            a.erase(a.begin());
        }
        if (b.size()) c=*b.rbegin();
        if (b.size() && (!a.size() || c>=0 || -c<*a.begin())) {
            sm+=c;
            b.erase(b.find(c));
        } else {
            a.erase(a.begin());
        }
    }
    print(sm);

    return 0;
}
