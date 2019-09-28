#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n;
	int i;
	int k;
	int j;
	int len;
	int count[26];
	scanf("%d", &n);
	char words[n][50];
	for (i = 0; i < n; i++) {
		scanf("%s", words[i]);
	}

	//DAT
	for (i = 0; i < n; i++) {
		len = strlen(words[i]);
		for (j = 0; j < 26; j++) {
			count[j] = 0;
		}
		for (j = 0; j < len; j++) {
			count[words[i][j] - 'a']++;
		}
		for (j = 0; j < 26; j++) {
			if (count[j] == 1) {
				printf("%c", j + 'a');
			}
		}
		printf("\n");
	}

	return 0;
}
