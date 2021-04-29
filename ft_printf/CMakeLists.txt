cmake_minimum_required(VERSION 3.19)
project(ftprintf C)

set(CMAKE_C_STANDARD 99)

add_library(ft_printf
        src/ft_atoi.c
        src/ft_printf.c
        src/ft_strcmp.c
        src/gets.c
        src/prints.c
        src/processing.c
        src/puts.c
        includes/ft_pft.h
        includes/ft_printf.h)