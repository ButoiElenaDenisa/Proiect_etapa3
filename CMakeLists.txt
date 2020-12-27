cmake_minimum_required(VERSION 3.17)
project(final)

set(CMAKE_CXX_STANDARD 11)

add_executable(biblioteca Apreciere.cpp ApreciereCompusa.cpp ApreciereScurta.cpp
        Autor.cpp Carte.cpp Cititor.cpp DBMS.cpp
        EBook.cpp IClasificabil.cpp Imprumut.cpp Jurnalist.cpp
        main.cpp Biblioteca.cpp Biblioteca.h)