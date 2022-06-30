#include <stdio.h>
#define BUFF_CAP  256
const char prefix = '|';

typedef struct koklu {
  int tam, kokici;
} koklu;

koklu f(int n) {
  if(n == 1 || n == 0) return (koklu) {n, n};
  koklu res = {
    .tam=1,
    .kokici=n
  };
  for(int i = 2; i < n; i++) {
    int isPrime = 1;
    for (int j=2; j*j<=i; j++) {
        if (i % j == 0) {
          isPrime=0;
        }
    }
    if(isPrime == 0) {
      continue;
    }
    if(n % i == 0) {
      if((n/i) % i == 0) {
        res.tam *= i;
        res.kokici /= i;
        res.kokici /= i;
        if(res.kokici % i == 0) {
          i--;
        }
      }
    }
  }
  return res;
}

int main(void) {
  int n = 0;
  char buff[BUFF_CAP] = {0};
  printf("koku alinacak sayi: ");
  scanf("%d", &n);
  koklu sade = f(n);
  sprintf(buff, "%d_/%d", sade.tam, sade.kokici);
  printf("Sonuc: %s\n",  buff);
  return 0;
}
