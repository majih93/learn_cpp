# learn C++

## constants

값이 변하지 않도록 상수로 선언하고 싶을 때 어떻게 할 수 있을까?

```c++

// const keyword를 사용해서 변수를 선언한다.
int main() {
    const double pi = 3.14; 
    pi = 0; // 재할당하려고 하면 에러 발생한다.
    // cannot assign to variable 'pi' with const-qualified type 'const double' 
}

```

## writing outputs in the console

```c++
int main() {
    int x = 10;
    
    // standard output stream
    // Standard output - console or terminal
    // Stream - sequence of characters
    // -> 표준 출력 도구에 stream을 출력할 수 있게 해주는 기능
    // << -> Stream insertion operator, 우측 피연산자를 좌측 객체에 삽입
    std::cout << "x = ";
    std::cout << x;
    
    // operator chaining 도 가능
    std::cout << "x = " << x;
    
    // 줄바꿈 처리를 원한다면 std::endl - end of line 을 사용할 수있음.
    std::cout << "x = " << x << std::endl;
    
    return 0;
}
```

그런데 위 코드에서 하나 작은 문제점이 있음. 뭐냐면... `std::`라는 코드가 계속 반복되고 있다는 점.

이는 `using` directive(지시자)를 통해서 해결할 수 있다.

`using`지시자를 사용하면 `std`라는 `namespace`에 속한 이름을 모두 가져와서 모듈 안에서 전역적으로 사용할 수 있게 해준다.


## Reading input from the console

`cin` 함수를 통해서 값을 입력받을 수 있음.

```c++
int main() {
   cout << "값 입력해" << endl;
   int value;
   cin >> value;
   cout << "입력한 값은 " << value << ". 맞지?ㅎ";

   double x;
   double y;


   cout << "값 x,y입력해.";
   // 앞서 cout과 마찬가지로 operator chaining으로 값 여러개 입력받을 수 있어.
   cin >> x >> y;

   cout << x + y;

   return 0;
}
```

## Working with the standard library

`cmath`와 같이, 표준 라이브러리를 활용해서 이미 내장된 기능을 사용할 수 있다.

표준 라이브러리란?

> Standard libraries in C++ are a collection of pre-written classes, functions, and objects provided by the C++ Standard Library to perform common tasks, making it easier to develop robust and efficient applications. These libraries cover a wide range of functionalities, from input/output operations to data structures, algorithms, and much more. Here are some of the key components of the C++ Standard Library:

```c++
#include <iostream>
# include <cmath> // 수학 관련 기능을 제공해주는 library

using namespace std;

int main() {
   double result = floor(1.2);
   cout << result << endl; // 1

   double powered = pow(2, 3);
   cout << powered; // 8
   return 0;
}
```

## data types

`C++`은 정적 타입 언어이다. 이는, 변수 선언 시 타입을 명시해야 하며 선언 시 명시된 타입이 프로그램의 생명주기 동안 변경될 수 없다는 의미이다.

