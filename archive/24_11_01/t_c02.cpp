// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ez

#include<bits/stdc++.h>
using namespace std;

#define rall(v) v.rbegin(),v.rend()
template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    sort(rall(a));
    print(a[0]+a[1]);

    return 0;
}
