// https://atcoder.jp/contests/abc276/tasks/abc276_a

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    for(int i=s.size()-1; i>=0; --i) {
        if(s[i]=='a') {
            print(i+1);
            return 0;
        }
    }
    print(-1);

    return 0;
}
