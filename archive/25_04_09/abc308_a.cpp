// https://atcoder.jp/contests/abc308/tasks/abc308_a

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define YesNo(x) puts(x?"Yes":"No")
template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    vi s(8);
    cin >> s;
    rep(i,8) {
        if (i) {
            if (s[i]%25!=0 || s[i]<100 || 675<s[i]) {
                YesNo(0);
                return 0;
            }
        }
        if (s[i-1]>s[i]) {
            YesNo(0);
            return 0;
        }
    }
    YesNo(1);

    return 0;
}
