#ifndef AES_TEST_HPP
#define AES_TEST_HPP

#include "AES.hpp"
#include <iostream>

const unsigned int BLOCK_BYTES_LENGTH = 16 * sizeof(unsigned char);

/*
    ======================
        Util Functions
    ======================
*/

void check_except(unsigned char *plain, unsigned char *key, unsigned int len)
{
    AES aes(AESKeyLen::AES_256);
    try {
        aes.encrypt(plain, key, len);
    } catch (std::exception& e) { 
        std::cout << "\033[32m [PASS] \033[0m" << std::endl;
        return;
    }
    
    std::cout << "\033[31m [FAIL] \033[0m" << std::endl;
}

void check(unsigned char *right, unsigned char *out, unsigned int len)
{
    if(!memcmp(right, out, len))
        std::cout << "\033[32m [PASS] \033[0m" << std::endl;
    else
        std::cout << "\033[32m [FAIL] \033[0m" << std::endl;
}

/*
    ======================
        Test Functions
    ======================
*/

void    test_key_length_128()
{
    AES aes(AESKeyLen::AES_128);

    unsigned char plain[] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};
    unsigned char key[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};
    unsigned char right[] = {0x69, 0xc4, 0xe0, 0xd8, 0x6a, 0x7b, 0x04, 0x30, 0xd8, 0xcd, 0xb7, 0x80, 0x70, 0xb4, 0xc5, 0x5a};

    unsigned char *out = aes.encrypt(plain, key, BLOCK_BYTES_LENGTH);

    std::cout << "Test Encryption With Key of Length 128:                              ";
    check(right, out, BLOCK_BYTES_LENGTH);
    delete[] out;
}

void    test_key_length_192()
{
    AES aes(AESKeyLen::AES_192);

    unsigned char plain[] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};
    unsigned char key[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c,0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17};
    unsigned char right[] = {0xdd, 0xa9, 0x7c, 0xa4, 0x86, 0x4c, 0xdf, 0xe0, 0x6e, 0xaf, 0x70, 0xa0, 0xec, 0x0d, 0x71, 0x91};

    unsigned char *out = aes.encrypt(plain, key, BLOCK_BYTES_LENGTH);

    std::cout << "Test Encryption With Key of Length 192:                              ";
    check(right, out, BLOCK_BYTES_LENGTH);
    delete[] out;
}

void    test_key_length_256()
{
    AES aes(AESKeyLen::AES_256);

    unsigned char plain[] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};
    unsigned char key[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                         0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
                         0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
                         0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f};
    unsigned char right[] = {0x8e, 0xa2, 0xb7, 0xca, 0x51, 0x67, 0x45, 0xbf, 0xea, 0xfc, 0x49, 0x90, 0x4b, 0x49, 0x60, 0x89};

    unsigned char *out = aes.encrypt(plain, key, BLOCK_BYTES_LENGTH);

    std::cout << "Test Encryption With Key of Length 256:                              ";
    check(right, out, BLOCK_BYTES_LENGTH);
    delete[] out;
}

void    test_encrypt_one_block()
{
    AES aes(AESKeyLen::AES_128);

    unsigned char plain[] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};
    unsigned char key[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};
    unsigned char right[] = {0x69, 0xc4, 0xe0, 0xd8, 0x6a, 0x7b, 0x04, 0x30, 0xd8, 0xcd, 0xb7, 0x80, 0x70, 0xb4, 0xc5, 0x5a};

    unsigned char *out = aes.encrypt(plain, key, BLOCK_BYTES_LENGTH);

    std::cout << "Test Encryption of One Block:                                        ";
    check(right, out, BLOCK_BYTES_LENGTH);
    delete[] out;
}

void    test_decrypt_one_block()
{
    AES aes(AESKeyLen::AES_128);

    unsigned char encrypted[] = {0x69, 0xc4, 0xe0, 0xd8, 0x6a, 0x7b, 0x04, 0x30, 0xd8, 0xcd, 0xb7, 0x80, 0x70, 0xb4, 0xc5, 0x5a};
    unsigned char key[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};
    unsigned char right[] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};

    unsigned char *out = aes.decrypt(encrypted, key, BLOCK_BYTES_LENGTH);

    std::cout << "Test Decryption of One Block:                                        ";
    check(right, out, BLOCK_BYTES_LENGTH);
    delete[] out;
}

void    test_encrypt_decrypt_one_block()
{
    AES aes(AESKeyLen::AES_256);

    unsigned char plain[] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};
    unsigned char key[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                         0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
                         0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
                         0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f};

    unsigned char *out = aes.encrypt(plain, key, BLOCK_BYTES_LENGTH);
    unsigned char *innew = aes.decrypt(out, key, BLOCK_BYTES_LENGTH);

    std::cout << "Test Encryption/Decryption of One Block:                             ";
    check(innew, plain, BLOCK_BYTES_LENGTH);
    delete[] out;
    delete[] innew;
}

void    test_encrypt_two_blocks()
{
    AES aes(AESKeyLen::AES_128);
    
    unsigned char plain[] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
                           0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff,
                           0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
                           0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f};
    unsigned char key[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};
    unsigned char right[] = {0x69, 0xc4, 0xe0, 0xd8, 0x6a, 0x7b, 0x04, 0x30, 0xd8, 0xcd, 0xb7,
                            0x80, 0x70, 0xb4, 0xc5, 0x5a, 0x07, 0xfe, 0xef, 0x74, 0xe1, 0xd5,
                            0x03, 0x6e, 0x90, 0x0e, 0xee, 0x11, 0x8e, 0x94, 0x92, 0x93};

    unsigned char *out = aes.encrypt(plain, key, 2 * BLOCK_BYTES_LENGTH);

    std::cout << "Test Encryption of Two Blocks:                                       ";
    check(right, out, 2 * BLOCK_BYTES_LENGTH);
    delete[] out;
}

void    test_decrypt_two_blocks()
{
    AES aes(AESKeyLen::AES_128);

    unsigned char encrypted[] = {0x69, 0xc4, 0xe0, 0xd8, 0x6a, 0x7b, 0x04, 0x30, 0xd8, 0xcd, 0xb7,
                                0x80, 0x70, 0xb4, 0xc5, 0x5a, 0x07, 0xfe, 0xef, 0x74, 0xe1, 0xd5,
                                0x03, 0x6e, 0x90, 0x0e, 0xee, 0x11, 0x8e, 0x94, 0x92, 0x93};
    unsigned char key[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};
    unsigned char right[] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
                           0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff,
                           0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
                           0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f};

    unsigned char *out = aes.decrypt(encrypted, key, 2 * BLOCK_BYTES_LENGTH);

    std::cout << "Test Decryption of Two Block:                                        ";
    check(right, out, 2 * BLOCK_BYTES_LENGTH);
    delete[] out;
}

void    test_encrypt_decrypt_one_cb()
{
    AES aes(AESKeyLen::AES_256);

    unsigned int cb_size = 1024 * sizeof(unsigned char);
    unsigned char *plain = new unsigned char[cb_size];

    for (unsigned int i = 0; i < cb_size; i++)
        plain[i] = i % 256;

    unsigned char key[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                         0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
                         0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
                         0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f};

    unsigned char *out = aes.encrypt(plain, key, cb_size);
    unsigned char *innew = aes.decrypt(out, key, cb_size);

    std::cout << "Test Encryption/Decryption of One Code Block:                        ";
    check(innew, plain, cb_size);
    delete[] plain;
    delete[] out;
    delete[] innew;
}

void    test_encrypt_one_block_without_byte()
{
    AES aes(AESKeyLen::AES_128);

    unsigned char plain[] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee};
    unsigned char key[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};

    std::cout << "Test Exception for Short Block Length:                               ";
    check_except(plain, key, (BLOCK_BYTES_LENGTH - 1 * sizeof(unsigned char)));
}

void    test_encrypt_one_block_plus_one_byte()
{
    AES aes(AESKeyLen::AES_128);

    unsigned char plain[] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0xaa};
    unsigned char key[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};

    std::cout << "Test Exception for Long Block Length:                                ";
    check_except(plain, key, (BLOCK_BYTES_LENGTH + 1 * sizeof(unsigned char)));
}


void    run_all_tests()
{
    test_key_length_128();
    test_key_length_192();
    test_key_length_256();
    test_encrypt_one_block();
    test_decrypt_one_block();
    test_encrypt_decrypt_one_block();
    test_encrypt_two_blocks();
    test_decrypt_two_blocks();
    test_encrypt_decrypt_one_cb();
    test_encrypt_one_block_without_byte();
    test_encrypt_one_block_plus_one_byte();
}

#endif
