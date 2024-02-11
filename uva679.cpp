#include <iostream>

using namespace std;

int dropping_balls(int D, int I){
    int T = 1 << (D - 1);

    if (I > T) {
        I = I % T;
    }

    if (I == T) {
        return (1 << D) - 1;
    }

    int k = 1;

    for (int d = 1; d < D; d += 1) {
        if (I % 2 == 1) {
            k = 2 * k;
            I = (I - 1) / 2 + 1;
        } else {
            k = 2 * k + 1;
            I = I / 2;
        }
    }

    return k;
}

int main(int argc, char *argv[]){
    int n;
    cin >> n;

    if (n == -1) {
        return 0;
    }

    for (int i = 0; i < n; i += 1) {
        int D, I;
        cin >> D >> I;

        if (D == -1) {
            return 0;
        }

        cout << dropping_balls(D, I) << endl;
    }

    return 0;
}