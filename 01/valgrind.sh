#!/bin/zsh

valgrind --leak-check=full --track-origins=yes ./out 2> output_valgrind.txt
valgrind --leak-check=full --track-origins=yes ./out 1> output_valgrind.txt

###
# valgrind --leak-check=full --track-origins=yes ./char 
# valgrind --leak-check=full --track-origins=yes ./sq 2> output_txt.valgrind
