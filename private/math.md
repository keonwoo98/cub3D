# Math.h 함수
>	기초 수식 함수들을 구현하는 C 언어의 표준 라이브러리 안의 함수들의 모임
```C
#include <math.h>
```

```C
double sin(double x); // sin(x)
double cos(double x); // cos(x)
double tan(double x); // tan(x)

double asin(double x); // arcsin(x)
double acos(double x); // arccos(x)
double atan(double x); // arctan(x)
double atan2(double y, double x) // arctan(y/x)

double sinh(double x); // hyperbolic sine(x)
double cosh(double x); // hyperbolic cos(x)
double tanh(double x); // hyperbolic tan(x)

double exp(double x); // e의 x승
double frexp(double x, int *exp); // 지수를 exp가 가리키는 변수에 저장, 가수를 반환
double ldexp(double x, int exp); // x * 2^exp를 반환
double log(double x); // logeX
double log10(double x); // log10X
double modf(double x, double *intpart) // 정수부를 intpart가 가리키는 변수에 저장, 소수부를 반환

double pow(double x, double y); // x^y
double sqrt(double x); // 루트 x
double ceil(double x); // x보다 작지않은 가장 작은 정수
double floor(double x); // x보다 크지 않은 가장 큰 정수
double fabs(double x); // x의 절댓값
double fmod(double x, double y); // x를 y로 나눈 나머지
```

## 변수, 상수, 형식
```C
HUGE_VAL // 아주 큰 값을 나타낸다. 오버플로우가 나면 이 값을 반환
M_E // 자연상수 e
M_LOG2E // log2e
M_LOG10E  // log 10e
M_LN2 // loge2
M_LN10 // log e10
M_PI // PI
M_PI_2 // PI / 2
M_PI_4 // PI / 4
M_1_PI // 1 / PI
M_2_PI // 2 / PI
M_2_SQRTPI // 2 / (Root PI)
M_SQRT2 // Root(2)
M_1_SQRT2 // 1 / Root(2)
```
