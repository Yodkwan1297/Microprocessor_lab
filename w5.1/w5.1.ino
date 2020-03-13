#include <SPI.h>
#define DATA_PIN 11
#define CLOCK_PIN 13
#define SS_PIN_1 10
#define SS_PIN_2 9
int iii;
int map7seg[10]={
  0b00111111,0b00000110,0b01011011,0b01001111,
  0b01100110,0b01101101,0b01111101,0b00000111,
  0b01111111,0b01101111
};

void spi_write_1(unsigned char cData){
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, cData);
  digitalWrite (SS_PIN_1, HIGH);
  digitalWrite (SS_PIN_1, LOW);
}

void spi_write_2(unsigned char cData){
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, cData);
  digitalWrite (SS_PIN_2, HIGH);
  digitalWrite (SS_PIN_2, LOW);
}

void setup()
{  
  pinMode(SS_PIN_1, OUTPUT);
  pinMode(SS_PIN_2, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
}
void loop()
{
  if(iii>10)
  {iii=0;}
  for(iii=0;iii<10;iii++)
    {spi_write_1(map7seg[iii]);
    digitalWrite(CLOCK_PIN,HIGH);
    digitalWrite(CLOCK_PIN,LOW);
    for(int ii=0;ii<10;ii++)
        {spi_write_2(map7seg[ii]);
      digitalWrite(CLOCK_PIN,HIGH);
      digitalWrite(CLOCK_PIN,LOW);
        delay(1000);
    }
    }
}
