#include <getopt.h>
#include "utils.h"

const char *version = "v0.1.0";

static const struct option long_options[] = {
        {"help",     no_argument,       NULL, 0},
        {"version",  no_argument,       NULL, 0},
        {"username", required_argument, NULL, 'u'},
        {"password", required_argument, NULL, 'p'},
        {"debug",    no_argument,       NULL, 'd'},
        {NULL,       no_argument,       NULL, 0}
};

void print_help(const char *argn) {
    printf("Usage: %s --username <username> --password <password>\n"
           "  -d, --debug    enable debug mode\n"
           "      --help     display this help and exit\n"
           "      --version  output version information and exit", argn);
}

int main(int argc, char *argv[]) {
    char *username = NULL;
    char *password = NULL;
    bool debug = false;
    int opt, opt_idx;
    while ((opt = getopt_long(argc, argv, "u:p:d", long_options, &opt_idx)) != -1) {
        switch (opt) {
            case 0:
                switch (opt_idx) {
                    case 0:
                        print_help(argv[0]);
                        exit(EXIT_SUCCESS);
                        break;
                    case 1:
                        printf("%s version %s\n", argv[0], version);
                        exit(EXIT_SUCCESS);
                        break;
                    default:
                        break;
                }
                break;
            case 'u':
                username = optarg;
                break;
            case 'p':
                password = optarg;
                break;
            case 'd':
                debug = true;
                print_log(INFO, "running in debug mode");
                break;
            default:
                print_help(argv[0]);
                exit(EXIT_FAILURE);
                break;
        }
    }
    if (username == NULL) {
        print_log(FATAL, "username is required");
    }
    if (password == NULL) {
        print_log(FATAL, "password is required");
    }
    print_log(INFO, "Hello %s, your password is %s", username, password);
    return 0;
}
