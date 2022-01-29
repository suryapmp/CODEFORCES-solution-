#include <bits/stdc++.h>
using namespace std;
long long int mod=998244353 ;
#define f first
#define s second
#define psb push_back
#define ppb pop_back
#define psf push_front
#define ppf pop_front
#define umap unordered_map
#define uset unordered_set
typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<long long int,long long int> pll;
typedef vector<pair<int,int>> vpi;
typedef vector<pair<long long int,long long int>> vpll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long int> vll;
typedef vector<vector<long long int>> vvll;
typedef unsigned int ui;
ll powm(ll x,ll y){
    if(x==1||x==0) return x;
    if(y==0) return 1;
    if(y==1) return x;
    ll ans=powm(x,y/2);
    ans=(ans*ans)%mod;
    if(y%2==1){
        ans=(ans*x)%mod;
    }
    return ans;
}
vi factors(ll a){
    vi ans;
    ll i=1;
    while(i*i<=a){
        if(a%i==0){
            ans.psb(i);
            if(a/i!=i){
                ans.psb(a/i);
            }
                
        }
        i++;
    }
    sort(ans.begin(),ans.end());
    return ans;
}
int pmfac(ll n){
    if(n==0) return 0;
    if(n==1) return 0;
    ll i=2;
    int ct=0;
    while(i*i<=n){
        // if(n%i==0){
           
        // }
        while(n%i==0){
            n/=i;
            ct++;
        }
        i++;
    }
    if(n!=1) ct++;
    return ct;
}
// enable fac and invfac in main function to use 
// factorial and inverse factorial vectors;
vll fc,invfc;
void fac(int n){    
    fc.resize(n);  
    fc[0]=1;
    for(int i=1;i<n;i++){
        fc[i]=(fc[i-1]*i)%mod;
    }
}
void invfac(int n){ 
    vll inv(n);
    for(int i=0;i<n;i++){
        inv[i]=powm(i,mod-2);
    }
    invfc.resize(n); 
    invfc[0]=1;
    invfc[1]=1;
    for(int i=2;i<n;i++){
        invfc[i]=(invfc[i-1]*inv[i])%mod;
    }
}
// enable fac() and invfac() in main function to use c;
ll c(int n,int r){   
    if(r>n) return 0;
    return (((fc[n]*invfc[r])%mod)*invfc[n-r])%mod;
}
ll p(int n,int r){   
    if(r>n) return 0;
    return ((fc[n]*invfc[n-r])%mod)%mod;
}
bool ispal(vi&a){
    int n=a.size();
    int si=0,ei=n-1;
    while(si<ei&&a[si]==a[ei]) si++,ei--;
    if(si<ei) return 0;
    return 1;
}
// enable siv() in main to use vector isprime;
vi isprime;
vi prime;
void siv(int n){
    isprime.assign(n,1);
    isprime[1]=0;
    for(int i=2;i<n;i++){
        if(isprime[i]==0)continue;
        prime.psb(i);
        int j=i;
        while(i*(ll)j<n){
            isprime[i*j]=0;
            j++;
        }
    }
}
int pmfacsiv(ll n){
    if(n==0) return 0;
    if(n==1) return 0;
    ll i=0;
    int ct=0;
    while(prime[i]*prime[i]<=n){
        // if(n%i==0){
           
        // }
        while(n%prime[i]==0){
            return prime[i];
            n/=prime[i];
            ct++;
        }
        i++;
    }
    return ct;
    if(n!=1) ct++;
    return ct;
}
vi fps;
void fp_sieve(int n){
    fps.assign(n,0);
    fps[1]=1;
    for(int i=2;i<n;i++){
        if(fps[i]==0){
            fps[i]=i;
            int j=i;
            while(i*(ll)j<n){
                if(fps[i*j]==0)
                fps[i*j]=i;
                j++;
            }
        }
    }
}
ll mystoll(string &a){
    ll ans=0,t=1;
    while(a.size()>0){
        ans=(a.back()-'0')*t+ans;
        t*=10;
        a.pop_back();
    }
    return ans;
}
string itos(ll a){
    if(a==0) return "0";
    string ans="";
    while(a>0){
        ans=(char)(a%10+'0')+ans;
        a/=10;
    }
    return ans;
}
ld ncr(ll n,ll k){
    if(k>n) return 0;
    ld ans=1;
    for(int i=1;i<=k;i++){
        ans=ans*(n-k+i)/i;
    }
    return floor(ans+0.01);
}
// struct node{
//     int val;
//     node* next;
//     node(val){
//         this->val=val;
//         next=0;
//     }
//     ~node(){
//         delete this->next;
//     }
// }
// struct mncomp{
//     bool operator()(const int &x,const int &y){
//         if(a[x][0]>a[y][0]) return 1;
//         else if(a[x][0]<a[y][0]) return 0;
//         else return a[x][2]>a[y][2];
//     }
// };
// struct mxcomp{
//     bool operator()(const int &x,const int &y){
//         if(a[x][1]<a[y][1]) return 1;
//         else if(a[x][1]>a[y][1]) return 0;
//         else return a[x][2]>a[y][2];
//     }
// };
// bool comp(const pi &a,const pi &b){
//         if(a.f<b.f) return 1;
//         else if(a.f>b.f) return 0;
//         else return a.s>b.s;
// }

int n;
vvi ed;
void dfs(int node,int pnt,vi &pt){
    pt[node]=pnt;
    for(int i=0;i<ed[node].size();i++){
        int cd=ed[node][i];
        if(cd==pnt) continue;
        dfs(cd,node,pt);
    }
}
int cnt=0;
bool ndfs(int node,int pnt,vi& vd){
    if(vd[node]!=-1){
        cnt++;
        return 0;
    }
    if(ed[node].size()==1&&node!=0) return 1;
    bool ans=0;
    for(int i=0;i<ed[node].size();i++){
        int cd=ed[node][i];
        if(cd==pnt) continue;
        ans|=ndfs(cd,node,vd);
    }
    return ans;
}
// void temp(){
//     cin>>n;
//     ed.assign(n,vi());
    
//     for(int i=0;i<n-1;i++){
//         int f,s;
//         cin>>f>>s;
//         f--,s--;
//         ed[s].psb(f);
//         ed[f].psb(s);
//     }
//     dfs(0,-1);
// }

/* code starts from here  */

void solve(){
   int k;
   cin>>n>>k;
   queue<int> q;
   vi vd(n,-1),fd(n,0);
   for(int i=0;i<k;i++){
    int t;
    cin>>t;
    fd[--t]=1;    
   }
   ed.assign(n,vi());
    
    for(int i=0;i<n-1;i++){
        int f,s;
        cin>>f>>s;
        f--,s--;
        ed[s].psb(f);
        ed[f].psb(s);
    }
   q.push(0);
   vi rvd(n,-1);
   rvd[0]=0;
   while(q.size()){
    int x=q.front();
    q.pop();
    for(int i=0;i<ed[x].size();i++){
        int cd=ed[x][i];
        if(rvd[cd]==-1){
            rvd[cd]=rvd[x]+1;
            q.push(cd);
        }
    }
   }
   vi pnt(n,-1);
   dfs(0,-1,pnt);
   vpi x;
   for(int i=0;i<n;i++){
    if(fd[i]){
        x.psb({rvd[i],i});
    }
   }
   sort(x.begin(),x.end());
   
   for(int i=0;i<k;i++){
    int curr=x[i].s;
    vd[curr]=0;
    while(vd[pnt[curr]]==-1&&vd[curr]+1<=rvd[pnt[curr]]){
        vd[pnt[curr]]=vd[curr]+1;
        curr=pnt[curr];
    }
   }
   cnt=0;
   bool ans=ndfs(0,-1,vd);
   if(ans){
    cout<<"-1\n";
   }else{
    cout<<cnt<<"\n";
   }
}


// C:\Users\my\AppData\Roaming\Sublime Text 3\Packages\User
int main(){
    // #ifndef ONLINE_JUDGE
 //    // for getting input from input.txt
 //    freopen("input.txt", "r", stdin);
 //    // for writing output to output.txt
 //    freopen("output.txt", "w", stdout);
 //    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);    
    // fac(1e5+1);
    // invfac(1e4+1); 
    // siv(1e5+1);
    // fp_sieve(1e7+1);
    
    
    int t=1;
    cin>>t; 
    
    while(t--){ 
        solve();
    }
    return 0;
}