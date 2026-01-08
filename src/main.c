#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <libgen.h>
#include <stdio.h>

#include <rtlang/error.h>
#include <rtlang/lexer.h>
#include <rtlang/utils.h>

static void usage(void);
static bool process(const char *path);

int main(int argc, char *argv[])
{
    int ch;

    loop {
        ch = getopt(argc, argv, "h");
        if (ch < 0)
            break;

        switch (ch) {
        case 'h':
            usage();
            return EXIT_SUCCESS;

        default:
            return EXIT_FAILURE;
        }
    }

    argc -= optind;
    argv += optind;

    if (!argc) {
        rt_error("no input files");
        return EXIT_FAILURE;
    }

    while (argc > 0) {
        if (!process(*argv))
            return EXIT_FAILURE;

        argc--, argv++;
    }

    return EXIT_SUCCESS;
}

static void usage()
{
    fprintf(stderr, "usage:\n");
    fprintf(stderr, "%s [options] <file> ...\n", rt_process_name());
}

static bool process(const char *path)
{
    bool status = false;

    rt_lexer_t *lexer;
    rt_token_t *token;

    lexer = rt_lexer_open(path);
    if (!lexer)
        return false;

    while (true) {
        token = rt_lexer_read_token(lexer);
        if (!token)
            break;

        printf("%s:'%s' at %u, %u\n",
               rt_token_type_name(token->type),
               token->text ? token->text : "", token->row,  token->column);

        if (token->type == RT_TOKEN_EOF) {
            status = true;
            break;
        }

        rt_token_free(token);
    }

    if (token)
        rt_token_free(token);

    rt_lexer_close(lexer);

    return status;
}
