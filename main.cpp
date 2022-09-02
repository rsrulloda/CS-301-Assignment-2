// Study Group 7 (Alex Milanez, John Edwin Karel Delgado, Ronell Sean Rulloda)

#include <iostream>
using namespace std;

bool LEFT = false;
bool RIGHT = true;

int count(int n) {
    int count = 1;
    for (int i=1; i<=n; i++) {
        count = count * i;
    }
    return count;
}

int getMobile(int a[], bool dir[], int n){
    int nextMobile = 0, mobile = 0;

    for (int i=0; i<n; i++) {
        if (dir[a[i]-1] == LEFT && i!=0) {
            if (a[i] > a[i-1] && a[i] > nextMobile) {
                mobile = a[i];
                nextMobile = mobile;
            }
        }

        if (dir[a[i]-1] == RIGHT && i!=n-1){
            if (a[i] > a[i+1] && a[i] > nextMobile){
                mobile = a[i];
                nextMobile = mobile;
            }
        }
    }

    if (mobile == 0 && nextMobile == 0) {
        return 0;
    } else {
        return mobile;
    }
}

int search(int a[], int n, int mobile) {
    for (int i = 0; i < n; i++) {
        if (a[i] == mobile) {
            return i + 1;
        }
    }
    return 0;
}


int printRest(int perm[], bool dir[], int n) {
    int mobile = getMobile(perm, dir, n);
    int position = search(perm, n, mobile);

    if (dir[perm[position-1] - 1] ==  LEFT) {
        swap(perm[position - 1], perm[position - 2]);
    } else {
        swap(perm[position], perm[position-1]);
    }

    for (int i = 0; i < n; i++) {
        if (perm[i] > mobile) {
            if (dir[perm[i] - 1] == RIGHT) {
                dir[perm[i] - 1] = LEFT;
            } else {
                dir[perm[i] - 1] = RIGHT;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << perm[i] << " ";
    }

    cout << endl;
    return 0;
}

void printPerm(int n) {
    int perm[n]; // Initialize array for integers of size n
    bool dir[n]; // Initialize array for directions of size n

    for(int i=0; i<n; i++) {
        perm[i] = i + 1; // Stores integers into array perm[n]
        dir[i] = LEFT; // Sets all integer direction to left
        cout << perm[i] << " "; // Prints out first perm
    }
    cout << endl;

    for(int i=1;i<count(n);i++) {
        printRest(perm, dir, n);
    }
}

void johnsonTrotter(int n) {
    cout << "There are " << count(n) << " permutations of the set {";

    for(int i=1;i<=n;i++) {
        if (i==n) {
            cout << i;
        } else {
            cout << i << ", ";
        }
    }

    cout << "}:\n";

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