#include <iostream>
using namespace std;


int recursiveSteps = 0;
int iterativeSteps = 0;

int fibonacciRecursive(int n) {
    recursiveSteps++; // Count each call as a step
    if (n <= 1) return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}


int fibonacciIterative(int n) {
    iterativeSteps = 0;
    if (n <= 1) return n;

    int a = 0, b = 1, sum = 0;
    for (int i = 2; i <= n; i++) {
        sum = a + b;
        a = b;
        b = sum;
        iterativeSteps++; 
    }
    return b;
}

int main() {
    int n;
    cout << "Enter the number of terms in the Fibonacci sequence: ";
    cin >> n;

 
    int totalRecursive = 0;
    cout << "\nRecursive Fibonacci sequence:\n";
    for (int i = 0; i < n; i++) {
        int fib = fibonacciRecursive(i);
        totalRecursive += fib;
        cout << fib << " ";
    }
    cout << "\nTotal steps (recursive): " << recursiveSteps;
    cout << "\nTotal Fibonacci value (recursive): " << totalRecursive << endl;

    int totalIterative = 0;
    cout << "\nIterative Fibonacci sequence:\n";
    for (int i = 0; i < n; i++) {
        int fib = fibonacciIterative(i);
        totalIterative += fib;
        cout << fib << " ";
    }
    cout << "\nTotal steps (iterative): " << iterativeSteps;
    cout << "\nTotal Fibonacci value (iterative): " << totalIterative << endl;

    return 0;
}
