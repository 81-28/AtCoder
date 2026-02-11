// https://atcoder.jp/contests/abc274/tasks/abc274_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,x,y;
    cin >> n >> x >> y;
    vi a(n);
    cin >> a;
    v<map<int,bool>> b(2);
    b[0][a[0]]=b[1][0]=1;
    rep1(i,n-1) {
        map<int,bool> bn;
        for (auto[num,bl]:b[i&1]) bn[num+a[i]]=bn[num-a[i]]=1;
        b[i&1]=bn;
    }
    YesNo(b[0][x]&&b[1][y]);

    return 0;
}
