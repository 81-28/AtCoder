// https://atcoder.jp/contests/abc386/tasks/abc386_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define YesNo(x) cout<<(x?"Yes\n":"No\n")

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int k;
    string s,t;
    cin >> k >> s >> t;
    int sn = s.size(), tn = t.size();
    int w=0;
    if (abs(sn-tn) <= 1) {
        if (sn==tn) {
            if (s==t) {
                YesNo(1);
                return 0;
            } else {
                rep(i,sn) {
                    if (s[i] != t[i]) {
                        if (w) {
                            YesNo(0);
                            return 0;
                        }
                        w++;
                    }
                }
                YesNo(1);
                return 0;
            }
        } else if(sn < tn) {
            int j=0;
            rep(i,sn) {
                if (s[i] != t[j]) {
                    if (w) {
                        YesNo(0);
                        return 0;
                    }
                    w++;
                    j++;
                }
                j++;
            }
            YesNo(1);
            return 0;
        } else {
            int j=0;
            rep(i,tn) {
                if (s[j] != t[i]) {
                    if (w) {
                        YesNo(0);
                        return 0;
                    }
                    w++;
                    j++;
                }
                j++;
            }
            YesNo(1);
            return 0;
        }
    }
    YesNo(0);

    return 0;
}
