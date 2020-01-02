# Server_PacMan_Simulator




## 프로젝트 네이밍규약


변수:


	-소문자 시작.

	-복수형 / 단수형 구분.	

	

함수:


	-대문자 시작.

	-동사로 시작.

	-bool타입은 Is로 시작하면서 긍정적인 이름으로한다. ( IsNotDo() 이런식으로 하지 않기 )
	
	-{} 괄호는 내려쓰기.
	




private:


	-네임앞에 "_" 붙이기 ex) int _sum = 0;   int _SumInt(int a, int b);





## 콘솔창 두개를 이용하여 제작하기

	-ConsoleLoggerHelper 라이브러리사용하기

### 1콘솔(기존콘솔) = 게임이 돌아감(자동)

	-매개변수입력으로 맵 자동생성 후 실행

	-길찾기 알고리즘을 이용해서 캐릭터와 AI의 움직임을 보여준다

### 2콘솔 = 게임 결과값이 출력됨

	-출력된 결과는 XML파일로 파싱해서 저장(승률을 보기위해)


