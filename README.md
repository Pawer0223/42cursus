# [libft](https://velog.io/@pawer/Libft) 

<details>
<summary>part 1 - libc 함수 직접구현</summary>
	<ul>
		<li>함수는 원본과 동일한 프로토타입 및 기능을 수행해야 한다. (man page 참조)</li>
		<li>직접 재 정의한 함수들은 실제 libc 함수와 성능적인 차이는 많이난다.</li>
	</ul>
</details>

<details>
<summary>part 2 - 문자열 함수구현</summary>
	<ul>
		<li>문자열 관련 함수 </li>
	</ul>
</details>

<details>
<summary>Bonus - List구현</summary>
	<ul>
		<li>LinkedList와 유사하다. 동일하다고는 볼 수 없다.</li>
		<li>특정 데이터 삭제시(ft_lstdelone) link가 유지되지 않는다.</li>
	</ul>
</details>
	
# [ft_printf](https://velog.io/@pawer/Printf)
<details>
<summary>printf함수 구현하기</summary>
	<ul>
		<li>서식문자 [cspdiuxX%] 구현</li>
		<li>flag [-0.*] 구현</li>
	</ul>
</details>
<details>
<summary>Bonus</summary>
	<ul>
		<li>서식문자 [nfge] 구현 => nf 구현, ge는 안함. </li>
		<li>flag [# +] 구현</li>
		<li>길이 [l ll h hh] 구현</li>
	</ul>
</details>

<details>
<summary>배운점</summary>
	<ul>
		<li>printf 구조 이해하기.</li>
		<li>가변인자 사용하기.</li>
		<li>컴퓨터에서 실수를 표현하는 방법(부동 소수점 표현방식)</li>
		<li>Bankers's Rounding</li>
	</ul>
</details>

# [get_next_line](https://velog.io/@pawer/getnextline)

<details>
<summary>개행단위로 파일을 읽기</summary>
	<ul>
		<li>read함수 이해하기. (buf에 fd의 내용을 BUFFER_SIZE만큼 읽는다.)</li>
		<li>static 키워드 이해하기.</li>
	</ul>
</details>

# [ft_server](https://velog.io/@pawer/FTSERVER)

<details>
<summary>wordpress를 동작시키는 컨테이너를 자동화하여 실행할 수 있도록 DockerFile 작성하기.</summary>
	<ul>
		<li>os => debian:buster</li>
		<li>web-server => nginx</li>
		<li>dbms => mariadb(mysql)</li>
		<li>CGI기능을 쓰기위한 프로그램 => php7.3-fpm</li>
		<li>php랑 mysql이랑 연동하는 프로그램 => php-mysql</li>
	</ul>
</details>

# [cub3d](https://velog.io/@pawer/Cub3d)

<details>
<summary>cub3d</summary>
	<ul>
		<li><a href="https://ko.wikipedia.org/wiki/OpenGL">OpenGL</a>을 활용하여, 3d그래픽 표현하기</li>
		<li><a href="https://lodev.org/cgtutor/raycasting.html">레이케스팅 구현</a></li>
	</ul>
</details>

# [libasm](https://velog.io/@pawer/libasm)
<details>
<summary>어셈블리 코드작성하기</summary>
	<ul>
		<li>64bit 어셈블리 코드를 intel문법 사용</li>
		<li>기본 함수 구현하기</li>
	</ul>
</details>

# [push_swap](https://velog.io/@pawer/pushswap)
<details>
<summary>stack 2개로 정렬하기</summary>
	<ul>
		<li>요구하는 stack명령어를 최소로 사용해야 함</li>
		<li>pa, pb => push기능 => ex) pa는 a스택 top의 데이터를 b스택 top으로 push 함 </li>
		<li>sa, sb => swap기능 => ex) sa는 a스택 최상위 데이터2개를 swap 함</li>
		<li>ra, rb => 위로 한칸씩 올리기 => ex) ra는 a스택 모든데이터의 위치를 한칸씩 위로 올림, 최상단 데이터는 최하단으로 감</li>
		<li>rra, rrb => 아래로 한칸씩 내리기 => ex) rra는 a스택 모든데이터의 위치를 한칸씩 아래로 내림, 최하단 데이터는 최상단으로 감</li>
	</ul>
</details>

# [pipex](https://www.notion.so/pipex-dec43b7e53664b1c8b0005452db22970)
<details>
<summary>unix pipe명령어 구현하기</summary>
	<ul>
		<li>파이프를 사용한 IPC(Inter-Process Communication)</li>
		<li>fork, wait, dup, pipe, execve함수 사용</li>
	</ul>
</details>

# [Philosophers](https://jolly-fuchsia-126.notion.site/philosophers-553143a709b642e3ac4c3148a919f8cf)
<details>
<summary>식사하는 철학자 문제 - 교착 상태 해결하기</summary>
	<details>
	<summary>thread와 mutex를 활용하여, 상호배제 구현하기</summary>
		<ul>
			<li>thread는 자원을 공유한다. 공유되는 자원 들(상태가 변경되거나, 참조되는)을 mutex를 통해 상호배제 한다</li>
			<li>종료를 알리는 공유자원의 flag가 변경될 때, 모든 쓰레드를 종료한다.</li>
			<li>모든 쓰레드가 종료되었는지 확인하기 위해 동기화기법 모니터를 사용한다. 이는 N개의 철학자의 상태를 N개의 모니터에서 관리한다.</li>
			<li>뮤텍스는 lock과 unlock함수를 통해 상호배제 한다.</li>
		</ul>
	</details>
	<details>
	<summary>process와 semaphore를 활용하여, 상호배제 구현하기</summary>
		<ul>
			<li>process는는자원을 복사한다. 따라서 finish쓰레드를 추가적으로 구현한다.</li>
			<li>종료를 monitor쓰레드에서 종료플레그를 알리는 세마포어가 +1이 되는 경우, 모든 프로세스를 강제로 kill해준다.</li>
			<li>세마포어는 wait를 통해 세마포어를 -1감소, post를 통해 +1 증가한다. (따라서 세마포어 생성시 초기 값을 정수로 함께 전달한다.)</li>
			<li> 세마포가 1이상의 값이 될때까지 기다린다.</li>
		</ul>
	</details>
</details>

# [Minishell]()
<details>
	<summary><a href="https://www.gnu.org/savannah-checkouts/gnu/bash/manual/bash.html">Bash</a> 만들기</summary>
	<details>
		<summary><a href="https://blog.naver.com/asianchairshot/221383363419">셸 & 콘솔 & 터미널</a></summary>
		<ul>
		  <li>셸은 명령어를 OS에 전달하고 결과를 전달받는 프로그램.</li>
		  <li>Shell은 운영체제 상에서, 다양한 운영체제 기능과 서비스를 사용하기 위한 인터페이스이다.</li>
		  <li>셸(껍데기)는 [ 사용자 <-> 운영 체제의 내부(커널) ] 사이의 인터페이스를 감싸는 층이기 때문에 이러한 이름이 붙었다.</li>
		</ul>
	</details>
	<details>
	<summary>구현 기능</summary>
		<ul>
		  <li>콘솔에 입력받기. (readline, add_history 함수 사용)</li>		
		  <li>입력 문자를 파싱 (1) => [|, &&, ||] 단위로 현재 line이 총 몇개의 명령어 실행을 의미하는지 ?</li>
		  <li>입력 문자를 파싱 (2) => special characters를 처리한다, [', ", $] quotation이 닫혀있는지, $의경우는 환경변수를 확인하여 변환해 준다. 환경변수는 main함수의 3번째 인자로 char *envp[]를 받아서 처리한다. </li>
		  <li>입력 문자를 파싱 (3) => [<, >, <<, >> ] redirection 및 heredoc 기호를 구분하여, 입 출력 파이프를 변경해주어야 할게 있는지 ?</li>
		  <li>입력 문자를 파싱 (4) =>입력 된 명령어의 프로그램이 존재하는지 ?, 환경변수 PATH를 활용하여 확인.</li>	
		  <li>리다이렉션 처리 및, 명령어 수행. fork -> dup2 -> execve </li>
		  <li>호출 실행결과의 종료 상태를 exit함수로 전달 함.</li>
		  <li>builtin함수 [echo, cd, pwd, env, export, unset, exit] 구현 </li>
		</ul>
	</details>
</details> 
