#include <stdio.h>
int main(int argc, const char **argv) {
    const int N = 4;
    unsigned char buf[] = {0x1f, 0x10, 0xff, 0x00};
    FILE *fo = fopen("test.bin", "wb");
    fwrite(buf, N, 1, fo);
    fclose(fo);
    return 0;
}
