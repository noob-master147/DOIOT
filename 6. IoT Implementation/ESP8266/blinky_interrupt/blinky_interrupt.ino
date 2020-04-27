
// blink LED until interrupt button is pushed then turn off LED using millis instead of delay

int led = 6;
int ledState = LOW;

volatile boolean interruptButton = false; //pin 2

unsigned long previousMillis = 0; //will store last time update

const long intervalOn = 1000;
const long intervalOff = 300;

void setup()
{
    attachInterrupt(2, interruptFunction, HIGH);
    pinMode(led, OUTPUT);
    digitalWrite(led, LOW);
}

void loop()
{
    if (interruptButton == true) //true/false to reverse button action
    {
        digitalWrite(led, LOW);
    }
    else
    {
        previousMillis = millis();
        while ((millis() - previousMillis) <= intervalOn)
        {
            ledState = HIGH;
            digitalWrite(led, ledState);
        }

        previousMillis = millis();
        while ((millis() - previousMillis) <= intervalOff)
        {
            ledState = LOW;
            digitalWrite(led, ledState);
        }
    }
}

void interruptFunction()
{
    if (interruptButton == false)
    {
        interruptButton = true;
    }
    else
    {
        interruptButton = false;
    }
}