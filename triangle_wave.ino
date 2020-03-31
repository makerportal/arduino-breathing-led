// RGB LED Triangle Wave Breathing LED

int led_pins[4] = {3,5,6};
int jj = 0; // 0 = red, 1 = green, 2 = blue
float smoothness_pts = 500;//larger=slower change in brightness

void setup() {
  Serial.begin(9600);
  for (int ii = 0;ii<sizeof(led_pins)/sizeof(int);ii++){
    pinMode(led_pins[ii],OUTPUT);
  }
}

void loop() {
  for (int ii=0;ii<smoothness_pts;ii++){
    float pwm_val = 255.0*(1.0 -  abs((2.0*(ii/smoothness_pts))-1.0));
    analogWrite(led_pins[jj],int(pwm_val));
    delay(5);
    Serial.println(int(pwm_val));
  }
}
