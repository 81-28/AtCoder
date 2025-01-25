// https://atcoder.jp/contests/abc390/tasks/abc390_b

#include<bits/stdc++.h>
using namespace std;

#define YesNo(x) cout<<(x?"Yes\n":"No\n")
template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    double r;
    r = (double)a[1]/(double)a[0];
    for (int i = 1; i < n-1; i++) {
        if (a[i]*r != a[i+1]) {
            YesNo(0);
            return 0;
        }
    }
    YesNo(1);

    return 0;
}
