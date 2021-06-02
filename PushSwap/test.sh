gcc -o ./my_test/random ./my_test/random_gene.c;
export ARG=$(./my_test/random $1);
echo "$1 개 데이터 테스트";
./push_swap "$ARG" | ./checker "$ARG";
./push_swap "$ARG" | wc -l;
echo $ARG;
