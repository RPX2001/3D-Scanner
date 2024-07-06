#ifndef ToF
#define ToF

void vl53l1x_init();
void vl53l1x_measure_distance();
uint16_t vl53l1x_read_distance();

#endif