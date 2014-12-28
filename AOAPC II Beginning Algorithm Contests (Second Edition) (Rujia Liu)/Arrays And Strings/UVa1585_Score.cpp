#include <stdio.h>
#include <string.h>
#define maxn 85

void solve()
{
	int ans = 0, subAns = 0;
	char s[maxn];
	scanf("%s", s);
	int len = strlen(s);
	for( int i = 0; i < len; ++i ) {
		if( s[i] == 'X' )
			subAns = 0;
		else {
			subAns++;
			ans += subAns;
		}
	}
	printf("%d\n", ans);
}
int main()
{
	//freopen( "in", "r", stdin );
	int T;
	scanf("%d", &T);
	while( T-- ) {
		solve();
	}
	return 0;
}