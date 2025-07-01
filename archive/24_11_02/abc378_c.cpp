// https://atcoder.jp/contests/abc378/tasks/abc378_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename T>
ostream &operator<<(ostream &os,const vector<T> &v){for(int i=0;i<(int)v.size();i++)os<<(i?" ":"")<<v[i];return os;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi b(n);
    unordered_map<int,int> m;
    int a;
    rep(i,n) {
        cin >> a;
        if (m[a]) b[i] = m[a];
        else b[i] = -1;
        m[a] = i+1;
    }
    print(b);

    return 0;
}
