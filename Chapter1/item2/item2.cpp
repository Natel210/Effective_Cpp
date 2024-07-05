#include <iostream>

//디파인을 잘못 사용한 예시

#define CALL_WiTH_MAX(a,b) ((a) > (b) ? (a) : (b))
template<typename T>
/*inline*/ T callWithMax(const T& a, const T& b) { return (a > b ? a : b); }

int main()
{
    int item1, item2;

    std::cout << "---- use define ----" << std::endl;
    item1 = 5;
    item2 = 0;
    std::cout << "a : " << item1 << std::endl;
    CALL_WiTH_MAX(++item1, item2);
    // 연산식
    // if (++item1 > item2)
    //     return ++item1;              | <= if enter
    std::cout << "CALL_WiTH_MAX(++item1, item2) => a : " << item1 << std::endl; // Increased++ by 2 times
    CALL_WiTH_MAX(++item1, item2 + 10);
    // 연산식
    // if (++item1 > item2) {...}
    // esle
    //     return item2;                | <= else enter
    std::cout << "CALL_WiTH_MAX(++item1, item2 + 10) => a : " << item1 << std::endl; // Increased++ by 1 times

    std::cout << "---- use template ----"<< std::endl;
    item1 = 5;
    item2 = 0;
    std::cout << "a : " << item1 << std::endl;
    callWithMax(++item1, item2);
    std::cout << "callWithMax(++item1, item2) => a : " << item1 << std::endl;
    callWithMax(++item1, item2 + 10);
    std::cout << "callWithMax(++item1, item2 + 10) => a : " << item1 << std::endl;

    system("pause");
    exit(0);
}
