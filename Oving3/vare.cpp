#include <iostream>

using namespace std;

const double moms = 15.0;
class Vare{
public:
  Vare(string vareNavn, int vareNr, double pris);
  string finnNavn();
  int finnVareNr();
  double finnPrisPerEnhet();
  void settPris(double nyPris);
  double finnPrisUtenMoms(double antallVare);
  double finnPrisMedMoms(double antallVare);
  
private:
  string vareNavn;
  int vareNr;
  double pris;
};

Vare::Vare(string vareNavn, int vareNr, double pris) : vareNavn(vareNavn), vareNr(vareNr), pris(pris){};

string Vare::finnNavn(){
  return vareNavn;
}

int Vare::finnVareNr(){
  return vareNr;
}

double Vare::finnPrisPerEnhet(){
  return pris;
}

void Vare::settPris(double pris){
  Vare::pris = pris;
}

double Vare::finnPrisUtenMoms(double antallVare){
  return antallVare;
}

double Vare::finnPrisMedMoms(double antallVare){
  return antallVare * moms;
}