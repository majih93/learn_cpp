#include <iostream>
#include <cmath> // 수학 관련 기능을 제공해주는 library
#include <vector>


/*
typedef는 C++에서 데이터 타입에 새로운 이름을 부여하는 키워드입니다. 이를 통해 복잡한 타입을 간단하게 표현하거나, 코드의 가독성을 높일 수 있습니다.
주요 특징:

- 기존 타입의 별칭 생성
- 복잡한 타입 선언 간소화
- 코드 유지보수 용이성 향상

newTypeName_t 형식으로 뒤에 `_t`라는 suffix를 붙여서 이름에서 typedef를 알 수 있도록 하는 것이 컨벤션이다.
 */

namespace MyNameSpace {
   int x = 1;
}

namespace AnotherNameSpace {
   // 같은 x라는 이름으로 변수 선언이 가능함. 다른 namespace이므로.
   int x = 2;
}



using namespace std;

// 별도의 namespace(JavaScript scope같은 느낌인가?)를 선언하면 같아보이는 변수명을 사용할 수 있음.
// chatGPT에게 물어본 결과
/* Namespaces are a feature in C++ designed to organize code into logical groups and to
// prevent name collisions that can occur especially when your code base includes multiple
// libraries. A namespace defines a scope that contains a set of related names, such as
variables, functions, and classes. */

typedef std::vector<std::pair<std::string,int>> pairlist_t;
// typedef std::string text_t;

// 하지만 typedef는 요즘 거의 using키워드로 대체되었다. 왜냐하면 using 키워드가 tempale으로 처리하기 더 좋기 때문이다.
// 강의자도 using키워드 사용하라고 추천함
// 명시적으로 benefit이 있을때만 꼭 사용하라고 추천함
using new_text_t = std::string;

// 사용자 정의 함수
// main함수 안에서 사용되기 때문에 이전에 선언은 되어야 하지만, 통상적으로 정의는 main함수 아래에 하는 것이 일반적이다.
// 위에서 선언하고, 아래에서 정의한다
void someUserDefinedFunction();

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

   // 생성한 typedef를 활용해서 기존에 존재하는 타입에 새로운 구분자를 부여한 것을 사용해보자.
   pairlist_t pairlist;

   // std::string firstname;
   // text_t firstname = "Bro";
   // cout << firstname;

   new_text_t myName = "ji";

   cout << myName << endl;

   // type conversion
   // 명시적 타입 변환
   // 암시적 타입 변환

   int num = 3.14;
   double numb = (int) 3.14;

   cout << num << endl; // int타입으로 지정된 변수이기 때문에 소수점은 버리고 3만 출력된다.
   cout << numb << endl; // 3이지만, 3.14를 int로 변환해서 double값에 할당하였음.

   // 근데 이거를 언제 쓰냐?
   // 예를 들어, 10개중에 몇개를 맞췄는지 퍼센티지를 표현한다고 해보자.
   int correct = 8;
   int total = 10;
   double score = correct/total * 100;

   cout << score << endl; // 그냥 correct/total을 하면 0이 출력된다 왜냐하면 int값 연산으로 처리되어 소수점이 버려지기 때문
   // 이를 방지하기 위해서 하나를 double로 type conversion시켜준다.
   double score_right = (double)correct/total * 100;
   double score_right2 = correct/(double)total * 100;
   cout << score_right << endl; // 80
   cout << score_right2 << endl; // 80

   // 입력 받기
   // 출력의 경우 cout함수에 출력값을 주입받는 형태로 cout << 출력값 으로 사용했지만,
   // 입력의 경우 cin >> 형태로 사용한다. 내가 뭔가를 입력 받는다는 느낌으로 이해하면 될듯?
   string user_name;
   // cout << "이름을 입력하세요" << endl;
   // cin >> user_name; // 입력값을 user_name변수에 할당
   //
   // cout << "Hello " << user_name << endl;

   // whitespace가 포함된 문자열을 받으려면?
   // cout << "full name을 입력하세요:" << endl;
   // getline(cin, user_name);
   // cout << "Hello " << user_name << endl;
   //
   // // 그런데 앞단에 cin으로 다른 값을 입력받은 상태에서, getline으로 값을 입력받으면 입력받은 값이 줄바꿈 처리되어서 입력된다.
   // // 이는 cin이 input buffer에 추가한 \n이 남아있어서 그런 것인데, 이로 인해서 getline을 이어서 하게되면 줄바꿈 처리가 된 이후에 값이 찍히는 것.
   //
   // // 이런 상황을 방지하기 위해서는 getline에 입력값 앞에 존재하는 공백을 다 제거하는 처리가 필요하다.
   // // ws는 whitespace의 약자로, 입력 스트림에서 선행 공백 문자를 제거하는 역할을 한다.
   // getline(cin >> ws, user_name); // ws를 통해서 공백제거처리

   // 사용자 지정함수
   someUserDefinedFunction();

   // 배열...!
   // 타입이 같은 데이터만 담을 수 있음.
   // 값이 없는 배열을 미리 선언할 수 있지만, 길이를 미리 지정해야 한다.
   int intArray[3];

   intArray[0] = 1;

   cout << intArray << endl; // 0x16cfbb3ec -> 배열이 시작하는 지점의 메모리 주소(0번째 인덱스 주소)
   cout << intArray[0] << endl; // 1
   cout << intArray[1] << endl; // 아직 할당하지 않은 배열인덱스에 접근하면 garbage data가 반환됨.


   // sizeof(); -> 피연산자의 데이터 크기를 구하는 함수
   cout << sizeof(intArray) << endl; // 12 -> int가 하나에 4니까, 4*3해서 12
   cout << sizeof(2) << endl; // 4
   cout << sizeof("A") << endl; // 2
   cout << sizeof("2.112") << endl; //6
   cout << sizeof(2.112) << endl; // 8

   return 0;
}

// 선언한 사용자 정의 함수를 정의한다.
void someUserDefinedFunction() {
   cout << "MyFunction!" << endl;
}



