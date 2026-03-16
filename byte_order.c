#include <stdio.h>

int main() {
    unsigned int num = 0x12345678;  // 4-byte integer
    unsigned char *bytePtr = (unsigned char*)&num;

    printf("Memory representation of num: ");
    for (int i = 0; i < sizeof(num); i++) {
        printf("%02x ", bytePtr[i]);
    }
    printf("\n");

    if (bytePtr[0] == 0x78) {
        printf("System is Little Endian.\n");
    } else if (bytePtr[0] == 0x12) {
        printf("System is Big Endian.\n");
    } else {
        printf("Unknown Endianness.\n");
    }

    return 0;
}
