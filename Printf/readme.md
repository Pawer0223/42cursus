# Subject

#### 문제 이해하기
 - 변환하는 서식문자는 `cspdiuxX%` 로 구현한다.
 - `It will manage any combination of the following flags: ’-0.*’ and minimum field width with all conversions` 이건 뭔소리지 ?
    - 포맷 형식에서 주어진 `-0.*` 4개의 문자로 번역해라.
    - `- , 0`은 flags를 의미한다. (밑에서 정리)
    - `*`은 정수를 입력받아서 처리하는 문자이다.
    - `.`은 정밀도를 나타내기위한 기호이다.  
#### Bonus
- 서식문자 `nfge`도 번역
- `길이`도 번역
- flags에서 `'#' ' ' '+'`도 번역

# Step1 : 가변인자 이해하기

### 참조

[참조 1](https://dojang.io/mod/page/view.php?id=577)
[참조 2](https://jhnyang.tistory.com/293)

### 가변인자란?
- C언어 함수 중, 매개변수의 개수가 정해지지 않은 함수가 존재할 수 있다. 
- 매번 함수에 들어가는 인수(argument)의 개수가 변하는 것을 가변 인자(가변 인수, variable  argument)라고 한다.
- 함수에서 가변 인자를 정의할 때는 고정 매개변수가 한 개 이상 있어야 하며, 고정 매개변수 뒤에 `...`을 붙여 매개변수의 개수가 정해지지 않았다는 표시를 해준다. (`...`뒤에는 다른 매개변수를 지정할 수 없다.)
   - 고정 매개변수가 필요한 이유는 시작 위치를 알아야하기 때문이다. (아래 va_start참조)
```c
      반환값 자료형 함수이름(자료형 고정매개변수, ...)
      {
         ...
      }
```

### va_list
- 가변 인수들을 저장할 수 있는 타입이다.
- `va_list`타입에 저장된 인수들에 접근하기 위해서는 `stdarg`에 정의된 매크로를 사용한다.

### va_start
``` c
void	va_start(va_list ap, last);
```
- 가변 인수에 순차적으로 접근할 수 있도록, 시작 주소를 설정한다.
- 인자로 `va_list`의 인수턴스와 `마지막 위치의 고정인수`를 전달한다.
  - 마지막 위치의 고정 인수란 아래와 같은 가변인수를 사용하는 함수가있을 때, `args2`에 해당한다.
- va_start 함수로 가변인수의 초기 주소값을 할당할 때, 아래와 같이 ap가 `...`의 첫번 째 위치를 가르키게 만든다. (고로, 마지막 위치의 고정인수를 넘겨줘야 시작위치를 구분할 수 있다.)
![](https://images.velog.io/images/pawer/post/3e5443dc-9518-49f5-b222-26a87a9a58ab/image.png)

#### va_start TEST

- va_start할 때, 가변인자가 없으면 null값이 초기화 되나??? => No 없어도 주소는 할당 됨.
``` c
      void va_test(const char *str, ...) {
          va_list ap;
          printf("input str is : [%s]\n", str);
          va_start(ap, str);
          printf("ap address : [%p]\n", ap);
      }
      
      int main(int argc, const char *argv[]) {
          va_test("TEST");
          va_test("TOAST", 1, 2);
      }
```

### va_arg
```c
type	va_arg(va_list ap, type);
```
- 가변 인자 메모리공간에서, 전달한 자료형의 크기만큼 값을 가져온다.
- 값을 가져온 후, 포인터의 주소를 자료형 크기만큼 뒤로 옮겨서 다음 값을 가져올 수 있도록 한다.

### va_end
```c
void	va_end(va_list ap);
```
- va_list의 포인터주소가 가르키는 값을 null로 초기화 한다.

### va_copy
```c
void	va_copy(va_list dest, va_list src);                                
```
- src에 저장된 가변 파라메터를 dest로 복사한다.

### 가변인자 사용예시
``` c
      void printfNumbers(int args, int args2, ...)
      {
          va_list ap;

          va_start(ap, args2);
          for (int i = 0; i ＜ args; i++){
              int num = va_arg(ap, int);
              printf("%d ", num);
          }
          va_end(ap);    
          printf("\n");
      }
```
  
# Step2 : printf 구조 이해하기

### 참조

[참조 1](https://linux.die.net/man/3/printf)
[참조 2](https://dojang.io/mod/page/view.php?id=736)
[참조 3](https://modoocode.com/35)
[참조 4](http://blog.naver.com/PostView.nhn?blogId=ruvendix&logNo=220891854070)

### printf 함수란?

- 표준 출력(stdout)에 일련의 데이터들을 `형식 문자열(format)`에 지정되어 있는 형태로 출력한다.
- 형식 문자열에는 `형식 태그(format tag)`라 불리는 것이 추가적으로 들어갈 수 있는데, 이에 대응하는 인자를 형식 태그가 지정한 형태로 치환되어 출력된다.
- 따라서 형식 문자열 다음으로 오는 인자의 개수는 반드시 형식 문자열 속 태그의 개수 이상이어야 한다.
- 형식 태그
```
%[플래그(flag)][폭(width)][.정밀도(precision)][길이(length)]서식 문자(specifier)

```
### 서식문자란 ?
- 서식 문자(specifier)란 대응하는 인자를 어떠한 형태로 표현할지 결정하는 역할을 한다.

| <center>서식 문자 | <center>설명 | <center>예시 |
| :-: | :- | :- |
| c | 문자 | 'a' |
| d, i | 부호 있는 10진 정수 |  |
| u | 부호 없는 10진 정수 |  |
| e | 지수 표기법으로 출력, e문자 사용 | 3.9265e + 2 |
| E | 지수 표기법으로 출력, E문자 사용 | 3.9265E + 2 |
| f | 십진법 부동 소수점 수 |  |
| g | %f와 %e중에서 짧은 것을 사용 (소문자) |  |
| G | %F와 %E중에서 짧은 것을 사용 (대문자) |  |
| o | 부호 없는 8진수 정수 |  |
| s | 문자열 |  |
| x | 부호 없는 16진 정수(소문자) | 1000(16) => 3e8 |
| X | 부호 없는 16진 정수(대문자) | 1000(16) => 3E8 |
| p | 포인터 주소 |  |
| n | 아무것도 출력하지 않는다. <br>but 부호 있는 int형 포인터를 함께전달해야 한다. <br>전달 된 포인터에 출력 된 문자열의 갯수가 저장된다. | int num 1;<br>printf("123%n6789\n", &num1); // 123456789<br>printf("num : %d\n", num1); // 3<br> printf("12345%n6789\n", &num1); // 123456789<br> printf("num : %d\n", num1); // 5<br> printf("1%n6789\n", &num1); // 16789 <br> printf("num : %d\n", num1); // 1|
| % | %를 출력한다 | printf("%%\n"); // % |
  
### 플래그(flag)
  - 출력 형식에 대해 추가적인 option(?)을 부여할 수 있다. 
  
| <center>기호 | <center>설명 |
| :-: | :- |
| - | 왼쪽 정렬하여 출력한다. |
| + | 양수(+), 음수(-)의 부호를 출력한다. |
| ' ' (space) | 양수는 '+' 부호를 붙이지않고 공백으(' ')로 표시, 음수는 '-'로 표시. |
| # | 진법에 맞게 숫자 앞에 표시한다. `0, 0x, 0X` |
| 0 | 출력 대상 `width`의 빈 공간을 0으로 채운다. |
### 폭(width)
  - 출력되는 데이터의 폭을 지정한다.
   - ex) 문자열 "abc"를 출력하기 위한 폭을 100으로 설정한다면, 100공간에 "abc"가 보여진다. (이 때 빈공간은 flag로 제어할 수 있다.)
  - width는 `정수 값`으로 입력받는다.
  - `*`로 입력된 경우는 반드시 인자로 정수를 함께 입력받아야하며, 입력값이 width로 설정된다.
```c
  int width = 10;
  printf("flag[*], width[%d] => [%*d]\n",width, width, 12345); // [     12345]
```
### 정밀도(precision)
  - 정밀도는 반드시 `앞에 마침표(.)`를 찍어야 한다. (폭과 구분하기위하여)
  - 출력 데이터의 정밀도를 지정한다. (쉽게 출력 할 자릿수를 지정한다.)
  - `.`마침표 뒤에 정수입력을 하지 않는 경우도 존재한다. (링크4 참조)
    - 이 경우 `0`을 출력한다고 했을 때, 정수`%.d` 와 실수`%.f`의 결과는 다르다.
      - 정수의 경우 아무것도 출력하지않는 반면, 실수는 [0]을 출력한다.
```c
    // 123
    printf("%10.3s\n","12345");
    // -00123
    printf("%10.5d\n", -123);
    // -123
    printf("% 10.1d\n", -123);
    // 123.1235
    printf("%10.4f\n", 123.123456789);
    
    int zeroI = 0;
    float zeroF = 0;
    // zeroI : [], zeroF : [0]
    printf("zeroI : [%.d], zeroF : [%.f]\n", zeroI, zeroF);
```
  
### 길이(length)
  - 출력할 데이터의 자료형 범위를 설정한다.
  - `%d` 서식문자의 경우 `정수형 데이터를 10진법으로 출력` 의 의미를 가진다. 여기에 길이를 지정해주면 출력할 데이터 자료형의 크기를 지정할 수 있다.

  
  | <center>길이 | <center>d, i | o, u, x, X | f F e g G a A | c | s | p |n
| :-: | :- | :-: | :-: | :-: | :-: | :-: | :-: |
  default | int | unsigned int | float, double | int | char * | void * | int *
  hh | signed char | unsigned char |  | |  |  | signed char *
  h | short int | unsigned short int |  | |  |  | short int *
l | long int | unsigned long int | double | wint_t | wchar_t * |  | long int *
ll | long long int | unsigned long long int | | | |  | long long int *
j | intmax_t | uintmax_t |  |  |  |  | intmax_t *
z | size_t | size_t |  |  |  |  | size_t *
t | ptrdiff_t | ptrdiff_t |  |  |  |  | ptrdiff_t *
L |  |  | long double | | | | 


# Step3 : 구현하기
  
### [FlowChart](https://viewer.diagrams.net/?highlight=0000ff&edit=_blank&layers=1&nav=1&title=Printf_FlowChart.drawio#R7V1rd5s4Gv41nLR7jn2QuImPxrl0d2em3dPutv20h8bU9tQxGdtpkv76kUASQhJGdgDj2B%2FagCwESO%2FleW%2FCcsZ3Tzer%2BH72ezpJFha0J0%2BWc2lBCG0f4j%2Bk5Zm2QBTkLdPVfJK3gaLh4%2FxXQhtt2vownyTrUsdNmi428%2Fty4226XCa3m1JbvFqlj%2BVu39NF%2Ba738TRRGj7exgu19fN8spnlrQgGRfu7ZD6dsTsDP8x%2FuYtZZ%2Fom61k8SR%2BFJufKcsarNN3kR3dP42RBZo%2FNy%2Bd%2FPn9e%2FPbDv%2FnXf9Z%2Fxf%2BN%2Fv3pj%2F8N8sGud7mEv8IqWW6aHZqu7s948UDni77r5plN4Cp9WE4SMohtOdFsc7fAhwAf%2FplsNs90weOHTYqb0tVmlk7TZbz4LU3vab%2Fv6XJDuwFyniwnI7Kw%2BPzbIr39kTddzxcLeg98RvsjfLberNIffO3IAHwhSOdF%2FC1ZRPHtj2n2oON0ka7wT8t0mZChJpgY6LsUD3dVtEaGc0vXYJ0%2BrG6TLf0cSuLxappsG8%2FP%2B5HnE%2BiUrtxNkt4lm9Uz7rBKFvFm%2FrNMzDHliSnvV6w7PqBLvwMZOCoZXEXWaGxFyLoaW%2BGVFdrZQWBFLu5oXV1aoUeOcSNyrfByC9mQJXuczTfJx%2Fs4m7tHLGrKpCSSCJ6FaLqI12u6wDXrv9v6%2FUxWm%2BRp64zTXx3g5ZdQwQdCKgYeCykCfNo2EySIa7e0SK6ySF%2BxYD2z60vY1TdkV6bNavmVqUna35h96Ugf0jl%2Br6JL%2Bv37Gj%2BYTDr8hvtTk6dQ0x%2BpQkz163Hc5LbEc%2FiFXpedfCXXDT12evnEb0rOntnZ03zzRTgWrsJnxUXkhF1zIMINdqNb0BrdFn2ogHX9knx1oCQ38ymgFzVP%2F75C%2FxcW9C4y5TYmCo2ovpEV2RbCy3etytlZevftYV2v20r0SKj9Or6bL8hbv0sWP5PN%2FDbWaMB4MZ8u8cktJpdkpSd0fMv5corP%2FOLsU8ZYWFe0qBlhWTNCpNGMrkYzorY0Y6Cs5eMKr8mrwyTAscs8Y2tmHnaJSdDJ2w9chwhq42tJa%2Bh1SMP6gAluUSG8%2B%2FxrefPhy837%2BMZ5%2F345C5JHNDAFMpTk7CEMmK3cOrZRdYQEwj2ZkPPXVZQEpo%2F4Weh2Tzqs21AjoREoP%2BOovuIoHd%2FoO8L%2BIilQYhLX6xZJsTcVeOD7Ip4W6IlCqisLIeJWQCMrdM%2FYSo%2BtJA3vAo2Gd7rEVozu5dUlizoiIBmvIvEVgdfoBJIBl%2Bt0CLi2qW8R6maP0h6PdUXqntchqWvnVjUJi7k9OVL3gkOTugqtCImPbOJ5xsuQUzah9WsLuW%2BGb18BD%2Fg6J3OnPKBR5ltI%2FRixamsWHUezHMF%2BZZC4BTS7TTvUGoGhIZbthxFoS0agoaewdiAfHNCa1HOfCrbAkMq1CsFXlnqZ5xLhm9u3swQzEvQXmA6ibyt8NCVH0Gw4PFaYDReF5OAkNWCgw96dakCgi8vm68DWOpIIQKv2ZCJ4g%2B9MaGRB%2F87on9nb%2FqtI5B5cRaqhs4pVwY0eiaITLvMJc%2BVh81BYJ0JP8vLUxd4z5kVs1Ufeq%2BdE5B%2BcE1Xb4ORg0eHhzVHBFid0h2W8EQTefsDFCcsDoUO6wfX8oYbgWGrQODuIiFiUVRZiwtHOVFZEZJkYdoXHYbWFugBotypJtZWvsORYvULNIGVl2V2GQLVzD88W8z6qofu46VaIXWsyA9NMmp4qH2A7e5rNsvYJw75pH6iisxNMjTxmLjwq5nJtlblk9bIvcwEgs%2BnBucthWtoA26EqCzVPGY%2ByDqq9Oyb2cZhhQXwh7l%2B4oPBV2HQOX4Zk2kOCVatXB0f8tuCIo%2FqMzhkpPc1IeZEP37SCpPt8FMct20duuKfdy7mkaqAK2diY5DMruTjzUl95KTQF9%2FBomMm390QaMjMpA7XNTKrb%2FMxMx8RM5qaydzTcFOyL22VuUgZqm5vMTN4zN%2FWWmwJTbjKNehyem5DsGdqXm5SBWuYmV%2BPDLWKv2Ch1SFIFsUVRljUh2boBtXVpTgUP8mZB29HYorFglmgROcw2viwHefMASN4%2Fj4pktjEeDbksYJLHjnFPd6i3pCW7nGcHVL5JQH7Kbxm6LMMjC8SQCfk%2FnvmsBb9JFsBGgEZtSBbImI6fPRA31nVPRibVj%2B%2BIYZ43FDklQtS8PmccWlHubBjRR%2BVx9CLKzlNVtCsxJoPkMfiRnzX20bXgg2CIyi4upEnJhJ49DKguEP0LQVv%2BBReqrKJoHVUFCDM2idczPruyatC7I4GhPAeHk%2BfMS1Yrz11TX6ewyp7Gg%2BS9UM5TOvM8OISyF0v2TpnK8cBFymC2HPXc2aFZdS%2Bn8sELAs9HbVZZ6GLdO2Zl9TSy7QfK%2Bh0%2BuO2qRaanCHX3EHGSpGWydTes3LCcdE1xr9tf3Os6qszcO7yKAlWO2XKKc9v4V19r0SSUVKGqASIuAWGO6sbkqYpsynHNg%2FFc6D7CPGCDsukT6kpAPFeVt61FkEJNfuuJCttyKN3eR9juBmQPJmx33N%2BoQ2GLgAZT7i1skUbYGkbcG8tWsdWM7V35ScsxGs4S%2BG5fkpTNte1M2DABA2gcwmGB7%2B631Nv4o6%2BXnz6s7799%2BgVvx%2B7Nrz%2F%2FYru1dbvG%2FVsr7dw0vvmhntlDuaAHdRs%2B5hOyg1tRh6AIKDJwIvKarfCS1Wxxb51YvOUJo%2BXlKQxHbfEsvtEVpXCExSAYdYCKyTvlDtRPKHfQ1B31AZxpfHCBpkq9cx8ct7%2FPEG1%2FiNY01Oovggo8BfQoObzmHj6nNBAytFT38O6V7%2BPauz2X24EnEITBGcmZogPHOH3AMfX8NI7kKvC6mn3a6Srv5q87llUOYa9WGWgSZ%2Bvq5BV4lVXz5kHODD8NNDHPSzLA6HL%2FAQz9ZurYumgxRmMhnlL79%2FiJjhxC6mGLpChv9uZhyLK7AcWNI5vixii0%2BM7g28HkP5jHjkdKoizIze5DAupIiKznLWT45QNeSQ0SFWFt2T2Y3wBGgA0zplPDe5PUcyE0o3mrXmJTGw3Dss7zmZIXsamPhr7TJTYN2wnXHJ013LwWq7Byg7KV63qAo73mDV2tPX%2FWjztTRa1%2BhCyhoGH62R2IuyXyGsAuYux8nmo2lcTaKf8IBSkzGmv21zhvM2no2HCBP9TpDw8OQaf6w1eLLsiXCVSHFNX1IxoTxHhgBMp%2BqLyabKx6l3qnfHoSLwKeKXyHxiWbL1RvwPblD7HAYcd%2BXL%2BdZOujgzTG1AF80xKAjow7TzXuZHVyMbgoLClqZ5WTTStl0AhmZgWTQYoAwt1esLPWq9M%2BocTRVaqHFSh1pHfUtL6TZPLmWbdCsHuST7pdw6WiCEOtbW%2FgM0j7WDMvzzh5tXQiZUhh%2BdE5nfianCi%2B2aY%2B9qqqj7MCYL9iXjfSAKBLDcDvdiA%2Fxo41bAfmfmQMBdvxg%2B3qxwCBvJe%2FB0SSqb8AW80SjbXh%2BPBV92nu6oeFTzwDqPPJk%2Bj3zuBruSgrAqxubJR5SQqHfB8d2ioecIBOKABfn23RxAZvWu%2FmYcTCgdnbNJWrHSelyowAohJxDDyWXNVw4oECN0BN5gEIXnoBf5eWJYvqUqUyhJRN5hFDlwYhvWhb7FMXtxww0CPFJrWFUbq4p3epj9ApVvd9PJkQ1CJU4doVIcttMlCJhmr3YUa8VJS9BY9JFoWn6vZVEXmLPDSL8DyANya5e2%2BrHz4b7yrbPmvkCN7tnot0R8J5WIfqRLqjqydrMULZzrY%2BRyfkWQaGQa5GV7YeJhlpaz3f79jUY7Oy3dSDNtld11aciBaMLtiPF9m%2FGp%2FivkZhWzwbQiAnC%2Fosx6%2Bc86qybIv7G6v2dyljhWLkkJX%2Feyw%2FOcvkEDNMRMHtGSTUsOXWazJIRgBEdynaY2BJKc9Em9alcYtf39BvkCDqHZ6vw%2FRmcYnwnQ5dRo6YJsOyznnBH7ctTOaTPjHM1HlG1aOQdcC6EGk0LYcKmSVDOl7TLSVybWuYbESZklcJMhATIjpskRJ0SZKcilJGMVAsIBCRRooEI5aRT5e6VHQoJkzxDUGUeeNZUdls9FJRyw4ZX7OPpcO2r%2B%2BkChECdHIaGRpvCgSNdwV6efjVV5LHO66X035cQEyj1JgNme59Q1yayRZYfQx%2BETlaBjw0DHTRMh4WF%2FnTUWMqzbEoVKMnpwikOTPWsy2EXQFpr%2Bxj8FC3PAvVgPthAmtHQxnu4QT6QNbirUt0fWHkvrn223LjDf1PvTPDfMUMYx7QugBZe5CMPVA%2FAmSw1xEyLuoPxvo7e759JOmMQCSZ%2Bv4DQHd%2BbdWPzSdWEB5rPMl4ikfcqCfOAeaT3ipXPOGrVMxZq1qsmFKqRn%2BZx5ui12tmseZWvM4RTfYsdAWrXYN5G3KM9xEEq55kVRg6unwxGfc0Jwydc%2B2nuSx0TWVh81UPL1R5aqygEDYUfiy%2FrcmfpmXDLnIpv%2Bu%2BskTcd6I%2BliVvfytHqbKiQmT3XaSgMJBCDQPd11v4J166gVianR1O0qQ23k4VOp2Z1K4cmxpAr9tCu8MkqB1baqqWeA6avWL73tCFyAtA%2Fr9fJiO3448HwIpPep1MjFPK7Bs4mq%2BIwqCwwJsOcmqJEZ6glNfYyIdNM5Mpg2eDNZ1m5kvfTpDrag2uYM%2FWrrnN1khBwDnKBfK2ZdvisEZgUbdNhSKZctg70GDirLtPAr68e9Y3F2Pis7L9IYqIslI%2BTPaOjVf9BLAABjIc0ewdy7Fq0%2Fh1G59KeiXyaPCdFMp5gpLIDxzmnhDj9Sxjgec9s3V7XOHZlnv12dAAtu0Ow7BS%2B3uaLeVa%2B2akdtUO4snoSvNs24GyVu%2BgjvQO7G6rym3zsaU8Nsk3cbyiUp5s21jKgn3Kf%2F9yfFjQkwMtgasJr%2BsYsjUoqNaAVOQaCR8fKpLGeLaTkApGXD4eA%2B1YAtEr3YorM%2B2du5nzK6u2hCLPlKc6XTG%2Fls98Vq6QJuWwe0Hhwzz9F91QCnEEniZ7uSENi09XaboRGRu%2F6Oz3dJKQHn8D)

### printf를 구성하기 위한 구조체 정의

```c
typedef struct s_printf
{
  va_list *ap;
  char	*length;
  char	flag;
  char	specifier;
  int	width;
  int	precision_len;
}		t_printf
```
- 정의 된 구조체는 전역변수로 사용한다. `t_printf	*g_info;`
  - 해당 전역변수는 `init_g` 메서드 호출시 동적할당 및 값이 초기화 된다.
- 문자열에서 `%`를 만났을 때 형식 태그를 전부 검사하여 출력한다.
- 검사가 마친 후에는 g_info의 값을 clear한 후, 다음 `%`가 있을 때 재사용 한다.

### 구조체 의미분석
- ap : 가변인자를 처리하기위한 va_list 포인터 변수.
  - 최초 함수가 호출될 때, 전역변수로 초기화한다.
- flag : flag를 기록한다.
  - [플래그(flag)]에 해당
  - flag가 존재하지 않는다면 0
- length : 길이를 기록한다.
  - [길이(length)]에 해당
  - length가 존재하지 않는다면 0
  - char * 타입 이므로, 동적할당 된 경우 반드시 free 해주어야 함
- width : 너비를 기록해 준다.
  - [폭(width)]에 해당
  - width가 존재하지 않는다면 -1(초기 값)
- precision_len : 정밀도의 길이를 기록한다.
  - [.정밀도(precision)]
  - 정밀도가 없으면 -1(초기 값)
  - 있으면 setting.
- specifier : 서식 문자를 기록한다.
  - 서식 문자(specifier)에 해당
  - 이건 초기값을 아직 안줬음.. 필요하면 추가..

### 사용되는 전역변수
| 자료형 | 변수 명 | 용도 |
|--|--|--|
| t_printf * | g_info | `%`를 만났을 때, 포맷형식을 검사하면서 구조체로 저장한다. 마지막에 g_info의 내용을 해석해서 포맷에 맞게끔 출력한다. |
| int | g_i | 포맷 검사를 위해, 입력 format 문자열을 공통적으로 다룬다. 이 때 인덱스 위치를 전역적으로 기록하기 위함.<br> ※ 주의 ※ <br>index가 전역적으로 사용 되는것은 위험하다. 따라서 index의 종료위치 및 증감연산에 대해 신중해야 한다.<br>ft_printf를 구현하면서, format이나 index가 계속 전달되어야 한다고 판단했다.<br>전역 변수를 최소화 하기 위하여 format은 인자로 전달 되도록 하고, index만 전역변수로 설정 함. |

  
### 함수 설명
| 함수 명 | 매개변수 | 반환 값 | 처리 내용 설명 |
|--|--|--|--|
| ft_printf | 1. const char *format<br>=> 입력 포맷<br>2. ...<br>=>가변인자 | int<br>=> write과정에서 error발생 시 0을 return | 1. 포맷과 가변인자를 입력받아 처리한다. <br>2. 최초 va_list의 시작 위치를 지정한 후, 주소값을 인자로 전역변수 초기화 함수 호출<br> 3. 입력 format을 대상으로 `%`를 만나는 경우 포맷검사 후 write, 아닌 경우는 단순 write 수행한다.|
| check_size | 1. const char *format<br> => 입력 포맷<br>2. int type<br> => 1의 경우 width를 set<br>=> 2의 경우 precision_len을 set| int<br>=> len구하기 위해 substr 과정에서 동적할당 실패시 0을 return 한다.| 입력 문자열에서 width 및 precision_len을 구하여 set 한다. |
| check_len | 1. const char *format<br>=>입력 포맷 | int<br>=> 동적할당 실패시 0 return; | 길이가 존재하는지 확인한다. 있다면 동적할당 후 저장한다. |
  
# Step4 : 컴퓨터에서 실수를 표현하는 방식

### 참조
- [wiki](https://ko.wikipedia.org/wiki/%EB%B6%80%EB%8F%99%EC%86%8C%EC%88%98%EC%A0%90)
- [blog 1](https://www.secmem.org/blog/2020/05/15/float/)
- [blog 2](https://gsmesie692.tistory.com/94)
- [blog 3](https://nybounce.wordpress.com/2016/06/24/ieee-754-floating-point%EB%B6%80%EB%8F%99%EC%86%8C%EC%88%98%EC%A0%90-%EC%82%B0%EC%88%A0%EC%97%90-%EB%8C%80%ED%95%98%EC%97%AC/)
- [263.3 -> 2진수 변환](https://www.youtube.com/watch?v=8afbTaA-gOQ)

### 실수의 특징
- 실수라는 수의 특징은 `.(점)`을 기준으로 `정수`와 `실수`를 구분한다.
- 컴퓨터의 한정된 메모리 공간에서 실수를 해석하기 위해서는, `정수`와 `실수`를 구분할 수 있어야 한다.
  
### 실수의 2진수 변환

- `정수`부는 10진수 변환과정과 동일하게 2로 나눈 나머지를 몫이 0이될 때까지 구한다.
- 그리고 가장 마지막의 나머지부터 차례대로 나열하면 된다.
- `실수`는 `실수부(소수점 아래)`가 0이될 때까지 계속해서 2를 곱한다.
- 0이될 때까지의 과정에서의 `정수부`(0 or 1)를 처음부터 차례대로 나열하면 된다.(정수는 마지막 부터 읽는다면, 실수는 처음부터 읽는다.)
  - ex) 12.125일 때
  - `정수부` => `1100`
  - `실수부` 
      => `0.125` x 2 => `0`.25
      => `0.25` x 2 => `0`.5
      => `0.5` x 2 => `1`.0
      => 따라서 실수부는 2진수로 `001`으로 표현.
  - 12.125 => `1100.001`
### 고정 소수점방식?
- `정수`와 `실수`를 표현하는 비트수를 정해놓고 해석한다.
- 만약 실수를 4byte공간에 저장할 때, `1bit = 부호`, `16bit = 정수`, `15bit는 실수`를 표현한다고 `가정`한다면
- 실수 `12.125`는 2진수로 `1100.001`이기 때문에 `실수`에 해당하는 2진수 `100`은 15비트 공간에 저장 된다. (뒷자리는 0으로 채움)
- 고정 소수점 방식은 편리하기는 하지만, 정해진 비트의 범위가 상대적으로 적기 때문에 표현 가능한 `정수`의 범위가 적고, 실수를 표현할 때 `정밀도`또한 떨어지게 된다.
  - 만약 실수가 나누어 떨어지지 않는 경우에 `실수`를 2진수로 표현할 때 자리수가 계속해서 늘어나게 된다.
    - ex) 0.34를 2진수로 표현한다면 아래와 같이 연산이 계속 진행된다.
  	=> `0.34` x 2 => `0`.68
  	=> `0.68` x 2 => `1`.36
 	=> `0.36` x 2 => `0`.72
  	=> `0.72` x 2 => `1`.44
  	=> `0.44` x 2 => `1`.88
  	=> ...
    - 위 경우, 고정 소수점방식에서는 `실수 부`를 `최대 15bit`로 표현하게 된다. 따라서 고정 소수점방식의 실수는 `정밀도`가 낮다. (부동소수점 방식에 비해)

### 부동 소수점방식?
- 부동(floating)은 "둥둥 떠다니는"이라는 의미를 가지고있다.
- 부동 소수점은 `고정소수점`과 반대로 소수점을 나타내는 "점"의 위치가 바뀐다는 특징을 가진다. (고정적이지 않다.)
- 즉, 소수점의 위치가 동적이다.
- 부동소수점 표현 방식은, 단정도(32bit)와 배정도(64bit)에 따라 실수를 표현하는 bit가 정해져 있고, 해석하는 방식이 정해져 있다.
- 단정도와 배정도에따라 bit만 다를뿐 해석되는 의미는 동일하다.
- 마지막 `1bit는 부호비트`이다.
- `가수부`를 나타내는 비트.
  - 쉽게, 실수를 2진수로 표현한 후 `가수부`에 저장한다.
  - 단정도는 `8bit` 배정도는 `11bit`로 표현한다.
- `지수부`를 나타내는 비트.
  - 쉽게, 가수부에서 `2^n`위치부터 실수임을 구분할 수 있다.
    - ex) 2^2라면 가수부의 `n + 1`비트부터는 `실수(소수점 이하)`를 나타낸다.
  - 가수부의 표현범위를 벗어난다면 bit수만큼 0으로 채워준다. (아래에서 추가설명 함)
- 실수를 부동 소수점방식으로 표현한다면, 실수의 `정밀도`를 높이고 정수의 표현 범위도 넓힐 수 있다.
- 부동 소수점 방식으로 표현하기 위해서는 `2진수로 변환된 실수`를 정해진비트에 저장하는 것이아니라, `정규화 과정`을 통해 실수 및 정수의 표현범위를 넓힐 수 있다.
- 쉽게 위에서 `12.125`의 2진수 `1100.001`을 `1.100001` * 2^`n`으로 나타내도록 하는것이다.
  - 정확하게 얘기하면 `정수부가 1만 남을때까지(중요)` 소수점을 이동시킨다. (왼쪽 or 오른쪽) 그리고 `이동한 칸 수만큼 n 자리`에 집어 넣으면 된다.
  -	즉, 예시에서 n은 3이 된다.
  - 따라서 1.`100001`에서 `2^3` 이동한 후부터의 bit는 `실수`를 표현함을 구분할 수 있다.
     - 여기서 bit를 이동하여 실수를 구분한다고 하였다
     - 즉, 소수를 표현하는 bit의 공간이 고정적이지 않고 `n`의 크기에 따라 계속 변한다.
     - 소수표현을 위한 메모리 공간이 계속 변하기 때문에 floating(둥둥 떠다니는)것 같다는 표현을 하여 `부동 소수점방식`이라 표현한다.
  - 여기서 정규화 과정을 거쳐 만들어진 `1.100001 * 2^n`과 같은 표기법을 `과학적 표기법`이라고 한다.
  - 여기서 지수를 의미하는 n은 8bit공간에, 음수와 양수 모두 존재할 수 있다. (0.00012 같은 경우에는 1.2 * 10^-4 가 된다.)
  - 따라서 `지수부`에 값을 저장할 때는, bias값이라는 걸 더해주는데 4byte에선 127이된다.
  - 따라서 지수는 `-127 ~ +128`의 값을 가질 수 있고, `0~126은 음수` `127은0` `128~255은 양수` 를 표현한다. (8byte에서 bias값은 1023) 
  - 또한 정규화를 거쳐 저장 된 데이터는 아래와 같이 해석된다. (중요 !)
    - `(+1)` x `2^(130 - 127)` x `(1 + 2^-1 + 2^-6)` 
  - 만약 실수를 4byte공간에 저장할 때, `1bit = 부호`, `8bit = n`, `23bit는 이진수`를 표현한다고 한다면?
    - `23bit`공간에 이진수를 표현할 수 있다.
       - 정규화를 거쳐 만들어진 2진수는 위에서 설명했듯이 정수부를 1만 남기고 이동시킨다. 이 때 정수부는 항상 1이기 때문에 반드시 `1.xxx ... `와 같은 형태이다.
      - 이 때 맨앞의 1은 생략하고 나머지를 23bit로 표현한다. 예시에서도 1.100001일 때 1을 제외한 `100001 ... ` 이 채워진다.
      - 생략한 `1`을 `숨겨진 비트(hidden bit)`라고 한다. 실수 표현의 시작 bit는 `1`이 생략되있음을 절대로 망각하지 말자.
    - `8bit`공간에는 실수 자료형이 표현된 비트를 구분할 수 있는 2^`n`의 값을 저장할 수 있다. 
      - 여기서 `의문점 1`, 그렇다면 n비트 이후 부터 실수다 !를 구분할 수 있다면 n이 가수부의 23bit를 넘어가면 어떻게 될까?
      - 가수부의 범위를 넘어가는 경우, 23bit를 모두 `정수`로 해석한다. 또한 초과되는 bit만큼 0을 채워넣음으로써, 큰 범위의 정수를 표현한다.
      - 예를들어, 이진수가 `1(hidden bit) 000 0000 0000 0000 0000 0001` 일 때 지수부의 n이 30이라고 한다면?
      - `1(hidden bit) 000 0000 0000 0000 0000 0001` `0000 00` 과 같이 6bit가 0으로 채워짐으로써, 가수부에서 나타내는 정수가 더 큰 값을 가지고 있다는 것을 의미하게 된다. 

# Step5. 실수를 bit단위로 해석하기.

- [리틀 엔디안 참조, bit order, byte order](https://jhnyang.tistory.com/172)
- [비트단위 연산](http://www.tcpschool.com/c/c_refer_bitCalculation)
- [코드 참조 + 댓글까지](http://hisjournal.net/blog/160)
  
### 부동소수점 디버깅해보기
- float타입의 10.0f는 어떻게 저장될까?
  - 32bit공간에 10.0을 표현한다.
  - 1bit는 부호비트, 8bit는 지수비트 , 나머지 23bit는 가수를 표현한다.
  - 예상한 값은 부호비트 = 0, 지수비트 = 0, 가수 = 10이 될것이라 예상했다.
  - 실제 메모리에 저장된 값 `0x00007FFFFFFEEA4C => [ 00 00 20 41 ]` 이다.
  - 이를 [리틀엔디언](https://ko.wikipedia.org/wiki/%EC%97%94%EB%94%94%EC%96%B8) 방식으로 해석하면 [ 41 20 00 00 ] 이다.
  - 2진수로 풀어쓰면 `[0100] [0001] [0010] [0000]` [0000][0000][0000][0000]이 된다. 
  - 부동소수점 표현방식에 맞게 해석하면 비트부호 = 0, 지수비트 = `10000010` , 가수비트는 `010 0000 0000 ... `이 된다.
      - 이를  - `(+1)` x `2^(130 - 127)` x `(1 + 2^-2)`로 해석할 수 있다.
      - 즉, `2^3` x `1 + 0.125` = 8 x 1.125 = `10.0`이 된다. 
  - 결론적으로, 저장된 bit를 해석하여 실수표현의 값을 유추할 수 있다.

### bit연산 방법

- 정리하면 Byte단위로 끊어서, 비트연산을 수행한다.
- 위에서 `10.0f`가 메모리에 `[00 00 20 41]`과 같이 저장되어있을 때 리틀 엔디안 방식에 따라 해석하기위해 마지막 byte인 `41`부터 해석한다.
- Byte단위로 해석하기 위해 float의 메모리 주소를 `char *`로 변환.
- float(4byte)에서 마지막 byte의 시작은 `시작주소 + 3byte이동`으로 찾을 수 있다.
- 해당 byte에 접근한 후, 1 (`0000 0001`) 과 비트연산 `&`를 수행한다.
- [41]은 `0100 0001`이므로 (이해가 안된다면 참조 비트단위 연산 보기) 가장앞의 `0`100 0001부터 1과 비교하기위해 `쉬프트 연산`을 수행한다. 
  - 즉, 처음에는 `(char *로 변환 된 시작주소 + 3) >> 7` 하면 `0100 0001`이 0000 000`0`이 되니깐 메모리의 0번째 bit를 맨 오른쪽으로 옮긴 후, 이 값이 1인지 0인지 알 수 있다.
```c
    float d = 10.0f;

    unsigned char* ptr;
    ptr = (unsigned char*)&d;

    unsigned char dif = 128;
    int j = 0;
    for (int i = sizeof(float) - 1; i >= 0; i--) {
        for (j = 7; j >= 0; j--)
  	{
           // 8765 4321 이렇게 있으면 8을 1로보내서 1하고 & 연산 함.
            printf("%d", (*(ptr + i) >> j) & 0x01);
  	}
        printf(" ");
    }
  ```
  
  
# 고민한 점
  
### flag가 0일 때, 정밀도가 존재한다면??

- 정수의 경우
```c
   	printf("%%010d :[%010d]\n", 12345); //[0000012345]
  	// ↓ warning: '0' flag ignored with precision and '%d' gnu_printf format occured 	
  	printf("%%010.1d :[%010.1d]\n", 12345); // [     12345]

```
  
### 16진수 음수 변환 ??
  
-	printf에서 음수의 16진수 변환은 제공하지 않는다.
-	man -3 printf => ` The unsigned int argument is converted to unsigned octal (o), unsigned decimal (u), or unsigned hexadecimal (x and X) notation. `
-	따라서 16진수로 표현되는 값은 `0~ffffffff`범위이다.
  	- 여기서 `ffffffff`은 unsigned int 의 max값이다. => `4294967295`
-	예시
	-	`printf("%x", 0)` => `0`
  	-	`printf("%x", -1)` => `ffffffff`
	-	`printf("%x", -2)` => `fffffffe`
	-	`printf("%x", -3)` => `fffffffd`
  	-	`printf("%x", UINT_MAX)` => `ffffffff`
  	-	따라서 -1은 unsigned int max와 같다.즉, 음수는 [ UINT_MAX + n + 1 ] (n < 0) 과 같다.

  
# 배운점
  
- printf의 buffer기능에 대해 공부하기.
- 자료구조, 컴퓨터구조, os, 네트워크 ,데이터베이스

