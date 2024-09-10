// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ap

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb(a) push_back(a)
#define all(v) v.begin(), v.end()
template<typename T>
using v = vector<T>;
using vi = v<int>;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
void print() { cout << '\n'; }
template<typename T>
void print(const T &t) { cout << t << '\n'; }
template<typename Head, typename... Tail>
void print(const Head &head, const Tail &... tail) {
    cout << head << ' ';
    print(tail...);
}


int main() {
    fastio();

    int n,k;
    cin >> n >> k;
    set<int> sa;
    map<int,vi> mb;
    rep(i,n) {
        int a,b;
        cin >> a >> b;
        if (sa.find(a) == sa.end()) sa.insert(a);
        mb[a].pb(b);
    }

    // 全ての(a,b)で人数を調べる
    int ans = 0;
    for (int i = *sa.begin(); i+k <= *sa.rbegin(); i++) {
        vi b;
        for (int ai = i; ai <= i+k; ai++) {
            if (mb.count(ai)) b.insert(b.end(),all(mb[ai]));
        }
        if (!b.empty()) {
            sort(all(b));
            for (int j = *b.begin(); j+k <= *b.rbegin(); j++) {
                ans = max(ans,(int)distance(lower_bound(all(b),j),upper_bound(all(b),j+k)));
            }
        }
    }
    print(ans);

    return 0;
}
