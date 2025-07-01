// https://atcoder.jp/contests/abc386/tasks/abc386_a

#include<bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()
#define YesNo(x) cout<<(x?"Yes\n":"No\n")
template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    vi a(4);
    cin >> a;
    sort(all(a));
    if (a[0]==a[1] && a[1]!=a[2] && a[2]==a[3]) {
        YesNo(1);
        return 0;
    }
    if (a[0]!=a[1] && a[1]==a[2] && a[2]==a[3]) {
        YesNo(1);
        return 0;
    }
    if (a[0]==a[1] && a[1]==a[2] && a[2]!=a[3]) {
        YesNo(1);
        return 0;
    }
    YesNo(0);

    return 0;
}
