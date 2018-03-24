#pragma comment(linker, " /stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
#include <utility>
#define ONLINE_JUDGE
#define forn(i,n) for(int i = 0; i < n; ++i)
#define foe(i,n) for(int i = 1; i <= n; ++i)
#define all(x) (x).begin(),(x).end()
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define pb push_back
#define mk make_pair
#define pi acos(-1.0)
#define re(x) exit(0*puts(x))
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define INF 99999999
#define sz(x) (int)(x).size()
const double EPS = 1e-16;
const int N = 2*(1e6);
const long long MOD = 1e9+7;
const int MAX_MEM = 1e8;
const int P = 239017;
const int LOGN = 25;
using ll = long long;
using lli = long long int;
using pii = pair<int,int>;
using vi = vector<int>;
using vii = vector<pii>;
using ull = unsigned long long;
template < class T >
int valbit(T n, int idx){ return ((n >> idx) & 1);}
template < class T >
int setbit(T n, int idx) { return (n | (1 << idx));}
template < class T > 
int xorbit(T n, int idx) {return (n ^ (1 << idx));}
template <class T>
using min_heap = priority_queue<T,vector<T>,greater<T>>;
#define reunique(v) v.resize(unique(v.begin(),v.end()) - v.begin())
template < class T >  int highbit(T x) {int t = 1; if(x >= t << 16) t <<= 16; if(x >= t << 8) t <<= 8; if(x >= t << 4) t <<= 4; if(x >= t << 2) t <<= 2; if(x >= t << 1) t <<= 1; return t;}
template < class T > int bitcount(T v) {int c =  ((v & 0xfff) * 0x1001001001001ULL & 0x84210842108421ULL) % 0x1f; c += (((v & 0xfff000) >> 12) * 0x1001001001001ULL & 0x84210842108421ULL) % 0x1f; return c;}
template < class T > T count(T x) {bool f = x && !(x & (x - 1)); return f;}
ll binpow(ll a, ll b)
{
	ll ret = 1;
	while(b)
	{
		if(b & 1) ret = ret * a;
		a = a * a;
		b >>= 1;
	}
	return ret;
}
inline int readInt()
{
  int s = 1, x = 0, c = getc(stdin);
  while (c <= 32)
    c = getc(stdin);
  if (c == '-')
    s = -1, c = getc(stdin);
  while ('0' <= c && c <= '9')
    x = x * 10 + c - '0', c = getc(stdin);
  return x * s;
}
int n,cnt;
string s,temp,c;
string a[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin >> n >> s;
	for(int i = 0; i < n; ++i){
		a[i] = s.substr(0,n-i);
	}
	for(int i = 0; i < n; ++i){
		for(int j = (int)a[i].size(); j < s.size(); ++j){
			temp += s[j];
			if(a[i] == temp)
				cnt = max(cnt,(int)a[i].size());
		}
		temp.clear();
	}
	if(!cnt) cout << n << "\n";
	else cout << n - cnt + 1 << "\n";
	return 0;
}
