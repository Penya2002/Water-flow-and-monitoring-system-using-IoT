int trigPin=11;
int echoPin=10;
int distance;
long time;
void setup()
{
  pinMode(10, INPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  digitalWrite(11, HIGH);
  delayMicroseconds(10);
  digitalWrite(11, HIGH);
  delayMicroseconds(10);
  digitalWrite(11, LOW);
  time=pulseIn(10,HIGH);
  distance=(time*0.034)/2;
  Serial.println("Distance =");
  Serial.println(distance);
  delay(1000);
  
}