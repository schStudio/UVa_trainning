#include <stdio.h>
#include <string.h>
/*这是一道值得思考的题目
		1.写出程序框架
		2.处理多行情况: readChar()函数的设计
		3(*).当写不出循环的时候，考虑计数之间的关系，多换角度思考关系
*/
char code[8][1<<8];

char readChar()
{
	char ch;
	for(;;) {
		ch = getchar();
		if( ch != '\n' && ch != '\r' ) return ch;
	}
}
bool readCodes()
{
	memset( code, 0, sizeof(code) );
	code[1][0] = readChar();
	for( int len = 2; len <= 7; ++len ) {
		for( int i = 0; i < (1<<len)-1; ++i ) {
			char ch = getchar();
			if ( ch == EOF ) return false;
			if( ch == '\n' || ch == '\r' ) return true;
			code[len][i] = ch;
		}
	}
	return true;
}
int readInt( int n )
{
	int res = 0;
	while( n-- )
		res = res * 2 + readChar() - '0';
	return res;
}
void solve()
{
	while( readCodes() ) {
		for(;;) {
			int len = readInt(3);
			if( len == 0 ) break;
			for(;;) {
				int v = readInt(len);
				if( v == (1<<len)-1 ) break;
				putchar( code[len][v] );
			}
		}
		putchar( '\n' );
	}
}
int main()
{
	//freopen( "in", "r", stdin );
	//freopen( "out", "w", stdout );
	solve();
	return 0;
}