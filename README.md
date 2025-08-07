# BMX160_SensorAPI
Bosch does not provide a dedicated sensor API for the BMX160. Instead, the recommended approach is to use the [BMI160](https://github.com/boschsensortec/BMI160_SensorAPI) and [BMM150](https://github.com/boschsensortec/BMM150_SensorAPI) sensor APIs together, For more information refer to the [Bosch community forum](https://community.bosch-sensortec.com/mems-sensors-forum-jrmujtaw/post/example-code-or-sensor-api-for-bmx160-Fr56z38hmtgSQAW). This repository aims to simplify that process.

## Sensor overview
The BMX160 is a small, low-power, 9-axis inertial measurement unit (IMU) sensor developed by Bosch Sensortec. It integrates a 3-axis accelerometer, a 3-axis gyroscope, and a 3-axis geomagnetic sensor into a single package.
### Key features
- High performance accelerometer and gyroscope, geomagnetic sensor
- Very low power consumption: typ. 1585 μA in high performance mode
- Android Marshmallow certified: significant motion, step detector / step counter (5 μA each)
- Very small 2.5 x 3.0 mm2 footprint, height 0.95 mm
- Built-in power management unit (PMU) for advanced power management
- Power saving with fast start-up mode of gyroscope
- Wide power supply range: 1.71 V … 3.6 V
- Allocatable FIFO buffer of 1024 bytes
- Hardware sensor time-stamps for accurate sensor data fusion
- Integrated interrupts for enhanced autonomous motion detection
- Flexible digital primary interface to connect to host over I2C or SPI
- Extended I2C mode with clock frequencies up to 1 MHz
### Important Links
- [BMX160 Data Sheet](https://www.mouser.com/pdfdocs/BST-BMX160-DS000-11.pdf)
