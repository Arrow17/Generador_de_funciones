#ifndef PWM_H
#define PWM_H

#include <xc.h>
#define _XTAL_FREQ 8000000

void init_pwm();

void pwm_25();

void pwm_50();

void pwm_75();

void pwm_100();

#endif
