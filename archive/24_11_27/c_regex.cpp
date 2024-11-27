// https://atcoder.jp/contests/abc381/tasks/abc381_c

#include<bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,sn,pos,r,ans=0;
    string s,ms;
    cin >> n >> s;
    regex pattern(R"(1*/2*)");
    for (sregex_iterator it(all(s),pattern), end_it; it != end_it; ++it) {
        ms = it->str();
        sn = ms.size();
        pos = ms.find('/');
        r = sn-1-pos;
        ans = max(ans,min(pos,r)*2+1);
    }
    print(ans);

    return 0;
}
