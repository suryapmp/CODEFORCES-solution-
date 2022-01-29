*/
#include<bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mod 1000000007
#define en "\n"
#define inf 1e18
#define pb push_back
#define vi vector<ll>
#define vs vector<string>
#define pii pair<ll, ll>
#define mp make_pair
#define all(n) n.begin(), n.end()
#define ff first
#define ss second
#define loop(i, a, b) for (int i = (a); i <= (b); i++)
#define looprev(i, a, b) for (int i = (a); i >= (b); i--)
#define test ll txtc; cin>>txtc; for(int tcase=1;tcase<=txtc;tcase++)
#define logarr(arr,a,b) for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
typedef unsigned long long ull;
typedef long double lld;
typedef long long int ll;
typedef long double ld;
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(unordered_set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(multimap <T, V> v);
template <class T, class V> void _print(unordered_map <T, V> v);
template <class T, class V> void _print(unordered_multimap <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T> void _print(unordered_multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(multimap <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_multimap <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <typename T> T gcd(T a, T b) {if (a % b) return gcd(b, a % b); return b;}
template <typename T> T lcm(T a, T b) {return (a * (b / gcd(a, b)));}
template<typename T> void inline in(vector<T> &v, ll n) {
  v.resize(n+1); for (ll i = 1; i <= n; i++) cin >> v[i];
}
bool inline isVowel (char c) {
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}




int main() 
{
FIO;
cout << setprecision(8) << fixed;
//Code here.....boom-->:):):):):)

test{
  ll n;cin>>n;    
  vi b;in(b,n);   
  vi p;in(p,n);
  vi dist(n+1,-1);     
  if(b[p[1]]!=p[1]){
    cout<<-1<<en;   
    continue;
  }
  dist[p[1]]=0;  
  bool flag=true;   
  loop(i,2,n){
      if(dist[b[p[i]]]==-1)
      {
        flag=false;
        break;   
      }
      dist[p[i]]=dist[p[i-1]]+1;   
  }
  if(!flag){
    cout<<-1<<en;
    continue;
  }
  loop(i,1,n){
    cout<<dist[i]-dist[b[i]]<<" ";
  }
  cout<<en;
  
  
  
}





return 0;
}