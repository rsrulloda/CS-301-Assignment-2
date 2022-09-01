// Study Group 7 (Alex Milanez, John Edwin Karel Delgado, Ronell Sean Rulloda)

#include <iostream>

using namespace std;

void printPerm(int n) {
    cout << "test: " << n;
}

void johnsonTrotter(int n) {
    int permCount = 0;

    cout << "There are " << permCount << " permutations of the set {" << "}:\n";

    printPerm(n);
}


int main() {
    int n;

    cout << "Please enter a positive integer between 1 and 25:";
    cin >> n;

    if(n>=1 && n<=25) {
        johnsonTrotter(n);
    } else {
        cout << "Value entered is not between 1 and 25";
    }

    return 0;
}