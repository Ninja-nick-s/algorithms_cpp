/*************************************Ninja-nick-s*****************************************/

#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define YES {cout<<"YES\n";return;} 
#define NO {cout<<"NO\n";return;} 
#define all(x) x.begin(), x.end()
#define rep(i,start,end) for(auto i=(start)-((start)>(end));i!=(end)-((start)>(end));((start)<(end)?i++:i--))
const ll mod = 1e9+7, N = 2e6+7, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);
ll ans = 1;
while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}
return ans;}

void PA(int v[], int n, int x = 0) { for (int i = x ; i < n + x; i++)cout << v[i] <<" "  ;}
void IA(int a[], int n, int x = 0) {for (int i = x; i < n + x; i++)cin >> a[i];}
string yup="YES";
string nope="NO";

map<int,vector<int> > adj;
map<int , bool> vis;
vector<int> ans;

void bfs(int v){
    queue<int> q;
    q.push(v);
    vis[v]=true;
    while(!q.empty()){
        int s = q.front();
        ans.push_back(s);
        q.pop();
        for(auto x:adj[s]){
            if(!vis[x]){
                vis[x] = true;
                q.push(x);
            }
        }
    }
}
/* CHECK t */
void Solve(){
    //int n;cin>>n;
    int v,e; cin>>v>>e;
    // rep(i,0,n){
    //     rep(j,0,n){
    //         int x;cin>>x;
    //         if(x==1){
    //             adj[i].push_back(j);
    //         }
    //     }
    // }
    rep(i,0,e){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
    }
    bfs(0);
    for(auto x:ans){
        cout<<x<<" ";
    }
}
 
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r", stdin);
        freopen("output.txt","w", stdout);
    #endif

    fast;
    int t = 1;
    //cin >> t;
    //cout<<fixed<<setprecision(9);
    while(t--){
        Solve();cout<<"\n";
    }
    return 0;
}