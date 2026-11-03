//
// Created by Pablo Chávez on 29/10/26.
//

#ifndef DATASTRUCTUREANDALGORITHMS_FIBONACCI_H
#define DATASTRUCTUREANDALGORITHMS_FIBONACCI_H
#include <vector>

class fibonacci
{
    // Fibonacci Function has all the requirements to be implemented as a dynamic programming algorithm
    // First it has overlapping subproblems
    // Second it has optimal substructure
public:
    int counter = 0;

    int fib(int n)
    {
        counter++;
        if (n == 0 || n == 1) return n;
       return fib(n - 1) + fib(n - 2);
    }

    // Same function as fib but with memoization
    // Memoization is a technique used to optimize recursive algorithms by storing the results of
    // expensive function calls and reusing them when the same inputs occur again.
    int memoCounter = 0;
    std::vector<int> memo = std::vector<int>(100, -1);
    int fibMemo(int n)
    {
        if (memo[n] != -1) return memo[n];
        if (n == 0 || n == 1) return n;
        memo[n] = fibMemo(n - 1) + fibMemo(n - 2);
        memoCounter++;
        return memo[n];
    }

    // Fib function but using another method called, bottom up.
    // Bottom up mean that we are solving the problem from the bottom until the top.
    // More efficient (O(n)).
    int bottomCounter = 0;
    int fibBottom(int n)
    {
        std::vector<int> fibList;
        fibList.push_back(0);
        fibList.push_back(1);

        for (int index = 2; index <= n; index++)
        {
            bottomCounter++;
            fibList.push_back(fibList[index - 1] + fibList[index - 2]);
        }
        return fibList[n];
    }
};


#endif //DATASTRUCTUREANDALGORITHMS_FIBONACCI_H
