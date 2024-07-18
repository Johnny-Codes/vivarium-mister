#include <stdio.h>
#include <bcm2835.h>

#define BUTTON_PIN RPI_V2_GPIO_P1_11  // GPIO 17
#define RELAY_PIN  RPI_V2_GPIO_P1_13  // GPIO 27

int main(int argc, char **argv) {

    if (!bcm2835_init()) {
        printf("BCM2835 init failed");
        return 1;
    }

    // set button to input
    bcm2835_gpio_fsel(BUTTON_PIN, BCM2835_GPIO_FSEL_INPT);
    // enable pull up on button
    bcm2835_gpio_set_pud(BUTTON_PIN, BCM2835_GPIO_PUD_UP);

    // set relay to output
    bcm2835_gpio_fsel(RELAY_PIN, BCM2835_GPIO_FSEL_OUTP);

    int relay_state = 0;
    int last_button_state = LOW;

    while(1) {
        int button_state = bcm2835_gpio_lev(BUTTON_PIN);

        if (button_state == LOW && last_button_state == HIGH) {
            // debounce delay
            bcm2835_delay(50);
            // read button state to confirm
            button_state = bcm2835_gpio_lev(BUTTON_PIN);
            if (button_state == LOW) {
                    // toggle relay state
                    relay_state = !relay_state;
                    bcm2835_gpio_write(RELAY_PIN, relay_state);
                }
            }
        
        // update last button state
        last_button_state = button_state;

        // small delay to avoid high cpu usage
        bcm2835_delay(10);
    }

    bcm2835_close();
    return 0;
}
