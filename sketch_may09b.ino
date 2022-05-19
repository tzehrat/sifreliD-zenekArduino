#include<LiquidCrystal.h>
#include<Keypad.h>
LiquidCrystal lcd(12,11,10,9,8,7);
char sifre[4]={'1','2','3','4'};
char sifre1[4];
char tus;
int i=0;
char tus_takimi[4][4]={{'1','2','3','A'},{'4','5','6','B'},{'7','8','9','C'},{'*','0','#','D'}};
byte satir_pini[4]={A0,A1,A2,A3};
byte sutun_pini[4]={A4,A5,3,2};
Keypad kpd=Keypad(makeKeymap(tus_takimi),satir_pini,sutun_pini,4,4);
void setup(){
  lcd.begin(16,2);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(4,OUTPUT);
}
void loop(){
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  tus=kpd.getKey();
  if(tus){
    sifre1[i++]=tus;
    lcd.setCursor(i,1);
    lcd.print('x');
    digitalWrite(4,HIGH);
    delay(100);
    digitalWrite(4,LOW);
  }
  if(i==4){
    delay(200);
    if(strncmp(sifre1,sifre,4)==0){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("SIFRE DOGRU");
      digitalWrite(5,HIGH);
      digitalWrite(6,LOW);
      delay(2000);
      digitalWrite(5,LOW);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("SIFRE GIRINIZ");
      i=0;
    }
    else{
      lcd.clear();
      lcd.print("SIFRE HATALI");
      digitalWrite(5,LOW);
      digitalWrite(6,HIGH);
      digitalWrite(4,HIGH);
      delay(2000);
      digitalWrite(4,LOW);
      lcd.clear();
      lcd.print("SIFRE GIRINIZ");
      i=0;
    }
  }
}
