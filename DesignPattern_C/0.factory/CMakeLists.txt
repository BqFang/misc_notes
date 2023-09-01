cmake_minimum_required(VERSION 3.26.0)

project(factory)

set(FRUIT_LIST apple.c banana.c)


add_executable(factory main.c factory.c ${FRUIT_LIST})

