#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>

enum {len=230454};
uint8_t buff[len];

void shade(
    uint32_t I1, uint32_t I2, uint32_t I3,
    uint8_t* imageDataArray);

void setBmpHeader(uint8_t* buff){
    uint8_t bytes[37] = {
        0x42, 0x4D, 0x36, 0x84, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x00,
        0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x40, 0x01, 0x00, 0x00, 0xF0, 0x00,
        0x00, 0x00, 0x01, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x84,
        0x03
    };
    for(size_t i = 0; i < 37; ++i){
        *buff = bytes[i];
        ++buff; 
    }
}

int main(){
    uint8_t r1, g1, b1, r2, g2, b2, r3, g3, b3;
    uint32_t I1, I2, I3;
    printf("Please input RGB values for the first vertice in the proper format, e.g. '238 130 238' to input violet: ");
    scanf("%" SCNu8 " %" SCNu8 " %" SCNu8, &r1,&g1,&b1);
    printf("Please input RGB values for the second vertice: ");
    scanf("%" SCNu8 " %" SCNu8 " %" SCNu8, &r2,&g2,&b2);
    printf("Please input RGB values for the third vertice: ");
    scanf("%" SCNu8 " %" SCNu8 " %" SCNu8, &r3,&g3,&b3);
    I1 = (0x00<<24) + (b1<<16) + (g1<<8) + r1;
    I2 = (0x00<<24) + (b2<<16) + (g2<<8) + r2;
    I3 = (0x00<<24) + (b3<<16) + (g3<<8) + r3;
    setBmpHeader(buff);
    shade(I1, I2, I3, buff+54);

    printf("Opening file...");
    FILE *imgFile;
    imgFile = fopen("shading.bmp", "wb");
	if (imgFile == NULL)
	{
		printf("Error!\n");
		return -1;
	}
    else printf("Success\n");

    fwrite(buff, len, 1, imgFile);
	fclose(imgFile);

    return 0;
}
