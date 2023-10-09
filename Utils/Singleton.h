//
// Created by cheng on 2023/8/24.
//

#ifndef UNTITLED1_SINGLETON_H
#define UNTITLED1_SINGLETON_H

#include<mutex>
using namespace std;
template <typename T>
class Singleton{
private:
    Singleton(){}
    ~Singleton(){}
    Singleton(const Singleton&) = delete;
    Singleton& operator = (const Singleton&) = delete;
public:
    static T* instance(){
        static T instance;
        return &instance;
    }
};
/*
class Singleton
{
public:
    static T* instance(){
        if(m_instance == nullptr){
            std::lock_guard<mutex> lock(mtx);
            if(m_instance == nullptr){
                m_instance = new T();
            }
        }
        return m_instance;
    }
private:
    Singleton(){}
    Singleton(const Singleton<T> &) = delete;
    Singleton<T> & operator = (const Singleton<T> &) = delete;
    ~Singleton(){}
private:
    static T* m_instance;
    static mutex mtx;
};

template<typename T>
T* Singleton<T>::m_instance = nullptr;

template<typename T>
mutex Singleton<T>::mtx;
 */

#endif //UNTITLED1_SINGLETON_H