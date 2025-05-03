// https://atcoder.jp/contests/abc404/tasks/abc404_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}

template<typename T>
T min(const vector<T>& v){return *min_element(v.begin(),v.end());}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    v<string> s(n),t(n);
    cin >> s >> t;
    vi d(4);
    rep(i,4)d[i]=i;
    rep(i,n)rep(j,n) {
        if (t[i][j]!=s[i][j]) d[0]++;
        if (t[i][j]!=s[n-1-j][i]) d[1]++;
        if (t[i][j]!=s[n-1-i][n-1-j]) d[2]++;
        if (t[i][j]!=s[j][n-1-i]) d[3]++;
    }
    print(min(d));

    return 0;
}
