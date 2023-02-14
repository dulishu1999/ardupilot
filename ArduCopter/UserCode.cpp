#include "Copter.h"
#include <chrono>
#include <AP_HAL/AP_HAL.h>

/*
#直接推油门起飞是纯姿态起飞

*/

#ifdef USERHOOK_INIT
void Copter::userhook_init()
{
    // put your initialisation code here
    // this will be called once at start-up
}
#endif

#ifdef USERHOOK_FASTLOOP 
void Copter::userhook_FastLoop()
{
    // put your 100Hz code here
    static RC_Channel *ch6 = rc().channel(CH_6);
    static uint8_t ch6_flag = 0;
    static u_int8_t timeCnt = 0;
    if(ch6->get_control_in() == 0) ch6_flag = 0;
    if(ch6->get_control_in() ==1000 && ch6_flag == 0){//如果遥控器接收值发生翻转，表示触发执行阶跃函数
        switch (g.phasestep_channelclass)
        {
        case 1://pitch
            /* code */
            if(g.phasestep_stepclass == 0){//step 类型为不翻转
                if(timeCnt == 0){
                    copter.addPitchAngle += g.phasestep_angle;
                }
                timeCnt ++;
                if(timeCnt > g.phasestep_ts*100){
                    copter.addPitchAngle = 0;
                    timeCnt = 0;
                    ch6_flag = 1;
                }
            }
            if(g.phasestep_stepclass == 1){//step 类型为翻转
                if(timeCnt == 0){
                    copter.addPitchAngle += g.phasestep_angle;
                }
                timeCnt ++;
                if(timeCnt > g.phasestep_ts*100 && timeCnt <= g.phasestep_ts*100*2){
                    copter.addPitchAngle = 0;
                }
                else if(timeCnt > 2*g.phasestep_ts*100 && timeCnt <= g.phasestep_ts*100*3){
                    copter.addPitchAngle -= g.phasestep_angle;

                }
                else{
                    timeCnt = 0;
                    ch6_flag = 1;

                }
            }
            break;
        case 2://roll
            /* code */
            if(g.phasestep_stepclass == 0){//step 类型为不翻转
                if(timeCnt == 0){
                    copter.addRollAngle += g.phasestep_angle;
                }
                timeCnt ++;
                if(timeCnt > g.phasestep_ts*100){
                    copter.addRollAngle = 0;
                    timeCnt = 0;
                    ch6_flag = 1;
                }
            }
            if(g.phasestep_stepclass == 1){//step 类型为翻转
                if(timeCnt == 0){
                    copter.addRollAngle += g.phasestep_angle;
                }
                timeCnt ++;
                if(timeCnt > g.phasestep_ts*100 && timeCnt <= g.phasestep_ts*100*2){
                    copter.addRollAngle = 0;
                }
                else if(timeCnt > 2*g.phasestep_ts*100 && timeCnt <= g.phasestep_ts*100*3){
                    copter.addRollAngle -= g.phasestep_angle;

                }
                else{
                    timeCnt = 0;
                    ch6_flag = 1;

                }
            }
            break;
        default:
            break;
        }

    }
}
#endif

#ifdef USERHOOK_50HZLOOP
void Copter::userhook_50Hz()
{
    // put your 50Hz code here
}
#endif

#ifdef USERHOOK_MEDIUMLOOP
void Copter::userhook_MediumLoop()
{
    // put your 10Hz code here
}
#endif

#ifdef USERHOOK_SLOWLOOP
void Copter::userhook_SlowLoop()
{
    // put your 3.3Hz code here
}
#endif

#ifdef USERHOOK_SUPERSLOWLOOP
void Copter::userhook_SuperSlowLoop()
{
    // put your 1Hz code here
}
#endif

#ifdef USERHOOK_AUXSWITCH
void Copter::userhook_auxSwitch1(uint8_t ch_flag)
{
    // put your aux switch #1 handler here (CHx_OPT = 47)
}

void Copter::userhook_auxSwitch2(uint8_t ch_flag)
{
    // put your aux switch #2 handler here (CHx_OPT = 48)
}

void Copter::userhook_auxSwitch3(uint8_t ch_flag)
{
    // put your aux switch #3 handler here (CHx_OPT = 49)
}
#endif
