#include <stdio.h>
#include <string.h>

#define maxn 85
int kase = 0;
void solve()
{
	char s[maxn];
	scanf( "%s", s );
	int len = strlen(s);
	for( int i = 1; i <= len; ++i ) { //注意i的意思：子串长度；所以判断要用==号
		if( len % i == 0 ) {
			int subLen = i;
			int pos = 0;
			while( strncmp( s+pos, s, subLen ) == 0 )
				pos += subLen;
			if( pos >= len ) {
				if( kase++ ) putchar('\n');
				printf( "%d\n", subLen );
				break;
			}
		}
	}
}
int main()
{
	//reopen( "in", "r", stdin );
	int T;
	scanf( "%d", &T );
	while( T-- ) {
		solve();
	}
	return 0;
}