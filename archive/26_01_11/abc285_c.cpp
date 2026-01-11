// https://atcoder.jp/contests/abc285/tasks/abc285_c

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    // vi six(14,1);
    // rep1(i,13) six[i]=six[i-1]*26;
    string s;
    cin >> s;
    int n=s.size();
    int ans=0;
    // rep(i,n) ans+=six[i];
    // rep(i,n) ans+=six[i]*(s[n-1-i]-'A');
    int add=1;
    rep(i,n) {
        ans+=add*(s[n-1-i]-'A'+1);
        add*=26;
    }
    print(ans);

    return 0;
}
