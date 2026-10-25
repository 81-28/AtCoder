// https://atcoder.jp/contests/abc442/tasks/abc442_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
#define all(v) v.begin(),v.end()

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


bool up(const pii& p) {return p.second>0 || (p.second==0 && p.first>0);}
int cross(const pii& a,const pii& b) {return a.first*b.second-a.second*b.first;}
bool comp(const pii& a,const pii& b) {return up(a)!=up(b) ? up(a)>up(b) : cross(a,b)>0;}

signed main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    v<pii> p(n);
    for (auto& [x,y]:p) cin >> x >> y;
    v<pii> pp=p;
    sort(all(pp),comp);
    while (q--) {
        int a,b;
        cin >> a >> b;
        auto ita=upper_bound(all(pp),p[--a],comp);
        auto itb=lower_bound(all(pp),p[--b],comp);
        print(ita-itb + (ita>itb ? 0:n));
    }

    return 0;
}
