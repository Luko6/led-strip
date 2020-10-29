#define G 9 // Defining the pinouts for the colors
#define R 6
#define B 3

// Initialize the value array
int led_values[3] = {50, 50, 50};
int old_led_values[3];

String msg = "";

/////////////////////////////////////////////////////////////////////////////////////////////////

void setup() {
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);

  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  Serial.println("Serial Ready");
  RGB(50,50,50);
}

// the loop routine runs over and over again forever:
void loop() {
  if (Serial.available()) {
    msg = Serial.readString();
    Serial.println("Recieved: ");
    Serial.println(msg);

    switch (msg[0]) {
      case 'r':
        Serial.println(msg[1]);
        Serial.println((int)msg[1]-'0');
        rainbow((int)msg[1]-'0');
        Serial.println("Finished rainbow");
        break;
      default:
        displayValue(msg, old_led_values, led_values);
        break;
    }
  }
}



void displayValue(String msg, int old_led_values[3], int led_values[3]) {
  int k = 0;
  char c[2];

  for (int i = 0; i < 3; i++) {
    old_led_values[i] = led_values[i];
  }
  
  for(int i = 0; i < 5; i += 2){
      c[0] = msg[i];
      c[1] = msg[i+1];
      led_values[k] = hexadecimalToDecimal(c);
      k++;             
    }
    
  fade(old_led_values, led_values);
}

void rainbow(int lim){
  int r = 254, g = 1, b = 127;;
  int Rdir = -1, Gdir = 1, Bdir = -1;

  lim *= 512;

  if(lim == 0) lim = 32767;  
  
  while (0 < lim) {
    RGB(r,g,b);
    r += Rdir;
    g += Gdir;
    b += Bdir;

    if(r >= 255 || r <= 0) Rdir *= -1;
    if(g >= 255 || g <= 0) Gdir *= -1;
    if(b >= 255 || b <= 0) Bdir *= -1;

    lim--;
    delay(10);
  }
}

void test() {
  RGB(255, 0, 0);
  delay(400);
  RGB(0, 255, 0);
  delay(400);
  RGB(0, 0, 255);
  delay(400);
}

void fade(int o[3], int n[3]) {

  int r_fade = (o[0] - n[0]) / 10;
  int g_fade = (o[1] - n[1]) / 10;
  int b_fade = (o[2] - n[2]) / 10;

  /*Serial.print("R_f: ");
    Serial.print(r_fade);
    Serial.print(" G_f: ");
    Serial.print(g_fade);
    Serial.print(" B_f: ");
    Serial.print(b_fade);*/


  for (int i = 0; i < 10; i++) {
    RGB(o[0] - r_fade * i, o[1] - g_fade * i, o[2] - b_fade * i);
    /*Serial.print("\nR: ");
      Serial.print(o[0]-r_fade*i);
      Serial.print(" G: ");
      Serial.print(o[1]-g_fade*i);
      Serial.print(" B: ");
      Serial.print(o[2]-b_fade*i);*/

    // FADE SPEED !!!!!
    delay(35);
  }

  RGB(n[0], n[1], n[2]);
  /*Serial.print("\nR: ");
    Serial.print(n[0]);
    Serial.print(" G: ");
    Serial.print(n[1]);
    Serial.print(" B: ");
    Serial.print(n[2]);*/
}


void RGB(int r, int g, int b) {
  analogWrite(R, r);
  analogWrite(B, b);
  analogWrite(G, g);
}

// Function to convert hexadecimal to decimal
int hexadecimalToDecimal(char hexVal[])
{
  int len = strlen(hexVal);

  // Initializing base value to 1, i.e 16^0
  int base = 1;

  int dec_val = 0;

  // Extracting characters as digits from last character
  for (int i = len - 1; i >= 0; i--)
  {
    // if character lies in '0'-'9', converting
    // it to integral 0-9 by subtracting 48 from
    // ASCII value.
    if (hexVal[i] >= '0' && hexVal[i] <= '9')
    {
      dec_val += (hexVal[i] - 48) * base;

      // incrementing base by power
      base = base * 16;
    }

    // if character lies in 'A'-'F' , converting
    // it to integral 10 - 15 by subtracting 55
    // from ASCII value
    else if (hexVal[i] >= 'A' && hexVal[i] <= 'F')
    {
      dec_val += (hexVal[i] - 55) * base;

      // incrementing base by power
      base = base * 16;
    }
  }

  return dec_val;
}