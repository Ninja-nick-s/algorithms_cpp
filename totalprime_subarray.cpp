#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int N = 10000002;
vector<bool> prime(N,true);
vector<int> nump(N);     //total prime subarray
void SieveOfEratosthenes()
{
    prime[0] = prime[1] = false;
    for (int p = 2; p * p <= N; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= N; i += p)
                prime[i] = false;
        }
    }
    int c = 0;
    for (int p = 0; p <= N; p++){
        if (prime[p]){
            c++;
        }
        nump[p] = c;
    }
}

void solve(){
    int n;cin>>n;
    if(n==2){
        cout<<"1";
    }
    else if(n==3){
        cout<<"2";
    }
    else{
        int l = n/2;
        int k = nump[n] - nump[l];
        int ans = k+1;
        cout<<ans;
    }
}
int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r", stdin);
        freopen("output.txt","w", stdout);
    #endif
    fast;
    int t;
    SieveOfEratosthenes();
    cin>>t;
    while(t--){
        solve();cout<<"\n";
    }
    return 0;
}