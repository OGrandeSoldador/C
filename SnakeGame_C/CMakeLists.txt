cmake_minimum_required(VERSION 3.10)

# Nome do projeto.
project(Code)

# Definir o padrão do C (opcional, mas recomendado).
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# Adicionar os arquivos-fonte ao projeto.
add_executable(Code
    main.c
    map.c
    player.c
    conio.c
    objetos.c
)