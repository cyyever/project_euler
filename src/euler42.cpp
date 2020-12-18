/*
 *	程序名：euler42.c
 *	作者：陈源源
 *	日期：2016-02-05
 *	功能：解决eulerproject 42题(https://projecteuler.net/problem=42)
 */

#include <cinttypes>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>

int main() {
  FILE *p42;
  unsigned char *p;
  unsigned char word[128];
  uint64_t word_value, n, triangle_num;
  size_t count;

  p42 = fopen(DATA_DIR "/p042_words.txt", "r");
  if (!p42) {
    printf("fopen failed:%m");
    return -1;
  }
  count = 0;
  while (true) {
    fscanf(p42, "%[^,]", word);
    p = word + 1;
    word_value = 0;
    while (*p != '"') {
      word_value += *p - 'A' + 1;
      p++;
    }
    for (n = 1;; n++) {
      triangle_num = n * (n + 1) / 2;
      if (triangle_num == word_value)
        count++;
      else if (triangle_num > word_value)
        break;
    }
    if (feof(p42))
      break;
    fscanf(p42, ",");
  }
  fclose(p42);
  printf("%zu\n", count);
  return 0;
}
