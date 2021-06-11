#define IRsensor 2
#define buzz 5
const int un=105;//duration of one unit in ms with 5% correction
void setup()
{
  pinMode(IRsensor, INPUT);
  pinMode(buzz,OUTPUT);
  Serial.begin(9600);
}
int readPin = 0,tap = 1;
float sta=0,sto=0,diff=0,osta=0,odiff=0;
void loop()
{
  readPin=digitalRead(IRsensor);
  dtime(readPin);
  delay(un);
}

float dtime(int value)
{
    if((tap==1)&&(value==0))
{ 
  sta=millis();
  tone(buzz,1000);
  tap=0;
  odiff=osta-sto;
  //Serial.print("space size=");Serial.println(odiff);
  if(odiff>=3*un&&odiff<7*un)
  Serial.print(' ');
  if(odiff>=7*un)
  Serial.print('/');
}
  if((tap==0)&&(value==1))
{
  sto=millis();
  noTone(buzz);
  tap=1;
  diff=sto-sta;
  //Serial.print("ditda size=");Serial.println(diff);
  if(diff<3*un)
  Serial.print('.');
  if(diff>=3*un)
  Serial.print('-');
}
  if((tap==1)&&(value==1))
  osta=millis();
}
