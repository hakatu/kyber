#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "kem.h"
#include "kex.h"
#include "params.h"
#include "indcpa.h"
#include "polyvec.h"
#include "poly.h"
//#include "cpucycles.h"
//#include "speed_print.h"
#include "fips202.h"
#include <string.h>
//#include "fpga_sha.h"

int main(void)
{
    // char input[800]="Co chang trai viet len cay loi yeu thuong co gai ay moi tinh nhu gio nhu may viet nen buc tranh ve bang diu em Co truong thuc nhu gia buot la mua ngay co ay di theo chan me cha chang trai vu vo tu xa trong tim hut hang nhu mat mot thu gi";
    // gets(input);
    // uint8_t *text;
    // text=input;
    uint8_t text[]={0xe7, 0x28, 0x55, 0x61, 0x9b, 0xaa, 0x8c, 0xb2, 0x71, 0x41, 0x3a, 0x71, 0x28, 0xdb, 0x9b, 0x3a, 0x97, 0x74, 0x0a, 0x24, 0x70, 0x93, 0x23, 0x03, 0xdc, 0x86, 0x44, 0x6e, 0x41, 0x8b, 0x3f, 0xb1, 0xd5, 0xf8}; 
    // uint8_t text[6] = {0xfd, 0x69, 0x9b, 0x12, 0xab, 0xac};
    // uint8_t output1[32];
    // sha3_256(output1,text,sizeof(text));
    // printf("SHA3-256 hashvalue is: ");
    // for (uint8_t i=0; i<32; i++)
    // {
    //     printf("%02x", output1[i]);
    // }
    // uint8_t output2[64];
    printf("34 bytes input of absorb is: ");
    for (uint8_t i=0; i<sizeof(text); i++)
    {
        printf("%02x", text[i]);
    }
    keccak_state state;
    shake128_absorb_once(&state,text,sizeof(text));
    printf("\nAbsorboutput is: ");
    for (uint8_t j=0; j<25; j++)
    {
        printf("%016llx", state.s[j]);
        if (j<(25-1))
        {
            printf("_");
        }
    }
    printf("\nSqueeze using input is absorb output");
    uint8_t block=3;
    printf("\nSqueeze %d blocks output is:", block);
    uint8_t buf[506]={0};
    shake128_squeezeblocks(buf,1,&state);
    printf("\nSqueeze state output is: ");
    for (uint8_t j=0; j<25; j++)
    {
        printf("%016llx", state.s[j]);
        if (j<(25-1))
        {
            printf("_");
        }
    }
    printf("\nSqueeze out is: ");
    for (uint16_t i=0; i<506; i++)
    {
        printf("%02x", buf[i]);
    }





    //shake128_squeezeblocks
    

    // sha3_512(output2,text,sizeof(text));
    // printf("\nSHA3-512 hashvalue is: ");
    // for (uint8_t i=0; i<64; i++)
    // {
    //     printf("%02x", output2[i]);
    // }
    // hps_fpgainit();
    // fpga_sha3_256(output3,text,strlen(input));
    // printf("\nSHA3-256 hashvalue (FPGA) is: ");
    // for (uint8_t i=0; i<32; i++)
    // {
    //     printf("%02x", output3[i]);
    // }
    // hps_fpgarelease();
}

