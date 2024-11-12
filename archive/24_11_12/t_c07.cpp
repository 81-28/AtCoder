// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_fe

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(),v.end()
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
    vi c(n);
    cin >> c;
    sort(all(c));
    vi a(n+1,0);
    rep(i,n)a[i+1] = a[i]+c[i];
    int q,x;
    cin >> q;
    rep(i,q) {
        cin >> x;
        auto it = upper_bound(all(a),x);
        print(it-a.begin()-1);
    }

    return 0;
}
