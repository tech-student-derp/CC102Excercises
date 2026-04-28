#include <iostream>
#include <fstream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int countPrimesInFile() {
    ifstream file("NUMS.TXT");
    int num, count = 0;

    if (!file) {
        cout << "error opening file\n";
        return 0;
    }

    while (file >> num) {
        if (isPrime(num))
            count++;
    }

    file.close();
    return count;
}

int main() {
    cout << "prime count: " << countPrimesInFile() << endl;
    return 0;
}