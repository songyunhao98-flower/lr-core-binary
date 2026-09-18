#include <stdio.h>

/*
 * isLessOrEqual - if x <= y then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */

int isLessOrEqual(int x, int y) {
    int sx = (x >> 31) & 1;
    int sy = (y >> 31) & 1;
    int same = !(sx ^ sy);
    int diff = sx & !sy;  // 异号且x负y正 → x<=y成立
    int sub1 = y + (~x + 1); // y‑x（同号时无溢出）
    int sub2 = !((sub1 >> 31) & 1);
    return (same & sub2) | diff;
}


int main(void) {
  int x, y;
  if (scanf("%d %d", &x, &y) != 2)
    return 1;
  printf("%d\n", isLessOrEqual(x, y));
  return 0;
}
