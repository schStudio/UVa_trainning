#include <stdio.h>
#include <string.h>
#define maxn 105

int less( const char*s, int p, int q )
{
	int n = strlen(s);
	for( int i = 0; i < n; ++i ) {
		if( s[(p+i)%n] != s[(q+i)%n] )
			return s[(p+i)%n] < s[(q+i)%n];
	}
	return 0;
}
int main()
{
	//freopen( "input.txt", "r", stdin );
	int T;
	char s[maxn];
	scanf("%d", &T);
	while( T-- ) {
		scanf("%s", s);
		int ans = 0;
		int len = strlen(s);
		for( int i = 1; i < len; ++i ) {
			if( less( s, i, ans ) ) ans = i;
		}
		for( int i = 0; i < len; ++i ) {
			putchar( s[(ans+i)%len] );
		}
		putchar('\n');
	}
	return 0;
}