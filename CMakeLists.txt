cmake_minimum_required(VERSION 3.12)

project(ssl_rsa_sign_verify)
# project(ssl_rsa_sign_verify C)

set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_C_STANDARD 99)

# find_library(SSL_LIB libssl.a REQUIRED)
# find_library(CRYPTO_LIB libcrypto.a REQUIRED)
link_libraries(crypto)
add_executable(ssl_rsa_sign_verify main.cpp)