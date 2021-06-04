export BLUE='\033[1;34m'
export YELLOW='\033[1;33m'
export GREEN='\033[1;32m'
export RED='\033[1;31m'
export NO_COLOR='\033[0m'

gcc -o ./my_test/random ./my_test/random_gene.c;
gcc -o ./my_test/basic ./my_test/basic_test.c;
make

echo "${GREEN}[1] ./test.sh [num] => count of elements";
echo "[2] ./test.sh all [num](0 ~ 9) => [num] element permutation test${NO_COLOR}"

CHECKER_R="";

function	leak_check()
{
	echo "${RED}--------------------leak test start--------------------${NO_COLOR}";
	leaks -atExit -- ./push_swap "$ARG";
	echo "${RED}---------------------leak test end---------------------${NO_COLOR}";
}

function    exec_push_swap()
{
	if [ -z "$ARG" ]
	then
		echo "${RED}ARG is Null${NO_COLOR}"
	else
		echo "${YELLOW}--------------------test data--------------------${NO_COLOR}";
		echo $ARG;
		echo "${YELLOW}-----------------Checker Result------------------${NO_COLOR}";
		CHECKER_R=`./push_swap "$ARG" | ./checker "$ARG"`;
	if [ "$CHECKER_R" = "OK" ]
		then
			echo ${BLUE}${CHECKER_R};
			echo "${YELLOW}----------------Instruction Cnt------------------${NO_COLOR}";
			./push_swap "$ARG" | wc -l | tr -d " ";
		else
			echo ${RED}${CHECKER_R}${NO_COLOR};
		fi
	fi
}

if [ "$1" = "all" ]
then
	# -z -> null is true
	if [ -z "$2" ]
	then
		echo "${RED}please call [2]${NO_COLOR}"
	else
		./my_test/basic "$2"
	fi
else
	# -n -> not null is [true]
	if [ -n "$1" ]
	then
		export ARG=$(./my_test/random $1);
	fi
		exec_push_swap
fi
