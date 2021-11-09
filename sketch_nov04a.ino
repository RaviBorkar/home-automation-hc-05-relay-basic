// kiwano projects Er Ravi Borkar
//  PROJECT: Home Automation

//  Connections:
//  Arduino     Bluetooth   |    Arduino   Relay
  //RX(0)       TX          |    2         IN
//  TX(1)       RX          |    VCC       VCC
 // 5V          5V/3.3V     |    GND       GND
 // GND         GND         |
//*/

const int relay = 2;      //pin where Relay is connected
char data;                //variable to store data
void setup() {
  Serial.begin(9600);     //Begin serial communication
  pinMode(relay, OUTPUT); //make relay pin as output
}

void loop() {
  if (Serial.available() > 0) //if there is data on RX
  {
    data = Serial.read();     //save it inside variable
    if (data == 'a')
    { digitalWrite(relay, HIGH);  //Turn ON the Light
      Serial.println("Light ON");
    }
    if (data == 'b')
    { digitalWrite(relay, LOW);   //Turn OFF the Light
      Serial.println("Light OFF");
    }
  }
}
