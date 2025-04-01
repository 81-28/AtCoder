// https://atcoder.jp/contests/abc310/tasks/abc310_a

#include<bits/stdc++.h>
using namespace std;

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

    int n,p,q;
    cin >> n >> p >> q;
    vi d(n);
    cin >> d;
    print(min(p,q+min(d)));

    return 0;
}
