#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FOD(i,a,b) for(ll i=a;i>=b;i--)
#define fast() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define file(x) freopen(x".inp","r",stdin); freopen(x".out","w",stdout);
vector<ll> a[100005];
ll b[100005];
ll n,m,kq=0,q=0;
priority_queue< ll,vector<ll>,greater<ll> > pq;
map<ll,bool> kt;
void dfs(ll s){
	kt[s]=true;
	pq.push(s);
	for (auto x: a[s])
		if (!kt[x])
			dfs(x);	
}
void cj(){

	FOR(i,1,n)
		if (!kt[i]){
			kq++;
			dfs(i);
			while (!pq.empty()){
				cout<<pq.top()<<" ";
				pq.pop();
			}
			cout<<endl;
		}
}
int main(){
	fast();
//	file("");
	cin>>n>>m;
	ll x,y;
	FOR(i,1,m){
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	cj();
	return 0;
}
