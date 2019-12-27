cmake_minimum_required(VERSION 3.4.1)

add_library(TextCMake SHARED TextCMake.cpp)
target_link_libraries(TextCMake)

add_library(CTransferJava SHARED CTransferJava.cpp)
target_link_libraries(CTransferJava)