# 42Seoul-cppModule00
## ex00
### 목표
- 아래와 같이 동작하는 megaphone 프로그램을 만들어보자!
- c++의 기능을 사용해서 만들어보자!
```cpp
$>./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
$>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
$>./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
$>
```

### 배운 것
#### std::cout, std::cin
- std::cout, std::cin은 각각 iostream 헤더 파일에 있는 ostream, istream 클래스의 객체이다.
- 입출력 스트림을 추상화한 객체이며, std::cout은 표준 출력, std::cin은 표준 입력에 대한 스트림 객체이다.
! 표준 에러에 대한 스트림 객체는 std::cerr, std::clog 이다.
! std::cerr는 버퍼를 사용하지 않고 바로바로 출력하며, std::clog는 버퍼를 사용하여 출력한다.

#### <<, >> 연산자
- 입출력 스트림에 데이터를 입력하거나 출력할 때 사용한다.
- << : 출력 연산자로서, 왼쪽 피연산자에 출력할 데이터를 전달한다.
- \>\> : 입력 연산자로서, 오른쪽 피연산자에 입력 데이터를 전달한다.

#### std::toupper
- 인자로 받은 문자가 소문자인 경우 대문자로 바꿔서 반환해주는 c++ 표준 함수이다.

#### std::endl과 개행 문자('\n')의 차이
- std::endl은 개행 문자를 출력하고 버퍼를 비우는 동작까지 수행한다.
- std::endl이 그냥 개행 문자를 사용하는 것보다 느리다.
- 개행 문자를 사용하는 것이 속도면에서 유리하다.
- std::endl은 마지막에 사용해주는 것이 좋다.

---

## ex01
### 목표
- 전화번호부를 만들어보자!
- PhoneBook 클래스와 Contact 클래스를 만들어서 사용해야한다.
  - PhoneBook
    - Contact의 배열을 가지고 있다.
    - Contact를 8개 까지 보관할 수 있으며, 9번 째가 들어온 경우 가장 오래된 곳에 덮어씌운다.
    - 동적 메모리 할당은 금지된다.
  - Contact
    - 연락처 정보를 가지고 있다.
    - first name, last name, nickname, phone number, darkest secret을 가진다.
- 프로그램이 시작되면, 입력 창을 띄워서 사용자로부터 아래 입력을 받는다.
  - ADD : 새로운 Contact 저장
    - Contact 등록에 필요한 정보들을 하나씩 입력 받는다.
    - 전부 입력이 완료되면 Contact를 등록한다.
  - SEARCH : 특정 Contact의 정보 출력
    - index, first name, last name, nick name 4개의 열로 구성하여 현재 저장되어 있는 Contact 들의 정보를 출력한다.
    - 출력은 오른쪽 정렬이 되어야하며, 10글자가 초과된 경우 마지막 글자를 '.'으로 만든 뒤 그 뒤의 문자는 삭제한다.
    - 그다음, 유저로부터 index를 입력 받는다.
    - index를 입력 받으면, 해당 index에 해당하는 Contact 정보를 출력한다.
  - EXIT
    - 프로그램이 종료되며 전화번호부를 전부 지운다.
  - 그외 모든 입력 값은 무시되어야한다.
- 프로그램이 실행되면, EXIT을 입력 받을 때까지 사용자로부터 입력을 받아야한다.

### 배운 것
#### class
- class는 특정 객체에 대한 설계도이다.
- 객체가 어떤 멤버 함수, 멤버 변수를 가지고 있는지 등을 설계한다.
- 보통 헤더 파일에는 class의 멤버 함수, 멤버 변수를 선언만하고 정의는 .cpp 소스 파일에서 한다.
- 멤버 함수를 가질 수 있는 구조체라고 볼 수 있다.

#### 인스턴스(Instance)
- class의 설계에 맞게 만들어진(메모리에 생성된) 것을 말한다.

#### 객체(Object)
- class와 인스턴스를 포함해서 지칭하는 용어이다.

#### 접근 지정자(Access Modifiers)
- 멤버 함수나 멤버 변수에 접근할 수 있는 범위를 설정 한다.
  - public : 클래스 외부에서도 접근할 수 있도록 한다.
  - private : 클래스 내부에서만 접근할 수 있도록 한다.
  - protected : 클래스 내부와, 자식 클래스(상속받은 클래스)에서 접근할 수 있도록 한다.

#### class와 구조체의 차이점
- 기본 접근 지정자의 차이가 있다.
  - class : 기본적으로 private. (정보 은닉 우선)
  - 구조체 : 기본적으로 public. (데이터 구조 표현 우선)

#### Getter, Setter
- 멤버 변수의 값을 설정하거나, 가져오기 위해 사용하는 멤버 함수이다.
- 직접 멤버 변수를 접근하지 않고, 멤버 함수를 통해 접근하기 위해 사용한다.
- 멤버 변수를 private으로 설정하고, Getter, Setter를 public으로 설정하여 멤버 변수의 정보 은닉이 가능하다.
- Setter를 사용하여 멤버 변수를 변경할 때, Setter 내에서 유효성 검사가 가능하다.

#### 멤버 함수의 const
- 멤버 함수 이름 마지막에 const 키워드를 붙이면, 해당 멤버 함수에서는 멤버 변수의 값을 수정할 수 없도록 한다.
  ex) ```void MemberFunc() const```

#### std::string
- cpp에서 문자열을 쉽게 다루기 위해 사용되는 표준 클래스이다.
- 문자열 데이터를 관리하는데 유용한 멤버 함수들과 연산자 오버로딩을 제공 한다.

#### std::getline()
- 한 줄을 읽어서 저장하는 표준 함수이다.
- 입력 스트림의 버퍼에 개행 문자가 올 때까지 읽는다. (white space 포함)
- 개행 문자가 나오면, 개행 문자 이전까지를 저장하며, 개행 문자부터는 입력 버퍼에서 삭제한다.
  - Ex) "Hello world!" 입력 -> "Hello world!" 까지 저장 -> 입력 버퍼에 남은 "\n"은 삭제. 

#### std::cin에 남아있는 EOF 제거
- std::cin은 내부적으로 stdin을 사용하며, std::cin 및 stdin은 각각의 상태 값을 독립적으로 가지고 있다.
- std::cin은 아래와 같은 네 가지의 상태 값을 가지고 있으며, bit로 상태를 나타낸다.
    - goodbit : 오류 없음.
    - badbit : 복구 불가능한 스트림 오류 발생.
    - failbit : 입력 / 출력 실패.
    - eofbit : EOF를 만남.
- std::cin에서 EOF를 입력 받은 경우, eofbit가 설정되어 계속 유지되기 때문에, 이후에 std::cin을 사용할 때마다 EOF를 만난 것으로 판단하고 입력을 종료하게 된다.
- 즉, std::cin의 상태 값을 다시 초기화 해주어야 다음 std::cin에서 입력을 정상적으로 받을 수 있다.
- 또한, stdin의 상태 값도 초기화 해주어야 표준 입력 스트림을 다시 사용할 수 있다.

```cpp
if (std::cin.eof())
{
	std::clearerr(stdin);
	std::cin.clear();
	std::cout << std::endl;
}
```
- std::cin.eof() : 현재 cin(표준 입력) 스트림이 eof를 만났는지 확인.
- std::clearerr(stdin) : 표준 입력 스트림(stdin)에 대해 상태 값 초기화.
- std::cin.clear() : std::cin의 상태 값 초기화.

#### std::stringstream
- 문자열 입출력을 위한 스트림 형식의 클래스이다.
- 문자열을 스트림 형식으로 처리할 수 있다.
- stringstream으로 문자열을 넣고, stringstream을 정수 자료형에 입력하면 정수형으로 변환할 수도 있다.
- stoi처럼 사용할 수 있다.
```cpp
std::string str;
std::stringstream ss;
int i;

str = "42";
ss << str; // stringstream에 문자열 "42" 입력.
ss >> i; // i에 숫자 42 저장.
```

---

## ex02
### 목표
- 제공해준 파일들을 확인하여, 사라진 Account.cpp 소스 파일을 직접 복구하자.
- 제공 파일 목록
  - Account 클래스의 구조가 포함된 Account.h 파일.
  - Account 클래스를 사용하여 테스트했던 main.cpp 파일.
  - 테스트의 출력 내용이 담긴 log 파일.
  
### 배운 것
#### 생성자
- 인스턴스가 생성되면 자동으로 호출되는 멤버 함수이다.
- 클래스 이름과 동일한 함수명을 사용한다.
```cpp
class test
{
public:
    test() {} // 생성자
};
```

#### 소멸자
- 인스턴스가 메모리에서 없어질 때 자동으로 호출되는 멤버 함수이다.
- 클래스 이름 앞에 '~'를 붙인 함수명을 사용한다.
```cpp
class test
{
public:
    ~test() {} // 소멸자
};
```

#### static 멤버 함수
- 멤버 함수에 static 키워드를 붙이면, 인스턴스에 바인딩된 함수가 아니라 클래스에 속하는 함수가 된다.
- 클래스의 인스턴스를 생성하지 않고도 해당 멤버 함수를 호출할 수 있다.
- 클래스의 모든 인스턴스가 공유 한다.
```cpp
class MyClass
{
public:
    static void StaticFunction(int value)
    {
        std::cout << "hello world!" << std::endl;
    }
};

MyClass::StaticFunction();
```

#### static 멤버 변수
- 멤버 변수에 static 키워드를 붙이면, 클래스의 모든 인스턴스 간 공유되는 변수가 된다.
- 모든 클래스 인스턴스가 동일한 static 멤버 변수를 사용 한다.
- data 메모리 영역에 저장 된다.
- 클래스 외부에서 초기화를 해줘야 비로소 메모리에 할당된다.
- static 멤버 변수의 접근 지정자가 private인 경우, 해당 멤버 변수는 static 멤버 함수만 접근이 가능하다.
```cpp
class MyClass
{
public:
    static void setStaticVariable(int value)
    {
        _myStaticVariable = value;
    }

    static int getStaticVariable()
    {
        return _myStaticVariable;
    }

    void someFunction()
    {
        // myStaticVariable에 접근할 수 없음
        // setStaticVariable() 또는 getStaticVariable() 호출을 통해 접근해야 함
        setStaticVariable(10); // 정적 멤버 함수 호출을 통해 myStaticVariable에 값을 설정
        int value = getStaticVariable(); // 정적 멤버 함수 호출을 통해 myStaticVariable의 값을 가져옴
    }

private:
    static int _myStaticVariable;
};

int MyClass::_myStaticVariable = 0; // 초기화
```


#### timestamp 출력
```cpp
#include <ctime>

int main()
{
  std::time_t currentTime = std::time(NULL);
  std::tm* timeInfo = std::localtime(&currentTime);
  char timeString[18];

  std::strftime(timeString, 18, "[%Y%m%d_%H%M%S]", timeInfo);
  std::cout << timeString << ' ';

  return 0;
}
```
- std::time() : Epoch 시간으로부터 지금까지 경과한 "초"를 반환한다.
- std::localtime() : 인자로 넣은 초를 가지고 시간, 분, 초 등의 정보를 가지고 있는 std::tm 구조체를 만들어 반환한다.
- std::strftime() : std::tm 구조체의 값을 가지고, 특정 형식의 문자열로 변환하여 저장한다.

#### OS마다 vector의 요소 삭제 순서가 다른 이유
- main 함수가 끝나면서 vector도 없어지게되고, vector의 요소들도 없어지게 되면서 요소의 소멸자가 각각 호출된다.
- 이때, vector에서는 요소들을 제거할 때 allocator(할당자)를 사용 한다.
- allocator란, 메모리 할당 및 해제를 관리하는 템플릿 클래스의 객체이다. (STL 개념)
- **vector가 allocator를 사용하여 요소들을 제거할 때의 순서는, 표준으로 명확하게 정해진 것이 없다.**
- **표준 c++ 라이브러리의 내부 구현에 따라 다르게 되는 것**이다.
- **표준 라이브러리는 컴파일러가 같이 제공**한다.
    - macOS = **LLVM(clang)** 컴파일러 사용.
    - Linux(Ubuntu) = **GCC(GNU Compiler Collection)** 컴파일러 사용.
