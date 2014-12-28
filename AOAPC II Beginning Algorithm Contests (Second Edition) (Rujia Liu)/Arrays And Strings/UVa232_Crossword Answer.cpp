#include <stdio.h>
#include <string.h>
#include <ctype.h>

char s[15][15];
int n[15][15];
int kase = 0;

int solve()
{
	int r, c;
	scanf( "%d", &r ); if( !r ) return 0;
	scanf( "%d", &c );
	for( int i = 0; i < r; ++i )
		scanf( "%s", s[i] );
	memset( n, 0, sizeof(n) );
	int ct = 1;
	for( int i = 0; i < r; ++i )
		for( int j = 0; j < c; ++j )
			if ( isalpha(s[i][j]) )
			if ( i-1 < 0 || j-1 < 0 || s[i-1][j] == '*' || s[i][j-1] == '*' )
				n[i][j] = ct++;
	if( kase++ ) putchar( '\n' );
	printf( "puzzle #%d:\n", kase );
	printf( "Across\n" );
	for( int i = 0; i < r; ++i )
		for( int j = 0; j < c; ++j ) {
			if( n[i][j] ) {
				printf( "%3d.", n[i][j] );
				while( j < c && s[i][j] != '*' ) putchar( s[i][j++] );
				putchar( '\n' );
			}
		}
	printf( "Down\n" );
	for( int i = 0; i < r; ++i )
		for( int j = 0; j < c; ++j ) {
			if( n[i][j] ) {
				int ti = i;
				printf( "%3d.", n[i][j] );
				while( i < r && s[i][j] != '*' ) {
					putchar( s[i][j] );
					n[i][j] = 0;
					i++;
				}
				putchar( '\n' );
				i = ti;
			}
		}
	return 1;
}
int main()
{
	//freopen( "in", "r", stdin );
	//freopen( "out", "w", stdout );
	while( solve() );
	return 0;
}