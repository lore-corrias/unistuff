cmake_minimum_required(VERSION 3.25)
project(lab C)

set(CMAKE_C_STANDARD 99)

add_executable(lab selection_sort/selection_sort_iterativo.c selection_sort/selection_sort_ricorsivo.c utils/array.c utils/array.h selection_sort/selection_sort.h selection_sort/selection_sort.c binary_search/binary_search.c binary_search/binary_search.h binary_search/binary_search_iterativa.c binary_search/binary_search_ricorsiva.c binary_search/binary_search_hotel.c binary_search/binary_search_hotel.h main.c matrice_sparsa/matrice_sparsa.c kmp_pattern_search/kmp_pattern_search.c kmp_pattern_search/kmp_pattern_search.h)
