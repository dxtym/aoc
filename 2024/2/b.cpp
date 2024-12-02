#include <cstdio>
#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<long long> vll;
typedef pair<int,int> pi;
typedef pair<long,long> pll;

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vb vector<bool>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple

template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }

#define MOD 1000000007
#define PI 3.14159265358979323846
#define read(type) readInt<type>()
ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

bool check(const vi &a) {
    if (a.size() < 2) return true;
    bool g = (a[0] < a[1]);
    f(i, 1, a.size()) {
        if ((a[i] > a[i-1] && !g) || (a[i] < a[i-1] && g) ||
            (abs(a[i] - a[i-1]) < 1 || abs(a[i] - a[i-1]) > 3)) {
            return false;
        }
    }
    return true;
}

void solve() {
    // setIO("");
    string r;
    int sm = 0;
    while (getline(cin, r)) {
        vi a; int n;
        istringstream stream(r);
        while (stream >> n) a.pb(n);
        if (check(a)) {
            sm++;
            continue;
        }
        bool f = false;
        f(i, 0, a.size()) {
            vi b = a;
            b.erase(b.begin() + i);
            if (check(b)) {
                f = true;
                break;
            }
        }
        sm += f;
    }
    cout << sm << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
