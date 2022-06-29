/* ALGORITHM
 * Get window size
 * Send frames in window to receiver
 * For each ACK from receiver, send next frame from sliding window
 * If an error occur, send that frame
 * Do steps 2-5 until all frames are sent
 */
#include <stdio.h>
#include <stdlib.h>
void main() {
  int err, w, n, s = 1, f[25];
  int erf = 0, erfi[25];

  printf("Enter no. of frames: ");
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) f[i] = i;
  printf("Enter Window size: ");
  scanf("%d", &w);

  while (s <= n) {
    for (int i = s; i < s + w && i <= n; i++) {
      if (erf != 0) {
        f[i] = erfi[erf];
        erf--;
      }
      printf("\nSent Frame %d", f[i]);
    }
    erf = 0;
    for (int i = s; i < s + w && i <= n; i++) {
      err = rand() % 4;
      if (err == 0) {
        printf("\nError at Frame %d", f[i]);
        erf++;
        erfi[erf] = i;

      } else {
        printf("\nAck %d!", f[i]);
      }
    }
    s += w - erf;
  }
}
