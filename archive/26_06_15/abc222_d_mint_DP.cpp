// https://atcoder.jp/contests/abc222/tasks/abc222_d

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using mint=modint998244353;

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a(n),b(n);
    cin >> a >> b;
    int mi=a[0],mx=b[n-1];
    // c[i][j]:i-1番目がjであるときのパターン数
    vector c(n+1,v<mint>(mx+2,0));
    c[n]=v<mint>(mx+2,1);
    for (int i=n-1; i>=0; --i) {
        for (int j=b[i]; j>=mi; --j) c[i][j]=c[i+1][j]*(j>=a[i])+c[i][j+1];
    }
    print(c[0][mi].val());

    return 0;
}
