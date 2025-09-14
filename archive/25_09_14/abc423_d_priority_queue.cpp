// https://atcoder.jp/contests/abc423/tasks/abc423_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename... Args>
istream &operator>>(istream &is,tuple<Args...> &t){apply([&is](auto&... args){((is>>args),...);},t);return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k;
    cin >> n >> k;
    v<tuple<int,int,int>> t(n);
    rep(i,n) cin >> t[i];
    // {時刻,人数}
    priority_queue<pii,v<pii>,greater<>> q;
    auto[a0,b0,c0]=t[0];
    int sm=c0;
    int last=a0;
    print(last);
    q.push({a0+b0,-c0});
    for (int i=1; i<n; ++i) {
        auto[a,b,c]=t[i];
        while (!q.empty() && sm+c>k) {
            auto[tm,p]=q.top();
            q.pop();
            last=tm;
            sm+=p;
        }
        chmax(last,a);
        print(last);
        sm+=c;
        q.push({last+b,-c});
    }

    return 0;
}
