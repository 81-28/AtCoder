// https://atcoder.jp/contests/abc390/tasks/abc390_a

#include<bits/stdc++.h>
using namespace std;

#define rep1(i,n) for(int i=1;i<(int)(n+1);i++)
#define pb push_back
#define YesNo(x) cout<<(x?"Yes\n":"No\n")
template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    vi a(5);
    cin >> a;
    vi d;
    rep1(i,5) {
        if (i!=a[i-1]) d.pb(i);
    }
    YesNo(d.size() == 2 && d[0]+1==d[1]);

    return 0;
}
