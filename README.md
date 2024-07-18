# RASPBERRY PI MISTER

## ABOUT

This Raspberry Pi Project controls a relay that turns a water pump on and off to send water through a line to a misting output. Initially created for any -ariums (vivarium, terrarium, etc.). 

## WIRING

GPIO Pin 17 controls a button that will turn the pump on/off as desired

GPIO Pin 27 controls the relay

### Relay

| RPi | Relay |
| :------- | :------- |
| 5v | DC+ |
| GND | DC- |
| GPIO 27/PIN 13 | IN |

Power supply to pump
NO -> power
power -> power on pump
COM -> negative on pump

## CRON JOB

Edit the `bcm2835_delay(x)` to change how many seconds the program runs. Try testing it out and seeing how much water you like.

Set up a Cron Job to run the script when you want it to mist your vivarium

Find where the program file lives {PATH}

Open Crontab editor
- `crontab -e`

Add the Cron Job
- This will run every day at 7am. Look up how to set up Cron Jobs to change the time `0 7 * * * {PATH}`

Verify Cron Job
`crontab -l`

## BUTTON

Set up a button 
