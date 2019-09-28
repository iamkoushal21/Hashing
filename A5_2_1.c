#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	char data;
	struct node *next;
}node;

int hashfunction(char key) 
{
	return (key - 'a');
}

int count(node *head) 
{
	int k = 0;
	while (head) {
		k++;
		head = head->next;
	}

	return k;
}

int main()
{
	node *chain[26];
	node *temp = NULL;
	int i, j, key, len;
	int n;
	scanf("%d", &n);
	char words[n][50];
	for (i = 0; i < n; i++) {
		scanf("%s", words[i]);
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < 26; j++) {
			chain[j] = NULL;
		}	
		len = strlen(words[i]);
		for (j = 0; j < len; j++) {
			temp = (node *) malloc(sizeof(node));
			temp->data = words[i][j];
			temp->next = NULL;
			key = hashfunction(words[i][j]);
			if (chain[key] != NULL) {
				temp->next = chain[key];
			}
			chain[key] = temp;
		}
		for (j = 0; j < 26; j++) {
			if (count(chain[j]) == 1) {
				printf("%c", chain[j]->data);
			}
		}
		printf("\n");
	}

	return 0;
}
