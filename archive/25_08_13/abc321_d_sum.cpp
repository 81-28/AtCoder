// https://atcoder.jp/contests/abc321/tasks/abc321_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(v) v.begin(),v.end()

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

template<typename T>
auto sum(const v<T>& v){return accumulate(v.begin(),v.end(),T{});}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m,p;
    cin >> n >> m >> p;
    vi a(n),b(m);
    cin >> a >> b;
    sort(all(a));
    sort(all(b));
    int j=m-1;
    int ans=0,sm=sum(b);
    rep(i,n) {
        while (0<=j && a[i]+b[j]>p) sm-=b[j--];
        ans+=a[i]*(j+1)+sm+p*(m-(j+1));
    }
    print(ans);

    return 0;
}
