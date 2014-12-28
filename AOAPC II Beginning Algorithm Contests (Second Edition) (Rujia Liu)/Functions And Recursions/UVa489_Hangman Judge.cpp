#include <stdio.h>
#include <string.h>

int win, lose;
int len_s2, len_s1;
int chance, finished;
char s1[1005], s2[1005];
void guess( char c )
{
	bool exist = false;
	for( int i = 0; i < len_s1; ++i ) {
		if ( s1[i] == c ) {
			finished--;
			s1[i] = ' ';
			exist = true;
		} 
	}
	if ( !exist ) chance--;
	if( !chance ) lose = 1;
	if( !finished ) win = 1;
}

void solve()
{
	int rnd;
	while( scanf( "%d%s%s", &rnd, s1, s2 ) == 3 && rnd != -1 ) {
		win = lose = 0;
		chance = 7;
		finished = len_s1 = strlen( s1 );
		len_s2 = strlen( s2 );
		for( int i = 0; i < len_s2; ++i ) {
			guess( s2[i] );
			//printf( "s1:%s\n", s1 );
			if( win || lose )
				break;
		}
		printf( "Round %d\n", rnd );
		if ( win ) printf( "You win.\n" );
		else if ( lose ) printf( "You lose.\n" );
		else printf( "You chickened out.\n" );
	}
}
int main()
{
	//freopen( "in", "r", stdin );
	//freopen( "out", "w", stdout );
	solve();
	return 0;
}