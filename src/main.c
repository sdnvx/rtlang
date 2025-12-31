#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <libgen.h>
#include <stdio.h>

static void process(const char *path);

int main(int argc, char *argv[])
{
    char *proc;
    int ch;

    proc = basename(argv[0]);

    while (true) {
        ch = getopt(argc, argv, "");
        if (ch < 0)
            break;
    }

    if (!argc) {
        fprintf(stderr, "%s: no input files\n", proc);
        return EXIT_FAILURE;
    }

    while (argc > 0) {
        process(*argv);
        argc--, argv++;
    }

    return EXIT_SUCCESS;
}

static void process(const char *path)
{
}
