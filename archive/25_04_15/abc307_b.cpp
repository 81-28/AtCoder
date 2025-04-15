// https://atcoder.jp/contests/abc307/tasks/abc307_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define YesNo(x) puts(x?"Yes":"No")
template<typename T>
using v=vector<T>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}

bool isPal(const string& s,const string& t) {
    string st=s+t;
    int l=0,r=st.size()-1;
    while (l<r) {
        if (st[l]!=st[r]) return 0;
        l++,r--;
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    v<string> s(n);
    cin >> s;
    rep(i,n)rep(j,n) {
        if (i!=j && isPal(s[i],s[j])) {
            YesNo(1);
            return 0;
        }
    }
    YesNo(0);

    return 0;
}
