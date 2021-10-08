#ifndef 角度角度
#define SM
#include<mbed.h>
#include<vector>

class Servo
{
    private:
    PwmOut& servo_pwm;
    float min_pulsewidth_ms;//0度のパルス幅
    float max_pulsewidth_ms;//180度のパルス幅
    float operatingspeed;//0.1秒で何度回るか
    float dig_to_pulse(float);
    float pulse_to_dig(float);
    float nowdig;
    public:
    Servo(PwmOut&,float,float,float);
    void Servo_Move_Absolute(float);//速度はいいのでx度の場所に回ってほしい
    void Servo_Move_Relative(float);//現在位置からx度の場所に行ってほしい（プラスが反時計）
    void Servo_Move_Absolute(float,float);//角度,角速度(0.1秒でx度)
    void Servo_move_Relative(float,float);//角度,角速度
};
#endif
