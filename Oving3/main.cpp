#include "vare.cpp"
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

int Sirkel::finnAreal() const {
  return pi * radius * radius;
}

double Sirkel::finnOmkrets() const {
  double omkrets = 2.0 * pi * radius;
  return omkrets;
}
// End Oppgave 1 --------------------------------------------------------------------------------------


// Oppgave 2
#include <iostream>
using namespace std;
int main() {
  Sirkel enSirkel(5);
  double arealet = enSirkel.finnAreal();
  cout << "Arealet er lik " << arealet << endl;
  double omkretsen =
      enSirkel.finnOmkrets();
  cout << "Omkretsen er lik " << omkretsen << endl;

  // End Oppgave 2 --------------------------------------------------------------------------------------
  // Oppgave 3 ------------------------------------------------------------------------------------------
  const double kvantum = 2.5;
  const double kilopris1 = 73.50;
  const double kilopris2 = 79.60;
  Vare enVare("Norvegia", 123, kilopris1);
  cout << "Varenavn: " << enVare.finnNavn() << ", varenr: " << enVare.finnVareNr() << " Pris pr enhet: " << enVare.finnPrisPerEnhet() << endl;
  double pris1 = enVare.finnPrisUtenMoms(kvantum);
  double pris2 = enVare.finnPrisMedMoms(kvantum);
  cout << "Kilopris: " << kilopris1 << endl;
  cout << "Prisen for " << kvantum << " kg er " << pris1 << " uten moms " << endl;
  cout << "Prisen for " << kvantum << " kg er " << pris2 << " med moms" << endl;
  enVare.settPris(kilopris2);
  cout << "Ny kilopris: " << enVare.finnPrisPerEnhet() << endl;
  cout << "Prisen for " << kvantum << " kg er " << enVare.finnPrisUtenMoms(kvantum) << " uten moms" << endl;
  cout << "Prisen for " << kvantum << " kg er " << enVare.finnPrisMedMoms(kvantum) << " med moms" << endl;
}
// End Oppgave 3 --------------------------------------------------------------------------------------