
  #define DEBUG 1
  
  /*Key Mappings*/
  #define mapb00000 '?'
  #define mapb00001 ' '
  #define mapb00010 'o'
  #define mapb00011 '\n'
  #define mapb00100 'e'
  #define mapb00101 'l'
  #define mapb00110 'n'
  #define mapb00111 ','
  #define mapb01000 't'
  #define mapb01001 'u'
  #define mapb01010 'i'
  #define mapb01011 'g'
  #define mapb01100 'h'
  #define mapb01101 'f'
  #define mapb01110 'y'
  #define mapb01111 '.'
  #define mapb10000 '\b'
  #define mapb10001 's'
  #define mapb10010 'r'
  #define mapb10011 '?'
  #define mapb10100 'd'
  #define mapb10101 '?'
  #define mapb10110 '?'
  #define mapb10111 'p'
  #define mapb11000 'a'
  #define mapb11001 'c'
  #define mapb11010 'w'
  #define mapb11011 '?'
  #define mapb11100 'm'
  #define mapb11101 'v'
  #define mapb11110 'b'
#define mapb11111 '?'
  
char binMap[] = {mapb00000, mapb00001, mapb00010, mapb00011, mapb00100, mapb00101, mapb00110, mapb00111, 
                   mapb01000, mapb01001, mapb01010, mapb01011, mapb01100, mapb01101, mapb01110, mapb01111, 
                   mapb10000, mapb10001, mapb10010, mapb10011, mapb10100, mapb10101, mapb10110, mapb10111, 
                   mapb11000, mapb11001, mapb11010, mapb11011, mapb11100, mapb11101, mapb11110, mapb11111};
               
byte reqChar = 0x00;     

#define LOOP_DELAY 5

#define outLedPin RED_LED
#define loopStartLedPin GREEN_LED

#define bit0BtnPin P3_2
#define bit1BtnPin P6_6
#define bit2BtnPin P1_6
#define bit3BtnPin P3_3
#define biBtnPin P3_4

byte started = 0x00;
int bit0State = 0, bit1State = 0, bit2State = 0, bit3State = 0, bit4State = 0;
int bit0HasPressed = 0, bit1HasPressed = 0, bit2HasPressed = 0, bit3HasPressed = 0, bit4HasPressed = 0;

void setup() {
  // put your setup code here, to run once:
  if (DEBUG) {
    Serial.begin(9600);
  }

  pinMode(outLedPin, OUTPUT);
  pinMode(loopStartLedPin, OUTPUT);

  pinMode(bit0BtnPin, INPUT);
  pinMode(bit1BtnPin, INPUT);
  pinMode(bit2BtnPin, INPUT);
  pinMode(bit3BtnPin, INPUT);
  pinMode(bit4BtnPin, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(loopStartLedPin, HIGH); 
  bit0State = digitalRead(bit0BtnPin);
  bit1State = digitalRead(bit1BtnPin);
  bit2State = digitalRead(bit2BtnPin);
  bit3State = digitalRead(bit3BtnPin);
  bit4State = digitalRead(bit4BtnPin);

  if (bit0State == HIGH && !bit0HasPressed) {
     reqChar ^= 0b1;
     bit0HasPressed = 1;
     started = 1;
  }

  if (bit1State == HIGH && !bit1HasPressed) {
    reqChar ^= 0b10;
    bit1HasPressed = 1;
    started = 1;
  }
  
  if (bit2State == HIGH && !bit2HasPressed) {
    reqChar ^= 0b100;
    bit2HasPressed = 1;
    started = 1;
  }

  if (bit3State == HIGH && !bit3HasPressed) {
    reqChar ^= 0b1000;
    bit3HasPressed = 1;
    started = 1;
  }

  if (bit4State == HIGH && !bit4HasPressed) {
    reqChar ^= 0b10000;
    bit4HasPressed = 1;
    started = 1;
  }
  

  if (!bit0State && !bit1State && !bit2State && !bit3State && !bit4State && started == 1) {
    if(DEBUG) {
      Serial.print(binMap[reqChar]);
    }
    bit0HasPressed = 0;
    bit1HasPressed = 0;
    bit2HasPressed = 0;
    bit3HasPressed = 0;
    bit4HasPressed = 0;
    started = 0;
    reqChar &= 0;
  }

  if(started) {
    digitalWrite(outLedPin, HIGH); 
  } else {
    digitalWrite(outLedPin, LOW); 
  }
  
  
  delay(LOOP_DELAY);  
}
