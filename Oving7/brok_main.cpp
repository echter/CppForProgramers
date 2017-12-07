#include "brok.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void skriv(const string &tekst, const Brok &brok) {
  cout << tekst << brok.finnTeller() << " / ";
  cout << brok.finnNevner() << endl;
}
void skriv(const string &tekst, const int i) {
  cout << tekst << i << endl;
}

int operator-(const int &a, const Brok &b) {
  Brok temp(a, 1);
  return (temp - b).toInt();
}

int main() {
  Brok a(10, 20);
  Brok b(3, 4);
  Brok c(1, 4);
  Brok d = a / b;
  Brok e(1, 4);

  skriv("a = ", a);
  skriv("b = ", b);
  skriv("c = ", c);
  skriv("d = ", d);

  b += a;
  ++c;
  d *= d;

  skriv("b = ", b);
  skriv("c = ", c);
  skriv("d = ", d);

  c = a + b - d * a;
  c = -c;

  skriv("c = ", c);

  if (a + b != c + d)
    cout << "a + b != c + d" << endl;
  else
    cout << " a + b == c + d" << endl;
  while (b > a)
    b -= a;
  skriv("b = ", b);

  Brok br = a - 5;


  // Oppg a
  skriv("a-5= ", br);
  skriv("5-1/2= ", 5 - a);


  skriv("5-1/4= ", 5 - e);

  skriv("Resultat av 5-1/4 direkte: ", 19 / 4);

  /* Oppg b
   * Tolker først 5-3 = 2, og 2-a = 1, siden a > 0, og den alltid må runde ned.
   * 1-7 = -6, og -6 - 0.25 = -6.
   * */
  skriv("5-3-1/2-7-1/4: ", 5 - 3 - a - 7 - e);

  return 0;
}