rm *.o
ls *.s | xargs -n1 nasm -f macho64
arch -x86_64 gcc -c *.c
arch -x86_64 gcc *.o 
# 8664 gcc -c main.c
