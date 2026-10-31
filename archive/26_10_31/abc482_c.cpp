// https://atcoder.jp/contests/abc482/tasks/abc482_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define pb push_back
#define all(v) v.begin(),v.end()

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w,n,q;
    cin >> h >> w >> n >> q;
    vi r,c;
    while (n--) {
        int x,y;
        cin >> x >> y;
        r.pb(x),c.pb(y);
    }
    sort(all(r)),sort(all(c));
    while (q--) {
        int m,x,y;
        cin >> m >> x >> y;
        if (m&1) {
            auto itl=lower_bound(all(r),x);
            auto itr=upper_bound(all(r),y);
            print(itr-itl);
        } else {
            auto itl=lower_bound(all(c),x);
            auto itr=upper_bound(all(c),y);
            print(itr-itl);
        }
    }

    return 0;
}
