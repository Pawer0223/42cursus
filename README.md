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
		<li>[레이케스팅](https://lodev.org/cgtutor/raycasting.html)구현</li>
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

# [pipex](https://velog.io/@pawer/)
<details>
<summary>unix pipe명령어 구현하기</summary>
	<ul>
		<li>입, 출력 스트림의 이해</li>
		<li>프로세스 fork</li>
	</ul>
</details>
