#include<mbed.h>
#include<vector>
#include"Servo_Motor.h"

Servo::Servo(PwmOut& _servo,float _minwidth,float _maxwidth,float _maxspeed=60)
:servo_pwm(_servo),min_pulsewidth_ms(_minwidth),max_pulsewidth_ms(_maxwidth),operatingspeed(_maxspeed)
{
    this->Servo_Move(0);
    this->nowdig=0;
}

float dig_to_pulse(float dig)
{
    return (float)(max_pulsewidth_ms-min_pulsewidth_ms)*dig/180+min_pulsewidth;
}

float pulse_to_dig(float pulse)
{
    return (float)(pulse-min_pulsewidth_ms)*180/(max_pulsewidth_ms-min_pulsewidth_ms);
}

void Servo_Move_Absolute(float dig)
{
    servo_pwm.period_us(20000);
    servo_pwm.pulsewidth_ms(dig_to_pulse(dig));
    nowdig = dig;
}

void Servo_Move_Absolute(float dig,float speed)
{
    if(dig<nowdig&&speed<0)
    {
        speed*=-1;
    }else if(dig>nowdig&&speed>0)
    {
        speed*=-1;
    }
    if(speed>operatingspeed)
    {
        speed=operatingspeed;
    }else if(speed<-operatingspeed)
    {
        speed=-1*operatingspeed;
    }
    servo_pwm.period_us(20000);
    float cnt = 0;
    while(1)
    {
        nowdig+=speed;
        servo_pwm.pulsewidth_ms(dig_to_pulse(nowdig));
        wait_us(100000);
        if(-2<nowdig-dig&&nowdig-dig<2)
        {
            break;
        }
        cnt+=1;
    }
}

void Servo_Move_Relative(float dig)
{
    Servo_Move_Absolute(nowdig+dig);
}

void Servo_Move_Relative(float dig,float speed)
{
    Servo_Move_Absolute(nowdig+dig,speed);
}