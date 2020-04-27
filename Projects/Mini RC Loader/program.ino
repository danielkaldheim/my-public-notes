#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <Servo.h>

#define motorPin1_1 4
#define motorPIN1_2 15
#define motorPIn2_1 14
#define motorPIn2_2 12
#define armPin 5
#define bucketPin 13
#define lightFrontPin 16
#define lightEmergencyPin 0

const char *ssid = "FNM_Mini_Loader_4WD_J"; // Phone to this AP
const char *pw = "00010001";                // access password

IPAddress ip(192, 168, 0, 1); // Roboremo Connection IP
IPAddress netmask(255, 255, 255, 0);

const int port = 9876; // Connection Port
int m1speed = 0, m2speed = 0;
int ledFront;
int loaderArmAngle = 90, loaderBucketAngle = 90; // Servo Initial Location
int ledEmergencyOff = LOW;
unsigned long preMillisLed = 0;
const long intervalLed = 1000; //Light bulb interval 1 second (1000ms)
char cmd[100];
int cmdIndex;

Servo loaderArm, loaderBucket;
WiFiServer server(port);
WiFiClient client;

void setup()
{
    pinMode(motorPin1_1, OUTPUT);
    pinMode(motorPIN1_2, OUTPUT);
    pinMode(motorPIn2_1, OUTPUT);
    pinMode(motorPIn2_2, OUTPUT);
    pinMode(lightFrontPin, OUTPUT);
    pinMode(lightEmergencyPin, OUTPUT);
    analogWrite(motorPin1_1, 0);
    analogWrite(motorPIN1_2, 0);
    analogWrite(motorPIn2_1, 0);
    analogWrite(motorPIn2_2, 0);
    digitalWrite(lightFrontPin, LOW);
    digitalWrite(lightEmergencyPin, LOW);

    loaderArm.attach(armPin);
    loaderArm.write(loaderArmAngle);
    loaderBucket.attach(bucketPin);
    loaderBucket.write(loaderBucketAngle);

    delay(1000);

    WiFi.softAPConfig(ip, ip, netmask); // configure ip address for softAP
    WiFi.softAP(ssid, pw);              // configure ssid and password for softAP
    server.begin();                     // start TCP server
}

boolean cmdStartsWith(const char *st)
{
    for (int i = 0;; i++)
    {
        if (st[i] == 0)
            return true;

        if (cmd[i] == 0)
            return false;

        if (cmd[i] != st[i])
            return false;
        ;
    }

    return false;
}

void exeCmd()
{

    if (cmdStartsWith("m1 "))
    {
        m1speed = atoi(cmd + 3);
        Serial.println(m1speed);
    }

    if (cmdStartsWith("m2 "))
    {
        m2speed = atoi(cmd + 3);
        Serial.println(m2speed);
    }

    if (m1speed > 0)
    {
        analogWrite(motorPin1_1, m1speed);
    }

    if (m1speed < 0)
    {
        analogWrite(motorPIN1_2, -m1speed);
    }

    if (m1speed == 0)
    {
        analogWrite(motorPin1_1, 0);
        analogWrite(motorPIN1_2, 0);

        if (m1speed == 0)
        {
        }
    }

    if (m2speed > 0)
    {
        analogWrite(motorPIn2_1, m2speed);
    }

    if (m2speed < 0)
    {
        analogWrite(motorPIn2_2, -m2speed);
    }

    if (m2speed == 0)
    {
        analogWrite(motorPIn2_1, 0);
        analogWrite(motorPIn2_2, 0);

        if (m1speed == 0)
        {
        }
    }

    if (cmdStartsWith("arm "))
    {
        loaderArmAngle = atoi(cmd + 3);
        loaderArm.write(loaderArmAngle);
    }

    if (cmdStartsWith("buc "))
    {
        loaderBucketAngle = atoi(cmd + 3);
        loaderBucket.write(loaderBucketAngle);
    }

    if (cmdStartsWith("fl"))
    {
        ledFront = (ledFront == LOW) ? HIGH : LOW;
        digitalWrite(lightFrontPin, ledFront);
    }
}

void loop()
{
    if (!client.connected())
    {
        client = server.available();
        return;
    }

    if (client.available())
    {
        char c = (char)client.read();
        if (c == '\n')
        {
            cmd[cmdIndex] = 0;
            exeCmd();
            cmdIndex = 0;
        }
        else
        {
            cmd[cmdIndex] = c;
            if (cmdIndex < 99)
                cmdIndex++;
        }
    }

    unsigned long currMillis = millis();

    if (currMillis - preMillisLed >= intervalLed)
    {
        preMillisLed = currMillis;
        ledEmergencyOff = (ledEmergencyOff == LOW) ? HIGH : LOW;
        digitalWrite(lightEmergencyPin, ledEmergencyOff);
    }
}
