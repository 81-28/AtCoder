// https://atcoder.jp/contests/abc399/tasks/abc399_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rall(v) v.rbegin(),v.rend()
#define f first
#define s second
template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;

template<typename T>
ostream &operator<<(ostream &os,const vector<T> &v){for(int i=0;i<(int)v.size();i++)os<<(i?" ":"")<<v[i];return os;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    v<pii> p(n);
    rep(i,n) {
        cin >> p[i].f;
        p[i].s = i;
    }
    sort(rall(p));
    map<int,int> m;
    vi ans(n);
    int r=1;
    rep(i,n) {
        if (m[p[i].f]) {
            ans[p[i].s] = m[p[i].f];
        } else {
            ans[p[i].s] = r;
            m[p[i].f] = r;
        }
        r++;
    }
    print(ans);

    return 0;
}
