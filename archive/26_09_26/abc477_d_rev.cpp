// https://atcoder.jp/contests/abc477/tasks/abc477_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using vb=v<bool>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    string b(n,0);
    v<pii> p(q);
    for (auto&[m,x]:p) {
        cin >> m;
        if (m&1) {
            cin >> x;
            b[--x]^=1;
        } else {
            char c;
            cin >> c;
            x=c-'a';
        }
    }
    vb done(n,0);
    string ans(n,'a');
    set<int> s;
    rep(i,n) {
        if (!b[i]) s.insert(i);
    }
    for (int i=q-1; i>=0; --i) {
        auto[m,x]=p[i];
        if (m&1) {
            b[x]^=1;
            if (done[x]) continue;
            if (b[x]) s.erase(x);
            else s.insert(x);
        } else {
            for (auto it=s.begin(); s.size(); it=s.erase(it)) {
                int j=*it;
                ans[j]+=x;
                done[j]=1;
            }
        }
    }
    print(ans);

    return 0;
}
