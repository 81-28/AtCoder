// https://atcoder.jp/contests/abc329/tasks/abc329_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}

template<typename T>
auto sum(const vector<T>& v){return accumulate(v.begin(),v.end(),T{});}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    vi c(26,0);
    int combo = 1;
    for (int i=1; i<n; i++) {
        if (s[i-1] == s[i]) {
            combo++;
        } else {
            int idx = s[i-1]-'a';
            c[idx] = max(c[idx],combo);
            combo = 1;
        }
    }
    int idx = s[n-1]-'a';
    c[idx] = max(c[idx],combo);
    print(sum(c));

    return 0;
}