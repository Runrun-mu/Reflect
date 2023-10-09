//
// Created by cheng on 2023/8/24.
//

#ifndef UNTITLED1_B_H
#define UNTITLED1_B_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "../ClassRegister.h"

class B: public Object{
public:
    B(): m_name("a"){}

    virtual void show() override {
        cout << "name = " << m_name << endl;
    }

    void f1(){
        cout << "f1b" << endl;
    }

    void f2(){
        cout << "f2b" << endl;
    }
public:
    string m_name;
};

REGISTER_CLASS(B);
#endif //UNTITLED1_B_H
