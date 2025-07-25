# BMX160_SensorAPI
### Sensor overview
The BMX160 is a small, low-power, 9-axis inertial measurement unit (IMU) sensor developed by Bosch Sensortec. It integrates a 3-axis accelerometer, a 3-axis gyroscope, and a 3-axis geomagnetic sensor into a single package.

NOTE: Bosch does not provide a driver for the BMX160, instead the supported flow is to use the [BMI160](https://github.com/boschsensortec/BMI160_SensorAPI) and [BMM150](https://github.com/boschsensortec/BMM150_SensorAPI) sensor APIs together. Unfortunately, this requires a manual edit to the BMI160 driver source code to update the device ID. See the [Bosch community forum](https://community.bosch-sensortec.com/mems-sensors-forum-jrmujtaw/post/example-code-or-sensor-api-for-bmx160-Fr56z38hmtgSQAW) for details. This repository helps to mitigate the problem.

### Important Links
- [BMX160 Data Sheet](https://www.mouser.com/pdfdocs/BST-BMX160-DS000-11.pdf)
