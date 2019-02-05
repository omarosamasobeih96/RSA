cmake_minimum_required(VERSION 3.7)
project(RSA___Cpp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Decryption.h
        Encryption.h
        Generator.h
        Key.h
        Message.h
        Source.cpp
        Utility.h)

add_executable(RSA___Cpp ${SOURCE_FILES})