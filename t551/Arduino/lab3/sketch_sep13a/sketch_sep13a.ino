
int fp_pin = 13;
int rp_pin = 12;
int fn_pin = 11;
int rn_pin = 10;

void setup()
{
    pinMode(fp_pin, OUTPUT);
    pinMode(rp_pin, OUTPUT);
    pinMode(fn_pin, OUTPUT);
    pinMode(rn_pin, OUTPUT);   
}

enum ramp_state
{
    ramp_up,
    ramp_down
};

enum direction_state
{
    forward,
    reverse
};

ramp_state cur_ramp_state = ramp_up;
direction_state cur_direction_state = forward;

int pwm_state = 0;

void loop()
{
    if(cur_direction_state == forward)
    {
        digitalWrite(fp_pin, HIGH);
        analogWrite(fn_pin, pwm_state);
    }
    else
    {
        digitalWrite(rp_pin, HIGH);
        analogWrite(rn_pin, pwm_state);
    }
  
    if(cur_ramp_state == ramp_up)
    {
        if(pwm_state < 255)
        {
            pwm_state += 1;
        }
        else
        {
            cur_ramp_state = ramp_down;
        }
    }
    if(cur_ramp_state == ramp_down)
    {
        if(pwm_state > 0)
        {
            pwm_state -= 1;
        }
        else
        {
            cur_ramp_state = ramp_up;
        }
    }
}

