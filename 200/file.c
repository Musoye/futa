#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *sfile, *dfile;
    char ch;

    sfile = fopen("./students.txt", "r");
    if (sfile == NULL) {
        printf("Cannot open source file.\n");
        exit(1);
    }

    dfile = fopen("./matrix.txt", "w");
    if (dfile == NULL) {
        printf("Cannot open destination file.\n");
        fclose(sfile);
        exit(1);
    }

    while ((ch = fgetc(sfile)) != EOF) {
        fputc(ch, dfile);
    }

    printf("File copied successfully.\n");

    fclose(sfile);
    fclose(dfile);

    return 0;
}