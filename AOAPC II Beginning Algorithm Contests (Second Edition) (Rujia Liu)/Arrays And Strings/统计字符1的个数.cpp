#include <stdio.h>
#include <string.h>
#include <time.h>

#define maxn 10000000 + 10
char s[maxn];

int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%s", s);
	int tot = 0;
	int len = strlen(s);
	for ( int i = 0; i < len; ++i ) {
		if( s[i] == '1' ) tot++;
	}
	printf("%d\n", tot);
	printf("Time = %.3fs\n", (double)clock()/CLOCKS_PER_SEC );
	return 0;
}