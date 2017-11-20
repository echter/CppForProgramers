#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {


    vector<double> numbers = {3.0, 6.0, 4.0, 5.0, 7.0};
    cout << numbers[0] << endl;

    double emplaceNumber = 12.5;
    numbers.emplace(numbers.begin() + 1, emplaceNumber);

    cout << numbers[1] << endl;

    vector<double>::iterator firstSearch = find(numbers.begin(), numbers.end(), 6.1);

    if (firstSearch != numbers.end()) {
        cout << "Number " << 6.1 << " Found" << endl;
    } else {
        cout << "Number " << 6.1 << " NOT Found" << endl;
    }

    vector<double>::iterator secondSearch = find(numbers.begin(), numbers.end(), 7.0);

    if (secondSearch != numbers.end()) {
        cout << "Number " << 7.0 << " Found" << endl;
    } else {
        cout << "Number " << 7.0 << " NOT Found" << endl;
    }


}