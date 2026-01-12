# ITWL-FPV Flight Controller

## Features

- STM32H743 microcontroller
- ICM42653 IMU 
- BMP581 barometer
- MMC34160 magnetometer
- SDCARD
- USB FS
- 6x UART
- 10x PWM
- 3x I2C
- 1x CAN
- 2x GPIOs
- OSD via SPI1
- camera switch

## Pinout

![ITWL-FPV1_1](AEDROX_FC_H7_PINOUT.png "ITWL-FPV")

## UART Mapping

 - SERIAL0 -> USB
 - SERIAL1 -> UART8 (MAVLink2, DMA-enabled)
 - SERIAL2 -> UART1 (MAVLink2, DMA-enabled)
 - SERIAL3 -> UART2 (DisplayPort, DMA-enabled)
 - SERIAL4 -> UART3 (GPS, DMA-enabled)
 - SERIAL5 -> UART4 (GPS, DMA-enabled)
 - SERIAL6 -> UART6 (RCIN, DMA-enabled)
 - SERIAL7 -> UART7 (ESC Telemetry, DMA-enabled)
 

## RC Input

The default RC input is configured on the UART3 (RX3/SBUS). Non SBUS,  single wire serial inputs can be directly tied to RX3 if SBUS pin is left unconnected. RC could  be applied instead at a different UART port such as UART4 or UART8, and set the protocol to receive RC data: ``SERIALn_PROTOCOL = 23`` and change SERIAL3 _Protocol to something other than '23'.

- PPM is supported.  
- SBUS/DSM/SRXL connects to the RX3 pin.  
- FPort requires connection to TX3. Set :ref:`SERIAL3_OPTIONS<SERIAL3_OPTIONS>` = 7  
- CRSF/ELRS also requires both TX3 and RX3 connections and provides telemetry automatically.

## OSD Support

Onboard OSD using OSD_TYPE 1 (MAX7456 driver) is supported by default. 

## PWM Output

The ITWL-FPV1.1 supports up to 10 PWM outputs. The pads for motor output
M1 to M12 are provided on the motor connector.

The PWM is in 4 groups:

* PWM 1-4 in group1 (TIM1)
* PWM 5-8 in group2 (TIM2)
* PWM 9-10 in group3 (TIM3)

Channels within the same group need to use the same output rate. If
any channel in a group uses DShot then all channels in the group need
to use DShot.

## Battery Monitoring

The board has a internal voltage sensor and connections on the ESC connector for an external current sensor input.
The voltage sensor can handle up to 12S LiPo batteries.

The default battery parameters are:

 - :ref:BATT_MONITOR<BATT_MONITOR> = 4
 - :ref:BATT_VOLT_PIN<BATT_VOLT_PIN__AP_BattMonitor_Analog> = 10
 - :ref:BATT_CURR_PIN<BATT_CURR_PIN__AP_BattMonitor_Analog> = 11 (CURR pin)
 - :ref:BATT_VOLT_MULT<BATT_VOLT_MULT__AP_BattMonitor_Analog> = 11.0
 - :ref:BATT_AMP_PERVLT<BATT_AMP_PERVLT__AP_BattMonitor_Analog> = 40

## Compass

The TWL-FPV1.1 have a compass on IMU module. Also can attach an external compass using I2C on the SDA and SCL connector.

## GPIOs

The numbering of the GPIOs for PIN variables in ardupilot is:

 - GPIO pin KAMERA A/B switches camera A or B to OSD
 - GPIO1 pin is ArduPilot GPIO 81
 - GPIO2 pin is ArduPilot GPIO 82

## Physical

- Mounting: 30.4 x 30.5mm
- Dimensions: 38 x 50 x 10 mm
- Weight: ?.?g

## Firmware

Firmware for the ITWL-FPV is available from //Z58/Pracownia SOIR/1. PROJEKTY/autopilot/ardupilot

## Loading Firmware

To flash firmware initially, connect USB while holding the bootloader button and use DFU to load the `with_bl.hex` file. Subsequent updates can be applied using `.apj` files through a ground station.
