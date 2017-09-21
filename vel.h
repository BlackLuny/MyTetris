//
//  vel.hpp
//  RainProblem
//
//  Created by BlackK on 2016/11/2.
//  Copyright © 2016年 BlackK. All rights reserved.
//

#ifndef vel_hpp
#define vel_hpp
#include <iostream>
#include <vector>
using namespace std;
template <typename T>
void ff(T a);
template < typename T,int n>
class vel{
private:
    vector<T> _data;
    int _num;
public:
    vel():_data(),_num(0){};
    vel & operator<<(const T &data){
        if(_num<n){
            _data.push_back(data);
            _num++;
        }
        return *this;
    }
    vel & operator,(const T &data){
        return (*this)<<data;
    }
    vel& operator()(const T & op1, const T& op2)
    {
        return (*this)<<op1<<op2;
    }
    //乘法运算1
    vel operator*(const vel& other) const;
    vel operator*(const T&) const;
    friend vel operator*(const T& x,const vel & v){
        return v*x;
    }
    //加法运算符
    vel operator+(const vel& other) const;
    vel operator+(const T&) const;
    friend vel operator+(const T& x,const vel & v){
        return v+x;
    }
    //减法运算符
    vel operator-(const vel& other) const;
    vel operator-(const T&) const;
    //除法运算符
    vel operator/(const vel& other) const;
    vel operator/(const T&) const;
    template <typename P,int q>
    friend vel<P,q> operator/  (const P& x,const  vel<P,q> & v);
    //括号运算符
    T& operator[](const int i){
            return _data[i];
    }
    T operator[](const int i) const {
        return _data[i];
    }

    friend ostream & operator<<(ostream & os,const vel & v){
        if(v._num){
            os<<"{";
            for (int i = 0; i<v._num-1; i++) {
                os<<v._data[i]<<",";
            }
            return os<<v._data[v._num-1]<<"}";
        }else{
            return os<<"{}";
        }
    }

    virtual ~vel(){};
    
    
};

template < typename T,int n>
vel<T,n> vel<T,n>::operator*(const vel& other) const {
    vel<T,n> newVel;
    if(_num==other._num)
        for(int i = 0;i<_num;i++)
            newVel << (*this)[i] * (other[i]);
    return newVel;
}
template <typename T,int n>
vel<T,n> vel<T,n>::operator*(const T& x) const {
    vel<T,n> newVel;
    for(int i = 0;i<_num;i++)
        newVel << (*this)[i] * x;
    return newVel;
}

template < typename T,int n>
vel<T,n> vel<T,n>::operator+(const vel& other) const {
    vel<T,n> newVel;
    if(_num==other._num)
        for(int i = 0;i<_num;i++)
            newVel << (*this)[i] + (other[i]);
    return newVel;
}
template <typename T,int n>
vel<T,n> vel<T,n>::operator+(const T& x) const {
    vel<T,n> newVel;
    for(int i = 0;i<_num;i++)
        newVel << (*this)[i] + x;
    return newVel;
}

template < typename T,int n>
vel<T,n> vel<T,n>::operator-(const vel& other) const {
    vel<T,n> newVel;
    if(_num==other._num)
        for(int i = 0;i<_num;i++)
            newVel << (*this)[i] - (other[i]);
    return newVel;
}
template <typename T,int n>
vel<T,n> vel<T,n>::operator-(const T& x) const {
    vel<T,n> newVel;
    for(int i = 0;i<_num;i++)
        newVel << (*this)[i] - x;
    return newVel;
}
template < typename T,int n>
vel<T,n> vel<T,n>::operator/(const vel& other) const {
    vel<T,n> newVel;
    if(_num==other._num)
        for(int i = 0;i<_num;i++)
            newVel << (*this)[i] / (other[i]);
    return newVel;
}
template <typename T,int n>
vel<T,n> vel<T,n>::operator/(const T& x) const {
    vel<T,n> newVel;
    for(int i = 0;i<_num;i++)
        newVel << (*this)[i] / x;
    return newVel;
}
template <typename T,int n>
vel<T,n> operator/ (const T& x,const vel<T,n> &v) {
    vel<T,n> newVel;
    for(int i = 0;i<v._num;i++)
        newVel << x / v[i];
    return newVel;
}
#endif /* vel_hpp */
