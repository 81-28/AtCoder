// https://atcoder.jp/contests/abc438/tasks/abc438_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi b;
    rep(i,n) {
        int a;
        cin >> a;
        b.pb(a);
        int m=b.size();
        if (m>3 && b[m-1]==b[m-2]&&b[m-2]==b[m-3]&&b[m-3]==b[m-4]) {
            rep(j,4) b.pop_back();
        }
    }
    print(b.size());

    return 0;
}
