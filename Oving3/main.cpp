#include <iostream>

// Oppgave 1 --------------------------------------------------------------------------------------------
const double pi = 3.141592;
class Sirkel {
public:
  Sirkel(double startRadius);
  int finnAreal() const;
  double finnOmkrets() const;
private:
  double radius;
};
// ==> Implementasjon av klasse

Sirkel::Sirkel(double startRadius) : radius(startRadius) {}

int Sirkel::finnAreal() const{
  return pi * radius * radius;
}

double Sirkel::finnOmkrets() const {
  double omkrets = 2.0 * pi * radius;
  return omkrets;
}
// End Oppgave 1 --------------------------------------------------------------------------------------

int main() {
  std::cout << "Hello World!\n";
}