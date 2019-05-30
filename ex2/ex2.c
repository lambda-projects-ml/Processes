// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory
// and then calls `fork()` to create a new process.

//Can both the child and parent access the file descriptor returned by `fopen()`?
// Yes. They both are able to read and write to the same file

//What happens when they are written to the file concurrently?
// They write in the order they are processed

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    fp = fopen("text.txt", "w+");

    int rc = fork();
    if (rc < 0)
    {
        printf("Failed");
        exit(1);
    }
    else if (rc == 0)
    {
        fprintf(fp, "%s\n", "Child");
    }
    else
    {
        fprintf(fp, "%s\n", "Parent");
    }

    return 0;
}
