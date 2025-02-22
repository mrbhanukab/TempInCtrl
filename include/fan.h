#pragma once

void fan_control()
{
    if (temprature > temprature_limit && fan_status == false)
    {
        digitalWrite(FAN, HIGH);
        for (int i = 0; i < 4; i++)
        {
            digitalWrite(BUZZER, HIGH);
            delay(100);
            digitalWrite(BUZZER, LOW);
            delay(100);
        }
        fan_status = true;
        bottomPanel("Fan: ON | Limit: " + String(temprature_limit));
    }
    else if (temprature <= temprature_limit && fan_status == true)
    {
        digitalWrite(FAN, LOW);
        for (int i = 0; i < 2; i++)
        {
            digitalWrite(BUZZER, HIGH);
            delay(150);
            digitalWrite(BUZZER, LOW);
            delay(150);
        }
        fan_status = false;
        bottomPanel("Fan: OFF | Limit: " + String(temprature_limit));
    }
}
