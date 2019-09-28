#include <stdio.h>
#include <string.h>

typedef struct Hash {
    char key[50];
    int value;
}Hash;

int hashfunc(int ascii, int n) {
    return ascii % n;
}

int main()
{
    int nos, n;
    char word[50];
    scanf("%d", &n);
    int ascii = 0;
    Hash count[n];
    int pos;
    int i ,j, len, hash;
    for (i = 0; i < n; i++) {
      count[i].value = 0;
    }
    for (i = 0; i < n; i++) {
        ascii = 0;
        scanf("%s", word);
        len = strlen(word);
        for (j = 0; j < len; j++) {
          ascii += word[j];
        }
        hash = hashfunc(ascii, n);
        if (count[hash].value == 0) {
          strcpy(count[hash].key, word);
          count[hash].value = 1;
        } else if (strcmp(word, count[hash].key) != 0) {
            pos = (hash + 1) % n;
            while (pos >= 0) {
              if (count[pos].value == 0){
                strcpy(count[pos].key, word);
                count[pos].value = 1;
                break;
              } else if (strcmp(word, count[pos].key) == 0) {
                break;
              }
              pos = (pos+1 % n);
            }
        }
    }
    len = 0;
    for (i = 0; i < n; i++) {
      if (count[i].value == 1) {
        len++;
      }
    }
    printf("\n%d", len);

    return 0;
}
