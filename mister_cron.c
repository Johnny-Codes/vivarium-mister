#include <stdio.h>
#include <bcm2835.h>

#define RELAY_PIN  RPI_V2_GPIO_P1_13  // GPIO 27

int main(int argc, char **argv) {
    
    if (!bcm2835_init()) {
        printf("BCM2835 init failed");
        return 1;
    }

    // set relay to output
    bcm2835_gpio_fsel(RELAY_PIN, BCM2835_GPIO_FSEL_OUTP);
    // turn relay/pump on
    bcm2835_gpio_write(RELAY_PIN, HIGH);
    // run for 5 seconds
    bcm2835_delay(5000);
    // turn off relay/pump
    bcm2835_gpio_write(RELAY_PIN, LOW);
    // safe close
    bcm2835_close();
    
    return 0;
}
