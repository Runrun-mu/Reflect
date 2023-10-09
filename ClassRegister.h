//
// Created by cheng on 2023/8/24.
//

#ifndef UNTITLED1_CLASSREGISTER_H
#define UNTITLED1_CLASSREGISTER_H
#include "ClassFactory.h"

class ClassRegister{
public:
    ClassRegister(const string & className, create_object method){
        cout << "register" << className << endl;
        Singleton<ClassFactory>::instance()->register_class(className, method);
    }

    ClassRegister(const string & className, const string & fieldName, const string & fieldType, uintptr_t offset)
    {
        // register class field
        Singleton<ClassFactory>::instance()->register_class_field(className, fieldName, fieldType, offset);
    }

    ClassRegister(const string & className, const string & methodName, uintptr_t method)
    {
        // register class method
        Singleton<ClassFactory>::instance()->register_class_method(className, methodName, method);
    }
};

#define REGISTER_CLASS(className)                                       \
    Object * createObject##className()                                  \
    {                                                                   \
        Object * obj = new className();                                 \
        obj->set_class_name(#className);                                \
        return obj;                                                     \
    }                                                                  	\
    ClassRegister classRegister##className(#className, createObject##className)
//创建一个A类型变量，计算每个变量离他起始位置有多远
#define REGISTER_CLASS_FIELD(className, fieldName, fieldType) \
    className className##fieldName; \
    ClassRegister classRegister##className##fieldName(#className, #fieldName, #fieldType, (size_t)(&(className##fieldName.fieldName)) - (size_t)(&className##fieldName))

#define REGISTER_CLASS_METHOD(className, methodName) \
    std::function<void(className *)> className##methodName##method = &className::methodName; \
    ClassRegister classRegister##className##methodName(#className, #methodName, (uintptr_t)&(className##methodName##method))

#endif //UNTITLED1_CLASSREGISTER_H
