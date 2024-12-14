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

int mod(int a, int b) {
    return (a % b + b) % b;
}

void solve() {
    // setIO("");
    string t;
    int x = 101/2, y = 103/2;
    map<pair<int, int>, int> mp;
    while (getline(cin, t)) {
        istringstream ss (t);
        string s; vi p, v;
        while (ss >> s) {
            size_t pos = s.find('=');
            if (pos != string::npos) {
                string key = s.substr(0, pos);
                string val = s.substr(pos+1);
                istringstream sss (val);
                string xy;
                while (getline(sss, xy, ',')) {
                    if (key == "p") p.pb(stoi(xy));
                    else v.pb(stoi(xy));
                }
            }
        }
        ll dx = p[0] + 100 * v[0], dy = p[1] + 100 * v[1];
        ll nx = mod(dx, 101), ny = mod(dy, 103);
        mp[{nx, ny}]++;
    }
    ll q1 = 0, q2 = 0, q3 = 0, q4 = 0;
    for (auto kv : mp) {
        int xx = kv.first.first, yy = kv.first.second;
        if (xx < x && yy < y) q1 += kv.second;
        else if (xx > x && yy < y) q2 += kv.second;
        else if (xx < x && yy > y) q3 += kv.second;
        else if (xx > x && yy > y) q4 += kv.second; 
    }
    cout << q1 * q2 * q3 * q4 << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
