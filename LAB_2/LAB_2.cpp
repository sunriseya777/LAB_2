 
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "CStr.h"

using namespace std;
int main()
{
    srand(time(0));
    cout << "class CStr\n\n";

    CStr s1;
    cout << "s1(rand): " << s1<< ", length: " << s1.length()<<"\n";

    CStr s2("allo");
    cout << s2<<"\n";

    CStr s3(5);
    cout << s3<<"\n";

    CStr s4(s2);
    cout << s4<<"\n";

    CStr s5;
    s5 = s2;
    cout << s5<<"\n";
    s5 = "World";
    cout << s5<<"\n";

    CStr s6 = s1 + CStr(" .");
    cout << s6<<"\n";

    s6 += CStr("><");
    cout << s6<<"\n";

    cout << "s6>s5? " << (s6 > s5 ? "yes" : "no")<<"\n";

    s5[0] = 'B';
    cout << "s5[0] = 'B':  " << s5 << "\n\n";

    cout << "s7? : ";
    CStr s7;
    cin >> s7;
    cout << "s7  : " << s7<<", len: " << s7.length();
}

 