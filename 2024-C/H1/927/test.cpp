#include <iostream>
#include <string>

using namespace std;

int main() {
    string x = "000123";
    
    // Check if x is not empty before attempting to erase
    while (!x.empty() && x[0] == '0') {
        x.erase(x.begin());
    }

    cout << "Result: " << x << endl;

    return 0;
}
