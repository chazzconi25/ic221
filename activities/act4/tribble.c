#include <stdio.h>

typedef struct {
  int a;
  int b;
  int c;
}Tribble;

void addTo(Tribble *t1, Tribble *t2) {
  t1->a += t2->a;

}
