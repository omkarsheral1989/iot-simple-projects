#define PWM_LED_PIN 19

const int analogChannel0=0;

void setup()
{
    //setup channel 0 with frequency 312500 Hz
    sigmaDeltaSetup(analogChannel0, 312500);
    //attach pin 18 to channel 0
    sigmaDeltaAttachPin(PWM_LED_PIN, analogChannel0);
    //initialize channel 0 to off
    sigmaDeltaWrite(analogChannel0, 0);
}

void loop()
{
    //slowly ramp-up the value
    //will overflow at 256
    static uint8_t i = 0;
    sigmaDeltaWrite(analogChannel0, i++);
    delay(10);
}
