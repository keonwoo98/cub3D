# Line Drawing Algorithms

## DDA Algorithm
Digital Differential Analyzer

	시작 좌표 = (X0, Y0)
	종료 좌표 = (Xn, Yn)

### Step 01
$$\Delta X = Xn - X0 $$
$$\Delta Y = Yn - Y0 $$
$$M = \Delta Y / \Delta X$$

### Step 02

- dx와 dy의 절댓값 중 어느 값이 더 큰지 비교한다.
- 차이가 더 많이나는 쪽을 Steps로 결정.

$$ if (abs (\Delta X) > abs (\Delta Y)$$
$$ Steps = abs(\Delta X)$$
$$ else $$
$$ Steps = abs(\Delta Y) $$

### Step 03
3가지의 경우로 나눠서 생각한다.
   1. 기울기 > 1
      - Xk+1 = round(Xk + 1/m)
      - Yk+1 = round(Yk + 1)

   2. 기울기 = 1
      - Xk+1 = round(Xk + 1)
      - Yk+1 = round(Yk + 1)

   3. 기울기 < 1
      - Xk+1 = round(Xk + 1)
      - Yk+1 = round(Yk + m)

### Step 04
- 종료 좌표랑 같아질때 까지나, Steps의 수만큼 Step 03을 반복시킨다.

### 장점
- 간단한 알고리즘
- 구현하기 쉽다.
- 시간복잡도가 많이 드는 곱셈 연산을 피한다.

### 단점
- round() 함수의 오버헤드
- round() 함수가 시간복잡도를 증가 시킨다.
- round() 함수로 인해 선이 부드럽게 그려지지 않는다.
- 정확한 좌표로 그려지지는 않는다.
