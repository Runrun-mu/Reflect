//
// Created by cheng on 2023/8/24.
//

#ifndef UNTITLED1_A_H
#define UNTITLED1_A_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "../ClassRegister.h"

class A: public Object{
public:
    A(): m_name("a"), m_age(18){}

    virtual void show() override {
        cout << "name = " << m_name << "age = " << m_age << endl;
    }

    void f1(){
        cout << "f1" << endl;
    }

    void f2(){
        cout << "f2" << endl;
    }
public:
    string m_name;
    int m_age;
};

REGISTER_CLASS(A);
REGISTER_CLASS_FIELD(A, m_name, string);
REGISTER_CLASS_FIELD(A, m_age, int);
REGISTER_CLASS_METHOD(A, f1);
#endif //UNTITLED1_A_H
