// orz WJMZBMR
#include <bits/stdc++.h>
using namespace std;
//#define che
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define MK make_pair
#define PB push_back
#define fi first
#define se second

typedef long long LL;
typedef pair<int, int> PII;
const int N=3e5 +10 ;
const LL MOD = 1e9+7;
int pre[N], n, nxt[3];
LL f[N]; char s[N];


int main(){
	#ifdef che
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	#endif
	scanf("%s", s); n=strlen(s);
	for (int i=0; i<n; ++i) pre[i+1] =( pre[i] + (s[i]-'a'+1))%3;
	
	bool flag= false;
	for (int i=0; i+1 < n; ++i)
		if ( s[i] ==s[i+1] ) flag= true;
	if ( !flag){
		puts("1"); return 0;
	}
	for (int i=0; i<3; ++i) nxt[i] = i==pre[n] ? n: n+1;
	f[n] = 1;
	for (int i=n; i--; ){
		f[i] = i&&pre[i] == pre[n];
		for (int c=0; c<2; ++c)
			f[i] =(f[i] + f[ nxt[(pre[i]+c+1)%3] ])%MOD;
		nxt[ pre[i]] = i;
	}
	cout<<f[0]<<endl;
	return 0;
	
}
