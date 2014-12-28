#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int c1[26];
int c2[26];

bool is_equal()
{
	for( int i = 0; i < 26; ++i )
		if ( c1[i] != c2[i] )
			return false;
	return true;
}

void solve()
{
	char s1[105], s2[105];
	while( scanf( "%s%s", s1, s2 ) != EOF ) {
		memset( c1, 0, sizeof(c1) );
		memset( c2, 0, sizeof(c2) );
		for( int i = 0; s1[i] != '\0'; ++i )
			c1[s1[i]-'A']++;
		for( int i = 0; s2[i] != '\0'; ++i )
			c2[s2[i]-'A']++;

		sort( c1, c1+26 );
		sort( c2, c2+26 );

		if( is_equal() )
			printf( "YES\n" );
		else
			printf( "NO\n" );
	}
}
int main()
{
	//freopen( "in", "r", stdin );
	//freopen( "out", "w", stdout );
	solve();
	return 0;
}