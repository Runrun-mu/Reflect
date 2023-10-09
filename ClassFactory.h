//
// Created by cheng on 2023/8/24.
//

#ifndef UNTITLED1_CLASSFACTORY_H
#define UNTITLED1_CLASSFACTORY_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <functional>
using namespace std;

#include "../Utils/Singleton.h"
#include "ClassField.h"
#include "ClassMethod.h"

class Object{
public:
    Object();
    virtual ~Object();

    //reflect class
    void set_class_name(const string& className);
    const string& get_class_name() const;

    //reflect field
    int get_field_count();
    ClassField* get_field(int pos);
    ClassField* get_field(const string & fieldName);

    template<class T>
    void get(const string & fieldName, T& value);

    template<class T>
    void set(const string& fieldName, const T & value);
    void set(const string& fieldName, const char * value);

    void call(const string & methodName);

    virtual void show() = 0;
private:
    string m_className;
};

using create_object = function<Object*(void)>;

class ClassFactory{
    friend class Singleton<ClassFactory>;
public:
    //reflect class
    void register_class(const string & className, create_object method);
    Object* create_class(const string & className);

    //reflect field
    void register_class_field(const string & className, const string & fieldName, const string & fieldType, size_t offset);
    int get_class_field_count(const string & className);
    ClassField * get_class_field(const string & className, int pos);
    ClassField * get_class_field(const string & className, const string & fieldName);

    // reflect class method
    void register_class_method(const string & className, const string &methodName, uintptr_t method);
    int get_class_method_count(const string & className);
    ClassMethod * get_class_method(const string & className, int pos);
    ClassMethod * get_class_method(const string & className, const string & methodName);

private:
    ClassFactory(){};
    ~ClassFactory() = default;
private:
    map<string, create_object> m_classMap;
    map<string, vector<ClassField *>> m_classFields;
    map<string, vector<ClassMethod *>> m_classMethods;
};

template<typename T>
void Object::get(const string & fieldName, T & value){
    ClassField* field = Singleton<ClassFactory>::instance()->get_class_field(m_className, fieldName);
    size_t offset = field->offset();
    value = *((T *)((unsigned char *)(this) + offset));
}

template<typename T>
void Object::set(const string & fieldName, const T& value){
    ClassField* field = Singleton<ClassFactory>::instance()->get_class_field(m_className, fieldName);
    size_t offset = field->offset();
    *((T*)((unsigned char*)(this) + offset)) = value;
}

#endif //UNTITLED1_CLASSFACTORY_H