#pragma once

#include <memory>
#include <vector>

#include "rp_Std.h"

template<typename T>
struct Pool_Result
{
    bool bSuccess;
    std::weak_ptr<T> target;
    Pool_Result(bool& bresult, std::shared_ptr<T>& sptr) : bSuccess(bresult)
    {
        target = sptr;
    }
};
//
//template<typename T>
//struct Pool_Object
//{
//    bool bUsing;
//    std::shared_ptr<T> pTarget;
//    Pool_Object(bool& buse, T&& target) : bUsing(buse)
//    {
//        pTarget = std::make_shared<T>(std::forward(target));
//    }
//};

template<typename T>
class T_pool
{
private:
    size_t m_Pool_Size;

    std::vector<std::shared_ptr<T>> m_Pool;
    

public:
    T_pool()
    {
        m_Pool.resize(DEFAULT_POOL_SIZE);
        m_Pool_Size = DEFAULT_POOL_SIZE;
    };
    T_pool(size_t size)
    {
        m_Pool.resize(size);
        m_Pool_Size = size;
    }
    virtual ~T_pool()
    {

    };

    
    Pool_Result<T> Insert(size_t& location,T&& tobject)
    {
        if (m_Pool[location] ==nullptr)
        {
            return Pool_Result<T>(false,nullptr);
        }
        
        m_Pool[location] = std::make_shared<T>(std::forward(tobject));
        return Pool_Result<T>(true, m_Pool[location]);
    }

    bool Push_back(T&& tobject)
    {
        if (m_Pool.size() != m_Pool.capacity())
        {
            m_Pool.push_back(std::make_shared<T>(std::forward(tobject)));
            return true;
        }
        return false;
    }

    std::weak_ptr<T> Take(size_t location)
    {
        if (m_Pool_Size - 1 < location)
        {
            return nullptr;
        }
        
        return m_Pool[location];                // 빈 컨테이너 접근시 ==nullptr
    }

};

