/*
  EFY PC OsciloScope
  Read A0 and send to UART at 115200.  

  Read the voltages as fast as possible and send to serial port.
  115200 baud pushes each byte at around 85us. 
  But the default ADC config by Arduino gives ADC at 116us. so here ADC config with additional lines of code and get samples faster than 85us.
  
  Data throughput is decided by the serial baud rate
  @ 115.2k baud we can get 12kSps
   
  Created on 18th Oct 2016
  by Balaji ramalingam, Robert Bosch, Banagalore
  Balajir@in.bosch.com
 
 */

// These constants won't change.  They're used to give names
// to the pins used:
const int analogInPin1 = A0;  // Analog input pin that the potentiometer is attached to
static int ctr,flag_tog;
static unsigned char adcval;

void setup()
{
  Serial.begin(115200);   //bits/sec
  
  pinMode(13, OUTPUT);

  ADCSRA = 0;             // clear ADCSRA register
  ADCSRB = 0;             // clear ADCSRB register
  ADMUX |= (0 & 0x07);    // set A0 analog input pin
  ADMUX |= (1 << REFS0);  // set reference voltage
  ADMUX |= (1 << ADLAR);  // left align ADC value to 8 bits from ADCH register

  // sampling rate is [ADC clock] / [prescaler] / [conversion clock cycles]
  ADCSRA |= (1 << ADPS2);                     // 16 prescaler for 76.9 KHz


  ADCSRA |= (1 << ADATE); // enable auto trigger
  ADCSRA |= (1 << ADIE);  // enable interrupts when measurement complete
  ADCSRA |= (1 << ADEN);  // enable ADC
  ADCSRA |= (1 << ADSC);  // start ADC measurements
}

ISR(ADC_vect)     // interupts the hardware to do its function then resumes the hardware
{
  adcval = ADCH;  // read 8 bit value from ADC
}
  
void loop()
{
  Serial.write(adcval);
  
  // Following code to generate ref signal at pin 13 @ 50HZ. You can connect A0 to see the waveform in PCScope.exe
  ctr++;
  if(ctr>117) //117=10.03ms
  {
   ctr=0; 
   flag_tog = !flag_tog; 
   digitalWrite(13, flag_tog);
  }
}
