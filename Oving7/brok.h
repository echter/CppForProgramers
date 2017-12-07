#ifndef BROEK_DEFINERT
#define BROEK_DEFINERT

class Brok {
public:
  Brok();
  Brok(int initTeller, int initNevner);
  void settBrok(int nyTeller, int nyNevner = 1);
  int finnTeller() const { return teller; }
  int finnNevner() const { return nevner; }
  int toInt() const;
  Brok operator+(const Brok &denAndre) const;
  Brok operator-(const Brok &denAndre) const;
  Brok operator-(const int integer) const;
  Brok operator*(const Brok &denAndre) const;
  Brok operator/(const Brok &denAndre) const;
  Brok operator-() const;
  Brok &operator++(); // Preinkrement
  Brok &operator--(); // Predekrement
  Brok &operator+=(const Brok &denAndre);
  Brok &operator-=(const Brok &denAndre);
  Brok &operator*=(const Brok &denAndre);
  Brok &operator/=(const Brok &denAndre);
  Brok &operator=(const Brok &original);
  bool operator==(const Brok &denAndre) const;
  bool operator!=(const Brok &denAndre) const;
  bool operator<=(const Brok &denAndre) const;
  bool operator>=(const Brok &denAndre) const;
  bool operator<(const Brok &denAndre) const;
  bool operator>(const Brok &denAndre) const;

private:
  void forkort();
  int sammenlikn(const Brok &denAndre) const;
  int teller;
  int nevner;
};
#endif