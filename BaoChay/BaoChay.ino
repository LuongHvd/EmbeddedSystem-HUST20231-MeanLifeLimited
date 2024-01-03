int LED_RED_Danger = 21;      //3      /*LED_RED_Danger pin defined*/
int LED_GREEN_Safe = 17; // 0

int gas_sensor_input_pin = 4; //1  
int flame_sensor_input_pin = 3; //2
int gasThreshold = 0;
void setup() {
    Serial.begin(115200);  /*baud rate for serial communication*/
    pinMode(LED_RED_Danger, OUTPUT);  /*LED_RED_Danger set as Output*/
    pinMode(LED_GREEN_Safe, OUTPUT);  /*LED_GREEN_Safe set as Output*/
    int tmp = 0;
    for (int i=1; i<=10; i++) {
        tmp = analogRead(gas_sensor_input_pin);
        Serial.println(tmp);
        delay(2000);
    }
    for (int i=1; i<=9; i++) {
        int tmp2 = analogRead(gas_sensor_input_pin);
        tmp +=tmp2;
        Serial.print(tmp2);
        Serial.print("\t");
        Serial.println(tmp);
        delay(500);
    }
    gasThreshold = (int) (tmp*0.104);
    Serial.print("Gas threshold: ");
    Serial.println(gasThreshold);
}
void loop() {
    // int tmp = 0;
    // for (int i=0; i=4; i++) {
    //     tmp += analogRead(gas_sensor_input_pin);
    // }
    // int gas_sensor_Aout =  (int) (tmp/5); /*Analog value read function*/
    int gas_sensor_Aout =  analogRead(gas_sensor_input_pin);
    int flame_sensor_Dout = digitalRead(flame_sensor_input_pin);
    Serial.print("Gas Sensor: ");  
    Serial.print(gas_sensor_Aout);   /*Read value printed*/
    Serial.print("/");
    Serial.print(gasThreshold);
    Serial.print("=");
    Serial.print(gas_sensor_Aout/(gasThreshold+0.0));
    Serial.print("\t");
    Serial.print("\t");
    Serial.print("Flame Sensor: ");
    if (flame_sensor_Dout == 0) 
        Serial.print(1);   /*Read value printed*/
    else 
        Serial.print(0);
    Serial.print("\t");
    Serial.print("\t");
    if (gas_sensor_Aout > gasThreshold || flame_sensor_Dout == 0) {    /*if condition with threshold 1800*/
        Serial.println("Cháy nhà!!!!!");  
        digitalWrite (LED_RED_Danger, HIGH) ; /*LED_RED_Danger set HIGH if Gas detected */
        digitalWrite (LED_GREEN_Safe, LOW) ; /*LED_GREEN_Safe set LOW if Gas detected */
    }
    else {
        Serial.println("An toàn");
        digitalWrite (LED_RED_Danger, LOW) ;  /*LED_RED_Danger set LOW if NO Gas detected */
        digitalWrite (LED_GREEN_Safe, HIGH) ;
    }
    delay(300);                /* DELAY of 300 mili sec*/
}