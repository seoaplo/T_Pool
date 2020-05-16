#pragma once

#include <iostream>
#include <unordered_map>
#include <assert.h>
#include <functional>

#include <queue>
enum  class E_OBJ
{
    PLAYER,
    MOB,
    ITEM,
    MAP,
    ETC
};


//////////////////////////////////////////////////
template<typename T>                            //
using UMap = std::unordered_map<int, T>;        //
                                                //이것들 처럼 집어넣기
std::function<void()> temp;                     //
//////////////////////////////////////////////////

template<typename T>
class Get_Obj_Map;

template<typename T>
class Obj_Map : public Get_Obj_Map<T>
{
public:
    bool Set(int&& obj_num, T&& obj);
    T& Get(int& obj_num) const ;

    virtual ~Obj_Map() {};
private:
    Obj_Map();
    std::unordered_map<int, T> m_uMap;

};

template<typename T>
Obj_Map<T>::Obj_Map() :Get_Obj_Map<T>()
{

};


template<typename T>
bool Obj_Map<T>::Set(int&& obj_num, T&& obj)
{
    auto result = m_uMap.insert((obj_num, std::forward(obj)));
    return result.second;
}


template<typename T>
T& Obj_Map<T>::Get(int& obj_num) const
{
    return m_uMap.find(obj_num);
}



template<typename T>
class Get_Obj_Map
{
public:

 static   Obj_Map<T>& Get()
    {
        static Obj_Map<T> single;
    }
 
 Get_Obj_Map() = delete;
};