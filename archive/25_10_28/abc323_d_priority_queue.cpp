// https://atcoder.jp/contests/abc323/tasks/abc323_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using pii=pair<int,int>;

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    // {サイズ,匹数}
    priority_queue<pii,v<pii>,greater<>> q;
    while (n--) {
        pii p;
        cin >> p;
        q.push(p);
    }
    int ans=0;
    while (!q.empty()) {
        auto[s,c]=q.top();
        q.pop();
        while (!q.empty()) {
            auto[ss,cc]=q.top();
            if (s!=ss) break;
            q.pop();
            c+=cc;
        }
        ans+=c&1;
        if (c>>1) q.push({s<<1,c>>1});
    }
    print(ans);

    return 0;
}
