// https://atcoder.jp/contests/abc311/tasks/abc311_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
template<typename T>
using v=vector<T>;
template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,d;
    cin >> n >> d;
    v<string> s(n);
    cin >> s;
    v<bool> b(d);
    bool ok;
    rep(i,d){
        ok=1;
        rep(j,n) {
            if (s[j][i]=='x') {
                ok=0;
                break;
            }
        }
        b[i]=ok;
    }
    for (int i=d; i>0; i--) {
        for (int j=0; j+i<=d; j++) {
            ok=1;
            rep(k,i) {
                if (!b[j+k]) {
                    ok=0;
                    break;
                }
            }
            if (ok) {
                print(i);
                return 0;
            }
        }
    }
    print(0);

    return 0;
}
