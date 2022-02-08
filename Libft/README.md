# Libft
>흔히 쓰이는 함수들을 재편성한 C 라이브러리 구현

## Part 1 - Libc functions

man에 정의되어 있는 대로 libc 함수들의 구성을 다시 구현합니다. 함수들은 원본과 같은 형식의 프로토타입을 선언하고 함수 이름 앞에는 `ft_`를 붙입니다. 함수의 프로토타입의 일부는 `restrict` 한정자를 사용합니다. 이 키워드는 c99 표준의 일부분입니다. 그러므로 이 키워드를 프로토타입에 포함시키는 것과 -std=c99 플리그를 사용하여 컴파일 하는 것은 금지됩니다.

|함수명|프로토타입|man 설명|
|:--|:--|:--|
|memset|`void *ft_memset(void *b, int c, size_t len)`|배열 b를 입력받아 len의 길이만큼 문자 c로 초기화하는 함수|
|bzero|`void ft_bzero(void *s, size_t n)`|문자열 s를 입력받아 문자열 s의 요소들을 n의 길이만큼 0으로 초기화하는 함수 <span style="color:red">*(n이 0이면 아무것도 하지 않음)*</span>|
|memcpy|`void *ft_memcpy(void *dst, const void *scr, size_t n)`|배열 src의 내용을 n길이만큼 배열 dst에 복사하는 함수 <span style="color:red">*(dst와 src가 겹치면 정의되지 않은 행동 발생; 그럴 시엔 memmove(3) 사용)*</span>|
|memccpy|`void *ft_memccpy(void *dst, const void *src, int c, size_t n)`|배열 src의 내용을 n의 길이만큼 배열 dst에 복사하되 문자 c를 만나게되면 복사를 중단하고 배열 dst에서 문자 c 다음 인덱스의 주소를 반환하는 함수 <span style="color:red">*(dst와 src가 겹치면 정의되지 않은 행동 발생)*</span>|
|memmove|`void *ft_memmove(void *dst, const void *src, size_t len)`|배열 src의 내용을 n의 길이만큼 배열 dst에 복사하되 `dst < src` 이면 순차적으로 복사, `dst > src` 이면 뒤에서부터 복사하는 함수 <span style="color:red">*(임시 배열을 사용하기 때문에 dst와 src가 겹쳐도 상관 없음)*</span>|
|memchr|`void *ft_memchr(const void *s, int c, size_t n)`|배열 s를 처음부터 n의 길이까지 검사하되 도중 요소 c를 발견하면 그 지점의 주소를 반환하는 함수 <span style="color:red">*(n바이트 내에서 없을 시 NULL 반환)*</span>|
|memcmp|`int ft_memcmp(const void *s1, const void *s2, size_t n)`|배열 s1과 s2를 n의 길이만큼 비교하되 같지 않은 부분이 나오면 그 인덱스의 `s1 - s2` 의 값을 반환하는 함수 <span style="color:red">*(n == 0 \|\| s1 == s2 일 시 0반환)*</span>|
|strlen|`size_t ft_strlen(const char *s)`|문자열의 길이를 반환하는 함수|
|strlcpy|`size_t ft_strlen(char *dst, char const *src, size_t dstsize)`|문자열 scr의 내용을 `dstsize - 1` 만큼(NULL 자리 확보) 문자열 dst에 복사 후 src의 길이를 반환하되 `dstsize == 0`이면 복사 진행하지 않고 src의 길이만 반환하는 함수 <span style="color:red">*(dst와 src가 겹치면 정의되지 않은 행동 발생)*</span>|
|strlcat|`size_t ft_strlcat(char *dst, const char *src, size_t dstsize)`|문자열 src의 내용을 `dstsize - 1` 만큼(NULL 자리 확보) dst 끝에 붙여넣되 `dstsize < dst의 길이` 일 경우 `dstzide + scr의 길이`를 반환하고(복사 x) `dstsize > dst의 길이` 일 경우 복사 후 `dst의 길이 + scr의 길이`를 반환하는 함수 <span style="color:red">*(dst와 src가 겹치면 정의되지 않은 행동 발생)*</span>|
|strchr|`char *ft_strchr(const char *s, int c)`|문자열 s의 첫 인덱스부터 검사하여 문자 c를 찾으면 그 주소를 반환하는 함수 <span style="color:red">*(문자 c가 존재하지 않을 경우 NULL반환)*</span>|
|strrchr|`char *ft_strrchr(const char *s, int c)`|문자열 s의 마지막 인덱스부터 검사하여 문자 c를 찾으면 그 주소를 반환하는 함수 <span style="color:red">*(문자 c가 존재하지 않을 경우 NULL반환)*</span>|
|strnstr|`char *ft_strnstr(const char *haystack, const char *needle, size_t len)`|문자열 haystack아 neelde을 포함한 경우(len만큼만 검사) haystack에서 needle을 찾은 주소(첫글자를 가리키는 포인터)를 반환하는 함수 <span style="color:red">*(존재하지 않을 경우 NULL반환; needle이 비어있는 경우 haystack반환)*</span>|
|strncmp|`int ft_strncmp(const char *s1, const char *s2, size_t n)`|문자열 s1과 s2를 n의 길이만큼 or 하나의 문자열이 끝날 때까지 비교하되 같지 않은 부분이 나오면 그 인덱스의 `s1 - s2` 의 값을 반환하는 함수 <span style="color:red">*(n == 0 \|\| s1 == s2 일 시 0반환)*</span>|
|atoi|`int ft_atoi(const char *str)`|문자열을 int형 정수로 반환하는 함수 <span style="color:red">*(선행 whitespace 무시; int형 범위를 벗어날 시 -1 또는 0반환)*</span>|
|isalpha|`int ft_isalpha(int c)`|인자가 알파벳일 경우 1을, 아닐 경우 0을 반환하는 함수|
|isdigit|`int ft_isdigit(int c)`|인자가 숫자(0~9)일 경우 1을, 아닐 경우 0을 반환하는 함수|
|isalnum|`int ft_isalnum(int c)`|인자가 알파벳 혹은 숫자(0~9)일 경우 1을, 아닐 경우 0을 반환하는 함수|
|isascii|`int ft_isascii(int c)`|인자가 아스키코드에 해당하는 문자일 경우 1을, 아닐 경울 0을 반환하는 함수|
|isprint|`int ft_isprint(int c)`|인자가 출력 가능한 아스키코드에 해당하는 문자일 경우 1을, 아닐 경울 0을 반환하는 함수|
|toupper|`int ft_toupper(int c)`|인자가 소문자라면 대문자로 변환 후 이를 반환하는 함수|
|tolower|`int ft_tolower(int c)`|인자가 대문자라면 소문자로 변환 후 이를 반환하는 함수|
|calloc|`void *ft_calloc(size_t count, size_t size)`|size크기의 변수를 count개 만큼 저장할 수 있는 메모리 공간을 할당 후 메모리를 0으로 초기화하는 함수 <span style="color:red">*(할당 실패 시 NULL반환)*</span>|
|strdup|`char *ft_strdup(const char *s1)`|포인터 s1이 가리키는 문자열을 복사하고(문자열 마지막에 NULL 추가) 복사된 문자열에 대한 포인터를 반환하는 함수 <span style="color:red">*(할당 실패 시 NULL반환)*</span>|

## Part 2 - Additional fuctions

libc에 포함되있지 않거나 다른 형식으로 포함된 함수들의 구성을 코드화해야 합니다. 이러한 함수 중 일부는 파트1의 함수들을 쓰는 데 유용할 수 있습니다.

|함수명|프로토타입|man 설명|
|:--|:--|:--|
|ft_substr|`char *ft_substr(char const *s, unsigned int start, size_t len)`|문자열 s의 start인덱스부터 len의 길이만큼 동적 할당한 메모리에 복사 후 그 주소를 반환하는 함수 <span style="color:red">*(할당 실패 시 NULL반환)*</span>|
|ft_strjoin|`char *ft_strjoin(char const *s1, char const *s2)`|동적 할당한 메모리에 문자열 s1과 s2를 이어서 복사한 후 그 주소를 반환하는 함수 <span style="color:red">*(할당 실패하거나 문자열 s1 또는 s2가 비어있을 경우 NULL반환)*</span>|
|ft_strtrim|`char *ft_strtrim(char const *s1, char const *set)`|문자열 s1의 앞과 뒤에서 문자열 set에 포함된 문자들이 있을 경우 제거한 후 이를 동적 할당한 메모리에 복사하여 그 주소를 반환하는 함수 <span style="color:red">*(할당 실패하거나 문자열 s1이 비어있을 경우 NULL반환)*</span>|
|ft_split|`char **ft_split(char const *s, char c)`|문자열 s를 문자 c를 기준으로 잘라서 각각을 동적 할당한 2차원 배열에 담아 그 주소를 반환하는 함수 <span style="color:red">*(할당 실패하거나 문자열 s가 비어있을 경우 NULL반환)*</span>|
|ft_itoa|`char *ft_itoa(int n)`|int형 숫자를 char *형의 문자열로 변환하여 동적 할당한 메모리에 저장 후 그 주소를 반환하는 함수|
|ft_strmapi|`char *ft_strmapi(char const *s, char (*f)(unsigned int, char))`|문자열 s의 모든 요소를 동적 할당한 배열에 각각 함수 f를 적용시킨 값을 저장 후 그 주소를 반환하는 함수 <span style="color:red">*(할당 실패하거나 문자열 s 또는 함수 f가 비어있을 경우 NULL반환)*</span>|
|ft_putchar_fd|`void ft_putchar_fd(char c, int fd)`|문자 c를 fd 파일 디스크립터를 적용하여 출력하는 함수 <span style="color:red">*(`fd < 0` 일 경우 return ;)*</span>|
|ft_putstr_fd|`void ft_putchar_fd(char *s, int fd)`|문자열 s를 fd 파일 디스크립터를 적용하여 출력하는 함수 <span style="color:red">*(문자열 s가 비어있거나 `fd < 0` 일 경우 return ;)*</span>|
|ft_putendl_fd|`void ft_putendl_fd(char *s, int fd)`|끝에 개행이 추가된 문자열 s를 fd 파일 디스크립터를 적용하여 출력하는 함수 <span style="color:red">*(문자열 s가 비어있거나 `fd < 0` 일 경우 return ;)*</span>|
|ft_putnbr_fd|`void ft_putnbr_fd(int n, int fd)`|int형 숫자 n을 char형으로 변환하여 fd 파일 디스크립터를 적용하여 출력하는 함수 <span style="color:red">*(`fd < 0` 일 경우 return ;)*</span>|

## Part 3 - List fuctions

메모리와 문자열을 조작하는 함수를 사용하는 것도 유용하지만, 곧 리스트를 조작하는 함수를 사용하는 것이 훨씬 더 유용합니다.  
리스트의 요소들은 다음의 구조를 갖습니다.
```c
typedef struct      s_list
{
    void            *content;
    struct s_list   *next;
}                   t_list;
```

|함수명|프로토타입|man 설명|
|:--|:--|:--|
|ft_lstnew|`t_list *ft_lstnew(void *content)`|구조체를 동적 할당으로 생성 후 구조체 안에 배열 content를 담고 그 주소를 반환하는 함수 <span style="color:red">*(할당 실패 시 NULL반환)*</span>|
|ft_lstadd_front|`void ft_lstadd_front(t_list **lst, t_lst *new)`|인자로 받은 연결리스트 lst 맨 앞에 인자로 받은 구조체 new를 끼워넣는 함수 <span style="color:red">*(lst 혹은 new가 비어있을 경우 return ;)*</span>|
|ft_lstsize|`int ft_lstsize(t_list *lst)`|인자로 받은 구조체 lst 이후에 연결된 구조체가 몇개인지 세어보는 함수|
|ft_lstlast|`t_list *ft_lstlast(t_list *lst)`|인자로 받은 구조체 lst에 연결된 구조체들 중 맨 마지막 구조체의 주소를 반환하는 함수 <span style="color:red">*(lst가 비어있을 경우 NULL반환)*</span>|
|ft_lstadd_back|`void ft_lstadd_back(t_list **lst, t_lst *new)`|인자로 받은 연결리스트 lst 맨 뒤에 인자로 받은 구조체 new를 끼워넣는 함수 <span style="color:red">*(lst 혹은 new가 비어있을 경우 return ;)*</span>|
|ft_lstdelone|`void ft_lstdelone(t_list *lst, void (*del)(void *))`|인자로 받은 구조체 lst의 요소 content를 del함수로 삭제한 후 lst의 메모리를 해제하는 함수 <span style="color:red">*(구조체 lst 혹은 함수 del이 비어있을 경우 return ;)*</span>|
|ft_lstclear|`void ft_lstclear(t_list **lst, void (*del)(void *))`|인자로 받은 구조체 lst와 연결된 모든 구조체들의 content를 del함수고 삭제한 후 구조체의 메모리를 해제시켜주는 함수 <span style="color:red">*(구조체 lst 혹은 함수 del이 비어있을 경우 return ;)*</span>|
|ft_lstmap|`t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))`|인자로 받은 구조체 lst와 연결된 모든 구조체들의 content에 f함수를 적용한 리스트를 복사하여 그 리스트의 첫번째 구조체의 주소를 반환하되 각 구조체의 content에 f함수를 적용하는 도중 실패한다면 앞서 f함수가 적용된 모든 구조체의 메모리를 해제한 후 NULL을 반환하는 함수 <span style="color:red">*(구조체 lst 혹은 함수 f가 비어있을 경우 NULL반환)*</span>|
