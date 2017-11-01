#include <cstdlib>
#include <fstream>
#include <climits>
#include <cstdlib>
#include <iomanip>
#include <iostream>

void readTemperature() {
  const char fileName[] = "temperatures.dat";
  std::ifstream infile;
  infile.open(fileName);
  if(!infile) { // innfil kan brukes som et logisk uttrykk
    std::cout << "Feil ved åpning av innfil." << std::endl;
    exit(EXIT_FAILURE); // uthopp fra programmet
  }
  int number;
  while(infile >> number) { // leser fram til filslutt
    std::cout << number << std::endl;
  }
  infile.close();
}

void putTemperature(double number) {
  
  const char filnavn[] = "temperatures.dat";
  std::ofstream outfile;
  outfile.open(filnavn);
  if(!outfile) {
    std::cout << "Feil ved åpning av utfil." << std::endl;
    exit(EXIT_FAILURE);
  }
  
  outfile << number << std::endl;
  outfile.close();
  
}

int main() {

  bool exerciseA = false;
  bool exerciseB = true;

  if(exerciseB) {
    putTemperature(10.0);
    putTemperature(11.0);
    readTemperature();
  }

  else if(exerciseA) {
    double temperatureArray[5];
    std::cout << "Write 5 temperatures: " << std::endl;
    for(int i = 0; i < 5; i++) {
      std::string temperatures;
      std::cout << "Temperature " << (i + 1) << ": ";
      std::cin >> temperatures;
      double temp = std::stod(temperatures);
      temperatureArray[i] = temp;
    }

    int u10counter = 0;
    int between10_20counter = 0;
    int o20counter = 0;

    for(int i = 0; i < 5; i++) {
      if(temperatureArray[i] < 10) {
        u10counter++;
      }
      else if(temperatureArray[i] <= 20) {
        between10_20counter++;
      }
      else {
        o20counter++;
      }
    }
    std::cout << "Amount under 10: " << u10counter << std::endl;
    std::cout << "Amount between 10 and 20: " << between10_20counter << std::endl;
    std::cout << "Amount over 20: " << o20counter << std::endl;
  }
}