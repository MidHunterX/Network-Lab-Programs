/* ALGORITHM
 * Get window size
 * Send frames in window to receiver
 * For each ACK from receiver, send next frame from sliding window
 * If an error occur, set the window back to the error frame
 * Do steps 2-5 until all frames are sent
 */
#include <stdio.h>
#include <stdlib.h>
void main() {
  int err, w, n, s = 0;
  printf("Enter no. of frames: ");
  scanf("%d", &n);
  printf("Enter Window size: ");
  scanf("%d", &w);
  while (s < n) {
    int r = 0;
    for (int i = s; i < s + w && i < n; i++) printf("Sent Frame %d\n", i + 1);
    for (int i = s; i < s + w && i < n; i++) {
      err = rand() % 4;
      if (err == 0) {
        printf("Error at Frame %d\n", i + 1);
        printf("\nRetransmitting Window\n");
        break;
      } else {
        printf("Ack %d!\n", i + 1);
        r++;
      }
    }
    s += r;
  }
}
