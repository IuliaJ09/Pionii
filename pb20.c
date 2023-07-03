#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[10][10],nr=0,aux,i,j;
	char s[3];
	FILE* f, * g;
	f = fopen("in10.txt", "rt");
	g = fopen("out10.txt", "wt");
	for (i = 0; i <= 8; i++)
		for (j = 0; j <= 8; j++)
			a[i][j] = 0;
		
	
	while (!feof(f))
	{
		fscanf(f,"%s", s);
		aux = s[1] - '0';
		a[aux][s[0] - 'a' + 1] = 1;
	}
	for (i = 1; i <= 8;i++)
	{
		for (j = 1; j <= 8; j++)
			if (a[i][j] != 0)
				if (a[i - 1][j - 1] != 0 || a[i - 1][j + 1] != 0)
					nr++;
	}
	fprintf(g, "%d", nr);
	system("pause");
	return 0;
}