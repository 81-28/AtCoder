// https://atcoder.jp/contests/abc382/tasks/abc382_d

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;

template<typename T>
ostream &operator<<(ostream &os,const vector<T> &v){for(int i=0;i<(int)v.size();i++)os<<(i?" ":"")<<v[i];return os;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    int d = m-10*(n-1);

    vvi a(1,vi(n,1));
    for (int i=1; a[i-1][0] != d; i++) {
        a.pb(a[i-1]);
        a[i][n-1]++;
        int j = n-1;
        while(j>=0) {
            if (a[i][j] > d) {
                a[i][j-1]++;
                a[i][j] = a[i][j-1];
                j--;
            } else break;
        }
        j++;
        for (; j<n; j++) a[i][j] = a[i][j-1];
    }

    vi b(n);
    rep(j,n) b[j] = j*10;

    int x = a.size();
    rep(i,x) rep(j,n) a[i][j] += b[j];
    print(x);
    rep(i,x) print(a[i]);

    return 0;
}
