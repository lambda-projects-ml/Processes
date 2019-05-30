// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100).

// What value is the variable in the child process?
// Currently set to take the original value
// What happens to the variable when both the child and parent change the value of x?
// They each have different values for the variable. One cannot change it for the other

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 100;
    int rc = fork();

    if (rc < 0)
    {
        printf("Fork Failed");
        exit(1);
    }
    else if (rc == 0)
    {
        // x = 10;
        printf("Child: %d\n", x);
    }
    else
    {
        x = 50;
        printf("Parent: %d\n", x);
    }

    return 0;
}
