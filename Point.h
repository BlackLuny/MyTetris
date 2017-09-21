//
//  Point.hpp
//  RainProblem
//
//  Created by BlackK on 2016/11/2.
//  Copyright © 2016年 BlackK. All rights reserved.
//

#ifndef Point_hpp
#define Point_hpp
#include <iostream>
#include "vel.h"
typedef vel<double, 2> Vel2;
typedef struct velocity_t{
    Vel2 direction;
    double speed;
    velocity_t(double direction_x, double direction_y, double t_speed)
    {
        speed = t_speed;
        direction(direction_x, direction_y);
    }
}velocity;
using namespace std;
class Point
{
    
protected:
    velocity _v;
    Vel2 _position;
public:
    void move();
    Point(Vel2 direction,double speed = 1.0,double x = 0,double y = 0);
    Point(Vel2 possition,velocity v);
    Point():_v(0, -1.0, 1.0){_position<< 0 <<0;}
    Vel2 getPosition()
    {
        return _position;
    }
    virtual ~Point(){};
};


#endif /* Point_hpp */
