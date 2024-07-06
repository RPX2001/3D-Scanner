//main function

#include <avr/io.h>
#include "delay.h"
#include "uart.h"
#include "TWI.h"
#include "ToF.h"
#include "stepper.h"

int main(){
  init_uart();
  i2c_init();
  vl53l1x_init();
  init_stepper();
  DDRD |= (1<<DDD4);  //pin PD5 output - z_dir

  while(1){
    
    //trans_string("Distance: ");
    //delay_ms(100);


    uint8_t vert_distnce = 10;   /*max Z axis distance*/
    uint8_t z_steps = 200;  // z steps per rotation
    uint32_t z_counts = (200/1*vert_distnce)/z_steps;  //total z_counts ntil return home
    uint8_t theta_counts = 200;
    
    PORTD &= (~(1<<PORTD4)); // z_dir LOW
    for(uint32_t j=0;j<z_counts;j++)
    {
      for(uint8_t i=0; i<theta_counts;i++)
      {
        rotate_tmotor(1);   //start rotate turn table
        //double sense_distance = 0; //reset distance measurement
        vl53l1x_measure_distance();
        uint16_t distance = vl53l1x_read_distance();
        trans_num(distance);
        trans_string("\n");
        
      }
      rotate_zmotor(z_steps); //start rotating z axis motor
      delay_ms(1000);
      //serial print(9999);
      trans_num(9999);
      trans_string("\n");
    }
    PORTD |= (1<<PORTD4); // move z to home
    delay_ms(10); //delay 10ms
    for(uint32_t k=0;k<z_counts;k++){
      rotate_zmotor(z_steps);
      delay_ms(10);
    }

  }
  return 0;
}



