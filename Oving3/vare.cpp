#include <iostream>

using namespace std;

class Vare{
public:
  string finnNavn();
  int finnVareNr();
  double finnPrisPerEnhet();
  void settPris(double nyPris);
  double finnPrisUtenMoms();
  double finnPrisMedMoms();
  
private:
  int vareNr;
  double pris;
  string vareNavn;
};

Vare::Vare(string vareNavn, int vareNr, double pris){};