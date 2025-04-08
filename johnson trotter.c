#include <stdio.h>
#include <stdbool.h>

#define LEFT_TO_RIGHT true
#define RIGHT_TO_LEFT false


int searchPosition(int a[], int n, int mobile) {
    for (int i = 0; i < n; i++) {
        if (a[i] == mobile)
            return i;
    }
    return -1;
}

int getMobile(int a[], bool dir[], int n) {
    int mobile = 0;

    for (int i = 0; i < n; i++) {
        if (dir[a[i] - 1] == RIGHT_TO_LEFT && i != 0 && a[i] > a[i - 1]) {
            if (a[i] > mobile)
                mobile = a[i];
        }

        if (dir[a[i] - 1] == LEFT_TO_RIGHT && i != n - 1 && a[i] > a[i + 1]) {
            if (a[i] > mobile)
                mobile = a[i];
        }
    }
    return mobile;
}

void printOnePerm(int a[], bool dir[], int n) {
    int mobile = getMobile(a, dir, n);
    if (mobile == 0)
        return;

    int pos = searchPosition(a, n, mobile);

    // Swap according to direction
    if (dir[mobile - 1] == RIGHT_TO_LEFT) {
        int temp = a[pos];
        a[pos] = a[pos - 1];
        a[pos - 1] = temp;
    } else if (dir[mobile - 1] == LEFT_TO_RIGHT) {
        int temp = a[pos];
        a[pos] = a[pos + 1];
        a[pos + 1] = temp;
    }

    for (int i = 0; i < n; i++) {
        if (a[i] > mobile) {
            dir[a[i] - 1] = !dir[a[i] - 1];
        }
    }

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int fact(int n) {
    int res = 1;
    for (int i = 1; i <= n; i++)
        res *= i;
    return res;
}

void printPermutations(int n) {
    int a[n];
    bool dir[n];

    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
        dir[i] = RIGHT_TO_LEFT;
    }

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    for (int i = 1; i < fact(n); i++)
        printOnePerm(a, dir, n);
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("All permutations using Johnson–Trotter algorithm:\n");
    printPermutations(n);

    return 0;
}
