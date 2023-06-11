#include <Arduino.h>

// Variaveis para armazenar os pinos de cada componente conectado
const int pino_botao1 = 7;
const int pino_botao2 = 8;
const int pino_botao3 = 9;

const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int gS = 415;
const int a = 440;
const int aS = 455;
const int b = 466;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 784;
const int gSH = 830;
const int aH = 880;

const int pino_buzzer = 10; 
const int pino_led1 = 11;
const int pino_led2 = 12;
const int pino_led3 = 13;
//Referencia das notas http://home.mit.bme.hu/~bako/tonecalc/tonecalc.htm

void setup(){
  // Configura os pinos
  pinMode(pino_botao1, INPUT_PULLUP); 
  pinMode(pino_botao2, INPUT_PULLUP); 
  pinMode(pino_botao3, INPUT_PULLUP); 
  pinMode(pino_buzzer, OUTPUT); 
  pinMode(pino_led1, OUTPUT); 
  pinMode(pino_led2, OUTPUT); 
  pinMode(pino_led3, OUTPUT); 
}

void beep (int frequencyInHertz, long timeInMilliseconds, int ledPin)
{
    digitalWrite(ledPin, HIGH);
    //LED acompanhando notas tocas

    int x;
    long delayAmount = (long)(1000000/frequencyInHertz);
    long loopTime = (long)((timeInMilliseconds*1000)/(delayAmount*2));
    for (x=0;x<loopTime;x++)
    {
        digitalWrite(pino_buzzer,HIGH);
        delayMicroseconds(delayAmount);

        digitalWrite(pino_buzzer,LOW);
        delayMicroseconds(delayAmount);
    }

    digitalWrite(ledPin, LOW);


    delay(20);
    //a little delay to make all notes sound separate
}

void march()
{
    //for the sheet music see:
    //http://www.musicnotes.com/sheetmusic/mtd.asp?ppn=MN0016254
    //this is just a translation of said sheet music to frequencies / time in ms
    //used 500 ms for a quart note

    beep(a, 500, pino_led1);
    beep(a, 500, pino_led1);
    beep(a, 500, pino_led1);
    beep(f, 350, pino_led2);
    beep(cH, 150, pino_led3);

    beep(a, 500, pino_led1);
    beep(f, 350, pino_led2);
    beep(cH, 150, pino_led3);
    beep(a, 1000, pino_led1);
    //first bit

    beep(eH, 500, pino_led3);
    beep(eH, 500, pino_led3);
    beep(eH, 500, pino_led3);
    beep(fH, 350, pino_led2);
    beep(cH, 150, pino_led3);

    beep(gS, 500, pino_led3);
    beep(f, 350, pino_led2);
    beep(cH, 150, pino_led3);
    beep(a, 1000, pino_led1);
    //second bit...

    beep(aH, 500, pino_led1);
    beep(a, 350, pino_led1);
    beep(a, 150, pino_led1);
    beep(aH, 500, pino_led1);
    beep(gSH, 250, pino_led3);
    beep(gH, 250, pino_led3);

    beep(fSH, 125, pino_led2);
    beep(fH, 125, pino_led2);
    beep(fSH, 250, pino_led2);
    delay(250);
    beep(aS, 250, pino_led1);
    beep(dSH, 500, pino_led3);
    beep(dH, 250, pino_led3);
    beep(cSH, 250, pino_led3);
    //start of the interesting bit

    beep(cH, 125, pino_led3);
    beep(b, 125, pino_led3);
    beep(cH, 250, pino_led3);
    delay(250);
    beep(f, 125, pino_led2);
    beep(gS, 500, pino_led3);
    beep(f, 375, pino_led2);
    beep(a, 125, pino_led1);

    beep(cH, 500, pino_led3);
    beep(a, 375, pino_led1);
    beep(cH, 125, pino_led3);
    beep(eH, 1000, pino_led3);
    //more interesting stuff (this doesn't quite get it right somehow)

    beep(aH, 500, pino_led1);
    beep(a, 350, pino_led1);
    beep(a, 150, pino_led1);
    beep(aH, 500, pino_led1);
    beep(gSH, 250, pino_led3);
    beep(gH, 250, pino_led3);

    beep(fSH, 125, pino_led2);
    beep(fH, 125, pino_led2);
    beep(fSH, 250, pino_led2);
    delay(250);
    beep(aS, 250, pino_led1);
    beep(dSH, 500, pino_led3);
    beep(dH, 250, pino_led3);
    beep(cSH, 250, pino_led3);
    //repeat... repeat

    beep(cH, 125, pino_led3);
    beep(b, 125, pino_led3);
    beep(cH, 250, pino_led3);
    delay(250);
    beep(f, 250, pino_led2);
    beep(gS, 500, pino_led3);
    beep(f, 375, pino_led2);
    beep(cH, 125, pino_led3);

    beep(a, 500, pino_led1);
    beep(f, 375, pino_led2);
    beep(c, 125, pino_led3);
    beep(a, 1000, pino_led1);
}

void loop(){
   march();
}