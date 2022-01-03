# **cub3D**

> Contributor : keokim, minjkim2

### **Contents**
------------
> [Subject](#subject)

> [Functions](#Functions)

> [Commit-Rule](#commit-message-rule)

### **Subject**
---
* 본 프로젝트는 최초의 FPS(First Person Shooter)이자 3D 게임의 초석인 Wolfenstein의 게임에서 영감을 받았다.
* Ray-casting(광선 투사)에 대해 알아봐야 할 것이다.
* 목표는 미로 안에서 다이나믹 뷰를 만들어 길을 찾는 것이다.

> **레이 캐스팅**은 컴퓨터 그래픽스와 계산기하학의 다양한 문제를 해결하기 위해 광선과 표면의 교차검사를 사용하는 기법이다. 쉽게 말해 2차원 맵에서 3차원의 원근감을 만드는 렌더링 기술이다.  
> 레이 트레이싱은 빛이 해당 물체의 표면에 닿은 후, 현실처럼 빛이 다시 재귀적으로 반사되어 결과물을 렌더링 하는 방식이지만, 레이 캐스팅은 해당 물체에 닿으면 일회성으로 사용되고 더 이상 연산을 수행하지 않는다.

### **Functions**
---
* open, close, read, write, printf, malloc, free, perror, strerror, exit
* All functions of the math
	* library (-lm man man 3 math)
* All functions of the MinilibX
* libft

### **Commit Message Rule**
---
* `Type : 내용` 형식으로 작성할 것.
* Add : 파일, 폴더 추가
* Feat : 새로운 기능 추가
* Remove : 필요 없는 코드, 기능 제거
* Refactor : 변수, 함수 이름 수정, 코드 최적화
* Docs : 문서 파일 수정
* Fix : Norm, bug 수정
* etc : 기타 업무
