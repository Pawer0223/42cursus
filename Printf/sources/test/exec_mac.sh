# gcc main.c ../*.c ../libft/*.c ../../headers/*.h -lm 
# gcc -g /home/taesan/42cursus/Printf/sources/test/main.c /home/taesan/42cursus/Printf/sources/*.c /home/taesan/42cursus/Printf/sources/libft/*.c /home/taesan/42cursus/Printf/headers/*.h -lm
gcc main.c -L ${HOME}/42cursus/Printf/ -lftprintf -lm
