// https://atcoder.jp/contests/abc313/tasks/abc313_a

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}

template<typename T>
T max(const vector<T>& v){return *max_element(v.begin(),v.end());}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    if (n==1) {
        print(0);
        return 0;
    }
    int a;
    vi b(n-1);
    cin >> a >> b;
    int m=max(b);
    print(max(0,m+1-a));

    return 0;
}
