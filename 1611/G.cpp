
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> // for less
using namespace std;
using namespace __gnu_pbds;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define endl "\n"
/*------------------------int to long long -----------------*/
#ifdef ill
#define int long long 
#endif
/*---------------------------DEBUG HELPER--------------------------------------*/
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef AATIF_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

//#define int long long 
// int dx[]={-1,1,0,0}; int dy[]={0,0,1,-1};
// int dx[]={2,2,-2,-2,1,1,-1,-1}; int dy[]={1,-1,1,-1,2,-2,2,-2};
long long mod = 1e9 + 7;
const double eps=1e-9;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef vector< pair< int, int > > vii;
typedef map<int, int> mii;
typedef pair<int, ii> pip;
typedef pair<ii, int> ppi;
#define arrinp(arr,init,final,size,type) type* arr=new type[size];for(int i=init;i<final;i++)cin>>arr[i];
#define cr2d(arr,n,m,t) t**arr=new t*[n];for(int i=0;i<n;i++)arr[i]=new t[m];
#define w(t) int t;cin>>t; while(t--)
#define takeInp(n) int n;cin>>n;
#define fr(i,init,final) for(int i=init;i<final;i++)
#define frr(i,init,final) for(int i=init;i>=final;i--)
#define Fr(i,final) for(int i=0;i<final;i++)
#define Frr(i,first) for(int i=first;i>=0;i--)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define debug(x) cerr<<">value ("<<#x<<") : "<<x<<endl;
#define setb __builtin_popcount
#define lsone(n) (n&(-n))
#define rlsone(n) (n&(n-1))
#define clr(a,b) memset(a,b,sizeof(a))
const int inf= INT_MAX;
/*-----------------------------RANDOM NUMBER GENERATOR ---------------------*/
#ifdef RNG 
unsigned seed=chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 rng(seed);
#endif 
/*------------------------------UNORDERED MAP HASH --------------------------------------------*/
//To make unordered_map unhackable 
// use it as unordered_map<int,int,custom_hash> mapp;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        /* http://xorshift.di.unimi.it/splitmix64.c */
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
/*---------------------------ORDERED SET--------------------------------------*/
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>  ordered_set; 
/*----------------------------------------------------------------------------*/
vi init(string s)
{
	istringstream sin(s);
	int n;
	vi arr;
	while(sin>>n)arr.push_back(n);
	return arr;
}
using i64 = long long;
// assume -P <= x < 2P
int norm(int x) {
    if (x < 0) {
        x += mod;
    }
    if (x >= mod) {
        x -= mod;
    }
    return x;
}
template<class T>
T power(T a, int b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
struct mint {
    int x;
    mint(int x = 0) : x(norm(x)) {}
    int val() const {
        return x;
    }
    mint operator-() const {
        return mint(norm( mod- x));
    }
    mint inv() const {
        assert(x != 0);
        return power(*this, mod - 2);
    }
    mint &operator*=(const mint &rhs) {
        x = i64(x) * rhs.x % mod;
        return *this;
    }
    mint &operator+=(const mint &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    mint &operator-=(const mint &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    mint &operator/=(const mint &rhs) {
        return *this *= rhs.inv();
    }
    ostream& operator<<(ostream&os)
    {
    	os<< this->x; 
    	return os; 
    }
    friend mint operator*(const mint &lhs, const mint &rhs) {
        mint res = lhs;
        res *= rhs;
        return res;
    }
    friend mint operator+(const mint &lhs, const mint &rhs) {
        mint res = lhs;
        res += rhs;
        return res;
    }
    friend mint operator-(const mint &lhs, const mint &rhs) {
        mint res = lhs;
        res -= rhs;
        return res;
    }
    friend mint operator/(const mint &lhs, const mint &rhs) {
        mint res = lhs;
        res /= rhs;
        return res;
    }
};
int gcd(int a,int b)
{
	if(a<b)return gcd(b,a);
	return (b==0?a:(a%b?gcd(b,a%b):b));
}
int gcd_e(int a,int b,int &x,int &y)
{
	
	if(b==0){x=1; y=0; return a;}
	int x1,y1;
	int p=gcd_e(b,a%b,x1,y1);
	x=y1;
	y=x1-(a/b)*y1;
	return p;
}
/*-----------------to solve int to long long problem-----------------*/
int Min (int a,int b){return min(a,b);}
int Max(int a,int b){ return max(a,b);}

//786 121 786 121 786 121 786 121 786 121 786 121 786 121 786 121 786 121
/*========================CODE*****CODE****CODE======================*/







vector<string> a; 
vector<vector<int>> dp; 
signed main()
{
	IOS
	w(T)
	{
		int n,m; 
		cin>>n>>m; 
		a=vector<string>(n,string(m,'1'));
		for(int i=0;i<n;i++)cin>>a[i]; 
		dp=vector<vector<int>> (n+2,vector<int>(m+2,0));
		auto possible=[&](int i,int j)->bool{ return i>=0&& i<(int)dp.size()&&j>=0&&j<(int)dp[0].size(); };
		
		
		for(int j=1;j<=m;j++)
		{
			for(int i=1;i<=n;i++)
			{
				dp[i][j]=max(possible(i-1,j-1)?dp[i-1][j-1]:0,possible(i+1,j-1)?dp[i+1][j-1]:0); 
				dp[i][j]=max(dp[i][j],(a[i-1][j-1]=='1')+(possible(i,j-2)?dp[i][j-2]:0));
			
			}
		}
		vector<int> cnt(2);
		for(int i=0;i<dp.size();i++)
		{
			for(int j=0;j<dp[0].size();j++)
			{
				int sum=(i+j)%2; 
				cnt[sum]=max(cnt[sum],dp[i][j]); 
			}
		}
		//for(auto & it:dp)for(auto & it2:it)ans=max(ans,it2); 
		cout<<cnt.front()+cnt.back()<<endl; 
		
	}
	
}