// https://atcoder.jp/contests/abc325/tasks/abc325_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;

#define f first
#define s second

template<typename F,typename S>
istream &operator>>(istream &is,pair<F,S> &p){is>>p.first>>p.second;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    v<pii> p(n);
    // {入る時間,出るまでの時間}
    priority_queue<pii,v<pii>,greater<>> q;
    while (n--) {
        pii p;
        cin >> p;
        q.push(p);
    }
    // 出る時間
    priority_queue<int,vi,greater<>> pq;
    int t=0,ans=0;
    while (!q.empty() || !pq.empty()) {
        if (!q.empty()) {
            if (pq.empty()) t=q.top().f;
            for (pii p=q.top(); p.f==t; p=q.top()) {
                pq.push(p.f+p.s);
                q.pop();
                if (q.empty()) break;
            }
        }
        ++ans;
        pq.pop();
        if (pq.empty()) continue;
        for (int i=pq.top(); i==t; i=pq.top()) {
            pq.pop();
            if (pq.empty()) break;
        }
        ++t;
    }
    print(ans);

    return 0;
}
