cmake_minimum_required(VERSION 3.20)
project(PesquisaExterna C)

set(CMAKE_C_STANDARD 99)

add_executable(PesquisaExterna main.c acessoSequencial.c acessoSequencial.h geradorArquivos.c geradorArquivos.h arvoreBinaria.c arvoreBinaria.h arvoreB.c arvoreB.h arvoreBEstrela.c arvoreBEstrela.h)
