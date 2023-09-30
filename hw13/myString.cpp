//
//  myString.cpp
//  hw10
//
//  Created by Дима on 27.09.23.
//

#include <iostream>
#include <cstring>
#include "myString.hpp"
using namespace std;
int myString:: counter = 0;

myString:: myString(){
    length = 80;
    str = new char[length + 1];
    counter++;
   
}

myString:: myString(char* array){
    length = strlen(array) + 1;
   str = new char[length];
    strcpy(str, array);
    counter++;
}


 void myString:: input(){
     char array[100];
    cout << "введите строку: ";
    cin.getline(array, sizeof(array));
      strcpy(str, array);
 
}




void myString :: MyStrcpy(myString& obj){
    str = new char[strlen(obj.str) + 1];
    strcpy(this -> str, obj.str);

}
void myString:: print() const{
    cout << str << endl;
}


bool myString :: MyStrStr(const char * str1){
    const char* result = strstr(this -> str, str1);
        if (result != nullptr) {
            cout << "подстрока найдена: " << result << endl;
            return true;
        }
        else{
            cout << "подстрока не найдена" << endl;
        }
    
    return false;
}


int myString :: MyChr(char c){
    for(int i = 0; i < length; i++){
        if(str[i] == c){
            cout << "искомый символ найден" << endl;
            break;
        }
        else{
            cout << "искомый символ не найден" << endl;
            break;
        }
    }
  
    return 0;
}



int myString:: MyStrLen(){
    int len = strlen(str);
    return len;
}

void myString :: MyStrCat(myString& b){
    int size = strlen(str) + strlen(b.str);
    char* newStr = new char[size];
    strcpy(newStr, str);
    strcat(newStr, b.str);
    delete[] str;
    str = newStr;
    cout << "обьединение строк: " << str << endl;
}


void myString:: MyDelChr(char c){
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (str[i] == c) {
            count++;
        }
    }
    
    int size = length - count;
    char* newStr = new char[size + 1];
    int j = 0;
    
    for (int i = 0; i < length; i++) {
        if (str[i] != c) {
            newStr[j] = str[i];
            j++;
        }
    }

    delete[] str;
    str = newStr;

    cout << str << endl;
}
int myString:: MyStrCmp(myString &b){
    size_t size1 = strlen(str);
    size_t size2 = strlen(b.str);
    int result = 0;
    if(size1 > size2){
        result = 1;
    }
     if(size1 < size2){
        result = -1;
    }
     if(size1 == size2){
        result = 0;
    }
    return result;
}
 void myString:: createdObjects(){
    cout << "количество созданных обьектов: " << counter << endl;
}


myString::myString(const myString& newStr)
{
    length = newStr.length;
    str = new char[strlen(newStr.str) + 1];
    strcpy(str, newStr.str);
}


char& myString:: operator[](const unsigned int index){
    if(index >= 0 && index < length - 1){
        return str[index];
    }
    return str[0];
}

void myString:: operator() (){
    length += 1;
}
myString& myString:: operator ->(){
    return *this;
}

myString :: ~myString(){
    delete[] str;
}

char* myString:: getString() const {
     return str;
 }

int myString:: getLength() const{
    return length;
}
void myString:: setLength(int l){
    length = l;
}
void myString:: setString(char* s){
    str = s;
}


 myString& myString:: operator =(const myString& right){
    if(this != &right){
        delete[] str;
        char* newStr = new char[right.length];
        for(int i = 0; i < length; i++){
            newStr[i] = str[i];
        }
    }
     return *this;
}
myString:: myString(myString&& obj){
    length = obj.length;
    obj.length = 0;
    str = obj.str;
    obj.str = nullptr;
}
myString myString:: returnString(myString obj){
    return obj;
}



myString operator+(const myString obj1, char c){
    myString result;
    result.setLength(obj1.getLength() + 1);//задаём результирующему обьекту размер
    char* newStr = new char[result.getLength()];//создаём временный массив символов
    strcpy(newStr, obj1.getString()); //копируем во временный массив первоначальный обьект
    for(int i = obj1.getLength() - 1; i < result.getLength(); i++){//от конца первоначального массива до конца нового проходимся по размеру
        if(i == result.getLength() - 1){//если дошли до конца массива, то устанавливаем \0
            newStr[i] = '\0';
        }
        else{//если это не конец массивва, то добавляем символ
            newStr[i] = c;
        }
    }
    result.setString(newStr);//устанавливаем в результат полученное значение

    return result;
}


myString operator+(char c, const myString obj1){
        myString result;
        result.setLength(obj1.getLength() + 1);
        char* newStr = new char[result.getLength()];//создаём временный массив 1
        char* newStr1 = new char[result.getLength()];//создаём временный массив 2
        strcpy(newStr, obj1.getString()); //копируем первоначальный обьект во временный массив
        strcpy(newStr1, obj1.getString());//копируем первоначальный обьект во временный массив
    int j = 0;
    newStr[0] = c; //устанавливаем нулевым символом нужный нам
        for(int i = 1; i < result.getLength(); i++){ //от первого символа до конца идём по циклу
            if(i == result.getLength() - 1){ // если i равно концу, то устанавливаем /0
                newStr[i] = '\0';
            }
            else{ //иначе копируем из одного временного массива данные в другой
                newStr[i] = newStr1[j];
                j++;
            }
        }
        result.setString(newStr); //устанавливаем результат
        return result;
    }





myString operator+(const myString obj1, int c){
    myString result;
    result.setLength(obj1.getLength() + c);
    char* newStr = new char[result.getLength()];
    strcpy(newStr, obj1.getString());
    for(int i = obj1.getLength() - 1; i < result.getLength(); i++){
        if(i == result.getLength() - 1){
            newStr[i] = '\0';
        }
        else{
            newStr[i] = 'c';
        }
    }
    result.setString(newStr);
    return result;
}

myString operator+(int c, const myString obj1){
    myString result;
    result.setLength(obj1.getLength() + c);
    char* newStr = new char[result.getLength()];
    char* newStr1 = new char[result.getLength()];
    strcpy(newStr, obj1.getString());
    strcpy(newStr1, obj1.getString());
    for (int i = 0, j = 0; i < result.getLength(); i++)
    {
        if (i == result.getLength() - 1)
        {
            newStr[i] = '\0';
        }
         if (i == 0) {
            newStr[i] = 'c';
        }
        if(i < obj1.getLength() - 1){
            newStr[i] = 'c';
        }
        else {
            newStr[i] = newStr1[j];
            j++;
        }
    }
    result.setString(newStr);
    return result;
}



myString operator++(const myString obj1, int c){
        myString result;
        result.setLength(obj1.getLength() + 1);
        char* newStr = new char[result.getLength()];
        strcpy(newStr, obj1.getString());
        for(int i = obj1.getLength() - 1; i < result.getLength(); i++){
            if(i == result.getLength() - 1){
                newStr[i] = '\0';
            }
            else{
                newStr[i] = 'c';
            }
        }
        result.setString(newStr);
        return result;
    }

myString operator++(const myString obj1){
        myString result;
        result.setLength(obj1.getLength() + 1);
        char* newStr = new char[result.getLength() + 1];
        char* newStr1 = new char[result.getLength()];
        strcpy(newStr, obj1.getString());
        strcpy(newStr1, obj1.getString());

    for (int i = 0, j = 0; i < result.getLength(); i++)
    {
        if (i == result.getLength() - 1)
        {
            newStr[i] = '\0';
        }
        else if (i == 0) {
            newStr[i] = 'c';
        }
        else {
            newStr[i] = newStr1[j];
            j++;
        }
    }
        result.setString(newStr);
        return result;
    }


//ostream& operator <<(ostream& os, myString& obj){
//    cout << "ostream& operator <<(ostream& os, myString& obj)" << endl;
//    os << obj.getString() << endl;
//    os << obj.getLength() << endl;
//    return os;
//}
//
//istream& operator >>(istream& is, myString& obj){
//    cout << "istream& operator >>(istream& is, myString& obj)" << endl;
//    char* s;
//    int l;
//    cout << "enter a string: ";
//    is >> s;
//    cout << "enter a length: ";
//    is >> l;
//    obj.setString(s);
//    obj.setLength(l);
//    delete s;
//    return is;
//}
//
