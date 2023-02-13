#include "Copter.h"
#include <AP_HAL/AP_HAL.h>

#define PHASE_STEP_SWITCH 1
#define PHASE_STEP_SWITCH_PITCH_ROLL 1 

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
    if(PHASE_STEP_SWITCH){//如果遥控器接收值发生翻转，表示触发执行阶跃函数
        switch (PHASE_STEP_SWITCH_PITCH_ROLL)
        {
        case 1:
            /* code */
            break;
        case 2:
            /* code */
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
