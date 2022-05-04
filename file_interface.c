#include <stdio.h>
#include <stdlib.h>
#include "library.h"

int main(int argc, char** argv) {
        FILE* f;
        int n, inp;
        struct tree* root = NULL;

        if (argc != 4) { printf("Error: too few or too many arguments\n"); return -1; }

        if ((f = fopen(argv[1], "r")) == NULL) { printf("Error: unable to open \"%s\" file\n", argv[1]); return -1; }

        while ((n = fscanf(f, "%d", &inp)) != EOF) {
            addElement(&root, inp);
        }

        fclose(f);
        printf("--------------\n");

        if ((f = fopen(argv[2], "r")) == NULL) { printf("Error: unable to open \"%s\" file\n", argv[2]); return -1; }

        while ((n = fscanf(f, "%d",&inp)) != EOF) {
             findElement(root, inp);
        }

        fclose(f);
	printf("--------------\n");

	if ((f = fopen(argv[3], "r")) == NULL) { printf("Error: unable to open \"%s\" file\n", argv[3]); return -1; }

        while ((n = fscanf(f, "%d",&inp)) != EOF) {
             deleteElement(&root, inp);
        }

        return 0;
}

