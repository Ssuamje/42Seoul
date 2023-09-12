## 평가 (125/125)
<img width="1055" alt="스크린샷 2023-05-16 오후 5 17 14" src="https://github.com/Ssuamje/42Seoul/assets/105692206/6928ec2a-ac11-41a9-a06c-1fd0eea3e25d">

![minitalk2](https://github.com/Ssuamje/42Seoul/assets/105692206/59c1b772-d4e9-4eb4-8c3a-fde0e1878792)

## 개요
minitalk은 서버와 클라이언트가 각각 시그널을 보내고 받으면서 통신을 구현하는 프로젝트입니다.

## 접근 및 해결
signal과 sigaction에 대해 알아보고, 그 방식에 대해 찾아보았습니다.
예제 코드들을 보면서 차근차근 작동하는지 여부를 확인하였습니다.
handler와 비트 연산, write를 통해서 클라이언트가 입력한 문자열을 서버가 출력할 수 있게끔 하였습니다.

## 내가 만든 테스터기
반복적으로 테스팅을 하면서, 일일히 문자열을 집어넣는 것이 너무 번거로워 아예 큰 볼륨으로 계속 테스트할 수 있게끔 스크립트를 작성하였습니다.

## 배운 점
시그널과 핸들링하는 방법에 대해 알게 되었습니다.

## 어려웠던 점
빠른 시간 내에 출력할 수 있게끔 하는 것과 중간에 멈추지 않도록 적당한 유휴기간(usleep)을 주는 방법이 어려웠습니다.