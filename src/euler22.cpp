/*
 *	程序名：euler22.c
 *	作者：陈源源
 *	日期：2016-02-11
 *	功能：解决eulerproject 22题(https://projecteuler.net/problem=22)
 */
#define _DEFAULT_SOURCE
#include <cinttypes>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <sys/types.h>

#define N 5163
static int cmpstringp(const void *p1, const void *p2);

int main() {
  FILE *p22;
  char *p;
  char name[128];
  char *names[N];
  size_t i;
  uint64_t score, total_score;

  p22 = fopen(DATA_DIR "/p022_names.txt", "r");
  if (!p22) {
    printf("fopen failed:%m");
    return -1;
  }
  i = 0;
  while (true) {
    fscanf(p22, "%[^,]", name);
    name[strlen(name) - 1] = '\0';
    names[i] = strdup(name + 1);
    if (!names[i]) {
      printf("strdup failed:%m");
      return -1;
    }
    i++;
    if (feof(p22))
      break;
    fscanf(p22, ",");
  }
  fclose(p22);

  qsort(names, N, sizeof(char *), cmpstringp);
  total_score = 0;
  for (i = 1; i <= N; i++) {
    p = names[i - 1];
    score = 0;
    while (*p) {
      score += (uint64_t)(*p - 'A' + 1);
      p++;
    }
    total_score += i * score;
  }
  printf("%" PRIu64 "\n", total_score);
  return 0;
}

/*
 *	功能：从man page复制，用于比较字符串
 *	参数：
 *		p1，p2：指向要比较的字符串
 *	返回值：
 *		参看man page
 */
static int cmpstringp(const void *p1, const void *p2) {
  return strcmp(*(char *const *)p1, *(char *const *)p2);
}
