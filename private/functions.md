# External Functions
> cub3D 허용 함수

## **open**
```C
#include <fcntl.h>

int
open(const char *path, int oflag, ...);
```
이미 존재하는 파일을 열거나 새로운 파일을 생성하는 `System call` 함수.

`path`의 파일 경로에 있는 파일이 reading / writing 용도로 열린다.

파일 디스크립터는 호출한 프로세스로 돌려준다.

`oflag`는 파일이 없을때 생성하는 옵션등을 지정해 줄 수 있다.

oflag는 아래 3개 중 하나를 **반드시** 설정해야 한다.
|oflag|description|
|:---|:---|
|`O_RDONLY`|open for reading only|
|`O_WRONLY`|open for writing only|
|`O_RDWR`|open for reading and writing|

아래 flag들은 or 연산으로 설정 가능
|oflag|description|
|:---|:---|
|O_NONBLOCK|do not block on open or for data to become available|
|O_APPEND|append on each write|
|O_CREAT|create file if it does not exist|
|O_TRUNC|truncate size to 0|
|O_EXCL|error if O_CREAT and the file exists|
|O_SHLOCK|atomically obtain a shared lock|
|O_EXLOCK|atomically obtain an exclusive lock|
|O_DIRECTORY|restrict open to a directory|
|O_NOFOLLOW|do not follow symlinks|
|O_SYNLINK|allow open of symlinks|
|O_EVTONLY|descriptor requested for even notifications only|
|O_CLOEXEC|mark as close-on-exec|
|O_NOFOLLOW_ANY|do not follow symlinks in the entire path|

`mode_t mode`
- 파일 생성 시 권한 설정
- or 연산으로 설정 가능
- `man 2 chmod`에 정의되어 있음

Return
- Success : 음수가 아닌 file descriptor
- Failure : -1 / errno set

## **close**
```C
#include <unistd.h>

int
close(int fildes);
```
file descriptor를 닫는다(제거한다).

프로세스 exit 시에, 모든 관련된 file descriptor들은 free된다.

그러나 프로세스당 사용 가능한 desciptor들의 수가 제한되어 있기 때문에,
close() 함수는 많은 양의 파일 디스크립터를 조작할 때 필요하다.

Process 에서 `fork()`를 진행할때, fork 하기 전에 연결된 파일 디스크립터들은 자식 프로세스에 그대로 복사된다.

새로운 자식 프로세스가 `execve()` 함수를 이용할때, 프로세스는 이 파일 디스크립터들을 그대로 상속한다.

파일 디스크립터들은 `execve()` 함수를 사용하기 전에 `dup2()` 나 `close()`를 통해 정리되어야 하고 `execve()` 가 실패할때 필요한 file descriptor들은 `execve()`가 성공적으로 실행됐을때는 closed 되어야 한다.

- Success : 0 return
- Failure : -1 return / errno is set


## **read**
```C
#include <unistd.h>

ssize_t
read(int fildes, void *buf, size_t nbyte);
```
`read()` 함수는 `nbyte` bytes만큼 `fildes`에 연결되어 있는 object의 데이터를 읽어온다.

obejct seeking 가능한 경우 : read() 함수는 fildes와 연관된 포인터에 의해 주어진 위치부터 시작한다.

read()가 끝난 후, pointer는 read를 수행한 number of bytes만큼 증가한다.

object seeking 불가능한 경우 : read() 함수는 항상 현재 위치에서 일어난다.

- Success : number of bytes read
- End-Of-File : 0 return
- Failure : -1 return / errno set

## **write**
```C
#include <unistd.h>

ssize_t
write(int fildes, const void *buf, size_t nbyte);
```
write() 함수는 fildes에 연결된 object에 nbyte 만큼 데이터를 쓴다.

object가 seeking 가능한 경우 : fildes 와 관련된 pointer에 의해 주어진 위치부터 write를 시작

write() 함수가 수행 된후 pointer는 number of bytes written 만큼 증가한다.

object가 seeking 불가능한 경우 : 항상 현재 위치에서 write()를 수행한다.

- Success : number of bytes written
- Failure : -1 return / errno is set

## **printf**
```C
#include <stdio.h>

int
printf(const char * restrict format, ...);
```
stdout에 데이터들을 형식 문자열(format)에 지정되어 있는 형태로 출력한다.

	%[flag][width][.precision][length]서식문자

**specifier**

대응하는 인자를 어떤 형태로 표현할 지 결정한다.
|서식 문자|출력 형태|예시|
|:--|:--|:--:|
|c|문자|a|
|d, i|부호 있는 십진수 정수|392|
|e|지수표기법으로 출력, e 문자 이용|3.9265e+2|
|E|지수표기법으로 출력, E 문자 이용|3.9265E+2|
|f|십진법으로 나타낸 부동소수점 수|392.65|
|g|%e나 %f보다 간략하게 출력|392.65|
|G|%E나 %f보다 간략하게 출력|392.65|
|o|부호있는 8진수|610|
|u|부호없는 10진수 정수|7235|
|x|부호없는 16진수 정수(소문자)|7fa|
|X|부호없는 16진수 정수(소문자)|7FA|
|p|포인터 주소|B800:0000|
|n|아무것도 출력하지 않는다. 인자로 부호있는 int형 포인터 전달, 현재까지 쓰여진 문자 수 저장||
|%|% 출력| |

**flag**

출력되는 형태에 대해 자세하게 지정할 수 있게 해준다.
|플래그|설명|
|---|---|
|+|출력 값이 양수더라도 + 기호를 앞에 붙여서 출력|
|(공백)|앞에 부호가 없다면 핰나을 띄어서 출력|
|#|o, x, X 서식문자와 사용되면 출력 값 앞에 0, 0x, 0X가 붙는다. e, E, f와 사용되면 소수점 아래 수가 없어도 소수점을 붙인다|
|0|왼쪽으로 정렬하되 빈칸 대신에 0을 삽입한다.|

**width**

출력되는 데이터의 폭을 지정해 준다.
|폭|설명|
|---|---|
|*|폭을 형식문자열 뒤에 오는 인자들에 넣어서 받는다. 정수값이다.|

**precision**

데이터 출력시 몇자리까지 출력해야 하는지를 지정한다. 
마침표(.)뒤에 숫자로 나타낸다.

|정밀도|설명|
|---|---|
|.*|형식 문자열에서 정밀도 생략, 뒤에 있는 인자로 값을 준다. 형식 태그가 적용되는 데이터 앞에 있어야 함.|

**length**

출력하는 데이터의 정확한 크기를 지정한다. (int 나 short 등)
|길이|설명|
|---|---|
|l|정수 서식 문자에 사용 될 경우 long 을 붙이는 것과 같은 효과, c 나 s에 사용되면 wide character, wide string으로 생각|
|L|인자를 long double로 생각 (e, E, f, g, G에만 적용)|

- Success : number of characters printed (\0 제외)
- Failure : negative value
## **malloc**
```C
#include <stdlib.h>

void *
malloc(size_t size);
```
size bytes 만큼 `메모리를 할당`시키고, 할당된 메모리의 주소를 가리키는 pointer를 리턴한다.

어떤 데이터 타입에도 사용 가능한다.

- Success : 할당된 메모리의 주소를 가리키는 `pointer`
- Failure : `NULL pointer` 리턴, errno set (ENOMEM)

ENOMOM : Cannot allocate memory

## **free**
```C
#include <stdlib.h>

void
free(void *ptr);
```
ptr이 가르키는 주소에 할당된 `메모리를 할당 해제` 시킨다.

ptr 이 NULL pointer일 경우, 아무 연산도 수행되지 않는다.

free() `does not return a value`

## **perror**
```C
#include <stdio.h>

void
perror(const char *s);
```
전역변수 errono 에 저장된 현재 값에 해당하는 error message를 개행과 함께 stderr file descriptor로 출력한다.

NON_NULL : message string 앞에 `s 문자열` + `": "`이 붙게 된다.

NULL : `message string`만 출력된다.

perror 는 오류가 발생한 다음에 바로 출력되어야 한다.

그렇지 않으면 다른 함수들의 호출에 의해 출력 결과가 바뀔 수 있다.

### **errono**
```C
#include <sys/errno.h>

extern int errno // errno external variable
```
거의 모든 `system call` 함수들이 error number를 제공한다.

system call 함수 실패 시 `정수 값(보통 -1)`을 리턴하고 errno를 셋팅한다.

system call 함수 성공 시 `errono를 셋팅하지 않는다`.

errno는 다른 error가 발생할 때 까지 남아있는다.

## **strerror**
```C
#include <string.h>

char *
strerror(int errnum);
```
`errnum` 에 해당하는 `error message string`의 pointer를 리턴한다.

error number를 찾을 수 없다면 `"Unknown errror: "`와 error number를 십진수로 포함한 string 을 리턴한다.

## **exit**
```C
#include <stdlib.h>

void
exit(int status);
```
`exit()` 함수는 프로세스를 종료한다.

종료하기 전에 `exit()`은 다음 과정을 거친다.
1. `atexit()` 함수에 등록된 함수들을 역순으로 실행한다.
2. 모든 열린 output stream들을 `Flush`
3. 모든 열린 stream들을 `Close`
4. `tmpfile()` 함수에 의해 열린 모든 file들을 Unlink

`wait()` 종류의 함수를 호출한 부모 프로세스에서 이용 가능한 8 bit의 status를 만든다.

C Standard (ISO C99) 정의
- EXIT_SUCCESS : 0
- EXIT_FAILURE : values of status

`exit()` functions `never return.`
