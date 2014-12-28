#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char s1[105];
char s2[105];
char s[210];
int len1, len2;
int allLen;

bool merge( int p )
{
	for( int i = 0; i < len1; ++i )
		if( s[i+p] + s1[i] - 2*'0' > 3 )
			return false;
	return true;
}
int length()
{
	int res = 0;
	for( int i = 0; i < allLen; ++i ) {
		while( i < allLen && s[i] != '0') {
			res++;i++;
		}
	}
	return res;
}
void slove()
{
	while( scanf( "%s%s", s1, s2 ) != EOF ) {
		len1 = strlen( s1 );
		len2 = strlen( s2 );
		allLen = 2*len1 + len2;
		memset( s, '0', len1 );
		strncpy(s+len1, s2, len2);
		memset( s+len1+len2, '0', len1 );
		int ans = len1+len2;
		int tmp;
		for( int i = 0; i < allLen-len1; ++i ) {
			if( merge(i) ) {
				int tmp = length();
				printf( "tmp=%d\n", tmp );
				if( tmp < ans ) ans = tmp;
			}
			if ( ans == max(len1, len2) )
				break;
		}
		printf( "%d\n", ans );
	}
}
int main()
{
	freopen( "in", "r", stdin );
	freopen( "out", "w", stdout );
	slove();
	return 0;
}
