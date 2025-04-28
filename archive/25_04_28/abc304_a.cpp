// https://atcoder.jp/contests/abc304/tasks/abc304_a

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(),v.end()
template<typename T>
using v=vector<T>;
using vi=v<int>;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    v<string> s(n);
    vi a(n);
    rep(i,n) cin >> s[i] >> a[i];
    auto it=min_element(all(a));
    int d=distance(a.begin(),it);
    rep(i,n) print(s[(i+d)%n]);

    return 0;
}
