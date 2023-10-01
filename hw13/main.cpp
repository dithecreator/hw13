//
//  main.cpp
//  hw10
//
//  Created by Дима on 27.09.23.
//

#include <iostream>
#include "myString.hpp"
using namespace std;

ostream& operator <<(ostream& os, myString& obj){
    cout << "ostream& operator <<(ostream& os, myString& obj)" << endl;
    os << obj.getString() << endl;
    os << obj.getLength() << endl;
    return os;
}

istream& operator >>(istream& is, myString& obj){
    cout << "istream& operator >>(istream& is, myString& obj)" << endl;
    int l;
    cout << "enter a length: ";
    is >> l;
    obj.setLength(l);
    char* s = new char[l];
    cout << "enter a string: ";
    is.ignore();
    is.getline(s, l);
    obj.setString(s);
    delete[] s;
    return is;
}
int main() {
//    myString my("sasha");
//    myString my1;
//    my.print();
//
//    my1.input();
//    cout << "введённая вами строка: ";
//    my1.print();
//    my.MyStrcpy(my1); //результат работы mystrcpy
//    my.print();
//
//    myString my2("dimasashaoleg");
//    my2.MyStrStr("dima"); //результат работы mystrstr
//
//    myString my3("violetta");
//    my3.MyChr('v'); //результат работы myChr
//
//    int sizelen =  my3.MyStrLen();
//    cout << "длина строки: " << sizelen << endl;
//    my3.MyStrCat(my2); //результат работы mystrcat
//
//    myString my4("olegasov");
//    my4.MyDelChr('s');
//
//    int result = my2.MyStrCmp(my4); // результат работы mystrcmp
//    cout << result << endl;
//    my.createdObjects();
//
//    myString my5("seg");
//    const char* myvalue = my5.getString();
//
//    myString my6("srg");
//    myString my7 = my6;
//    cout << "copy constructor: ";
//    my7.print();
    
//    myString my8 = my1 + 10;
    
//    my8.print();
    
    
//    myString my("Hello");
//    myString my1 = my + 'c';
//    myString my2 = 'c' + my;
//    myString my3 = my + 10;
//    myString my4 = 10 + my;
//    myString my5 = my++;
//    myString my6 = ++my;
//
//
//    cout << "obj + symbol: ";
//    my1.print();
//    cout << "symbol + object: ";
//    my2.print();
//    cout << "object + 10: ";
//    my3.print();
//    cout << "10 + object: ";
//    my4.print();
//    cout << "object++: ";
//    my5.print();
//    cout << "++object: ";
//    my6.print();
    
    myString my("Hello");
    myString my1 = my;
    my1.print();
    
    myString my2("Kitty");
    myString my3("!");
    cout << my2;
    cout << my3 << endl;
    cout << endl;
    cin >> my2;
    cout << my3;
    
//    myString result = returnString(my);
    myString result = move(my);
}
