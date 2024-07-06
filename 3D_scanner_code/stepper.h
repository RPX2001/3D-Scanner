#ifndef STEPPER            
#define STEPPER

void init_stepper();
void rotate_tmotor(uint8_t steps);
void rotate_zmotor(uint8_t steps);

#endif