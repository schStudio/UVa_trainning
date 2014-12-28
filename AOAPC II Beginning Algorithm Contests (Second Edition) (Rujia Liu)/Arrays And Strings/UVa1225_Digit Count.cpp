#include <stdio.h>
#include <string.h>

int ct[10];

void solve()
{
	int n;
	memset( ct, 0, sizeof(ct) );
	scanf( "%d", &n );
	for( int i = 1; i <= n; ++i ) {
		int tmp = i;	//注意i是计数器，不要乱改i的值
		while( tmp ) {
			ct[tmp%10]++;
			tmp /= 10;
		}
	}
	int kase = 0;
	for( int i = 0; i < 10; ++i ) {
		if( kase++ ) putchar( ' ' );
		printf( "%d", ct[i] );
	}
	printf( "\n" );
}
int main()
{
	//freopen( "in", "r", stdin );
	int T;
	scanf( "%d", &T );
	while( T-- ) {
		solve();
	}
	return 0;
}