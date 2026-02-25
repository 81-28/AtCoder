// https://atcoder.jp/contests/abc268/tasks/abc268_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

template<typename T>
T max(const v<T>& v){return *max_element(v.begin(),v.end());}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi ans(n,0);
    rep(i,n) {
        int p;
        cin >> p;
        ++ans[(p-i+n-1)%n];
        ++ans[(p-i+n)%n];
        ++ans[(p-i+n+1)%n];
    }
    print(max(ans));

    return 0;
}
