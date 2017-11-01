#include <iostream>

using namespace std;

int findSum(const int *array, int numElements){
  int sum = 0;
  for (int i = 0; i < numElements; i++){
    sum += array[i];
  }
  return sum;
}

void ex6(){
  int numbers[20];
  int *pointer = numbers;
  for (int i = 0; i < 20; i++){
    numbers[i] = i + 1;
  }
  cout << findSum(numbers,10) << endl;
  cout << findSum((10 + pointer),5) << endl;
  cout << findSum((15 + pointer),5) << endl;
}


int main() {
  
  // Set to true to run exercises
  bool exercise1 = false;
  bool exercise4 = false;
  bool exercise5 = false;
  bool exercise6 = true;
  
  if (exercise1){
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
  
  else if (exercise4){
    int a = 5;
    int &b = a;
    int *c;
    c = &b;
    a = b + *c;
    b = 2;
    
    // 1) error: ‘b’ declared as reference but not initialized int &b
    // The address b is referencing is never initialized. It has to be set to an initialized value. For example a
    // 2) error: invalid type argument of unary ‘*’ (have ‘int’) *a = *b + *c;
    // a and b are not pointers and therefore can't be used as pointers.
    // 3) error: lvalue required as left operand of assignment &b = 2;
    // a reference is already given to &b and therefore can't be changed
  }
  
  else if (exercise5){
    
    int number;
    int *numberPointer = &number;
    int &numberReference = number;
    number = 5; // Method 1
    cout << number << endl;
    ++*numberPointer; // Method 2
    cout << number << endl;
    ++numberReference; // Method 3
    cout << number << endl;
    
  }
  
  else if (exercise6){
    ex6();
  }
}
