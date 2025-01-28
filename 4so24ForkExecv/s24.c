main() {
    if (fork() == 0) {
        execv("extractB", 0);
        printf("\n Code EF");
    }
    printf("\n Code 45");
}

