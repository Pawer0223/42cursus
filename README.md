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
void	*calloc(size_t count, size_t size);
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
char	*strdup(const char *s1);
```
- 용도
  - 문자열 복사하기 위함
- 동작방식
  - 전달받은 s1을 복사 후, 복사 된 메모리의 주소를 반환한다.

#### 2-2) ft_memset
- 함수원형
```c
void	*memset(void *b, int c, size_t len);
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
void	*memcpy(void *restrict dst, const void *restrict src, size_t n);
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
void	*memccpy(void *restrict dst, const void *restrict src, int c, size_t n);
```
- 용도
  - 흠.. 언제 쓸 수 있을까..
- 동작방식
  - src에서 메모리 영역 dst로 n바이트를 넘기지 않고, 문자 c가 발견되면 복제를 멈추고 c의 다음주소를 return 한다.
    - ex) [ dst, "abcde", 'c' , 6 ] 

#### 2-5) ft_memmove
- 함수원형
```c
void	*memmove(void *dst, const void *src, size_t len);
```
- 용도
  - dst에 src를 복사하는데, 메모리 영역이 겹치지 않도록 한다 ! (dst 기준으로 !)
- 동작방식
  - 먼저 메모리상의 dst와 src의 주소를 비교한다. (포인터의 주소 값으로)
  - [ dst <= src ]의 경우, 즉 dst의 주소가 더 앞에있다면 그대로 len만큼 복사한다.
  - [ dst > len ]의 경우, 즉 dst의 주소가 더 뒤에있다면 src의 len크기의 문자열을 뒤에서부터 복사해준다.
    - ex) src = "abcde" ,len = 3일 때 dst => [][][c] -> [][b][c]  -> [a][b][c]
- 고민한 점
  - 최초 [ dst > len ]의 경우 abcde, 3의 경우 복사하면, cde가 복사되는걸로 이해했다..
     - 잘못 이해한 것이다. [ src + len - 1 ]의 주소부터 감소해나가기 때문에 복사의 시작은 c부터 b,a로 줄여나가서 의도한대로 복사가 잘 된다.

#### 2-6) ft_memchr
- 함수원형
```c
void	*memchr(const void *s, int c, size_t n);
```
- 용도
  - 문자열에서 특정문자 c가 존재할 때, 시작위치를 찾고 싶을 때!
- 동작방식
  - 문자열 s에서 c를 만나면, 해당 위치의 주소 값을 반환한다.
  - c가 없다면 null을 반환한다.

#### 2-7) ft_memcmp
- 함수원형
```c
int	memcmp(const void *s1, const void *s2, size_t n);
```
- 용도
  - 문자열 s1과 s2를 n범위에서 비교한다.
- 동작방식
  - s1 > s2 이면 양수반환
  - s2 > s1 이면 음수반환
  - s2 == s1 이면 0반환

#### 2-8) ft_strlen
- 함수원형
```c
size_t	strlen(const char *s);
```
- 용도
  - 문자열 s의 크기를 반환한다.
- 동작방식
  - null문자를 만날 때까지 cnt++한다.
    - ex) abc => 3, abcde => 5

#### 2-9) ft_strlcpy
- 함수원형
```c
size_t	strlcpy(char * restrict dst, const char * restrict src, size_t dstsize);
```
- 용도
  - 문자열에서 원하는 크기만큼만 dst에 복사한다.
  - 실제로는 size - 1 만큼만 복사하고, 마지막에는 null문자를 반드시 채워준다.
     - ex) src = "abcde", dstsize = 3 일때, dst에는 ab까지만 복사된다.
- 동작방식
  - dst에 src의 데이터를 dstsize - 1만큼 복사해준다.
  - return 값은, src의 length이다.
- 고민한 점
  - 입력 파라미터의 null처리를 고려해주지 못했다.
    - 먼저 src가 null이면 0 return;
    - dest가 null이거나, dstsize가 0이면 src_len을 바로 return;
    - 위의 두 조건에서 걸리지 않았다면, 문자열 복사 후 src_len을 return;

#### 2-10) ft_strlcat
- 함수원형
```c
size_t	strlcat(char * restrict dst, const char * restrict src, size_t dstsize);
```
- 용도
  - dst에 src를 붙여서 [dstsize - 1] 크기의 문자열을 만든다.
- 동작방식
  - 기존 dst의 값에 src를 0번째 index부터 차례대로 복사한다.
    - src이 null문자를 만나거나 
    - 문자열의 크기가 dstsize - 1이 될때까지
  - 반드시 dest의 마지막에는 null문자를 채워준다.
  - `최종 만들려는 문자열의 크기는 dstsize` 이다. 그러므로 [ strlen(dst) < dstsize ]의 경우 dst에 문자열을 붙일게 없다.
  - Return 값은 2가지로 분류할 수 있다.
     - 1. dest에 복사할 수 없는경우. 
       - return (src의 크기 + dstsize);
     - 2. dest에 복사할 수 있는경우.
       - return (dest_len + src_len);
- 고민한 점
   - dst나 src가 null일 때 ..
     - dst가 null인 경우 
     => 복사 할 주소를 모르니 segmentation fault가 뜬다.
     - src가 null인 경우
     => 역시 복사할 대상의 주소를 모르니 에러다. 이 경우 컴파일시 에러가 발생하고 있다.
     - 그런데 두 경우 모두 실제 lib함수에서 동일하게 에러가 발생한다. 찾아보니 char \*로 선언 되었기 때문에 null이 들어와서는 안된다. 라는 것 같다...

#### 2-11) ft_strchr
- 함수원형
```c
char	*strchr(const char *s, int c);
```
- 용도
  - 문자열 s에서 특정 문자 c가 존재하는 첫번째 위치의 주소를 알고싶을 때
- 동작방식
  - 문자열 s에서 char type의 문자 c를 만났을 때, 해당위치의 주소값을 반환한다.
  - 문자 c가없다면 null을 반환한다.
- 주의할 점
   - 문자 c가 널 문자('\0')인경우를 고려해야 한다.
      - 만약, "abcde "에서 " "를 찾는다고하면 마지막 알파벳 e뒤의 주소값이 반환되어야 한다.
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[]) {
 
 char *result = strchr("abc abc ", 0);
 char *result2= strchr("abc abc ", '\0');
 char *result3 = strchr("abc abc ", 0);
 char *result4 = strchr("abc abc ", '0');
 
 printf("result : [%s], addres : [%p] \n", result, result); // [] , 0x400630
 printf("result : [%s], addres : [%p] \n", result2, result2); // [] , 0x400630
 printf("result : [%s], addres : [%p] \n", result3, result3); // [] , 0x400630
 printf("result : [%s], addres : [%p] \n", result4, result4); // [null] , nil
}
        
```
#### 2-12) ft_strrchr
- 함수원형
```c
char	*strrchr(const char *s, int c);
```
- 용도
  - 문자열 s에서 특정문자 c가 처음 발견되는 위치를 뒤에서부터 찾고싶을 때
- 동작방식
  - 문자열 끝에서부터 char type의 c를 만나면, 해당 위치를 반환한다.
  - 못 찾았다면 null을 반환한다.
- 주의할 점
   - c가 '\0'의 경우를 체크한다.
   - strrchr는 문자열의 끝 '\0'부터 시작함으로, 해당 주소를 반환해주면 된다.
#### 2-13) ft_strnstr
- 함수원형
```c
char	*strnstr(const char *haystack, const char *needle, size_t len);
```
- 용도
  - 특정문자열에서 needle에 해당하는 문자열이 포함되어있는지 확인하고 싶을 때
- 동작방식
  - haystack에 needle이존재하면, 문자열이 시작하는 위치를 반환
    - ex) "abcde"에서 "bc"를 찾고자하면, b에해당하는 주소 값
  - needle이 null이라면, haystack을 반환한다.
- 고민한 점
   - needle의 null체크를 `if(!neddle[o])` 과 같이주었을 때, " ab"와 같이 앞의 공백이 null로 인식되지 않을까?
     - 저건 null이 아니다.. 치환문자로 ascii코드 32번에 해당한다..
#### 2-14) ft_strncmp
- 함수원형
```c
int	strncmp(const char *s1, const char *s2, size_t n);
```
- 용도
  - 두개의 문자열이 동일한지 n범위에서 비교한다.
- 동작방식
  - s1이크면 양수, 작으면 음수, 두 문자열이 같으면 0을 return 한다.
- 고민한 점
   - memcmp하고 차이가 뭐지..
     - 둘은 기능상 거의 동일하지만 `\0`이 포함된 문자열을 처리할 때 차이점을 보인다.
       - ex1) ["abc\0123" , "abc\0456" 4 ]
       => `abc\0`까지 비교하기 때문에 memcmp와 strncmp모두 0을 반환한다.
       - ex2) ["abc\0123" , "abc\0456" 5 ]
         => memcmp의 경우 `\0` 뒤의 1과 4를 비교하여 -3을 반환한다. (s2가 더 크다)
         => strncmp의 경우 `\0`를 만나면 종료되기 때문에 0을 반환한다.
   
#### 2-15) ft_atoi
- 함수원형
```c
int	atoi(const char *str);
```
- 용도
  - 전달받은 정수형 문자열을 int로 반환한다.
- 동작방식
  - 최초 `isspace`에 해당하는 문자는 건너뛴다. ( man isspace)
  - 다음에는 부호기호가 나올 수 있다.( '-' 또는 '+')
  - 다음에 연속해서 나오는 숫자(0~9)를 int로 변환한다.
    - `result = result * 10 + (str[i] - '0');` 하여 int값을 구한다.
    - ex) "123"은 아래과정을 거친다. (최초 result = 0)
      - result = (0 * 10) + ('1' - '0') => 1
      - result = (1 * 10) + ('2' - '0') => 12
      - result = (12 * 10) + ('3' - '0') => 123
- 주의할 점
   - 공식으로 int를 구해서 단순히 `-`를 곱하게 된다면, int범위 최소 값인 `-2147483648`변환시 max의 `2147483647` 의 범위를 넘어가면서 overflow가 발생한다.
   - 따라서 이러한 경우를 예방하고자 더 큰 범위를 보관할 수 있는 자료형(나는 long long)에 result를 구한 후 마지막에 음수를곱한다면, 위와같은 문제를 예방할 수 있다.
   
#### 2-16) ft_isalpha, ft_isdigit, ft_isalnum, ft_isascii, ft_isprint, ft_toupper, ft_tolower
- 문자열 c를 입력받아 의도하는 ascii코드의 범위에 존재하는지 확인한다.
- isprint는 출력가능한 아스키 문자표를 의미한다. [(ASCII 코드표 참조)](https://ko.wikipedia.org/wiki/ASCII)
### 3. <strings.h>
#### 3-1) ft_bzero
- 함수원형
```c
void	bzero(void *s, size_t n);
```
- 용도
  - 전달 된 메모리에 n크기만큼 0으로 채워준다.
 

## [ part2 ]
## [ Bonus ]

## 메모리 동적할당
- malloc함수로 필요한 만큼의 메모리를 할당 받을 수 있다.
  - malloc의 결과로 null을 return 하는 경우?
    - 요구하는 크기의 메모리를 할당할 수 없는경우 null을 return한다.
     - 이 경우 할당하지못한 메모리의 접근할 수 없고, 해서도 안된다.
     - malloc의 return이 null인 경우의 예외처리를 해주자.
## 포인터 주의점
- 포인터변수에 대해 null 체크 주의 할 것
- 다차원 포인터의 경우에는, 하위 포인터에 접근할 때에도 null체크 필요함.
- 구조체를 다룰 때, 구조체 내부에 동적할당 된 대상이 존재할 수도있다.
  - list구현하면서, free를 함수로 처리하는 이유 !
- 범위를 벗어나는 접근 주의 [참조](http://blog.naver.com/PostView.nhn?blogId=tipsware&logNo=221054714926)
  - `int arr[2] = {0, 1}` 과 같이 선언했어도 `arr[3]` 의 접근에 대한 에러가 발생하지는 않는다.
  - 이런 경우 의도하지않은 메모리공간에 침범하여 데이터가 overlap되는 등 문제가 발생하게 된다.
  - 지역 변수로 선언된 배열은 다른 지역 변수 또는 배열과 순차적으로 메모리에 나열된다. 때문에 자신의 영역을 벗어나면 다른 지역 변수들에게 영향을 미치게 된다.
```c
        #include <stdio.h>

        int main(int argc, const char *argv[]) {
         int arr[2] = {1, 2};
         int arr2[2] = {-1, -2};
         arr[2] = 4;
         for (int i = 0; i < 6; i++){
             printf("arr[%d]:%d\n",i,arr[i]);
         }
         // arr[0]:1
         // arr[1]:2
         // arr[2]:4
         // arr[3]:-2
         // arr[4]:-822601216
         // arr[5]: 297025583
        }
```
