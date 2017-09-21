//
//  Point.cpp
//  RainProblem
//
//  Created by BlackK on 2016/11/2.
//  Copyright © 2016年 BlackK. All rights reserved.
//

#include "Point.h"
void Point::move()
{
    Vel2 t = _v.speed * _v.direction;
    _position = _position + t;
}

Point::Point(Vel2 direction,double speed,double x,double y):_position(),_v(x, y, speed)
{
    _position<<x<<y;
}
