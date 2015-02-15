#include <Arduino.h>

void setup();
void loop();
#line 1 "src/sketch.ino"
/* --------------------------------
     温度計測（0℃〜100℃）
     明るさ測定(0~1023)-明るいと抵抗値が上がる-
 --------------------------------- */
float a_in_lm35;          // アナログ入力値(0〜203)
int a_in_cds;          // アナログ入力値
int temp_c = 0;  // 摂氏値( ℃ )
int count;

String line = "------------------------";
char trans[20]; 

void setup(){
    Serial.begin(9600);  // シリアル通信速度
}

void loop(){
    char *json = &trans[0];
    // アナログピンから計測値を取得(0〜203)
    a_in_lm35 = analogRead(0);
    a_in_cds = analogRead(1);
    // 入力値を摂氏に換算
    temp_c = ((5 * a_in_lm35) / 1024) * 100;
    /********そのまま出力***********
    // 改行しながら出力
    Serial.print("temperature: ");
    Serial.println(temp_c);
    Serial.print("     bright: ");
    Serial.println(a_in_cds);
   // ******************************/
   
   //jsonで書き出し
    sprintf(json, "{\"no\":%d, \"temp\":%d, \"bright\":%d}",count ,temp_c, a_in_cds);
    Serial.println(json);
    // 1000ms待機
    delay(1000);
    Serial.println(line);
    count++;
}
