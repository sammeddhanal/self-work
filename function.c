/*Write a program with nested function calls.
Print:
Address of local variables
Address of function parameters
Address of return address (using __builtin_return_address)*/




#include <stdio.h>

void func3(int a)
{
    int local3 = 30;

    printf("\n--- Inside func3 ---\n");
    printf("Address of parameter a: %p\n", (void*)&a);
    printf("Address of local variable local3: %p\n", (void*)&local3);
    printf("Return address: %p\n", __builtin_return_address(0));
}

void func2(int b)
{
    int local2 = 20;

    printf("\n--- Inside func2 ---\n");
    printf("Address of parameter b: %p\n", (void*)&b);
    printf("Address of local variable local2: %p\n", (void*)&local2);
    printf("Return address: %p\n", __builtin_return_address(0));

    func3(b + 1);
}

void func1(int c)
{
    int local1 = 10;

    printf("\n--- Inside func1 ---\n");
    printf("Address of parameter c: %p\n", (void*)&c);
    printf("Address of local variable local1: %p\n", (void*)&local1);
    printf("Return address: %p\n", __builtin_return_address(0));

    func2(c + 1);
}

int main()
{
    int x = 5;

    printf("--- Inside main ---\n");
    printf("Address of local variable x: %p\n", (void*)&x);

    func1(x);

    return 0;
}
