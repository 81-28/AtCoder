// https://atcoder.jp/contests/abc459/tasks/abc459_c

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

    int n,q;
    cin >> n >> q;
    vi cnt(n,0);
    map<int,int> mp={{0,n}};
    multiset<int> st;
    rep(i,n) st.insert(0);
    while (q--) {
        int m,x;
        cin >> m >> x;
        if (m==1) {
            --x;
            st.erase(st.find(cnt[x]));
            ++cnt[x];
            st.insert(cnt[x]);
            ++mp[cnt[x]];

        } else {
            int l=x+*st.begin();
            print(mp[l]);
        }
    }

    return 0;
}
