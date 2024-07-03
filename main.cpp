#include <iostream>
# include <cmath> // 수학 관련 기능을 제공해주는 library

using namespace std;

// 별도의 namespace(JavaScript scope같은 느낌인가?)를 선언하면 같아보이는 변수명을 사용할 수 있음.
// chatGPT에게 물어본 결과
/* Namespaces are a feature in C++ designed to organize code into logical groups and to
// prevent name collisions that can occur especially when your code base includes multiple
// libraries. A namespace defines a scope that contains a set of related names, such as
variables, functions, and classes. */
namespace MyNameSpace {
   int x = 1;
}

namespace AnotherNameSpace {
   // 같은 x라는 이름으로 변수 선언이 가능함. 다른 namespace이므로.
   int x = 2;
}



int main() {
   const double result = floor(1.2);
   cout << result << endl; // 1

   double powered = pow(2, 3);
   cout << powered << endl; // 8

   // string values
   // char가 연속적인 형태
   // std namespace에 의해서 제공됨
   string name = "Ji";
   cout << name << endl;

   // String literal
   cout << "Hello" << name << endl;


   // const keyword -> prevents the var getting modified
   const int age = 32;
   // age = 17; -> Cannot assign to readonly type age

   // common naming convention for constants -> UPPERCASE
   const double PI = 3.14;
   cout << PI<< endl;

   // namespace
   // :: -> scope resolution operator
   // main 함수 내에 또 하나의 x라는 이름의 변수 선언
   int x = 3;

   // 각 namespace별 이름을 ::연산자로 접근해서 사용한다.
   // Stream Insertion Operator
   // output을 출력하는 함수에 값을 주입하기 위해서 사용된다 여기에서
   // output stream이라고 하네 이거를.
   cout << "x in main function is " << x << endl; // 3
   cout << "x in MyNameSpace is " << MyNameSpace::x << endl; // 1
   cout << "x in AnotherNameSpace is " << AnotherNameSpace::x << endl; // 2

   // using namespace -> 특정 namespace를 전역에서 접근하는 형태로 선언한다.
   // using namespace로 처리된 namespace의 값은 resolution operator없이 바로 접근해서 사용할 수 있음.

   // 다른 강의에서 해당 강의자는 편의를 위해서 std를 using namespace로 접근했지만, 이번 강의자는 이것을
   // 'evil line of code' 라고 표현함. 그 이유는, std namespace에는 수많은 entity가 있어서 entity이름이 중복될
   // 가능성이 매우 크다고 한다.
   // using namespace std보다는, using namespace std::cout, using namespace std::string 과 같이 선언해서 쓰는것이
   // 더 안전한 alternative

   return 0;
}

// 이렇게 작성한 코드를 실행하려면, 내가 작성한 코드를 Machine Code로 컴파일해야한다.(OS가 실행할 수 있도록.)