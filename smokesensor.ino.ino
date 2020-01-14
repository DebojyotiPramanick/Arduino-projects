int analog=4;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(analog,INPUT);
}

void loop() {
  float k;
  k=analogRead(analog);
  Serial.println(k);
  delay(100);
}
