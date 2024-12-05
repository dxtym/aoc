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
#define vs vector<string>
#define vc vector<char>
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

void solve() {
    // setIO();
    vs s1, s2; string t;
    while (getline(cin, t)) {
        if (t.empty()) break;
        s1.pb(t);
    }
    while (getline(cin, t)) {
        s2.pb(t);
    }
    map<int, vi> mp;
    f(i, 0, s1.size()) {
        int n1, n2; char d;
        istringstream ss (s1[i]);
        ss >> n1 >> d >> n2;
        mp[n2].pb(n1);
    }
    int sm = 0;
    f(i, 0, s2.size()) {
        vi n; string t;
        istringstream ss (s2[i]);
        while (getline(ss, t, ',')) {
            n.pb(stoi(t));
        }
        bool f = false;
        f(j, 0, n.size()) {
            vi x = mp[n[j]];
            f(k, 0, j) {
                if (find(x.begin(), x.end(), n[k]) == x.end()) {
                    f = true;
                    break;
                }
            }
        }
        if (f) {
            sort(n.begin(), n.end(), [&mp](int a, int b) {
                vi x = mp[b];
                return find(x.begin(), x.end(), a) != x.end();
            });
            sm += n[n.size()/2];
        }
    }
    cout << sm << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}