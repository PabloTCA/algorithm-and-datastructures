//
// Created by Pablo Chávez on 29/10/26.
//

#ifndef DATASTRUCTUREANDALGORITHMS_FIBONACCI_H
#define DATASTRUCTUREANDALGORITHMS_FIBONACCI_H


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
};


#endif //DATASTRUCTUREANDALGORITHMS_FIBONACCI_H
