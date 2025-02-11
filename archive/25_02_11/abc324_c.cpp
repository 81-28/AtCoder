// https://atcoder.jp/contests/abc324/tasks/abc324_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<(int)(n+1);i++)
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

    int n;
    string t;
    cin >> n >> t;
    vi ans;
    string s;
    int sn,tn=t.size();
    int c,d;
    rep1(i,n) {
        cin >> s;
        sn = s.size();
        c=0;
        d = abs(sn-tn);
        if (d < 2) {
            if (d) {
                if (sn < tn) {
                    rep(j,sn) {
                        if (s[j] != t[j+c]) {
                            c++;
                            j--;
                        }
                        if (c>1) break;
                    }
                } else {
                    rep(j,tn) {
                        if (s[j+c] != t[j]) {
                            c++;
                            j--;
                        }
                        if (c>1) break;
                    }
                }
            } else {
                rep(j,tn) {
                    if (s[j] != t[j]) c++;
                    if (c>1) break;
                }
            }
            if (c<2) ans.pb(i);
        }
    }
    print(ans.size());
    print(ans);

    return 0;
}
