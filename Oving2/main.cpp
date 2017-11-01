#include <iostream>

using namespace std;
int main() {
  
  bool oppgave1 = true;
  bool oppgave4 = false;
  
  if (oppgave1){
    // Exercise 1a
    int i = 3;
    int j = 5;
    int *p = &i;
    int *q = &j;
    
    cout << "value: " << i << " Adress: " << &i << endl;
    cout << "value: " << j << " Adress: " << &j << endl;
    cout << "value: " << p << " Adress: " << &p << endl;
    cout << "value: " << q << " Adress: " << &q << endl;
    
    // Exercise 1b
    *p = 7;
    *q += 4;
    *q = *p + 1;
    p = q;
    cout << *p << " " << *q << endl;
  }
  
  else if (oppgave4){
    
  }
}
