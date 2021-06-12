#define IRsensor 2
#define buzz 5
const int un=105;//duration of one unit in ms with 5% correction
void setup()
{
  pinMode(IRsensor, INPUT);
  pinMode(buzz,OUTPUT);
  Serial.begin(9600);
}
int readPin = 0/*/input signal*/, tap = 1;//flag for change in input signal state
int sta=0,sto=0,diff=0,osta=0,odiff=0;//time markers
char input/*morse code signal*/, message;//final translated character
String morlet="";//string of morse code signal sequence making an english character

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

void loop()//contol starts here: controls delay between iterations
{
  readPin=digitalRead(IRsensor);
  dtime(readPin);
  delay(un);
}
void dtime(int value)//classifies input signal based on type and duration. value=readPin
{
    if((tap==1)&&(value==0))
{ 
  sta=millis();
  tone(buzz,1000);
  tap=0;
  odiff=osta-sto;
  //Serial.print("space size=");Serial.println(odiff);
  if(odiff>=3*un&&odiff<7*un)
  Serial.print(input=' ');
  if(odiff>=7*un)
  Serial.print(input='/');
}
  if((tap==0)&&(value==1))
{
  sto=millis();
  noTone(buzz);
  tap=1;
  diff=sto-sta;
  //Serial.print("ditda size=");Serial.println(diff);
  if(diff<3*un)
  Serial.print(input='.');
  if(diff>=3*un)
  Serial.print(input='-');
}
  if((tap==1)&&(value==1))
  osta=millis();
  
  generate(input);
}

void generate(char morsein)//builds morse code signal sequence. morsein=input
{
  switch (morsein)
  {
    case ' '://terminates morse code signal sequence building, translates sequence so far and reinitializes morlet as empty string
    message=translate(morlet);
    Serial.print(message);
    morlet="";
    break;
    
    case '/':
    message=' ';
    Serial.print(message);
    morlet="";
    break;

    case '.':
    morlet+=morsein;
    break;
    
    case '-':
    morlet+=morsein;
    break;
  }
}

char translate(String morbuff)//translates morse code signal sequence by comparison with char* arrays alpha and num. morbuff=morlet
{
  char character;
  char ch[morbuff.length()];
  for (int i = 0; i < morbuff.length(); i++)//converts string morbuff to character array for comparison
  {ch[i] = morbuff.charAt(i);}
  
  for (int y=0;y<=26;y++)
  {
    if (strcmp(ch,alpha[y])==0)
    character=(char)(65+y);
  }
  for (int y=0;y<=10;y++)
  {
    if (strcmp(ch,num[y])==0)
    character=(char)(48+y);
  }
  return character;//character returned to message
}
