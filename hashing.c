#include <stdio.h>
#include <stdlib.h>

typedef struct Listnode {
	int data;
	struct Listnode *next;
}Listnode;

typedef struct Hash {
	Listnode * key;
	int val;
}Hash;

int main()
{
	int nos;
	int pos;
	int i, k;
	int data;
	Listnode *head = NULL;
	Listnode *temp = NULL;
	Listnode *temp2 = NULL;
	Listnode *head2 =  NULL;
	Listnode *list1 = NULL;
	Listnode *list2 = NULL;
	scanf("%d", &nos);
	Hash hashtable[nos];
	for (i = 0; i < nos; i++) {
		scanf("%d%d", &data, &pos);
		temp = (Listnode *) malloc(sizeof(Listnode));
		temp->data = data;
		temp->next = NULL;
		hashtable[i].key = temp;
		hashtable[i].val = pos;
		if (head == NULL) {
			head = temp;
			temp2 = head;
		} else {
			temp2->next = temp;
			temp2 = temp;
		}
	}
	for (i = 0; i < nos; i++) {
		pos = hashtable[i].val;
		list1 = head;
		k = 0;
		while (list1) {
			k++;
			if (k == pos) {
				temp = (Listnode *) malloc(sizeof(Listnode));
				temp->data = list1->data;
				temp->next = NULL;
				if (head2 == NULL) {
					head2 = temp;
					temp2 = temp;
				} else {
					temp2->next = temp;
					temp2 = temp;
				}
			}
			list1 = list1->next;
		}
	}

	list2 = head2;
	while (list2) {
		printf("%d_", list2->data);
		list2 = list2->next;
	}
}
