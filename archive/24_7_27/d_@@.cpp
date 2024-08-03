// https://atcoder.jp/contests/abc364/tasks/abc364_d

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for(T &in : v) is >> in;
    return is;
}
void print() { cout << '\n'; }
template<typename T>
void print(const T &t) { cout << t << '\n'; }
template<typename Head, typename... Tail>
void print(const Head &head, const Tail &... tail) {
    cout << head << ' ';
    print(tail...);
}


int main() {
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    cin >> a;
    multiset<int> aset(all(a));
    rep(j,q) {
        float b;
        int k;
        cin >> b >> k;
        float left = 0;
        float right = max(abs(*aset.begin()-b),abs(*aset.rbegin()-b));
        int roops = log2(right);
        float mid = (left+right)/2;
        auto it_l = aset.lower_bound(b-mid);
        auto it_u = aset.upper_bound(b+mid);
        int count = distance(it_l,it_u);
        int count_in = 0;
        bool isIn = true;
        if (b-mid+1 <= b+mid-1)
        {
            count_in = distance(aset.lower_bound(b-mid+1),aset.upper_bound(b+mid-1));
        } else {
            isIn = false;
        }
        for (int i = 0; count != k && i <= roops; i++)
        {
            if (count > k)
            {
                if (isIn)
                {
                    if (count_in < k)
                    {
                        break;
                    }
                }
                right = mid;
            } else if (count < k)
            {
                left = mid+1;
            }
            mid = (left+right)/2;
            it_l = aset.lower_bound(b-mid);
            it_u = aset.upper_bound(b+mid);
            count = distance(it_l,it_u);
            if (b-mid+1 <= b+mid-1)
            {
                count_in = distance(aset.lower_bound(b-mid+1),aset.upper_bound(b+mid-1));
            } else {
                isIn = false;
            }
        }
        int ans = max(abs(*it_l-b),abs(*prev(it_u)-b));
        print(ans);
    }


    return 0;
}
