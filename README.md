# [Libft](https://github.com/Pawer0223/42cursus/tree/main/Libft)

## [ part1 ]
<details>
<summary>libc 함수 직접구현</summary>
<ul>
<li>함수는 원본과 동일한 프로토타입 및 기능을 수행해야 한다. (man page 참조)</li>
	<li>직접 재 정의한 함수들은 실제 libc 함수와 성능적인 차이는 많이난다.</li>
	<li>함수의 용도와 동작방식을 이해하는것에 집중</li>
</ul>
</details>

## [ part2 ] 문자열 함수구현
## [ Bonus ] 
<details>
<summary>List구현</summary>
- LinkedList와 유사하다. 동일하다고는 볼 수 없다.
  - 특정 데이터 삭제시(ft_lstdelone) link가 유지되지 않는다.
- List구현을 위한 구조체
```c
    typedef struct s_list 
    {
        void *content;
        struct s_list *next;
    }
```
</details>

# ft_printf
# get_next_line
# netwhat

