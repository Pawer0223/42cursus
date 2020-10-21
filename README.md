# Subject

## [ part1 ] libc 함수 직접구현
- 함수는 원본과 동일한 프로토타입 및 기능을 수행해야 한다. (man page 참조)
- 직접 재 정의한 함수들은 실제 libc 함수와 성능적인 차이는 많이난다.
	- 함수의 용도와 동작방식을 이해하는것에 집중
## [ part2 ] 문자열 함수구현
## [ Bonus ] List구현
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
# 정리
## [ part1 ]


### 1. <stdlib.h>
#### 1-1) ft_calloc.c
 - 함수 원형
```c
void *calloc(size_t count, size_t size);
```
 - 용도
    - 메모리 공간을 할당 후 바로 초기화작업을 보장하고 싶을 때
 - 장점
  	- overflow 여부를 확인할 수 있다. [참조](https://stackoverflow.com/questions/1538420/difference-between-malloc-and-calloc)
      - malloc에서는 size_t를 넘어서는 메모리 할당이 발생하면 잘못된 크기가 할당될 수 있지만, calloc은 2개의 인자를 받아 처리함으로써 이런 경우에 null을 return할 수 있다.
        - 이 내용은 불확실 하다.. 하지만 인자가 2개이니까 저런 장점은 충분히 있을 수 있겠다
 - 단점
     - malloc에 비해 느리다.
       - 할당한 메모리에 0으로 초기화하는만큼 연산이 더 수행되니깐.
       - 보통 [ malloc + 초기화 ] 해서 더 많이 사용하는 것 같다.
 - 동작방식
    - [ size * count ] 공간 할당 후, 메모리 공간을 0으로 채워준다. 
 - 고민한 점
  	- 메모리 공간을 초기화할 때, void \*를 char \*로 변경해서 채워주고 다시 void \*를 반환했다면... 그 메모리 공간은 이후에 char \*로 밖에 못쓰는것 아닌가?
      - 아니다. 포인터의 변환 및 메모리 공간에 대한 이해가 부족했다.
          - void \* 타입에는, 사용될 메모리 공간의 크기만이 할당 되어있다.
            - 이 공간을 어떤 자료형으로 사용할 것인가?를 형 변환을 통해 지정해 준다.
            - 즉, `할당된 메모리 공간을 해석하는 방법`을 지정한다. [=> 포인터의 변환](https://dojang.io/mod/page/view.php?id=494)
              - ex) char \*로 지정하면 메모리 공간을 char 단위로 해석한다. (1byte씩)
              - ex) int \*로 지정하면 메모리 공간을 int 단위로 해석한다. (4byte씩)
         - 컴퓨터 시스템의 메모리 관리는 바이트 단위로 한다. [참조](https://blog.naver.com/tipsware/221233872040)
           - char는 1Byte크기로 해석되는 자료형이기 때문에 할당 된 모든 공간에 대해 1Byte단위로 초기화 한다는 의미이다.

### 2. <string.h>
#### 2-1) ft_strdup.c
- 함수원형
```c
     char *strdup(const char *s1);
```
- 용도
  - 문자열 복사하기 위함
- 동작방식
  - 전달받은 s1을 복사 후, 복사 된 메모리의 주소를 반환한다.

#### 2-2) ft_memset
- 함수원형
```c
     void *memset(void *b, int c, size_t len);
```
- 용도
  - 문자열에 특정 unsigned char값으로 초기화 하고자 할 때.
- 동작방식
  - 전달받은 void \*에 len크기byte만큼을 c값으로 채운다. (c는 unsigned char로 변환)
- 주의할 점
  - memset이 문자c를 채울 때는 char단위(1Byte)로 채운다.
  - 문자 c의 파라미터 타입은 int이지만 내부적으로 unsigned char로 변환해서 처리한다.
```c
  int main() {
    int lValue;
    memset(&lValue, 1, sizeof(lValue));
    printf("[%x]\n", lValue); // result [1010101]
  }
  ```
  - 위 코드의 수행 결과는 lValue가 가리키고있는 4byte의 주소에 char(1byte)단위로 1을 채우게된다.
    - 즉, 1byte공간에 c라는 정수를 저장한다.
    - 메모리에 채워진 값을 확인해보기위해 16진수로 출력해본다. [참조](https://blog.naver.com/tipsware/221233872040)
      - 1Byte공간에는 2개의 16진수를 표현할 수 있다. (16진수 1개는 2^4크기로 표현됨으로)
      - 그렇기 때문에 메모리에 저장 된 1Byte단위의 정수를 확인하기 위해서는 16진수로 출력 후 2bit(2글자)씩 구분해서 읽으면 된다.
      - 문제에서 set하려는 c의 값1을 16진수로 표현하면 [01]이다. 즉 1Byte공간에서 앞의 4bit는 0 뒤의 4bit는 1로 채워진다.
      - 우리가 할당한 4Byte의 메모리 공간에는 아래와같이 데이터가 채워지게 될 것이다.
          - 첫번째 1Byte : [ 0 ][ 0 ][ 0 ][ 0 ] [ 0 ][ 0 ][ 0 ][ 1 ]
          - 두번째 1Byte : [ 0 ][ 0 ][ 0 ][ 0 ] [ 0 ][ 0 ][ 0 ][ 1 ]
          - 세번째 1Byte : [ 0 ][ 0 ][ 0 ][ 0 ] [ 0 ][ 0 ][ 0 ][ 1 ]
          - 네번째 1Byte : [ 0 ][ 0 ][ 0 ][ 0 ] [ 0 ][ 0 ][ 0 ][ 1 ]
    - 위와 같이 lValue의 메모리 공간의 각 Byte에는 1이라는 값이 채워지고, lValue의 메모리에 memset 된 정수를 출력하면 [16843009]이 된다.
      - 추가적으로 CPU계열에 따라 바이트정렬 방식이 다른데 현재 사용되는 시스템에서는 `작은 자릿수부터 표현하는 Little Endian방식으로 표현`한다. 
      ex) 100(16) => 1(10) , 201 => 257(10) // 맨 앞이 16^0, 마지막이 16^n

#### 2-3) ft_memcpy
- 함수원형
```c
     void *memcpy(void *restrict dst, const void *restrict src, size_t n);
```
- 용도
  - dst에 src를 n만큼 복사하기 위함
- 동작방식
  - dst에 src를 n크기만큼 채운다.
  - dst를 복사하는 과정에서 dst와 src의 메모리 공간이 overlap될 수 있다.
    - src의 데이터가 덮어쓰기 될 수 있다.
    - overlap되지 않게끔 하려면 memmove를 사용한다.
  - src와 dst가 같은 주소를 가르킨다면 동작하지 않는다.
  - 복사 된 dst의 주소를 반환한다.

#### 2-4) ft_memccpy
- 함수원형
```c
    void *memccpy(void *restrict dst, const void *restrict src, int c, size_t n);
```
- 용도
  - dst에 src를 n만큼 복사하기 위함
- 동작방식
  - dst에 src를 n크기만큼 채운다.
  - dst를 복사하는 과정에서 dst와 src의 메모리 공간이 overlap될 수 있다.
    - src의 데이터가 덮어쓰기 될 수 있다.
    - overlap되지 않게끔 하려면 memmove를 사용한다.
  - src와 dst가 같은 주소를 가르킨다면 동작하지 않는다.
  - 복사 된 dst의 주소를 반환한다.

#### 2-5) ft_memmove

### <strings.h>
#### 3-1) ft_bzero
- 함수원형
```c
    void bzero(void *s, size_t n);
```
- 용도
  - 전달 된 메모리에 n크기만큼 0으로 채워준다.
 


#### ft_memchr
#### ft_memcmp
#### ft_strlen
#### ft_strlcpy
#### ft_strlcat
#### ft_strchr
#### ft_strrchr
#### ft_trnstr
#### ft_strncmp
#### ft_atoi
#### ft_isalpha
#### ft_isdigit
#### ft_isalnum
#### ft_isascii
#### ft_isprint
#### ft_toupper
#### ft_tolower
## [ part2 ]
## [ Bonus ]

## 메모리 동적할당
- malloc함수로 필요한 만큼의 메모리를 할당 받을 수 있다.
  - malloc의 결과로 null을 return 하는 경우?
    - 요구하는 크기의 메모리를 할당할 수 없는경우 null을 return한다.
     - 이 경우 할당하지못한 메모리의 접근할 수 없고, 해서도 안된다.
     - malloc의 return이 null인 경우의 예외처리를 해주자.

