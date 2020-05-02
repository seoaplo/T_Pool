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

template<typename T>
struct Pool_Object
{
    bool bUsing;
    std::shared_ptr<T> pTarget;
    Pool_Object(bool& buse, T&& target) : bUsing(buse)
    {
        pTarget = std::make_shared<T>(std::forward(target));
    }
};

template<typename T>
class T_pool
{
private:
    size_t m_Pool_Size;

    std::vector<Pool_Object> m_Pool;
    

public:
    T_pool()
    {
        m_Pool.reserve(POOL_SIZE);
        m_Pool_Size = POOL_SIZE;
    };
    T_pool(size_t size)
    {
        m_Pool.reserve(size);
        m_Pool_Size = size;
    }
    virtual ~T_pool()
    {

    };

    
    Pool_Result<T> Insert(size_t& location,T&& tobject)
    {
        if (m_Pool[location].bUsing ==false)
        {
            return Pool_Result<T>(false,nullptr);
        }
        
        m_Pool[location] = Pool_Object<T>(true, tobject);
        return Pool_Result<T>(true, m_Pool[location].pTarget);
    }
    bool Push_back(T&& tobject)
    {
        //m_Pool.push_back(std::make_shared<T>(std::forward(tobject)));
    }

    Pool_Result<T> Take(size_t location)
    {

    }

};

