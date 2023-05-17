
unsigned int i,n,k,d,y;
unsigned long previousTime = 0;

byte hours = 12;    // start time
byte minutes = 15;
byte seconds = 00;

int val;

void setup() 
{
  DDRD = 0xFE;
  DDRB = 0xFF;
  DDRC = 0xFE;
  PORTC = 0x01;  
  PORTD = 0x03;
  PORTB = 0x00;
  
  if(hours == 12)
  hours = 0;
}

void loop() 
{
      while(bit_is_clear(PINC, 0))
      { 
      }
  if (millis() >= (previousTime)) 
  {
     previousTime = previousTime + 1000;
     seconds = seconds +1;
     if (seconds == 60)
     {
        seconds = 0;
        minutes = minutes +1;
     }
     if (minutes == 60)
     {
        minutes = 0;
        hours = hours +1;
     }
     if (hours == 12)
     {
        hours = 0;
     }   
  }  
  k=30;
  n=0;
  while(n < 60)
  {
  PORTC |= (1<<5);
  if ((k==0) || (k==5) || (k==10) || (k==15) || (k==20) || (k==25) || (k==30) || (k==35) || (k==40) || (k==45) || (k==50) || (k==55))
  {
  PORTC |= (1<<4);
  PORTC |= (1<<3);  
  }
  if ((k==0) || (k==15) || (k==30) || (k==45))
  {
  PORTC |= (1<<2);
  PORTC |= (1<<1);     
  }
  if((k == hours*5) || (( k == 0 ) && (hours == 0)))
  {
  PORTD |= (1<<2); 
  PORTD |= (1<<3); 
  PORTD |= (1<<4); 
  PORTD |= (1<<5); 
  PORTD |= (1<<6); 
  PORTD |= (1<<7); 
  PORTB |= (1<<0); 
  }
  if(k == minutes)
  {
  PORTD |= (1<<2); 
  PORTD |= (1<<3); 
  PORTD |= (1<<4); 
  PORTD |= (1<<5); 
  PORTD |= (1<<6); 
  PORTD |= (1<<7); 
  PORTB |= (1<<0); 
  PORTB |= (1<<1);
  PORTB |= (1<<2);     
  }
  if(k == seconds)
{
  PORTD |= (1<<2); 
  PORTD |= (1<<3); 
  PORTD |= (1<<4); 
  PORTD |= (1<<5); 
  PORTD |= (1<<6); 
  PORTD |= (1<<7); 
  PORTB |= (1<<0); 
  PORTB |= (1<<1);
  PORTB |= (1<<2); 
  PORTB |= (1<<3);
  PORTB |= (1<<4);
}
  delayMicroseconds(140);
  PORTD = 0x03;
  PORTB = 0x00;
  PORTC = 0x01; 
  PORTD |= (1<<2); 
  delayMicroseconds(30);
  PORTD &= ~(1<<2);     
  delayMicroseconds(600);
  n++;
  k++;
  if(k == 60)
  k=0;
  }
  while(bit_is_set(PINC, 0))
  { 
  }     
}
