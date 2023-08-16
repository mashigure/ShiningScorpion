/* --------------------------------
 * shining Scorpion
   -------------------------------- */

#include <WS2812.h>

#define NUM_LEDS       (  4)
#define COLOR_PER_LEDS (  3)
#define NUM_BYTES      (NUM_LEDS*COLOR_PER_LEDS)
#define LED_PIN        ( 15)
#define ONBOARD_LED    ( 17)
#define DELAYVAL       (100)


__xdata uint8_t ledData[NUM_BYTES];

// colors
typedef enum {
    C_NONE,
    C_BLUE,
    C_PURPLE,
    C_PINK,
    C_RED
} PixelColor;


// proto type
void changeColour(PixelColor c_before, PixelColor c_next);
void shining(PixelColor c1, PixelColor c2, PixelColor c3, PixelColor c4);
void setPixelColor(int led_no, PixelColor color);


// initialize
void setup()
{
    pinMode(LED_PIN, OUTPUT);
    pinMode(ONBOARD_LED, OUTPUT);
    digitalWrite(ONBOARD_LED, LOW);
    changeColour(C_NONE, C_BLUE);
}


void loop()
{
    delay(15 * 1000);
    changeColour(C_BLUE, C_PURPLE);
    delay(5 * 1000);
    changeColour(C_PURPLE, C_PINK);
    delay(5 * 1000);
    changeColour(C_PINK, C_RED);
    delay(15 * 1000);
    changeColour(C_RED, C_BLUE);
}


void changeColour(PixelColor c_before, PixelColor c_next)
{
    shining(c_before, c_before, c_before, c_next);
    delay(DELAYVAL);
    shining(c_before, c_before, c_next  , c_next);
    delay(DELAYVAL);
    shining(c_before, c_next  , c_next  , c_next);
    delay(DELAYVAL);
    shining(c_next  , c_next  , c_next  , c_next);
}


void shining(PixelColor c1, PixelColor c2, PixelColor c3, PixelColor c4)
{
    setPixelColor(0, c1);
    setPixelColor(1, c2);
    setPixelColor(2, c3);
    setPixelColor(3, c4);
    neopixel_show_P1_5(ledData, NUM_BYTES);
}


void setPixelColor(int led_no, PixelColor color)
{
    switch (color)
    {
        case C_BLUE  : set_pixel_for_GRB_LED(ledData, led_no,   0, 0, 255); break;
        case C_PURPLE: set_pixel_for_GRB_LED(ledData, led_no,  31, 0, 255); break;
        case C_PINK  : set_pixel_for_GRB_LED(ledData, led_no, 255, 0, 127); break;
        case C_RED   : set_pixel_for_GRB_LED(ledData, led_no, 255, 0,   0); break;
        default      : set_pixel_for_GRB_LED(ledData, led_no,   0, 0,   0); break;
    }
}
