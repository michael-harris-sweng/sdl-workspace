
#include <stdio.h>
#include <unistd.h>

#include "graphics.h"

int main(int argc, const char* argv[]) {
    Graphics graphics;
    for (int i = 0; i < 3; i++) {
        printf("Executing...\n");
        sleep(1);
    }
	return 0;
}
