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
float sta=0,sto=0,diff=0,odiff=0;
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
  odiff=sta-sto;
  Serial.print("space size=");Serial.println(odiff);
}
  if((tap==0)&&(value==1))
{
  sto=millis();
  noTone(buzz);
  tap=1;
  Serial.print("ditda size=");Serial.println(diff=sto-sta);
}
}
