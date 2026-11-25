// https://atcoder.jp/contests/abc229/tasks/abc229_c

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
#define rall(v) v.rbegin(),v.rend()

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,w;
    cin >> n >> w;
    v<pii> p(n);
    for (auto&[a,b]:p) cin >> a >> b;
    sort(rall(p));
    int ans=0;
    for (auto[a,b]:p) {
        if (w<=b) {
            ans+=a*w;
            break;
        }
        ans+=a*b;
        w-=b;
    }
    print(ans);

    return 0;
}
