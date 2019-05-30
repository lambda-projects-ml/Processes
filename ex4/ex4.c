// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    int rc = fork();
    char *args[] = {"/bin/ls", NULL};

    if (rc < 0)
    {
        exit(1);
    }
    else if (rc == 0)
    {
        execl("/bin/ls", "ls", 0, 0);

        // execv(args[0], args);
    }
    else
    {
        waitpid(rc, NULL, 0);
        printf("Parent");
    }

    return 0;
}
