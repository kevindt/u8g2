
#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

// put function declarations here:


// Constructors
U8G2_SH1106_128X64_NONAME_1_2ND_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

//Variables
const char *string_list = 
  "Altocumulus\n"
  "Altostratus\n"
  "Cirrocumulus\n"
  "Cirrostratus\n"
  "Cirrus\n"
  "Cumulonimbus\n"
  "Cumulus\n"
  "Nimbostratus\n"
  "Stratocumulus\n"
  "Stratus";

uint8_t current_selection = 1;

// Setup
void setup(void) {

  // U8g2 SH1106 
  u8g2.begin(/* menu_select_pin= */ 6, /* menu_next_pin= */ 7, /* menu_prev_pin= */ 5, /* menu_up_pin= */ U8X8_PIN_NONE, /* menu_down_pin= */ U8X8_PIN_NONE, /* menu_home_pin= */ U8X8_PIN_NONE);

  u8g2.setFont(u8g2_font_6x12_tr);
}

// Main loop
void loop(void) {

  current_selection = u8g2.userInterfaceSelectionList(
    "Cloud Types",
    current_selection, 
    string_list);

  if ( current_selection == 0 ) {
    u8g2.userInterfaceMessage(
	"Nothing selected.", 
	"",
	"",
	" ok ");
  } else {
    u8g2.userInterfaceMessage(
	"Selection:", 
	u8x8_GetStringLineStart(current_selection-1, string_list ),
	"",
	" ok \n cancel ");
  }
}