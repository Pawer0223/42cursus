export YELLOW='\033[1;33m'
export NO_COLOR='\033[0m'

gcc -o ./my_test/random ./my_test/random_gene.c;
export ARG=$(./my_test/random $1);
echo "${YELLOW}--------------------test data--------------------";
echo ${NO_COLOR}$ARG;
echo "${YELLOW}-----------------Checker Result------------------${NO_COLOR}";
./push_swap "$ARG" | ./checker "$ARG";
echo "${YELLOW}----------------Instruction Cnt------------------${NO_COLOR}";
./push_swap "$ARG" | wc -l | tr -d " ";
# echo "--------------------leak test start--------------------";
# leaks -atExit -- ./push_swap "$ARG";
# echo "--------------------leak test end--------------------";
