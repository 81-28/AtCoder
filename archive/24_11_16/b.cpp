// https://atcoder.jp/contests/abc380/tasks/abc380_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
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

    string s;
    cin >> s;
    int n = s.size();
    int combo = 0;
    vi a;
    rep(i,n) {
        if (s[i] == '-') {
            combo++;
        } else {
            if (combo>0) {
                a.pb(combo);
            }
            combo=0;
        }
    }
    print(a);

    return 0;
}
