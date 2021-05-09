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

int parent[1000000];
int rank[1000000];
void makeset(){
    memset(rank , 0,sizeof(rank));
    rep(i,0,1000000){
        parent = i;
    }
}

int findpar(int node){      // time complexity = O(4*constant) = O(1);
    if(node == parent[node]){
        return node;
    }

    return parent[node] = findpar(parent[node]);
}

void union(int u , int v){  //time complexity = O(1);
    u = findpar(u);
    v = findpar(v);
    if(rank[u] > rank[v]){
        parent[v] = u;
    }
    else if(rank[u]<rank[v]){
        parent[u] = v;
    }
    else{
        parent[v] = u;
        rank[u]++;
    }
}
/* CHECK t */
void Solve(){
    makeset();
    int n;cin>>n; // if we have to perform n operations of union
    while(n--){
        int v,u;cin>>v>>u;
        union(v,u);
    }

    // if asked do a & b belong to same component
    int a,b;cin>>a>>b;
    if(findpar(a) == findpar(b)){
        cout<<"same component";
    }
    else{
        cout<<"different component";
    }

}
 
int32_t main(){
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
