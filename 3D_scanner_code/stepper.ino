//stepper library
void init_stepper(){
  //setup stepper motor pins
  //setup turn table motor
	DDRD |= (1<<DDD6);  //pin PD6 output - t_enable
	DDRD |= (1<<DDD3);  //Pin PD3 Output - t_pulse
	DDRD |= (1<<DDD2);  //pin PD2 output - t_dir
	
  //set up z axis motor
	DDRD |= (1<<DDD7);  //pin PD7 output - z_enable
	DDRD |= (1<<DDD5);  //pin PD5 output - z_pulse
	DDRD |= (1<<DDD4);  //pin PD5 output - z_dir
	
	PORTD &= (~(1<<PORTD6));  //t_enable low
	PORTD &= (~(1<<PORTD7));  //z_enable low
	
}

//rotate turntable motor
void rotate_tmotor(uint8_t steps){
	for(uint8_t t=0;t<steps;t++){
		PORTD &= (~(1<<PORTD3)); //low t_pulse
		delay_ms(1);
		PORTD |= (1<<PORTD3); //high t_pulse
		delay_ms(1);
		
	}
	
}


//rotate z axis motor
void rotate_zmotor(uint8_t steps){
	for(uint8_t i=0;i<steps;i++)
	{
		PORTD &= (~(1<<PORTD5)); //low t_pulse
		delay_ms(1);
		PORTD|= (1<<PORTD5); //high t_pulse
		delay_ms(1);
	}
}

