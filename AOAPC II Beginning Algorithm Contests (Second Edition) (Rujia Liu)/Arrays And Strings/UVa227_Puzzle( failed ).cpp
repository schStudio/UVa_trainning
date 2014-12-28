#include <stdio.h>
#include <ctype.h>

#define OK '1'
char s[5][5];

char getSquare(){
	char ch;
	for( int i = 0; i < 5; ++i ) {
		for( int j = 0; j < 5; ++j ) {
			while( !isalpha((ch=getchar())) && ch != ' ' );
			if( ch == 'Z' )
				return ch;
			s[i][j] = ch;
		}
	}
	return OK;
}
void print()
{
	printf( "\nSquare:\n");
	for( int i = 0; i < 5; ++i ) {
		for( int j = 0; j < 5; ++j )
			putchar(s[i][j]);
		putchar('\n');
	}
}
void solve( int t )
{
	//print();
	int bi, bj;
	for( int i = 0; i < 5; ++i )
		for( int j = 0; j < 5; ++j )
			if( s[i][j] == ' ' ) {
				bi = i;
				bj = j;
				break;
			}
	char c;
	while( (c = getchar()) != '0' ) {
		int ai = bi, aj = bj;
		switch( c ) {
			case 'A': bi--; break;
			case 'B': bi++; break;
			case 'L': bj--; break;
			case 'R': bj++; break;
		}
		if ( bi < 0 || bi > 4 || bj < 0 || bj > 4 ) {
			printf( "This puzzle has no final configuration.\n");
			return;
		}
		else {
			s[ai][aj] = s[bi][bj];
			s[bi][bj] = ' ';
		}
	}
	printf( "Puzzle #%d:\n", t );
	for( int i = 0; i < 5; ++i ) {
		int kase = 0;			//注意kase的使用范围(针对行内元素->放到行外)
		for( int j = 0; j < 5; ++j ){
			if( kase++ ) putchar( ' ' );
			printf( "%c", s[i][j] );
		}
		printf( "\n" );
	}
}

int main()
{
	//freopen( "in", "r", stdin );
	//freopen( "out", "w", stdout );
	int kase = 0;
	for( int i = 1; getSquare() != 'Z'; ++i ) {
		if( kase++ ) putchar( '\n' );
		solve( i );
	}
	return 0;
}