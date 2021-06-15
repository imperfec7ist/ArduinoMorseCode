#define IRsensor 2
#define buzz 5
const int un=105;//duration of one unit in ms with 5% correction
void setup()
{
  pinMode(IRsensor, INPUT);
  pinMode(buzz,OUTPUT);
  Serial.begin(9600);
}
int readPin = 0,tap = 1,codeflag=1;
float sta=0,sto=0,diff=0,osta=0,odiff=0;
char morsechar;
String morlet, message;

//Following are arrays defining alphabet and number positions relative to their ASCII values
char alpha[26][5]=    
    {
    ".-",   //A
    "-...", //B
    "-.-.", //C
    "-..",  //D
    ".",    //E
    "..-.", //F
    "--.",  //G
    "....", //H
    "..",   //I
    ".---", //J
    "-.-",  //K
    ".-..", //L
    "--",   //M
    "-.",   //N
    "---",  //O
    ".--.", //P
    "--.-", //Q
    ".-.",  //R
    "...",  //S
    "-",    //T
    "..-",  //U
    "...-", //V
    ".--",  //W
    "-..-", //X
    "-.--", //Y
    "--.." //Z
    };

char num[10][6] = 
    {
    "-----", //0
    ".----", //1
    "..---", //2
    "...--", //3
    "....-", //4
    ".....", //5
    "-....", //6
    "--...", //7
    "---..", //8
    "----." //9
    };

void loop()
{
  readPin=digitalRead(IRsensor);
  classify(readPin);
  delay(un);
}

char classify(int value)
{
  char input;
    if((tap==1)&&(value==0))
{ 
  sta=millis();
  tone(buzz,1000);
  tap=0;
  odiff=osta-sto;
  //Serial.print("space size=");Serial.println(odiff);
  if(odiff>=3*un&&odiff<7*un)
  {
    message=translate(morlet);
    //Serial.print(message);
    //Serial.print(morlet);
    morlet="";
  }
  if(odiff>=7*un)
  {
    message=(translate(morlet))+' ';
    //Serial.print(message);
    //Serial.print(morlet);
    morlet="";
  }
}
  if((tap==0)&&(value==1))
{
  sto=millis();
  noTone(buzz);
  tap=1;
  diff=sto-sta;
  //Serial.print("ditda size=");Serial.println(diff);
  if(diff<3*un)
  {/*Serial.print*/(morlet+='.');}
  if(diff>=3*un)
  {/*Serial.print*/(morlet+='-');}
}
  if((tap==1)&&(value==1))
  osta=millis();
}

char translate(String morbuff)//translates morse code signal sequence by comparison with char* arrays alpha and num. morbuff=morlet
{
  char character;
  //char ch[morbuff.length()];
  //for (int i = 0; i < morbuff.length(); i++)//converts string morbuff to character array for comparison
  //{ch[i] = morbuff.charAt(i);}
  
  for (int y=0;y<26;y++)
  {
    if (morbuff==alpha[y])
    {
    character=65+y;
    Serial.print(character);
    }
  }
  for (int y=0;y<10;y++)
  {
    if (morbuff==num[y])
    {
    character=48+y;
    Serial.print(character);
    }
  }
  return character;//character returned to message
}
