export BLUE='\033[1;34m'
export YELLOW='\033[1;33m'
export GREEN='\033[1;32m'
export RED='\033[1;31m'
export NO_COLOR='\033[0m'

make

ls /usr/bin > ls.txt
echo "${YELLOW}[Test File Create]${NO_COLOR}"
echo "${GREEN}ls /usr/bin > ls.txt${NO_COLOR}";

RESULT="NONE";
PIPEX_COMMAND="";
LINUX_COMMAND="";
WRONG_CNT=0
LEAKS="leaks -atExit -- ";

DIFF="diff result.txt result2.txt > diff.txt"

function	echo_result()
{
	if [ "$RESULT" = "" ]
		then
			echo "${BLUE}OK${NO_COLOR}";
		else
			echo "${RED}Error${NO_COLOR}";
			WRONG_CNT=$((WRONG_CNT + 1)); # cnt++
		fi
}

function	exec_program()
{
	echo "${GREEN}${LINUX_COMMAND}${NO_COLOR}";
	eval ${LINUX_COMMAND}
	#cat result.txt

	echo "${GREEN}${PIPEX_COMMAND}${NO_COLOR}";
	eval ${PIPEX_COMMAND}
	#${LEAKS} ${PIPEX_COMMAND}
	#cat result2.txt

	eval ${DIFF}
	RESULT=`cat diff.txt`;
	echo_result 
}

function    case_1()
{
	echo "${YELLOW}--------------------basic 1--------------------${NO_COLOR}";

	LINUX_COMMAND="< ls.txt grep zip | wc -l > result.txt";
	PIPEX_COMMAND="./pipex ls.txt \"grep zip\" \"wc -l\" result2.txt";
	exec_program
}

function    case_2()
{
	echo "${YELLOW}--------------------basic 2--------------------${NO_COLOR}";

	LINUX_COMMAND="< ls.txt grep zip | grep u > result.txt";
	PIPEX_COMMAND="./pipex ls.txt \"grep zip\" \"grep u\" result2.txt";
	exec_program
}

function    case_3()
{
	echo "${YELLOW}--------------------Wrong Program 1--------------------${NO_COLOR}";

	LINUX_COMMAND="< ls.txt grap zip | wc -l > result.txt";
	PIPEX_COMMAND="./pipex ls.txt \"grap zip\" \"wc -l\" result2.txt";
	exec_program
	echo "${YELLOW}--------------------Wrong Program 2--------------------${NO_COLOR}";

	LINUX_COMMAND="< ls.txt grep zip | wac -l > result.txt";
	PIPEX_COMMAND="./pipex ls.txt \"grep zip\" \"wac -l\" result2.txt";
	exec_program
}

function    case_4()
{
	echo "${YELLOW}--------------------Wrong Option 1--------------------${NO_COLOR}";

	LINUX_COMMAND="< ls.txt grep zip | wc -eee > result.txt";
	PIPEX_COMMAND="./pipex ls.txt \"grep zip\" \"wc -eee\" result2.txt";
	exec_program

	echo "${YELLOW}--------------------Wrong Option 2--------------------${NO_COLOR}";

	LINUX_COMMAND="< ls.txt wc -eee | grep zip > result.txt";
	PIPEX_COMMAND="./pipex ls.txt \"wc -eee\" \"grep zip\" result2.txt";
	exec_program
}

function    case_5()
{
	echo "${YELLOW}--------------------Wrong--------------------${NO_COLOR}";

	LINUX_COMMAND="< 1 2 | 3 > 4";
	PIPEX_COMMAND="./pipex 1 \"2\" \"3\" 4";
	exec_program
}

function    bonus_case_1()
{
	echo "${YELLOW}--------------------bonus basic 1--------------------${NO_COLOR}";

	LINUX_COMMAND="< ls.txt grep zip | grep a | grep t > result.txt";
	PIPEX_COMMAND="./pipex ls.txt \"grep zip\" \"grep a\" \"grep t\" result2.txt";
	exec_program

	echo "${YELLOW}--------------------bonus basic 2--------------------${NO_COLOR}";
	LINUX_COMMAND="< ls.txt grep zip | grep a | grep t | wc -l > result.txt";
	PIPEX_COMMAND="./pipex ls.txt \"grep zip\" \"grep a\" \"grep t\" \"wc -l\" result2.txt";
	exec_program
}

function    bonus_case_2()
{
	echo "${YELLOW}--------------------here_doc [1 2 3 end 입력 ㄱ ㄱ]--------------------${NO_COLOR}";

	# 이게 안돌아가네..ㅎㅎ
	LINUX_COMMAND="cat << end | wc -l >> result.txt";
	PIPEX_COMMAND="./pipex here_doc end \"cat\" \"wc -l\" result2.txt";
	exec_program
}

function	mandatory()
{
	case_1
	case_2
	case_3
	case_4
	case_5
}

function	bonus_case()
{
	make fclean
	make bonus
	bonus_case_1
	# bonus_case_2
}

if [ "$1" = "bonus" ]
	then
		mandatory
		bonus_case
	else
		mandatory
	fi

echo "${YELLOW}WRONG_CNT : " ${WRONG_CNT}${NO_COLOR};