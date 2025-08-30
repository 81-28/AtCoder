// https://atcoder.jp/contests/abc421/tasks/abc421_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define all(v) v.begin(),v.end()

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


int f(int n) {
    string s=to_string(n);
    reverse(all(s));
    int res=0;
    int m=s.size();
    int d=1;
    for (int i=m-1; i>=0; --i) {
        int c=s[i]-'0';
        res+=c*d;
        d*=10;
    }
    return res;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int x,y;
    cin >> x >> y;
    vi a(10);
    a[0]=x,a[1]=y;
    for (int i=2; i<10; ++i) a[i]=f(a[i-1]+a[i-2]);
    print(a[9]);

    return 0;
}
