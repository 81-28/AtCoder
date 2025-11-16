// https://atcoder.jp/contests/abc291/tasks/abc291_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define all(v) v.begin(),v.end()

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi x(n*5);
    cin >> x;
    sort(all(x));
    cout<<fixed<<setprecision(8);
    print(accumulate(x.begin()+n,x.end()-n,0)/(3.0*n));

    return 0;
}
