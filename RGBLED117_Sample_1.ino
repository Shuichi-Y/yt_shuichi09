/* 
 * 8ΦLED(マイコン内蔵)のSW4_サンプル_１
 * 211021
 *  
*/

#include <Adafruit_NeoPixel.h>

#define RGBLED1_OUTPIN    2  //点灯出力
#define NUMLED 117 // LEDの個数は1。数珠つなぎに複数個のLEDをつなげることも可能
#define SW_1 4               // 4番ピンをSW入力_アリガトウ
#define SW_2 5               // 5番ピンをSW入力_オハヨウ
#define SW_3 6               // 6番ピンをSW入力_ガンバレ
#define SW_4 7               // 7番ピンをSW入力_変色
#define SW_5 8               // 8番ピンをSW入力_白
#define SW_6 9               // 9番ピンをSW入力_予備

// RGBLEDのライブラリを生成する
Adafruit_NeoPixel RGBLED1 = Adafruit_NeoPixel(NUMLED,RGBLED1_OUTPIN, NEO_RGB + NEO_KHZ800);

void setup() {
      RGBLED1.begin();   // NeoPixelのLEDの初期化
      pinMode(SW_1,INPUT_PULLUP);         // 入力ピンの設定
      pinMode(SW_2,INPUT_PULLUP);         // 入力ピンの設定
      pinMode(SW_3,INPUT_PULLUP);         // 入力ピンの設定
      pinMode(SW_4,INPUT_PULLUP);         // 入力ピンの設定
      pinMode(SW_5,INPUT_PULLUP);         // 入力ピンの設定
      pinMode(SW_6,INPUT_PULLUP);         // 入力ピンの設定
      
      RGBLED1.setBrightness(30) ;         // 明るさの指定
      int tenmetu = 50 ;                 // 点灯時間
      
      for (int i=0; i<117; i++)            // RGBLEDテスト
        {
          RGBLED1.setPixelColor(i,255,0,0) ;         // 赤
          RGBLED1.show() ;                           // LEDにデータを送り出す
          delay(tenmetu);
        }
       for (int i=116; i>-1; i--)            // RGBLEDテスト
        {
          RGBLED1.setPixelColor(i,0,255,0) ;         // 緑
          RGBLED1.show() ;                           // LEDにデータを送り出す
          delay(tenmetu);
        }
        for (int i=0; i<117; i++)            // RGBLEDテスト
        {
          RGBLED1.setPixelColor(i,0,0,255) ;         // 青
          RGBLED1.show() ;                           // LEDにデータを送り出す
          delay(tenmetu);
        }
        for (int i=116; i>-1; i--)            // RGBLEDテスト
        {
          RGBLED1.setPixelColor(i,0,0,0) ;           // 無色
          RGBLED1.show() ;                           // LEDにデータを送り出す
          delay(tenmetu);
        }
      }
      

void loop() {

      int dt_003 = 30 ;  //点滅時間
      int dt_01 = 100 ;  //点滅時間
      int dt_02 = 200 ;  //点滅時間
      int dt_03 = 300 ;  //点滅時間
      int dt_05 = 500 ;  //点滅時間
      int dt_07 = 700 ;  //点滅時間
      int dt_10 = 1000 ;  //点滅時間
      int dt_20 = 2000 ;  //点滅時間
      int dt_30 = 3000 ;  //点滅時間
      int dt_50 = 5000 ;  //点滅時間
      
      int colorless[3] = {0, 0, 0};
      int red[3] = {255, 0, 0};
      int green[3] = {0, 255, 0};
      int blue[3] = {0, 0, 255};
      int yellow[3] = {160, 220, 0};
      int magenta[3] = {160, 0, 220};
      int cyan[3] = {0, 255, 255};
      int white[3] = {150, 255, 255};
      int orange[3] = {255, 85, 0};
      int pink[3] = {255, 91, 172};
  
      RGBLED1.setBrightness(30) ;                                               // 明るさの指定

      if (digitalRead(SW_1)==HIGH && digitalRead(SW_2)==HIGH && digitalRead(SW_3)==HIGH && digitalRead(SW_4)==HIGH && digitalRead(SW_5)==HIGH && digitalRead(SW_6)==HIGH){
        for (int i=0; i<117; i++)                                               // 点灯無し
        {
        RGBLED1.setPixelColor(i, colorless[0], colorless[1], colorless[2]) ;   // 無色
        }
        RGBLED1.show() ;
        delay(dt_05);
        
      } else if (digitalRead(SW_1)==LOW && digitalRead(SW_2)==HIGH && digitalRead(SW_3)==HIGH && digitalRead(SW_4)==HIGH && digitalRead(SW_5)==HIGH && digitalRead(SW_6)==HIGH){
        
        int sptime = dt_03 ;
        
        for (int j=0; j<117; j++)                                              // 全部を白設定
        {
        RGBLED1.setPixelColor(j, white[0], white[1], white[2]) ;              // 白
        }
        RGBLED1.show() ;
        delay(dt_05);
        for (int k=0; k<9; k++)                                              
        {
        RGBLED1.setPixelColor(k, orange[0], orange[1], orange[2]) ;
        RGBLED1.show() ;
        delay(sptime);
        }
        for (int k=9; k<18; k++)                                              
        {
        RGBLED1.setPixelColor(k, cyan[0], cyan[1], cyan[2]) ;
        RGBLED1.show() ;
        delay(sptime);
        }
        for (int k=99; k<108; k++)                                              
        {
        RGBLED1.setPixelColor(k, magenta[0], magenta[1], magenta[2]) ;
        RGBLED1.show() ;
        delay(sptime);
        }
        for (int k=108; k<117; k++)                                              
        {
        RGBLED1.setPixelColor(k, pink[0], pink[1], pink[2]) ;
        RGBLED1.show() ;
        delay(sptime);
        }
        RGBLED1.setPixelColor(18, red[0], red[1], red[2]) ;                    // ９×９の４隅から色変更(反時計回り)
        RGBLED1.setPixelColor(26, green[0], green[1], green[2]) ;
        RGBLED1.setPixelColor(90, yellow[0], yellow[1], yellow[2]) ;
        RGBLED1.setPixelColor(98, blue[0], blue[1], blue[2]) ;
        RGBLED1.show() ; 
        delay(sptime);
        RGBLED1.setPixelColor(35, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(25, green[0], green[1], green[2]) ;
        RGBLED1.setPixelColor(91, yellow[0], yellow[1], yellow[2]) ;
        RGBLED1.setPixelColor(81, blue[0], blue[1], blue[2]) ;
        RGBLED1.show() ; 
        delay(sptime);
        RGBLED1.setPixelColor(36, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(24, green[0], green[1], green[2]) ;
        RGBLED1.setPixelColor(92, yellow[0], yellow[1], yellow[2]) ;
        RGBLED1.setPixelColor(80, blue[0], blue[1], blue[2]) ;
        RGBLED1.show() ; 
        delay(sptime);
        RGBLED1.setPixelColor(53, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(23, green[0], green[1], green[2]) ;
        RGBLED1.setPixelColor(93, yellow[0], yellow[1], yellow[2]) ;
        RGBLED1.setPixelColor(63, blue[0], blue[1], blue[2]) ;
        RGBLED1.show() ; 
        delay(sptime);
        RGBLED1.setPixelColor(54, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(22, green[0], green[1], green[2]) ;
        RGBLED1.setPixelColor(94, yellow[0], yellow[1], yellow[2]) ;
        RGBLED1.setPixelColor(62, blue[0], blue[1], blue[2]) ;
        RGBLED1.show() ; 
        delay(sptime);
        RGBLED1.setPixelColor(71, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(21, green[0], green[1], green[2]) ;
        RGBLED1.setPixelColor(95, yellow[0], yellow[1], yellow[2]) ;
        RGBLED1.setPixelColor(45, blue[0], blue[1], blue[2]) ;
        RGBLED1.show() ; 
        delay(sptime);
        RGBLED1.setPixelColor(72, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(20, green[0], green[1], green[2]) ;
        RGBLED1.setPixelColor(96, yellow[0], yellow[1], yellow[2]) ;
        RGBLED1.setPixelColor(44, blue[0], blue[1], blue[2]) ;
        RGBLED1.show() ; 
        delay(sptime);
        RGBLED1.setPixelColor(89, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(19, green[0], green[1], green[2]) ;
        RGBLED1.setPixelColor(97, yellow[0], yellow[1], yellow[2]) ;
        RGBLED1.setPixelColor(27, blue[0], blue[1], blue[2]) ;
        RGBLED1.show() ; 
        delay(sptime);
        RGBLED1.setPixelColor(88, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(34, green[0], green[1], green[2]) ;
        RGBLED1.setPixelColor(82, yellow[0], yellow[1], yellow[2]) ;
        RGBLED1.setPixelColor(28, blue[0], blue[1], blue[2]) ;
        RGBLED1.show() ; 
        delay(sptime);
        RGBLED1.setPixelColor(87, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(37, green[0], green[1], green[2]) ;
        RGBLED1.setPixelColor(79, yellow[0], yellow[1], yellow[2]) ;
        RGBLED1.setPixelColor(29, blue[0], blue[1], blue[2]) ;
        RGBLED1.show() ; 
        delay(sptime);
        RGBLED1.setPixelColor(86, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(52, green[0], green[1], green[2]) ;
        RGBLED1.setPixelColor(64, yellow[0], yellow[1], yellow[2]) ;
        RGBLED1.setPixelColor(30, blue[0], blue[1], blue[2]) ;
        RGBLED1.show() ; 
        delay(sptime);
        RGBLED1.setPixelColor(85, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(55, green[0], green[1], green[2]) ;
        RGBLED1.setPixelColor(61, yellow[0], yellow[1], yellow[2]) ;
        RGBLED1.setPixelColor(31, blue[0], blue[1], blue[2]) ;
        RGBLED1.show() ; 
        delay(sptime);
        RGBLED1.setPixelColor(84, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(70, green[0], green[1], green[2]) ;
        RGBLED1.setPixelColor(46, yellow[0], yellow[1], yellow[2]) ;
        RGBLED1.setPixelColor(32, blue[0], blue[1], blue[2]) ;
        RGBLED1.show() ; 
        delay(sptime);
        RGBLED1.setPixelColor(83, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(73, green[0], green[1], green[2]) ;
        RGBLED1.setPixelColor(43, yellow[0], yellow[1], yellow[2]) ;
        RGBLED1.setPixelColor(33, blue[0], blue[1], blue[2]) ;
        RGBLED1.show() ; 
        delay(sptime);
        RGBLED1.setPixelColor(78, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(74, green[0], green[1], green[2]) ;
        RGBLED1.setPixelColor(42, yellow[0], yellow[1], yellow[2]) ;
        RGBLED1.setPixelColor(38, blue[0], blue[1], blue[2]) ;
        RGBLED1.show() ; 
        delay(sptime);
        RGBLED1.setPixelColor(65, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(75, green[0], green[1], green[2]) ;
        RGBLED1.setPixelColor(41, yellow[0], yellow[1], yellow[2]) ;
        RGBLED1.setPixelColor(51, blue[0], blue[1], blue[2]) ;
        RGBLED1.show() ; 
        delay(sptime);
        RGBLED1.setPixelColor(60, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(76, green[0], green[1], green[2]) ;
        RGBLED1.setPixelColor(40, yellow[0], yellow[1], yellow[2]) ;
        RGBLED1.setPixelColor(56, blue[0], blue[1], blue[2]) ;
        RGBLED1.show() ; 
        delay(sptime);
        RGBLED1.setPixelColor(47, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(77, green[0], green[1], green[2]) ;
        RGBLED1.setPixelColor(39, yellow[0], yellow[1], yellow[2]) ;
        RGBLED1.setPixelColor(69, blue[0], blue[1], blue[2]) ;
        RGBLED1.show() ; 
        delay(sptime);
        RGBLED1.setPixelColor(48, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(66, green[0], green[1], green[2]) ;
        RGBLED1.setPixelColor(50, yellow[0], yellow[1], yellow[2]) ;
        RGBLED1.setPixelColor(68, blue[0], blue[1], blue[2]) ;
        RGBLED1.show() ; 
        delay(sptime);
        RGBLED1.setPixelColor(49, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(59, green[0], green[1], green[2]) ;
        RGBLED1.setPixelColor(57, yellow[0], yellow[1], yellow[2]) ;
        RGBLED1.setPixelColor(67, blue[0], blue[1], blue[2]) ;
        RGBLED1.show() ; 
        delay(dt_05);
        RGBLED1.setPixelColor(48, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(49, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(50, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(57, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(59, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(66, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(67, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(68, white[0], white[1], white[2]) ;  
        RGBLED1.show() ; 
        delay(sptime);
        RGBLED1.setPixelColor(38, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(39, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(40, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(41, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(42, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(47, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(51, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(56, white[0], white[1], white[2]) ;  
        RGBLED1.setPixelColor(60, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(65, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(69, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(74, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(75, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(76, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(77, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(78, white[0], white[1], white[2]) ;  
        RGBLED1.show() ; 
        delay(sptime);
        RGBLED1.setPixelColor(28, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(29, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(30, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(31, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(32, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(33, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(34, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(37, white[0], white[1], white[2]) ;  
        RGBLED1.setPixelColor(43, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(46, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(52, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(55, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(61, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(64, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(70, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(73, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(79, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(82, white[0], white[1], white[2]) ;  
        RGBLED1.setPixelColor(83, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(84, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(85, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(86, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(87, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(88, white[0], white[1], white[2]) ;
        RGBLED1.show() ; 
        delay(sptime);
        RGBLED1.setPixelColor(18, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(19, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(20, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(21, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(22, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(23, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(24, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(25, white[0], white[1], white[2]) ;  
        RGBLED1.setPixelColor(26, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(27, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(35, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(36, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(44, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(45, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(53, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(54, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(62, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(63, white[0], white[1], white[2]) ;  
        RGBLED1.setPixelColor(71, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(72, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(80, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(81, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(89, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(90, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(91, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(92, white[0], white[1], white[2]) ;  
        RGBLED1.setPixelColor(93, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(94, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(95, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(96, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(97, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(98, white[0], white[1], white[2]) ;
        RGBLED1.show() ; 
        delay(sptime);

        for (int k=0; k<9; k++)                                              
        {
        RGBLED1.setPixelColor(k, yellow[0], yellow[1], yellow[2]) ;
        RGBLED1.show() ;
        delay(sptime);
        }
        for (int k=9; k<18; k++)                                              
        {
        RGBLED1.setPixelColor(k, blue[0], blue[1], blue[2]) ;
        RGBLED1.show() ;
        delay(sptime);
        }
        for (int k=99; k<108; k++)                                              
        {
        RGBLED1.setPixelColor(k, green[0], green[1], green[2]) ;
        RGBLED1.show() ;
        delay(sptime);
        }
        for (int k=108; k<117; k++)                                              
        {
        RGBLED1.setPixelColor(k, red[0], red[1], red[2]) ; 
        RGBLED1.show() ;
        delay(sptime);
        }
        RGBLED1.setPixelColor(18, magenta[0], magenta[1], magenta[2]) ;                   // ９×９の４隅から色変更(時計回り)
        RGBLED1.setPixelColor(26, pink[0], pink[1], pink[2]) ;
        RGBLED1.setPixelColor(90, cyan[0], cyan[1], cyan[2]) ;
        RGBLED1.setPixelColor(98, orange[0], orange[1], orange[2]) ;
        RGBLED1.show() ; 
        delay(sptime);
        RGBLED1.setPixelColor(19, magenta[0], magenta[1], magenta[2]) ; 
        RGBLED1.setPixelColor(27, pink[0], pink[1], pink[2]) ;
        RGBLED1.setPixelColor(89, cyan[0], cyan[1], cyan[2]) ;
        RGBLED1.setPixelColor(97, orange[0], orange[1], orange[2]) ;
        RGBLED1.show() ; 
        delay(sptime);
        RGBLED1.setPixelColor(20, magenta[0], magenta[1], magenta[2]) ; 
        RGBLED1.setPixelColor(44, pink[0], pink[1], pink[2]) ;
        RGBLED1.setPixelColor(72, cyan[0], cyan[1], cyan[2]) ;
        RGBLED1.setPixelColor(96, orange[0], orange[1], orange[2]) ;
        RGBLED1.show() ; 
        delay(sptime);
        RGBLED1.setPixelColor(21, magenta[0], magenta[1], magenta[2]) ; 
        RGBLED1.setPixelColor(45, pink[0], pink[1], pink[2]) ;
        RGBLED1.setPixelColor(71, cyan[0], cyan[1], cyan[2]) ;
        RGBLED1.setPixelColor(95, orange[0], orange[1], orange[2]) ;
        RGBLED1.show() ; 
        delay(sptime);
        RGBLED1.setPixelColor(22, magenta[0], magenta[1], magenta[2]) ; 
        RGBLED1.setPixelColor(62, pink[0], pink[1], pink[2]) ;
        RGBLED1.setPixelColor(54, cyan[0], cyan[1], cyan[2]) ;
        RGBLED1.setPixelColor(94, orange[0], orange[1], orange[2]) ;
        RGBLED1.show() ; 
        delay(sptime);
        RGBLED1.setPixelColor(23, magenta[0], magenta[1], magenta[2]) ; 
        RGBLED1.setPixelColor(63, pink[0], pink[1], pink[2]) ;
        RGBLED1.setPixelColor(53, cyan[0], cyan[1], cyan[2]) ;
        RGBLED1.setPixelColor(93, orange[0], orange[1], orange[2]) ;
        RGBLED1.show() ; 
        delay(sptime);
        RGBLED1.setPixelColor(24, magenta[0], magenta[1], magenta[2]) ; 
        RGBLED1.setPixelColor(80, pink[0], pink[1], pink[2]) ;
        RGBLED1.setPixelColor(36, cyan[0], cyan[1], cyan[2]) ;
        RGBLED1.setPixelColor(92, orange[0], orange[1], orange[2]) ;
        RGBLED1.show() ; 
        delay(sptime);
        RGBLED1.setPixelColor(25, magenta[0], magenta[1], magenta[2]) ; 
        RGBLED1.setPixelColor(81, pink[0], pink[1], pink[2]) ;
        RGBLED1.setPixelColor(35, cyan[0], cyan[1], cyan[2]) ;
        RGBLED1.setPixelColor(91, orange[0], orange[1], orange[2]) ;
        RGBLED1.show() ; 
        delay(sptime);
        RGBLED1.setPixelColor(28, magenta[0], magenta[1], magenta[2]) ; 
        RGBLED1.setPixelColor(82, pink[0], pink[1], pink[2]) ;
        RGBLED1.setPixelColor(34, cyan[0], cyan[1], cyan[2]) ;
        RGBLED1.setPixelColor(88, orange[0], orange[1], orange[2]) ;
        RGBLED1.show() ; 
        delay(sptime);
        RGBLED1.setPixelColor(43, magenta[0], magenta[1], magenta[2]) ; 
        RGBLED1.setPixelColor(83, pink[0], pink[1], pink[2]) ;
        RGBLED1.setPixelColor(33, cyan[0], cyan[1], cyan[2]) ;
        RGBLED1.setPixelColor(73, orange[0], orange[1], orange[2]) ;
        RGBLED1.show() ; 
        delay(sptime);
        RGBLED1.setPixelColor(46, magenta[0], magenta[1], magenta[2]) ; 
        RGBLED1.setPixelColor(84, pink[0], pink[1], pink[2]) ;
        RGBLED1.setPixelColor(32, cyan[0], cyan[1], cyan[2]) ;
        RGBLED1.setPixelColor(70, orange[0], orange[1], orange[2]) ;
        RGBLED1.show() ; 
        delay(sptime);
        RGBLED1.setPixelColor(61, magenta[0], magenta[1], magenta[2]) ; 
        RGBLED1.setPixelColor(85, pink[0], pink[1], pink[2]) ;
        RGBLED1.setPixelColor(31, cyan[0], cyan[1], cyan[2]) ;
        RGBLED1.setPixelColor(55, orange[0], orange[1], orange[2]) ;
        RGBLED1.show() ; 
        delay(sptime);
        RGBLED1.setPixelColor(64, magenta[0], magenta[1], magenta[2]) ; 
        RGBLED1.setPixelColor(86, pink[0], pink[1], pink[2]) ;
        RGBLED1.setPixelColor(30, cyan[0], cyan[1], cyan[2]) ;
        RGBLED1.setPixelColor(52, orange[0], orange[1], orange[2]) ;
        RGBLED1.show() ; 
        delay(sptime);
        RGBLED1.setPixelColor(79, magenta[0], magenta[1], magenta[2]) ; 
        RGBLED1.setPixelColor(87, pink[0], pink[1], pink[2]) ;
        RGBLED1.setPixelColor(29, cyan[0], cyan[1], cyan[2]) ;
        RGBLED1.setPixelColor(37, orange[0], orange[1], orange[2]) ;
        RGBLED1.show() ; 
        delay(sptime);
        RGBLED1.setPixelColor(78, magenta[0], magenta[1], magenta[2]) ; 
        RGBLED1.setPixelColor(74, pink[0], pink[1], pink[2]) ;
        RGBLED1.setPixelColor(42, cyan[0], cyan[1], cyan[2]) ;
        RGBLED1.setPixelColor(38, orange[0], orange[1], orange[2]) ;
        RGBLED1.show() ; 
        delay(sptime);
        RGBLED1.setPixelColor(77, magenta[0], magenta[1], magenta[2]) ; 
        RGBLED1.setPixelColor(69, pink[0], pink[1], pink[2]) ;
        RGBLED1.setPixelColor(47, cyan[0], cyan[1], cyan[2]) ;
        RGBLED1.setPixelColor(39, orange[0], orange[1], orange[2]) ;
        RGBLED1.show() ; 
        delay(sptime);
        RGBLED1.setPixelColor(76, magenta[0], magenta[1], magenta[2]) ; 
        RGBLED1.setPixelColor(56, pink[0], pink[1], pink[2]) ;
        RGBLED1.setPixelColor(60, cyan[0], cyan[1], cyan[2]) ;
        RGBLED1.setPixelColor(40, orange[0], orange[1], orange[2]) ;
        RGBLED1.show() ; 
        delay(sptime);
        RGBLED1.setPixelColor(75, magenta[0], magenta[1], magenta[2]) ; 
        RGBLED1.setPixelColor(51, pink[0], pink[1], pink[2]) ;
        RGBLED1.setPixelColor(65, cyan[0], cyan[1], cyan[2]) ;
        RGBLED1.setPixelColor(41, orange[0], orange[1], orange[2]) ;
        RGBLED1.show() ; 
        delay(sptime);
        RGBLED1.setPixelColor(68, magenta[0], magenta[1], magenta[2]) ; 
        RGBLED1.setPixelColor(50, pink[0], pink[1], pink[2]) ;
        RGBLED1.setPixelColor(66, cyan[0], cyan[1], cyan[2]) ;
        RGBLED1.setPixelColor(48, orange[0], orange[1], orange[2]) ;
        RGBLED1.show() ; 
        delay(sptime);
        RGBLED1.setPixelColor(57, magenta[0], magenta[1], magenta[2]) ; 
        RGBLED1.setPixelColor(49, pink[0], pink[1], pink[2]) ;
        RGBLED1.setPixelColor(67, cyan[0], cyan[1], cyan[2]) ;
        RGBLED1.setPixelColor(59, orange[0], orange[1], orange[2]) ;
        RGBLED1.show() ; 
        delay(dt_05);
        RGBLED1.setPixelColor(48, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(49, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(50, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(57, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(59, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(66, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(67, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(68, white[0], white[1], white[2]) ;  
        RGBLED1.show() ; 
        delay(sptime);
        RGBLED1.setPixelColor(38, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(39, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(40, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(41, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(42, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(47, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(51, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(56, white[0], white[1], white[2]) ;  
        RGBLED1.setPixelColor(60, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(65, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(69, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(74, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(75, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(76, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(77, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(78, white[0], white[1], white[2]) ;  
        RGBLED1.show() ; 
        delay(sptime);
        RGBLED1.setPixelColor(28, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(29, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(30, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(31, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(32, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(33, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(34, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(37, white[0], white[1], white[2]) ;  
        RGBLED1.setPixelColor(43, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(46, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(52, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(55, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(61, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(64, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(70, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(73, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(79, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(82, white[0], white[1], white[2]) ;  
        RGBLED1.setPixelColor(83, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(84, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(85, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(86, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(87, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(88, white[0], white[1], white[2]) ;
        RGBLED1.show() ; 
        delay(sptime);
        RGBLED1.setPixelColor(18, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(19, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(20, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(21, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(22, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(23, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(24, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(25, white[0], white[1], white[2]) ;  
        RGBLED1.setPixelColor(26, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(27, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(35, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(36, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(44, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(45, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(53, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(54, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(62, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(63, white[0], white[1], white[2]) ;  
        RGBLED1.setPixelColor(71, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(72, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(80, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(81, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(89, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(90, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(91, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(92, white[0], white[1], white[2]) ;  
        RGBLED1.setPixelColor(93, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(94, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(95, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(96, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(97, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(98, white[0], white[1], white[2]) ;
        RGBLED1.show() ; 
        delay(dt_05);
        
        RGBLED1.setPixelColor(27, red[0], red[1], red[2]) ;              // 本
        RGBLED1.setPixelColor(80, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(81, red[0], red[1], red[2]) ; 
        RGBLED1.show() ; 
        delay(dt_05); 
        //RGBLED1.setPixelColor(27, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(80, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(81, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(27, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(28, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(62, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(63, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(79, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(82, red[0], red[1], red[2]) ; 
        RGBLED1.show() ; 
        delay(dt_05);
        //RGBLED1.setPixelColor(27, white[0], white[1], white[2]) ; 
        //RGBLED1.setPixelColor(28, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(62, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(63, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(79, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(82, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(27, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(28, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(29, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(45, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(61, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(64, red[0], red[1], red[2]) ;
        RGBLED1.setPixelColor(78, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(81, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(83, red[0], red[1], red[2]) ; 
        RGBLED1.show() ; 
        delay(dt_05);
        //RGBLED1.setPixelColor(27, white[0], white[1], white[2]) ;
        //RGBLED1.setPixelColor(28, white[0], white[1], white[2]) ;
        //RGBLED1.setPixelColor(29, white[0], white[1], white[2]) ;
        //RGBLED1.setPixelColor(45, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(61, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(64, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(78, white[0], white[1], white[2]) ; 
        //RGBLED1.setPixelColor(81, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(83, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(26, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(27, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(28, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(29, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(30, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(44, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(45, red[0], red[1], red[2]) ;
        RGBLED1.setPixelColor(46, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(60, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(62, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(63, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(65, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(77, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(80, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(81, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(82, red[0], red[1], red[2]) ;
        RGBLED1.setPixelColor(84, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(98, red[0], red[1], red[2]) ; 
        RGBLED1.show() ; 
        delay(dt_05);
        RGBLED1.setPixelColor(26, white[0], white[1], white[2]) ;
        //RGBLED1.setPixelColor(27, white[0], white[1], white[2]) ;
        //RGBLED1.setPixelColor(28, white[0], white[1], white[2]) ; 
        //RGBLED1.setPixelColor(29, white[0], white[1], white[2]) ;
        //RGBLED1.setPixelColor(30, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(44, white[0], white[1], white[2]) ;
        //RGBLED1.setPixelColor(45, white[0], white[1], white[2]) ;
        //RGBLED1.setPixelColor(46, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(60, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(62, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(63, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(65, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(77, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(80, white[0], white[1], white[2]) ;
        //RGBLED1.setPixelColor(81, white[0], white[1], white[2]) ;
        //RGBLED1.setPixelColor(82, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(84, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(98, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(25, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(27, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(28, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(29, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(30, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(31, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(43, red[0], red[1], red[2]) ;
        RGBLED1.setPixelColor(45, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(46, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(47, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(59, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(61, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(64, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(66, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(76, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(79, red[0], red[1], red[2]) ;
        RGBLED1.setPixelColor(81, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(82, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(83, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(85, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(97, red[0], red[1], red[2]) ; 
        RGBLED1.show() ; 
        delay(dt_05);
        RGBLED1.setPixelColor(25, white[0], white[1], white[2]) ;
        //RGBLED1.setPixelColor(27, white[0], white[1], white[2]) ;
        //RGBLED1.setPixelColor(28, white[0], white[1], white[2]) ;
        //RGBLED1.setPixelColor(29, white[0], white[1], white[2]) ; 
        //RGBLED1.setPixelColor(30, white[0], white[1], white[2]) ; 
        //RGBLED1.setPixelColor(31, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(43, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(45, white[0], white[1], white[2]) ; 
        //RGBLED1.setPixelColor(46, white[0], white[1], white[2]) ; 
        //RGBLED1.setPixelColor(47, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(59, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(61, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(64, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(66, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(76, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(79, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(81, white[0], white[1], white[2]) ; 
        //RGBLED1.setPixelColor(82, white[0], white[1], white[2]) ; 
        //RGBLED1.setPixelColor(83, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(85, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(97, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(24, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(27, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(28, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(29, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(30, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(31, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(32, red[0], red[1], red[2]) ;
        RGBLED1.setPixelColor(42, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(46, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(47, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(48, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(58, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(60, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(62, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(63, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(65, red[0], red[1], red[2]) ;
        RGBLED1.setPixelColor(67, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(75, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(78, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(82, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(83, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(84, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(86, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(96, red[0], red[1], red[2]) ; 
        RGBLED1.show() ; 
        delay(dt_05);
        RGBLED1.setPixelColor(24, white[0], white[1], white[2]) ; 
        //RGBLED1.setPixelColor(27, white[0], white[1], white[2]) ; 
        //RGBLED1.setPixelColor(28, white[0], white[1], white[2]) ; 
        //RGBLED1.setPixelColor(29, white[0], white[1], white[2]) ; 
        //RGBLED1.setPixelColor(30, white[0], white[1], white[2]) ; 
        //RGBLED1.setPixelColor(31, white[0], white[1], white[2]) ; 
        //RGBLED1.setPixelColor(32, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(42, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(46, white[0], white[1], white[2]) ; 
        //RGBLED1.setPixelColor(47, white[0], white[1], white[2]) ; 
        //RGBLED1.setPixelColor(48, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(58, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(60, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(62, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(63, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(65, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(67, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(75, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(78, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(82, white[0], white[1], white[2]) ; 
        //RGBLED1.setPixelColor(83, white[0], white[1], white[2]) ; 
        //RGBLED1.setPixelColor(84, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(86, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(96, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(23, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(27, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(28, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(29, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(30, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(31, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(32, red[0], red[1], red[2]) ;
        RGBLED1.setPixelColor(33, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(41, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(47, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(48, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(49, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(57, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(59, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(61, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(64, red[0], red[1], red[2]) ;
        RGBLED1.setPixelColor(66, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(68, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(74, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(77, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(80, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(81, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(83, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(84, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(85, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(87, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(95, red[0], red[1], red[2]) ; 
        RGBLED1.show() ; 
        delay(dt_05);
        RGBLED1.setPixelColor(23, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(27, white[0], white[1], white[2]) ; 
        //RGBLED1.setPixelColor(28, white[0], white[1], white[2]) ; 
        //RGBLED1.setPixelColor(29, white[0], white[1], white[2]) ; 
        //RGBLED1.setPixelColor(30, white[0], white[1], white[2]) ; 
        //RGBLED1.setPixelColor(31, white[0], white[1], white[2]) ; 
        //RGBLED1.setPixelColor(32, white[0], white[1], white[2]) ;
        //RGBLED1.setPixelColor(33, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(41, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(47, white[0], white[1], white[2]) ; 
        //RGBLED1.setPixelColor(48, white[0], white[1], white[2]) ; 
        //RGBLED1.setPixelColor(49, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(57, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(59, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(61, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(64, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(66, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(68, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(74, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(77, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(80, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(81, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(83, white[0], white[1], white[2]) ; 
        //RGBLED1.setPixelColor(84, white[0], white[1], white[2]) ; 
        //RGBLED1.setPixelColor(85, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(87, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(95, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(22, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(28, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(29, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(30, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(31, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(32, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(33, red[0], red[1], red[2]) ;
        RGBLED1.setPixelColor(34, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(40, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(48, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(49, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(50, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(56, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(58, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(60, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(65, red[0], red[1], red[2]) ;
        RGBLED1.setPixelColor(67, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(69, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(73, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(76, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(79, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(82, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(84, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(85, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(86, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(88, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(94, red[0], red[1], red[2]) ; 
        RGBLED1.show() ; 
        delay(dt_20);
        RGBLED1.setPixelColor(22, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(28, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(29, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(30, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(31, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(32, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(33, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(34, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(40, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(48, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(49, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(50, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(56, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(58, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(60, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(65, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(67, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(69, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(73, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(76, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(79, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(82, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(84, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(85, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(86, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(88, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(94, white[0], white[1], white[2]) ; 
        RGBLED1.show() ; 
        delay(dt_05) ;
 
        RGBLED1.setPixelColor(27, red[0], red[1], red[2]) ;              // 日
        RGBLED1.setPixelColor(44, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(45, red[0], red[1], red[2]) ;  
        RGBLED1.setPixelColor(62, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(63, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(80, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(81, red[0], red[1], red[2]) ; 
        RGBLED1.show() ; 
        delay(dt_05) ;
        RGBLED1.setPixelColor(44, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(45, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(63, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(80, white[0], white[1], white[2]) ; 
        //RGBLED1.setPixelColor(27, red[0], red[1], red[2]) ; 
        //RGBLED1.setPixelColor(62, red[0], red[1], red[2]) ; 
        //RGBLED1.setPixelColor(81, red[0], red[1], red[2]) ;  
        RGBLED1.setPixelColor(28, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(43, red[0], red[1], red[2]) ;  
        RGBLED1.setPixelColor(46, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(61, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(64, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(79, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(82, red[0], red[1], red[2]) ; 
        RGBLED1.show() ; 
        delay(dt_05);
        RGBLED1.setPixelColor(43, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(46, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(64, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(79, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(29, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(42, red[0], red[1], red[2]) ;  
        RGBLED1.setPixelColor(47, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(60, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(65, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(78, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(83, red[0], red[1], red[2]) ; 
        RGBLED1.show() ; 
        delay(dt_05);
        RGBLED1.setPixelColor(42, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(47, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(65, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(78, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(30, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(41, red[0], red[1], red[2]) ;  
        RGBLED1.setPixelColor(48, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(59, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(66, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(77, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(84, red[0], red[1], red[2]) ; 
        RGBLED1.show() ; 
        delay(dt_05);
        RGBLED1.setPixelColor(41, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(48, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(66, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(77, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(31, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(40, red[0], red[1], red[2]) ;  
        RGBLED1.setPixelColor(49, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(58, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(67, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(76, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(85, red[0], red[1], red[2]) ;
        RGBLED1.setPixelColor(44, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(45, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(63, red[0], red[1], red[2]) ;  
        RGBLED1.setPixelColor(80, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(81, red[0], red[1], red[2]) ; 
        RGBLED1.show() ; 
        delay(dt_05);
        RGBLED1.setPixelColor(27, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(44, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(45, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(62, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(63, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(80, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(81, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(40, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(49, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(67, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(76, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(32, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(39, red[0], red[1], red[2]) ;  
        RGBLED1.setPixelColor(50, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(57, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(68, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(75, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(86, red[0], red[1], red[2]) ;
        RGBLED1.setPixelColor(43, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(46, red[0], red[1], red[2]) ;  
        RGBLED1.setPixelColor(64, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(79, red[0], red[1], red[2]) ; 
        RGBLED1.show() ; 
        delay(dt_05);
        RGBLED1.setPixelColor(28, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(43, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(46, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(61, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(64, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(79, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(82, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(39, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(50, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(68, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(75, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(33, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(38, red[0], red[1], red[2]) ;  
        RGBLED1.setPixelColor(51, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(56, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(69, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(74, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(87, red[0], red[1], red[2]) ;
        RGBLED1.setPixelColor(42, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(47, red[0], red[1], red[2]) ;  
        RGBLED1.setPixelColor(65, red[0], red[1], red[2]) ; 
        RGBLED1.setPixelColor(78, red[0], red[1], red[2]) ; 
        RGBLED1.show() ; 
        delay(dt_20);
        RGBLED1.setPixelColor(29, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(30, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(31, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(32, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(33, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(38, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(42, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(47, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(51, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(56, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(57, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(58, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(59, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(60, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(65, white[0], white[1], white[2]) ;
        RGBLED1.setPixelColor(69, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(74, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(78, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(83, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(84, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(85, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(86, white[0], white[1], white[2]) ; 
        RGBLED1.setPixelColor(87, white[0], white[1], white[2]) ; 
        RGBLED1.show() ; 
        delay(dt_05);
// ノ
        RGBLED1.setPixelColor(81, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_05) ;
        RGBLED1.setPixelColor(81, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(80, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(82, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_05) ;
        RGBLED1.setPixelColor(80, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(82, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(27, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(44, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(45, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(62, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(63, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(79, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(83, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_05) ;
        RGBLED1.setPixelColor(27, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(44, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(45, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(62, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(63, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(79, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(83, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(28, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(43, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(46, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(61, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(64, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(78, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(84, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_05) ;
        RGBLED1.setPixelColor(28, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(43, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(46, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(61, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(64, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(78, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(84, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(29, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(42, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(47, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(60, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(65, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(77, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(85, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_05) ;
        RGBLED1.setPixelColor(29, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(42, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(47, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(60, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(65, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(77, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(85, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(30, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(41, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(48, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(59, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(66, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(76, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(86, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_20) ;
        RGBLED1.setPixelColor(30, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(41, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(48, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(59, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(66, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(76, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(86, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_05) ;
// オ
        RGBLED1.setPixelColor(44, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(80, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_05) ;
        RGBLED1.setPixelColor(80, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(43, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(63, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(79, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_05) ;
        RGBLED1.setPixelColor(63, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(79, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(42, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(62, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(64, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(78, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_05) ;
        RGBLED1.setPixelColor(62, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(64, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(78, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(27, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(41, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(45, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(61, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(62, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(63, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(65, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(77, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(80, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(81, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_05) ;
        RGBLED1.setPixelColor(27, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(45, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(62, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(63, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(65, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(77, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(80, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(81, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(28, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(40, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(46, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(60, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(64, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(66, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(76, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(79, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(82, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_05) ;
        RGBLED1.setPixelColor(28, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(44, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(46, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(61, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(66, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(64, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(76, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(79, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(82, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(29, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(39, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(47, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(59, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(65, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(67, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(75, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(78, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(83, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_05) ;
        RGBLED1.setPixelColor(29, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(43, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(47, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(60, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(65, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(67, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(75, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(78, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(83, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(30, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(38, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(48, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(58, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(66, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(68, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(74, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(77, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(84, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_20) ;
        RGBLED1.setPixelColor(30, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(38, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(39, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(40, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(41, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(42, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(48, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(58, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(59, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(66, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(68, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(74, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(77, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(84, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_05) ;
// ス
        RGBLED1.setPixelColor(44, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(81, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_05) ;
        RGBLED1.setPixelColor(81, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(43, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(80, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(82, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_05) ;
        RGBLED1.setPixelColor(80, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(82, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(42, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(63, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(79, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(83, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_05) ;
        RGBLED1.setPixelColor(63, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(79, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(83, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(41, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(62, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(64, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(78, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(80, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(84, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_05) ;
        RGBLED1.setPixelColor(62, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(64, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(78, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(80, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(84, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(40, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(45, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(61, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(65, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(77, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(79, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(81, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(85, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_05) ;
        RGBLED1.setPixelColor(44, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(45, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(61, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(65, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(77, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(79, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(81, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(85, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(39, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(46, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(60, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(66, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(76, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(78, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(82, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(86, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_05) ;
        RGBLED1.setPixelColor(43, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(46, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(60, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(66, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(76, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(78, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(82, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(86, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(38, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(47, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(59, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(67, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(75, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(77, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(83, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(87, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_20) ;
        RGBLED1.setPixelColor(38, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(39, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(40, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(41, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(42, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(47, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(59, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(67, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(75, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(77, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(83, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(87, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_05) ;
// ス
        RGBLED1.setPixelColor(44, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(81, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_05) ;
        RGBLED1.setPixelColor(81, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(43, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(80, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(82, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_05) ;
        RGBLED1.setPixelColor(80, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(82, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(42, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(63, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(79, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(83, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_05) ;
        RGBLED1.setPixelColor(63, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(79, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(83, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(41, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(62, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(64, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(78, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(80, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(84, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_05) ;
        RGBLED1.setPixelColor(62, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(64, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(78, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(80, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(84, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(40, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(45, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(61, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(65, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(77, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(79, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(81, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(85, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_05) ;
        RGBLED1.setPixelColor(44, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(45, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(61, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(65, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(77, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(79, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(81, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(85, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(39, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(46, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(60, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(66, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(76, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(78, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(82, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(86, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_05) ;
        RGBLED1.setPixelColor(43, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(46, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(60, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(66, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(76, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(78, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(82, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(86, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(38, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(47, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(59, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(67, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(75, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(77, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(83, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(87, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_20) ;
        RGBLED1.setPixelColor(38, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(39, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(40, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(41, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(42, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(47, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(59, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(67, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(75, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(77, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(83, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(87, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_05) ;
// メ
        RGBLED1.setPixelColor(81, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_05) ;
        RGBLED1.setPixelColor(81, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(62, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(80, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(82, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_05) ;
        RGBLED1.setPixelColor(62, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(80, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(82, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(61, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(63, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(79, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(83, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_05) ;
        RGBLED1.setPixelColor(61, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(63, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(79, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(83, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(60, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(62, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(64, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(78, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(80, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(84, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_05) ;
        RGBLED1.setPixelColor(60, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(62, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(64, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(78, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(80, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(84, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(44, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(45, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(59, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(61, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(65, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(77, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(79, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(85, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_05) ;
        RGBLED1.setPixelColor(44, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(45, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(59, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(61, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(65, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(77, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(79, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(85, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(43, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(46, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(58, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(60, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(66, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(76, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(78, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(86, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_05) ;
        RGBLED1.setPixelColor(43, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(46, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(58, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(60, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(66, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(76, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(78, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(86, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(42, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(47, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(57, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(59, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(67, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(75, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(77, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(87, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_20) ;
        RGBLED1.setPixelColor(42, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(47, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(57, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(59, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(67, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(75, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(77, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(87, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_05) ;
               
// 品
        RGBLED1.setPixelColor(63, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(80, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(81, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_05) ;
        RGBLED1.setPixelColor(80, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(64, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(79, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(82, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_05) ;
        RGBLED1.setPixelColor(79, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(27, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(44, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(45, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(80, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(65, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(78, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(83, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_05) ;
        RGBLED1.setPixelColor(44, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(63, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(78, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(80, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(81, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(28, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(43, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(46, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(66, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(77, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(79, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(84, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_05) ;
        RGBLED1.setPixelColor(43, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(64, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(77, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(79, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(82, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(29, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(42, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(44, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(47, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(63, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(67, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(76, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(78, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(80, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(81, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(85, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_05) ;
        RGBLED1.setPixelColor(27, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(42, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(44, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(45, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(65, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(76, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(78, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(80, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(83, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(30, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(41, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(43, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(48, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(64, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(68, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(75, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(77, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(79, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(82, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(86, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_05) ;
        RGBLED1.setPixelColor(28, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(41, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(43, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(46, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(66, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(75, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(77, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(79, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(84, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(31, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(40, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(42, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(49, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(65, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(69, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(74, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(76, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(78, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(80, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(81, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(83, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(87, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_05) ;//7
        RGBLED1.setPixelColor(29, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(40, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(42, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(47, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(63, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(67, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(74, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(76, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(78, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(80, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(81, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(85, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(32, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(39, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(41, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(50, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(66, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(70, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(73, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(75, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(77, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(79, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(82, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(84, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.setPixelColor(88, red[0], red[1], red[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_20) ;
        RGBLED1.setPixelColor(30, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(31, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(32, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(39, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(41, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(48, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(49, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(50, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(64, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(65, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(66, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(68, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(69, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(70, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(73, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(75, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(77, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(79, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(82, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(83, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(84, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(86, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(87, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.setPixelColor(88, white[0], white[1], white[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_05) ;

        for (int i=0; i<18; i++)            
        {
          RGBLED1.setPixelColor(i, white[0], white[1], white[2]) ;         // 白
          RGBLED1.show() ;                           // LEDにデータを送り出す
          delay(dt_003);
        }
        for (int i=18; i<99; i++)            
        {
          RGBLED1.setPixelColor(i, blue[0], blue[1], blue[2]) ;         // 青
          RGBLED1.show() ;                           // LEDにデータを送り出す
          delay(dt_003);
        }
        for (int i=99; i<117; i++)            
        {
          RGBLED1.setPixelColor(i, cyan[0], cyan[1], cyan[2]) ;         // シアン
          RGBLED1.show() ;                           // LEDにデータを送り出す
          delay(dt_003);
        }

// サ
        RGBLED1.setPixelColor(38, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_03) ;
        RGBLED1.setPixelColor(39, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_03) ;
        RGBLED1.setPixelColor(40, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_03) ;
        RGBLED1.setPixelColor(41, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_03) ;
        RGBLED1.setPixelColor(42, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_03) ;
        RGBLED1.setPixelColor(32, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_03) ;
        RGBLED1.setPixelColor(50, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_03) ;
        RGBLED1.setPixelColor(57, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_03) ;
        RGBLED1.setPixelColor(30, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_03) ;
        RGBLED1.setPixelColor(48, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_03) ;
        RGBLED1.setPixelColor(59, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_03) ;
        RGBLED1.setPixelColor(66, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_03) ;
        RGBLED1.setPixelColor(76, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_03) ;
        RGBLED1.setPixelColor(86, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_20) ;
        RGBLED1.setPixelColor(30, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.setPixelColor(32, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.setPixelColor(38, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.setPixelColor(39, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.setPixelColor(40, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.setPixelColor(41, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.setPixelColor(42, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.setPixelColor(48, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.setPixelColor(50, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.setPixelColor(57, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.setPixelColor(59, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.setPixelColor(66, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.setPixelColor(76, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.setPixelColor(86, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_05) ;

// ザ
        RGBLED1.setPixelColor(36, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_03) ;
        RGBLED1.setPixelColor(37, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_03) ;
        RGBLED1.setPixelColor(38, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_03) ;
        RGBLED1.setPixelColor(39, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_03) ;
        RGBLED1.setPixelColor(40, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_03) ;
        RGBLED1.setPixelColor(34, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_03) ;
        RGBLED1.setPixelColor(52, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_03) ;
        RGBLED1.setPixelColor(55, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_03) ;
        RGBLED1.setPixelColor(32, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_03) ;
        RGBLED1.setPixelColor(50, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_03) ;
        RGBLED1.setPixelColor(57, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_03) ;
        RGBLED1.setPixelColor(68, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_03) ;
        RGBLED1.setPixelColor(74, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_03) ;
        RGBLED1.setPixelColor(88, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_03) ;
        RGBLED1.setPixelColor(30, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_03) ;
        RGBLED1.setPixelColor(42, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_03) ;
        RGBLED1.setPixelColor(28, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_03) ;
        RGBLED1.setPixelColor(44, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_20) ;
        RGBLED1.setPixelColor(28, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.setPixelColor(30, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.setPixelColor(32, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.setPixelColor(34, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.setPixelColor(36, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.setPixelColor(37, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.setPixelColor(38, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.setPixelColor(39, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.setPixelColor(40, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.setPixelColor(42, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.setPixelColor(44, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.setPixelColor(50, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.setPixelColor(52, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.setPixelColor(55, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.setPixelColor(57, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.setPixelColor(68, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.setPixelColor(74, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.setPixelColor(88, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_05) ;
// エ
        RGBLED1.setPixelColor(33, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_03) ;
        RGBLED1.setPixelColor(32, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_03) ;
        RGBLED1.setPixelColor(31, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_03) ;
        RGBLED1.setPixelColor(30, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_03) ;
        RGBLED1.setPixelColor(29, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_03) ;
        RGBLED1.setPixelColor(40, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_03) ;
        RGBLED1.setPixelColor(49, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_03) ;
        RGBLED1.setPixelColor(58, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_03) ;
        RGBLED1.setPixelColor(67, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_03) ;
        RGBLED1.setPixelColor(76, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_03) ;
        RGBLED1.setPixelColor(87, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_03) ;
        RGBLED1.setPixelColor(86, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_03) ;
        RGBLED1.setPixelColor(85, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_03) ;
        RGBLED1.setPixelColor(84, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_03) ;
        RGBLED1.setPixelColor(83, yellow[0], yellow[1], yellow[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_20) ;
        RGBLED1.setPixelColor(29, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.setPixelColor(30, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.setPixelColor(31, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.setPixelColor(32, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.setPixelColor(33, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.setPixelColor(40, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.setPixelColor(49, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.setPixelColor(58, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.setPixelColor(67, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.setPixelColor(76, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.setPixelColor(83, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.setPixelColor(84, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.setPixelColor(85, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.setPixelColor(86, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.setPixelColor(87, blue[0], blue[1], blue[2]) ;   // 色設定
        RGBLED1.show() ; 
        delay(dt_05) ;

        //}      
      } else if (digitalRead(SW_1)==HIGH && digitalRead(SW_2)==LOW && digitalRead(SW_3)==HIGH && digitalRead(SW_4)==HIGH && digitalRead(SW_5)==HIGH && digitalRead(SW_6)==HIGH){
        RGBLED1.setBrightness(10) ;                                               // 明るさの指定
        for (int j=0; j<117; j++)                                              // 全部を白設定
        {
        RGBLED1.setPixelColor(j, white[0], white[1], white[2]) ;              // 白
        }
        RGBLED1.show() ;
        delay(dt_10) ;  
        
      } else if (digitalRead(SW_1)==HIGH && digitalRead(SW_2)==HIGH && digitalRead(SW_3)==LOW && digitalRead(SW_4)==HIGH && digitalRead(SW_5)==HIGH && digitalRead(SW_6)==HIGH){ 
        RGBLED1.setBrightness(50) ;                                               // 明るさの指定
        for (int j=0; j<117; j++)                                              // 全部を白設定
        {
        RGBLED1.setPixelColor(j, white[0], white[1], white[2]) ;              // 白
        }
        RGBLED1.show() ;
        delay(dt_10) ;
          
      } else if (digitalRead(SW_1)==HIGH && digitalRead(SW_2)==HIGH && digitalRead(SW_3)==HIGH && digitalRead(SW_4)==LOW && digitalRead(SW_5)==HIGH && digitalRead(SW_6)==HIGH){ 
        RGBLED1.setBrightness(30) ;                                               // 明るさの指定
        for (int j=0; j<117; j++)                                              // 全部を赤設定
        {
        RGBLED1.setPixelColor(j, red[0], red[1], red[2]) ;              // 赤
        }
        RGBLED1.show() ;
        delay(dt_10) ;
        
      } else if (digitalRead(SW_1)==HIGH && digitalRead(SW_2)==HIGH && digitalRead(SW_3)==HIGH && digitalRead(SW_4)==HIGH && digitalRead(SW_5)==LOW && digitalRead(SW_6)==HIGH){ 
        RGBLED1.setBrightness(30) ;                                               // 明るさの指定
        for (int j=0; j<117; j++)                                              // 全部を赤点滅設定
        {
        RGBLED1.setPixelColor(j, red[0], red[1], red[2]) ;              // 赤
        }
        RGBLED1.show() ;
        delay(dt_05) ;
        for (int j=0; j<117; j++)                                              // 全部を赤点滅設定
        {
        RGBLED1.setPixelColor(j, colorless[0], colorless[1], colorless[2]) ;              // 赤
        }
        RGBLED1.show() ;
        delay(dt_05) ;
      }
}
