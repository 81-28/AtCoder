// https://atcoder.jp/contests/joig2021-open/tasks/joig2021_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
#define all(v) v.begin(),v.end()
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


int m,d;
v<pii> p;
// 華やかさy以上のみを、d以上離して、m枚選ぶことができるかどうか
bool check(int y) {
    int last=-d;
    int cnt=0;
    for (auto[x,v]:p) {
        if (v>=y && x-last>=d) {
            ++cnt;
            last=x;
        }
    }
    return cnt>=m;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n >> m >> d;
    p=v<pii>(n);
    int mx=0;
    for (auto&[x,v]:p) {
        cin >> x >> v;
        chmax(mx,v);
    }
    sort(all(p));
    // [l,r)
    int l=-1,r=mx+1;
    while (l+1<r) {
        int mid=(l+r)/2;
        if (check(mid)) l=mid;
        else r=mid;
    }
    print(l);

    return 0;
}
