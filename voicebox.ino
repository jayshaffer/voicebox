/***************************************************
DFPlayer - A Mini MP3 Player For Arduino
 <https://www.dfrobot.com/product-1121.html>
 
 ***************************************************
 This example shows the basic function of library for DFPlayer.
 
 Created 2016-12-07
 By [Angelo qiao](Angelo.qiao@dfrobot.com)
 
 GNU Lesser General Public License.
 See <http://www.gnu.org/licenses/> for details.                           
 All above must be included in any redistribution
 ****************************************************/

/***********Notice and Trouble shooting***************
 1.Connection and Diagram can be found here
 <https://www.dfrobot.com/wiki/index.php/DFPlayer_Mini_SKU:DFR0299#Connection_Diagram>
 2.This code is tested on Arduino Uno, Leonardo, Mega boards.
 ****************************************************/

#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"

DFRobotDFPlayerMini myDFPlayer;
unsigned long debounceDelay = 50;
unsigned long lastButtonChange = 0;
const byte PLAY_INTERRUPT = 5;
const byte PLAY_POWER = 4;

void setup()
{
  Serial.begin(9600);
  pinMode(PLAY_INTERRUPT, INPUT_PULLUP);
  pinMode(PLAY_POWER, OUTPUT);
  bool online = myDFPlayer.begin(Serial);
  if(!online){
    delay(100);
    online = myDFPlayer.begin(Serial);
  }
  myDFPlayer.EQ(4);
  myDFPlayer.volume(20);  //Set volume value. From 0 to 30
}

void loop()
{
  digitalWrite(PLAY_POWER, HIGH);
  if(digitalRead(PLAY_INTERRUPT) == HIGH && (millis() - lastButtonChange) > debounceDelay){
      //myDFPlayer.enableLoopAll();
      myDFPlayer.randomAll();
      myDFPlayer.next();
      lastButtonChange = millis();
  }
}
