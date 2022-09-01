// Study Group 7 (Alex Milanez, John Edwin Karel Delgado, Ronell Sean Rulloda)

#include <iostream>
using namespace std;

int count(int n) {
    int count = 1;
    for (int i=1; i<=n; i++) {
        count = count * i;
    }
    return count;
}

int printRest(int perm[], bool dir[], int n) {
    return 0;
}

void printPerm(int n) {
    int perm[n]; // Initialize array for integers of size n
    bool dir[n]; // Initialize array for directions of size n
    bool LEFT = true;
    bool RIGHT = false;

    for(int i=0; i<n; i++) {
        perm[i] = i + 1; // Stores integers into array perm[n]
        dir[i] = LEFT; // Sets all integer direction to left
        cout << perm[i] << " "; // Prints out first perm
    }

    for(int i=1;i<n;i++) {
        printRest(perm, dir, n);
    }
}

void johnsonTrotter(int n) {
    cout << "There are " << count(n) << " permutations of the set {" << "}:\n";

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