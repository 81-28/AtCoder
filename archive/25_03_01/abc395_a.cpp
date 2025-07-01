// https://atcoder.jp/contests/abc395/tasks/abc395_a

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
    for (int i=1; i<n; i++) {
        if (a[i-1] >= a[i]) {
            YesNo(0);
            return 0;
        }
    }
    YesNo(1);


    return 0;
}
