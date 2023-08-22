#include <stdio.h>
#include <stdlib.h>

int Iterative(int n) {
    if (n <= 2) {
        return n;
    }

    int f0 = 0, f1 = 1, f2 = 2, fn;

    for (int i = 3; i <= n; i++) {
        fn = f0 + f1;
        f0 = f1;
        f1 = f2;
        f2 = fn;
    }


    return fn;
}

/// Recursive version
int Recursive(int n) {
    if (n <= 2) {
        return n;
    }
    return Recursive(n - 3) + Recursive(n - 2);
}

int memo[10000]; /// Adjust the size according to the maximum expected n value

int recurrenceMemoization(int n) {
    if (n <= 2) {
        return n;
    }

    if (memo[n] != -1) {
        return memo[n];
    }

    memo[n] = recurrenceMemoization(n - 3) + recurrenceMemoization(n - 2);
    return memo[n];
}



int main()
{

    /// Iterative method
    printf("Now displaying the iterative method\n");
    int n = 10; /// In this example, I will now test the Iterative function using n=10
    int result = Iterative(n);
    printf("F(%d) = %d\n", n, result);
    printf("=============================================\n");


    /// Recursive method
    printf("Now displaying the recursive method\n");
    int result2 = Recursive(n);
    printf("F(%d) = %d\n", n, result);
    printf("=============================================\n");


    /// Memoization method
    printf("Now displaying the Memoization method\n");
     for (int i = 0; i < 10000; i++) {
        memo[i] = -1;
    }

    int n2 = 10;
    printf("F(%d) = %d\n", n2, recurrenceMemoization(n));
    printf("=============================================\n");


    return 0; // Return 0 to show that everything went well
}
