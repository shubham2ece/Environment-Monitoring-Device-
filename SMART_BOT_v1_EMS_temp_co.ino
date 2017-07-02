

/*Level of CO
Health Effects, and Other Information
0 PPM
Normal, fresh air.
9 PPM
Maximum recommended indoor CO level (ASHRAE).
10-24 PPM
Possible health effects with long-term exposure.
25 PPM
Max TWA Exposure for 8 hour work-day (ACGIH).
Pocket CO TWA warning sounds each hour.
50 PPM
Maximum permissible exposure in workplace (OSHA).
First Pocket CO ALARM starts (optional, every 20 seconds).
100 PPM
Slight headache after 1-2 hours.
125 PPM
Second Pocket CO ALARM starts (every 10 seconds).
200 PPM
Dizziness, naseau, fagitue, headache after 2-3 hours of exposure.
400 PPM
Headache and nausea after 1-2 hours of exposure.
Life threatening in 3 hours.
Third Pocket CO ALARM starts (every 5 seconds).
800 PPM
Headache, nausea, and dizziness after 45 minutes; collapse and unconsciousness after 1 hour of exposure.
Death within 2-3 hours.
1000 PPM
Loss of consciousness after 1 hour of exposure.
1600 PPM
Headache, nausea, and dizziness after 20 minutes of exposure.
Death within 1-2 hours.
3200 PPM
Headache, nausea, and dizziness after 5-10 minutes; collapse and unconsciousness after 30 minutes of exposure.
Death within 1 hour.
6400 PPM
Death within 30 minutes.
12,800 PPM
Immediate physiological effects, unconsciousness.
Death within 1-3 minutes of exposure.
*/
#include <dht.h>
dht DHT;
//#include<LiquidCrystal.h>
//LiquidCrystal lcd(12,11,5,4,3,2);
const float analogInPin2 = A1 ; 
 float sensor2 = 0;


#define DHT11_PIN A5

void setup()
{
  Serial.begin(115200);
  Serial.println("SMART BOT ");
  Serial.print("VERSION:1 environment Monitoring system(EMS) ");
  Serial.println("Author:Shubham kumar,\t email:shubham2ece@gmail.com");


  Serial.println("Type,\tstatus,\tHumidity (%),\tTemperature (C),\tPollution(ppm)");
//    lcd.begin(16, 2);
}

void loop()
{
  // READ DATA
  Serial.print("EMS: \t");
  int chk = DHT.read11(DHT11_PIN);
  sensor2 = analogRead(analogInPin2);
   sensor2 = sensor2*4.88;
  switch (chk)
  {
    case DHTLIB_OK:  
		Serial.print("OK,\t"); 
		break;
    case DHTLIB_ERROR_CHECKSUM: 
		Serial.print("Checksum error,\t"); 
		break;
    case DHTLIB_ERROR_TIMEOUT: 
		Serial.print("Time out error,\t"); 
		break;
    case DHTLIB_ERROR_CONNECT:
        Serial.print("Connect error,\t");
        break;
    case DHTLIB_ERROR_ACK_L:
        Serial.print("Ack Low error,\t");
        break;
    case DHTLIB_ERROR_ACK_H:
        Serial.print("Ack High error,\t");
        break;
    default: 
		Serial.print("Unknown error,\t"); 
		break;
  }
  
  // DISPLAY DATA
  
  Serial.print(DHT.humidity, 1);
  Serial.print("\t \t");
  
  Serial.print(DHT.temperature, 1);
 // Serial.print(" ");
     Serial.print("\t \t");
//lcd.setCursor(0,1); lcd.print("CO(mV)");
//Serial.print("\tCO(mv):");
//Serial.println(sensor2);
   
  //lcd.print(sensor2); 
  delay(1000); 
 
 // lcd.clear();
  sensor2=(sensor2*0.5)-376;
  //lcd.setCursor(0,1); lcd.print("CO(ppm)");
  Serial.print("\tCO(ppm):");
  Serial.println(sensor2); 
//  lcd.print(sensor2);
 
  delay(1000);
 // lcd.clear();
if (sensor2 <50)
  {
    Serial.print("\t you r safe,Maximum permissible exposure in workplace is 50 PPM (OSHA)\n");
  }
  else if (50 < sensor2  )
    {
        Serial.print("\tpollution increased.slight headache after 4-8 hours.if ppm>100: symptoms are naseau,fagitue,dizziness,headache\t if ppm>800: unconsciousness after 1 hr of exposure\n ");
    }
  /* else if(sensor2>416)
    {
    Serial.print("\t Maximum permissible exposure in workplace is 50 PPM (OSHA).\n ");
    }
    else if (100>sensor2>50)
    {
    Serial.print("\t pollution increased.slight headache after 4-8 hours.\n ");
    }
    else if (200>sensor2>100)
    {
    Serial.print("\t pollution increased, Slight headache after 1-2 hours.\n ");
    }
     else if (400 > sensor2 > 200)
    {
    Serial.print("\t Dizziness, naseau, fagitue, headache after 2-3 hours of exposure.\n ");
    }
    else if (800>sensor2>400)
    {
    Serial.print("\t Headache nausea and dizziness after 1-2 hours of exposure Life threatening in 3 hours \n ");
    }
     else if (sensor2>800)
    {
    Serial.print("\tLoss of consciousness after 1 hour of exposure. \n ");
    }
 
  */
}
//
// END OF FILE
//
