#include <stdio.h>
#include <assert.h>
#include <time.h>

#define N 1024

double arr1[N][N], arr2[N][N], res[N][N], res2[N][N];

int main() {
  // int B = CLS / sizeof(double); // CLS (Cache line size) = 64 in this machine and can be obtained using "getconf LEVEL1_DCACHE_LINESIZE".
  int B = 8;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      arr1[i][j] = i + j + 0.5;
      arr2[i][j] = i + j + 0.5;
      res2[i][j] = 0;
    }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        res2[i][j] += arr1[i][k] * arr2[k][j];
      }
    }
  }
  double *rres, *rmul1, *rmul2, tmp;
  int i, j, k, i2, k2, j2;
  double en4 = (double)clock();
  for (i = 0; i < N; i += B)
    for (k = 0; k < N; k += B)
      for (j = 0; j < N; j += B)
        for (i2 = 0, rres = &res[i][j], rmul1 = &arr1[i][k]; i2 < B; ++i2, rres += N, rmul1 += N) {
          tmp = rmul1[0];
          rmul2 = &arr2[k][j];
          rres[0] += tmp * rmul2[0];
          rres[1] += tmp * rmul2[1];
          rres[2] += tmp * rmul2[2];
          rres[3] += tmp * rmul2[3];
          rres[4] += tmp * rmul2[4];
          rres[5] += tmp * rmul2[5];
          rres[6] += tmp * rmul2[6];
          rres[7] += tmp * rmul2[7];
          rmul2 += N;
          tmp = rmul1[1];
          rres[0] += tmp * rmul2[0];
          rres[1] += tmp * rmul2[1];
          rres[2] += tmp * rmul2[2];
          rres[3] += tmp * rmul2[3];
          rres[4] += tmp * rmul2[4];
          rres[5] += tmp * rmul2[5];
          rres[6] += tmp * rmul2[6];
          rres[7] += tmp * rmul2[7];
          rmul2 += N;
          tmp = rmul1[2];
          rres[0] += tmp * rmul2[0];
          rres[1] += tmp * rmul2[1];
          rres[2] += tmp * rmul2[2];
          rres[3] += tmp * rmul2[3];
          rres[4] += tmp * rmul2[4];
          rres[5] += tmp * rmul2[5];
          rres[6] += tmp * rmul2[6];
          rres[7] += tmp * rmul2[7];
          rmul2 += N;
          tmp = rmul1[3];
          rres[0] += tmp * rmul2[0];
          rres[1] += tmp * rmul2[1];
          rres[2] += tmp * rmul2[2];
          rres[3] += tmp * rmul2[3];
          rres[4] += tmp * rmul2[4];
          rres[5] += tmp * rmul2[5];
          rres[6] += tmp * rmul2[6];
          rres[7] += tmp * rmul2[7];
          rmul2 += N;
          tmp = rmul1[4];
          rres[0] += tmp * rmul2[0];
          rres[1] += tmp * rmul2[1];
          rres[2] += tmp * rmul2[2];
          rres[3] += tmp * rmul2[3];
          rres[4] += tmp * rmul2[4];
          rres[5] += tmp * rmul2[5];
          rres[6] += tmp * rmul2[6];
          rres[7] += tmp * rmul2[7];
          rmul2 += N;
          tmp = rmul1[5];
          rres[0] += tmp * rmul2[0];
          rres[1] += tmp * rmul2[1];
          rres[2] += tmp * rmul2[2];
          rres[3] += tmp * rmul2[3];
          rres[4] += tmp * rmul2[4];
          rres[5] += tmp * rmul2[5];
          rres[6] += tmp * rmul2[6];
          rres[7] += tmp * rmul2[7];
          rmul2 += N;
          tmp = rmul1[6];
          rres[0] += tmp * rmul2[0];
          rres[1] += tmp * rmul2[1];
          rres[2] += tmp * rmul2[2];
          rres[3] += tmp * rmul2[3];
          rres[4] += tmp * rmul2[4];
          rres[5] += tmp * rmul2[5];
          rres[6] += tmp * rmul2[6];
          rres[7] += tmp * rmul2[7];
          rmul2 += N;
          tmp = rmul1[7];
          rres[0] += tmp * rmul2[0];
          rres[1] += tmp * rmul2[1];
          rres[2] += tmp * rmul2[2];
          rres[3] += tmp * rmul2[3];
          rres[4] += tmp * rmul2[4];
          rres[5] += tmp * rmul2[5];
          rres[6] += tmp * rmul2[6];
          rres[7] += tmp * rmul2[7];
        }
         
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      assert(res[i][j] == res2[i][j]);
    }
  }
  printf("%f", (double)clock()/CLOCKS_PER_SEC);
  return 0;
}
