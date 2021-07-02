void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(A0,INPUT);
  pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int a;
  a=analogRead(A0);
  delay(200);
  Serial.print(a);
  if(a<70)
  {
    digitalWrite(LED_BUILTIN,LOW);
    Serial.println(" => LED is on");
  }
  else
  {
    digitalWrite(LED_BUILTIN,HIGH);
    Serial.println(" => LED is off");
  }
}
