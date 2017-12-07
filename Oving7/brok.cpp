#include "brok.h"
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

Brok::Brok() : teller(0), nevner(1) {}

Brok::Brok(int initTeller, int initNevner) {
  settBrok(initTeller, initNevner);
}

void Brok::settBrok(int nyTeller, int nyNevner) {
  if (nyNevner != 0) {
    teller = nyTeller;
    nevner = nyNevner;
    forkort();
  } else {
    throw "nevneren ble null";
  }
}

int Brok::toInt() const {
  return teller / nevner;
}

Brok Brok::operator+(const Brok &denAndre) const {
  Brok hjelp = *this;
  hjelp += denAndre;
  return hjelp;
}

Brok &Brok::operator+=(const Brok &denAndre) {
  settBrok(teller * denAndre.nevner + nevner * denAndre.teller,
            nevner * denAndre.nevner);
  return *this;
}

Brok &Brok::operator++() {
  teller += nevner;
  return *this;
}

Brok Brok::operator-(const Brok &denAndre) const {
  Brok hjelp = *this;
  hjelp -= denAndre;
  return hjelp;
}

Brok &Brok::operator-=(const Brok &denAndre) {
  settBrok(teller * denAndre.nevner - nevner * denAndre.teller,
            nevner * denAndre.nevner);
  return *this;
}

Brok &Brok::operator--() {
  teller -= nevner;
  return *this;
}

Brok Brok::operator-() const {
  Brok hjelp;
  hjelp.teller = -teller;
  hjelp.nevner = nevner;
  return hjelp;
}

Brok Brok::operator-(const int integer) const {
  Brok b(integer, 1);
  return *this - b;
}

Brok Brok::operator*(const Brok &denAndre) const {
  Brok hjelp = *this;
  hjelp *= denAndre;
  return hjelp;
}

Brok &Brok::operator*=(const Brok &denAndre) {
  settBrok(teller * denAndre.teller, nevner * denAndre.nevner);
  return *this;
}

Brok Brok::operator/(const Brok &denAndre) const {
  Brok hjelp = *this;
  hjelp /= denAndre;
  return hjelp;
}

Brok &Brok::operator/=(const Brok &denAndre) {
  settBrok(teller * denAndre.nevner, nevner * denAndre.teller);
  return *this;
}

Brok &Brok::operator=(const Brok &original) {
  teller = original.teller;
  nevner = original.nevner;
  return *this;
}

bool Brok::operator==(const Brok &denAndre) const {
  return (sammenlikn(denAndre) == 0) ? true : false;
}

bool Brok::operator!=(const Brok &denAndre) const {
  return (sammenlikn(denAndre) != 0) ? true : false;
}

bool Brok::operator<=(const Brok &denAndre) const {
  return (sammenlikn(denAndre) <= 0) ? true : false;
}

bool Brok::operator>=(const Brok &denAndre) const {
  return (sammenlikn(denAndre) >= 0) ? true : false;
}

bool Brok::operator<(const Brok &denAndre) const {
  return (sammenlikn(denAndre) < 0) ? true : false;
}

bool Brok::operator>(const Brok &denAndre) const {
  return (sammenlikn(denAndre) > 0) ? true : false;
}

//-------------------------------------------------------------------
//
// Sørg for at nevneren alltid er positiv.
// Bruker Euclids algoritme for å finne fellesnevneren.
//
void Brok::forkort() {
  if (nevner < 0) {
    teller = -teller;
    nevner = -nevner;
  }
  int a = teller;
  int b = nevner;
  int c;
  if (a < 0)
    a = -a;

  while (b > 0) {
    c = a % b;
    a = b;
    b = c;
  }
  teller /= a;
  nevner /= a;
}

//-------------------------------------------------------------------
//
// Returnerer +1 hvis *this > denAndre, 0 hvis de er like, -1 ellers
//
int Brok::sammenlikn(const Brok &denAndre) const {
  Brok hjelp = *this - denAndre;
  if (hjelp.teller > 0)
    return 1;
  else if (hjelp.teller == 0)
    return 0;
  else
    return -1;
}