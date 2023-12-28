int LED_RED_Danger = 3;            /*LED_RED_Danger pin defined*/
int LED_GREEN_Safe = 0;

int gas_sensor_input_pin = 1;    /*Digital pin 4 for sensor input*/
int flame_sensor_input_pin = 2;
int gasThreshold = 0;
void setup() {
  Serial.begin(115200);  /*baud rate for serial communication*/
  pinMode(LED_RED_Danger, OUTPUT);  /*LED_RED_Danger set as Output*/
  pinMode(LED_GREEN_Safe, OUTPUT);  /*LED_GREEN_Safe set as Output*/
  int tmp = 0;
  for (int i=1; i<=10; i++) {
    tmp = analogRead(gas_sensor_input_pin);
    delay(200);
  }
  for (int i=1; i<=9; i++) {
    int tmp2 = analogRead(gas_sensor_input_pin);
    tmp +=tmp2;
    Serial.print(tmp2);
    Serial.print("\t");
    Serial.println(tmp);
    delay(200);
  }
  gasThreshold = (int) (tmp*0.103);
  Serial.print("Gas threshold: ");
  Serial.println(gasThreshold);
}
void loop() {
  int gas_sensor_Dout = analogRead(gas_sensor_input_pin);  /*Analog value read function*/
  int flame_sensor_Dout = digitalRead(flame_sensor_input_pin);
  Serial.print("Gas Sensor: ");  
  Serial.print(gas_sensor_Dout);   /*Read value printed*/
  Serial.print("/");
  Serial.print(gasThreshold);
  Serial.print("\t");
  Serial.print("\t");
  Serial.print("Flame Sensor: ");
  if (flame_sensor_Dout == 0) 
    Serial.print(1);   /*Read value printed*/
  else 
    Serial.print(0);
  Serial.print("\t");
  Serial.print("\t");
  if (gas_sensor_Dout > gasThreshold || flame_sensor_Dout == 0) {    /*if condition with threshold 1800*/
    Serial.println("Cháy nhà!!!!!");  
    digitalWrite (LED_RED_Danger, HIGH) ; /*LED_RED_Danger set HIGH if Gas detected */
    digitalWrite (LED_GREEN_Safe, LOW) ; /*LED_GREEN_Safe set LOW if Gas detected */
  }
  else {
    Serial.println("An toàn");
    digitalWrite (LED_RED_Danger, LOW) ;  /*LED_RED_Danger set LOW if NO Gas detected */
    digitalWrite (LED_GREEN_Safe, HIGH) ;

  }
  delay(1000);                 /*DELAY of 1 sec*/
}
