// https://atcoder.jp/contests/abc338/tasks/abc338_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
template<typename T>
using v=vector<T>;
using vi=v<int>;
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}

template<typename T>
T max(const vector<T>& v){return *max_element(v.begin(),v.end());}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();
    vi c(26,0);
    rep(i,n) c[s[i]-'a']++;
    int m = max(c);
    rep(i,26) if (c[i]==m) {
        print((char)('a'+i));
        break;
    }

    return 0;
}
