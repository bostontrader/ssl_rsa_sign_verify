cmake_minimum_required(VERSION 3.12)

project(ssl_rsa_sign_verify)

set(CMAKE_CXX_STANDARD 11)

link_libraries(crypto)
add_executable(ssl_rsa_sign_verify main.cpp)