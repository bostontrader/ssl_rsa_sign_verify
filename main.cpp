#include <iostream>
#include <string> // std::string

#include <openssl/evp.h>
#include <openssl/pem.h>

int main()
{
    EVP_PKEY *skey = NULL;

    // Convert a string-based private key into an EVP_PKEY structure:
    // This is a throw-down pkey created specifically for this example.  Feel free to try to hack something else with it.
    std::string privateKey = "-----BEGIN RSA PRIVATE KEY-----\n"
                             "MIICXAIBAAKBgQC2FMkYZAWyhIZNmlQHy3i2/pKCaERFr6ub2QaAinPxxXV4irS+\n"
                             "I/qqorHub4Dji7xGRivQ7x76w1pqVnoMlx8P8k8Heqr62DF5TZiHl13eC9Ld/ju2\n"
                             "NtgqwS+28pLFWQjFfJuj8XHoPn/noPevABLEkgj1+36hRsdNtoWkiO3yyQIDAQAB\n"
                             "AoGAaGT8cz6Nwa+X7RBp01pGqOzGhXxQgH/a7Wz9/F7lYR4sXuNwA4BPbNwBFkrZ\n"
                             "5Byu4r/CyXUAFxhAU62nJmbSyHMNAZJyvYZFlbc20u3oMKQPkmZkhqH7pfoxvI2e\n"
                             "UMCvwmgnyzvNdJbsg3wAP1zLTTIKHsY2zTqOU1zds7a9fV0CQQDgVU0dy3ikOFpT\n"
                             "w+xdlohdy5OTz1WKG7dv997+FfiWdFt87u1mIRmAEtvIMSUFk9gR4ot4wl7fIGKN\n"
                             "Kh8BQiprAkEAz8ihA+LFsWMHoQTSPipaCBht3Ty6IGK1mHiKu83MLJSR83Ng8Ouv\n"
                             "jtfNyIV+Di5TXI58jKF86bBSNtxKenPMmwJBAKM/D8YtyhXe+ERan8efAo8W1MbM\n"
                             "Kxg8gSmWvAw0WtjJxcXNbK5USeU8U/mDYciERMkHDa2L7FP8khrd2wAkcQ8CQDxs\n"
                             "SXaJ0Zd+Bs/qSQFO65ODFx/I8w9L5ScLlrx6Yi9snOzA1qX4w7q0QuFXAIs7KX62\n"
                             "6L00kNCcN6xAb2AgoJUCQBSSSvbKQjv4YFv/G+RKhhCltxSjfmAN12wpFuv7Oy3e\n"
                             "5P4YOUZ9fi2FKkUpHdNyau1nbyc81UpmdA4uYd7pGLM=\n"
                             "-----END RSA PRIVATE KEY-----\n";

    BIO *bio = BIO_new(BIO_s_mem());
    if(BIO_write(bio, (unsigned char*)privateKey.c_str(), (size_t)privateKey.size()) != (int)privateKey.size())
        BIO_free_all(bio);

    PEM_read_bio_PrivateKey(bio, &skey, NULL, NULL);
    BIO_free_all(bio);

    if(skey == NULL)
        std::cout << "private key error\n";

    std::cout << "Success\n";

}