#include <stdio.h>
#include <string.h>

int main()
{
  int n;
  int i, len;
  char word[50];
  int count[26];
  scanf("%d\n", &n);
  while (n--) {
    for (i = 0; i < 26; i++) {
      count[i] = 0;
    }
    scanf("%s", word);
    len = strlen(word);
    for (i = 0; i < len; i++) {
      count[word[i]-'a']++;
    }
    for (i = 0; i < 26; i++) {
      if (count[i] != 0) {
        printf("%c %d ", 'a'+ i, count[i]);
      }
    }
    printf("\n");
  }

  return 0;
}
