int ledPin = 13;
int inputPin = 3;

void setup()
{
    pinMode(ledPin, OUTPUT);
    pinMode(inputPin, INPUT);
}

void loop()
{
    int state = digialRead(inputPin);
    digitalWrite(state);
    delay(20);
}
