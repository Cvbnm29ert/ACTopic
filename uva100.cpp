#include <iostream>

using namespace std;

int max_cycle(int a, int b){
    // 最大周期
    int maxc = 0;

    for (int i = a; i <= b; i += 1) {
        int n = i;
        // 周期
        int c = 1;

        while (n != 1) {
            c += 1;

            if ((n % 2) == 1) {
                n = 3 * n + 1;
            } else {
                n = n / 2;
            }
        }

        if (c > maxc) {
            maxc = c;
        }
    }

    return maxc;
}

int main(int argc, char *argv[]){
    int a, b;

    while (cin >> a >> b) {
        if (a > b) {
            cout << a << " " << b << " " << max_cycle(b, a) << endl;
            continue;
        }

        cout << a << " " << b << " " << max_cycle(a, b) << endl;
    }

    return 0;
}