/**
* Copyright (c) 2025 Bosch Sensortec GmbH. All rights reserved.
*
* BSD-3-Clause
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
* 1. Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
*
* 2. Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the
*    documentation and/or other materials provided with the distribution.
*
* 3. Neither the name of the copyright holder nor the names of its
*    contributors may be used to endorse or promote products derived from
*    this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
* FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
* COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*
* @file       bmx160_defs.h
* @date       2025-07-25
* @version    v0.0
*
*/

#ifndef BMX160_DEFS_H_
#define BMX160_DEFS_H_

/*************************** C types headers *****************************/

#ifdef __KERNEL__
#include <linux/types.h>
#include <linux/kernel.h>
#else
#include <stdint.h>
#include <stddef.h>
#endif

/*************************** Common macros   *****************************/

#if !defined(UINT8_C) && !defined(INT8_C)
#define INT8_C(x)                                 S8_C(x)
#define UINT8_C(x)                                U8_C(x)
#endif

#if !defined(UINT16_C) && !defined(INT16_C)
#define INT16_C(x)                                S16_C(x)
#define UINT16_C(x)                               U16_C(x)
#endif

#if !defined(INT32_C) && !defined(UINT32_C)
#define INT32_C(x)                                S32_C(x)
#define UINT32_C(x)                               U32_C(x)
#endif

#if !defined(INT64_C) && !defined(UINT64_C)
#define INT64_C(x)                                S64_C(x)
#define UINT64_C(x)                               U64_C(x)
#endif

/**@}*/
/**\name C standard macros */
#ifndef NULL                                                          // NULL is a macro defined in standard C and C++ headers <stddef.h>, <stdio.h>, <stdlib.h>
#ifdef __cplusplus                                                    // __cplusplus is a predefined macro provided by the compiler when compiling C++ code.
#define NULL                                      0
#else
#define NULL                                      ((void *) 0)
#endif
#endif

/*************************** Sensor macros   *****************************/

/* Test for an endian machine */
// check for Endianness. ie how the order in which bytes are arranged in multi-byte data types like int
// compilers like GCC define these macros __BYTE_ORDER__, __ORDER_LITTLE_ENDIAN__
// if not defined anything assume it as little endian
#ifndef __ORDER_LITTLE_ENDIAN__
#define __ORDER_LITTLE_ENDIAN__                   0
#endif                                 

#ifndef __BYTE_ORDER__
#define __BYTE_ORDER__                            __ORDER_LITTLE_ENDIAN__
#endif

#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#ifndef LITTLE_ENDIAN
#define LITTLE_ENDIAN                             1
#endif
#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#ifndef BIG_ENDIAN
#define BIG_ENDIAN                                1
#endif
#else
#error "Code does not support Endian format of the processor"
#endif

/** Mask definitions */
#define BMX160_ACCEL_BW_MASK                      UINT8_C(0x70)
#define BMX160_ACCEL_ODR_MASK                     UINT8_C(0x0F)
#define BMX160_ACCEL_UNDERSAMPLING_MASK           UINT8_C(0x80)
#define BMX160_ACCEL_RANGE_MASK                   UINT8_C(0x0F)
#define BMX160_GYRO_BW_MASK                       UINT8_C(0x30)
#define BMX160_GYRO_ODR_MASK                      UINT8_C(0x0F)
#define BMX160_GYRO_RANGE_MASK                    UINT8_C(0x07)

#define BMX160_ACCEL_BW_POS                       UINT8_C(4)
#define BMX160_GYRO_BW_POS                        UINT8_C(4)

/** Mask definitions for INT_EN registers */
#define BMX160_ANY_MOTION_X_INT_EN_MASK           UINT8_C(0x01)
#define BMX160_HIGH_G_X_INT_EN_MASK               UINT8_C(0x01)
#define BMX160_NO_MOTION_X_INT_EN_MASK            UINT8_C(0x01)
#define BMX160_ANY_MOTION_Y_INT_EN_MASK           UINT8_C(0x02)
#define BMX160_HIGH_G_Y_INT_EN_MASK               UINT8_C(0x02)
#define BMX160_NO_MOTION_Y_INT_EN_MASK            UINT8_C(0x02)
#define BMX160_ANY_MOTION_Z_INT_EN_MASK           UINT8_C(0x04)
#define BMX160_HIGH_G_Z_INT_EN_MASK               UINT8_C(0x04)
#define BMX160_NO_MOTION_Z_INT_EN_MASK            UINT8_C(0x04)
#define BMX160_SIG_MOTION_INT_EN_MASK             UINT8_C(0x07)
#define BMX160_ANY_MOTION_ALL_INT_EN_MASK         UINT8_C(0x07)
#define BMX160_STEP_DETECT_INT_EN_MASK            UINT8_C(0x08)
#define BMX160_DOUBLE_TAP_INT_EN_MASK             UINT8_C(0x10)
#define BMX160_SINGLE_TAP_INT_EN_MASK             UINT8_C(0x20)
#define BMX160_FIFO_FULL_INT_EN_MASK              UINT8_C(0x20)
#define BMX160_ORIENT_INT_EN_MASK                 UINT8_C(0x40)
#define BMX160_FIFO_WATERMARK_INT_EN_MASK         UINT8_C(0x40)
#define BMX160_LOW_G_INT_EN_MASK                  UINT8_C(0x08)
#define BMX160_STEP_DETECT_EN_MASK                UINT8_C(0x08)
#define BMX160_FLAT_INT_EN_MASK                   UINT8_C(0x80)
#define BMX160_DATA_RDY_INT_EN_MASK               UINT8_C(0x10)

/** PMU status Macros */   // check if need this
#define BMX160_AUX_PMU_SUSPEND                    UINT8_C(0x00)
#define BMX160_AUX_PMU_NORMAL                     UINT8_C(0x01)
#define BMX160_AUX_PMU_LOW_POWER                  UINT8_C(0x02)

#define BMX160_GYRO_PMU_SUSPEND                   UINT8_C(0x00)
#define BMX160_GYRO_PMU_NORMAL                    UINT8_C(0x01)
#define BMX160_GYRO_PMU_FSU                       UINT8_C(0x03)

#define BMX160_ACCEL_PMU_SUSPEND                  UINT8_C(0x00)
#define BMX160_ACCEL_PMU_NORMAL                   UINT8_C(0x01)
#define BMX160_ACCEL_PMU_LOW_POWER                UINT8_C(0x02)

/** Mask definitions for INT_OUT_CTRL register */
#define BMX160_INT1_EDGE_CTRL_MASK                UINT8_C(0x01)
#define BMX160_INT1_OUTPUT_MODE_MASK              UINT8_C(0x04)
#define BMX160_INT1_OUTPUT_TYPE_MASK              UINT8_C(0x02)
#define BMX160_INT1_OUTPUT_EN_MASK                UINT8_C(0x08)
#define BMX160_INT2_EDGE_CTRL_MASK                UINT8_C(0x10)
#define BMX160_INT2_OUTPUT_MODE_MASK              UINT8_C(0x40)
#define BMX160_INT2_OUTPUT_TYPE_MASK              UINT8_C(0x20)
#define BMX160_INT2_OUTPUT_EN_MASK                UINT8_C(0x80)

/** Mask definitions for INT_LATCH register */
#define BMX160_INT1_INPUT_EN_MASK                 UINT8_C(0x10)
#define BMX160_INT2_INPUT_EN_MASK                 UINT8_C(0x20)
#define BMX160_INT_LATCH_MASK                     UINT8_C(0x0F)

/** Mask definitions for INT_MAP register */
#define BMX160_INT1_LOW_G_MASK                    UINT8_C(0x01)
#define BMX160_INT1_HIGH_G_MASK                   UINT8_C(0x02)
#define BMX160_INT1_SLOPE_MASK                    UINT8_C(0x04)
#define BMX160_INT1_NO_MOTION_MASK                UINT8_C(0x08)
#define BMX160_INT1_DOUBLE_TAP_MASK               UINT8_C(0x10)
#define BMX160_INT1_SINGLE_TAP_MASK               UINT8_C(0x20)
#define BMX160_INT1_FIFO_FULL_MASK                UINT8_C(0x20)
#define BMX160_INT1_FIFO_WM_MASK                  UINT8_C(0x40)
#define BMX160_INT1_ORIENT_MASK                   UINT8_C(0x40)
#define BMX160_INT1_FLAT_MASK                     UINT8_C(0x80)
#define BMX160_INT1_DATA_READY_MASK               UINT8_C(0x80)
#define BMX160_INT2_LOW_G_MASK                    UINT8_C(0x01)
#define BMX160_INT1_LOW_STEP_DETECT_MASK          UINT8_C(0x01)
#define BMX160_INT2_LOW_STEP_DETECT_MASK          UINT8_C(0x01)
#define BMX160_INT2_HIGH_G_MASK                   UINT8_C(0x02)
#define BMX160_INT2_FIFO_FULL_MASK                UINT8_C(0x02)
#define BMX160_INT2_FIFO_WM_MASK                  UINT8_C(0x04)
#define BMX160_INT2_SLOPE_MASK                    UINT8_C(0x04)
#define BMX160_INT2_DATA_READY_MASK               UINT8_C(0x08)
#define BMX160_INT2_NO_MOTION_MASK                UINT8_C(0x08)
#define BMX160_INT2_DOUBLE_TAP_MASK               UINT8_C(0x10)
#define BMX160_INT2_SINGLE_TAP_MASK               UINT8_C(0x20)
#define BMX160_INT2_ORIENT_MASK                   UINT8_C(0x40)
#define BMX160_INT2_FLAT_MASK                     UINT8_C(0x80)

/** Mask definitions for INT_DATA register */
#define BMX160_TAP_SRC_INT_MASK                   UINT8_C(0x08)
#define BMX160_LOW_HIGH_SRC_INT_MASK              UINT8_C(0x80)
#define BMX160_MOTION_SRC_INT_MASK                UINT8_C(0x80)

/** Mask definitions for INT_MOTION register */
#define BMX160_SLOPE_INT_DUR_MASK                 UINT8_C(0x03)
#define BMX160_NO_MOTION_INT_DUR_MASK             UINT8_C(0xFC)
#define BMX160_NO_MOTION_SEL_BIT_MASK             UINT8_C(0x01)

/** Mask definitions for INT_TAP register */
#define BMX160_TAP_DUR_MASK                       UINT8_C(0x07)
#define BMX160_TAP_SHOCK_DUR_MASK                 UINT8_C(0x40)
#define BMX160_TAP_QUIET_DUR_MASK                 UINT8_C(0x80)
#define BMX160_TAP_THRES_MASK                     UINT8_C(0x1F)

/** Mask definitions for INT_FLAT register */
#define BMX160_FLAT_THRES_MASK                    UINT8_C(0x3F)
#define BMX160_FLAT_HOLD_TIME_MASK                UINT8_C(0x30)
#define BMX160_FLAT_HYST_MASK                     UINT8_C(0x07)

/** Mask definitions for INT_LOWHIGH register */
#define BMX160_LOW_G_HYST_MASK                    UINT8_C(0x03)
#define BMX160_LOW_G_LOW_MODE_MASK                UINT8_C(0x04)
#define BMX160_HIGH_G_HYST_MASK                   UINT8_C(0xC0)

/** Mask definitions for INT_SIG_MOTION register */
#define BMX160_SIG_MOTION_SEL_MASK                UINT8_C(0x02)
#define BMX160_SIG_MOTION_SKIP_MASK               UINT8_C(0x0C)
#define BMX160_SIG_MOTION_PROOF_MASK              UINT8_C(0x30)

/** Mask definitions for INT_ORIENT register */
#define BMX160_ORIENT_MODE_MASK                   UINT8_C(0x03)
#define BMX160_ORIENT_BLOCK_MASK                  UINT8_C(0x0C)
#define BMX160_ORIENT_HYST_MASK                   UINT8_C(0xF0)
#define BMX160_ORIENT_THETA_MASK                  UINT8_C(0x3F)
#define BMX160_ORIENT_UD_ENABLE                   UINT8_C(0x40)
#define BMX160_AXES_EN_MASK                       UINT8_C(0x80)

/** Mask definitions for FIFO_CONFIG register */
#define BMX160_FIFO_GYRO                          UINT8_C(0x80)
#define BMX160_FIFO_ACCEL                         UINT8_C(0x40)
#define BMX160_FIFO_MAG                           UINT8_C(0x20)
#define BMX160_FIFO_TAG_INT1                      UINT8_C(0x08)
#define BMX160_FIFO_TAG_INT2                      UINT8_C(0x04)
#define BMX160_FIFO_TIME                          UINT8_C(0x02)
#define BMX160_FIFO_HEADER                        UINT8_C(0x10)
#define BMX160_FIFO_CONFIG_1_MASK                 UINT8_C(0xFE)

/** Mask definitions for STEP_CONF register */
#define BMX160_STEP_COUNT_EN_BIT_MASK             UINT8_C(0x08)
#define BMX160_STEP_DETECT_MIN_THRES_MASK         UINT8_C(0x18)
#define BMX160_STEP_DETECT_STEPTIME_MIN_MASK      UINT8_C(0x07)
#define BMX160_STEP_MIN_BUF_MASK                  UINT8_C(0x07)

/** Mask definition for FIFO Header Data Tag */
#define BMX160_FIFO_TAG_INTR_MASK                 UINT8_C(0xFC)

/** Fifo byte counter mask definitions */
#define BMX160_FIFO_BYTE_COUNTER_MASK             UINT8_C(0x07)

/** Enable/disable bit value */
#define BMX160_ENABLE                             UINT8_C(0x01)
#define BMX160_DISABLE                            UINT8_C(0x00)

/** Latch Duration */
#define BMX160_LATCH_DUR_NONE                     UINT8_C(0x00)
#define BMX160_LATCH_DUR_312_5_MICRO_SEC          UINT8_C(0x01)
#define BMX160_LATCH_DUR_625_MICRO_SEC            UINT8_C(0x02)
#define BMX160_LATCH_DUR_1_25_MILLI_SEC           UINT8_C(0x03)
#define BMX160_LATCH_DUR_2_5_MILLI_SEC            UINT8_C(0x04)
#define BMX160_LATCH_DUR_5_MILLI_SEC              UINT8_C(0x05)
#define BMX160_LATCH_DUR_10_MILLI_SEC             UINT8_C(0x06)
#define BMX160_LATCH_DUR_20_MILLI_SEC             UINT8_C(0x07)
#define BMX160_LATCH_DUR_40_MILLI_SEC             UINT8_C(0x08)
#define BMX160_LATCH_DUR_80_MILLI_SEC             UINT8_C(0x09)
#define BMX160_LATCH_DUR_160_MILLI_SEC            UINT8_C(0x0A)
#define BMX160_LATCH_DUR_320_MILLI_SEC            UINT8_C(0x0B)
#define BMX160_LATCH_DUR_640_MILLI_SEC            UINT8_C(0x0C)
#define BMX160_LATCH_DUR_1_28_SEC                 UINT8_C(0x0D)
#define BMX160_LATCH_DUR_2_56_SEC                 UINT8_C(0x0E)
#define BMX160_LATCHED                            UINT8_C(0x0F)

/** BMX160 Register map */
#define BMX160_CHIP_ID_ADDR                       UINT8_C(0x00)
#define BMX160_ERROR_REG_ADDR                     UINT8_C(0x02)
#define BMX160_PMU_STATUS_ADDR                    UINT8_C(0x03)  // The register shows the current power mode of the sensor (aacl, gyro. mag)
#define BMX160_MAG_DATA_ADDR                      UINT8_C(0x04)
#define BMX160_GYRO_DATA_ADDR                     UINT8_C(0x0C)
#define BMX160_ACCEL_DATA_ADDR                    UINT8_C(0x12)
#define BMX160_STATUS_ADDR                        UINT8_C(0x1B)
#define BMX160_INT_STATUS_ADDR                    UINT8_C(0x1C)
#define BMX160_FIFO_LENGTH_ADDR                   UINT8_C(0x22)
#define BMX160_FIFO_DATA_ADDR                     UINT8_C(0x24)
#define BMX160_ACCEL_CONFIG_ADDR                  UINT8_C(0x40)
#define BMX160_ACCEL_RANGE_ADDR                   UINT8_C(0x41)
#define BMX160_GYRO_CONFIG_ADDR                   UINT8_C(0x42)
#define BMX160_GYRO_RANGE_ADDR                    UINT8_C(0x43)
#define BMX160_MAG_CONFIG_ADDR                    UINT8_C(0x44)
#define BMX160_FIFO_DOWN_ADDR                     UINT8_C(0x45)
#define BMX160_FIFO_CONFIG_0_ADDR                 UINT8_C(0x46)
#define BMX160_FIFO_CONFIG_1_ADDR                 UINT8_C(0x47)
#define BMX160_MAG_RANGE_ADDR                     UINT8_C(0x4B)
#define BMX160_MAG_IF_0_ADDR                      UINT8_C(0x4C)
#define BMX160_MAG_IF_1_ADDR                      UINT8_C(0x4D)
#define BMX160_MAG_IF_2_ADDR                      UINT8_C(0x4E)
#define BMX160_MAG_IF_3_ADDR                      UINT8_C(0x4F)
#define BMX160_INT_ENABLE_0_ADDR                  UINT8_C(0x50)
#define BMX160_INT_ENABLE_1_ADDR                  UINT8_C(0x51)
#define BMX160_INT_ENABLE_2_ADDR                  UINT8_C(0x52)
#define BMX160_INT_OUT_CTRL_ADDR                  UINT8_C(0x53)
#define BMX160_INT_LATCH_ADDR                     UINT8_C(0x54)
#define BMX160_INT_MAP_0_ADDR                     UINT8_C(0x55)
#define BMX160_INT_MAP_1_ADDR                     UINT8_C(0x56)
#define BMX160_INT_MAP_2_ADDR                     UINT8_C(0x57)
#define BMX160_INT_DATA_0_ADDR                    UINT8_C(0x58)
#define BMX160_INT_DATA_1_ADDR                    UINT8_C(0x59)
#define BMX160_INT_LOWHIGH_0_ADDR                 UINT8_C(0x5A)
#define BMX160_INT_LOWHIGH_1_ADDR                 UINT8_C(0x5B)
#define BMX160_INT_LOWHIGH_2_ADDR                 UINT8_C(0x5C)
#define BMX160_INT_LOWHIGH_3_ADDR                 UINT8_C(0x5D)
#define BMX160_INT_LOWHIGH_4_ADDR                 UINT8_C(0x5E)
#define BMX160_INT_MOTION_0_ADDR                  UINT8_C(0x5F)
#define BMX160_INT_MOTION_1_ADDR                  UINT8_C(0x60)
#define BMX160_INT_MOTION_2_ADDR                  UINT8_C(0x61)
#define BMX160_INT_MOTION_3_ADDR                  UINT8_C(0x62)
#define BMX160_INT_TAP_0_ADDR                     UINT8_C(0x63)
#define BMX160_INT_TAP_1_ADDR                     UINT8_C(0x64)
#define BMX160_INT_ORIENT_0_ADDR                  UINT8_C(0x65)
#define BMX160_INT_ORIENT_1_ADDR                  UINT8_C(0x66)
#define BMX160_INT_FLAT_0_ADDR                    UINT8_C(0x67)
#define BMX160_INT_FLAT_1_ADDR                    UINT8_C(0x68)
#define BMX160_FOC_CONF_ADDR                      UINT8_C(0x69)
#define BMX160_CONF_ADDR                          UINT8_C(0x6A)

#define BMX160_IF_CONF_ADDR                       UINT8_C(0x6B)
#define BMX160_SELF_TEST_ADDR                     UINT8_C(0x6D)
#define BMX160_OFFSET_ADDR                        UINT8_C(0x71)
#define BMX160_OFFSET_CONF_ADDR                   UINT8_C(0x77)
#define BMX160_INT_STEP_CNT_0_ADDR                UINT8_C(0x78)
#define BMX160_INT_STEP_CONFIG_0_ADDR             UINT8_C(0x7A)
#define BMX160_INT_STEP_CONFIG_1_ADDR             UINT8_C(0x7B)
#define BMX160_COMMAND_REG_ADDR                   UINT8_C(0x7E)
#define BMX160_SPI_COMM_TEST_ADDR                 UINT8_C(0x7F)
#define BMX160_INTL_PULLUP_CONF_ADDR              UINT8_C(0x85)

/** Error code definitions */
#define BMX160_OK                                 INT8_C(0)
#define BMX160_E_NULL_PTR                         INT8_C(-1)
#define BMX160_E_COM_FAIL                         INT8_C(-2)
#define BMX160_E_DEV_NOT_FOUND                    INT8_C(-3)
#define BMX160_E_OUT_OF_RANGE                     INT8_C(-4)
#define BMX160_E_INVALID_INPUT                    INT8_C(-5)
#define BMX160_E_ACCEL_ODR_BW_INVALID             INT8_C(-6)
#define BMX160_E_GYRO_ODR_BW_INVALID              INT8_C(-7)
#define BMX160_E_LWP_PRE_FLTR_INT_INVALID         INT8_C(-8)
#define BMX160_E_LWP_PRE_FLTR_INVALID             INT8_C(-9)
#define BMX160_E_MAG_NOT_FOUND                    INT8_C(-10)
#define BMX160_E_FOC_FAILURE                      INT8_C(-11)
#define BMX160_E_READ_WRITE_LENGTH_INVALID        INT8_C(-12) // check what is it
#define BMX160_E_INVALID_CONFIG                   INT8_C(-13) // check what is it

/**\name API warning codes */
#define BMX160_W_GYRO_SELF_TEST_FAIL              INT8_C(1)
#define BMX160_W_ACCEl_SELF_TEST_FAIL             INT8_C(2)

/** BMX160 unique chip identifier */
#define BMX160_CHIP_ID                            UINT8_C(0xD8)

/** Soft reset command */
#define BMX160_SOFT_RESET_CMD                     UINT8_C(0xb6)
#define BMX160_SOFT_RESET_DELAY_MS                UINT8_C(15)

/** Start FOC command */
#define BMX160_START_FOC_CMD                      UINT8_C(0x03)

/** NVM backup enabling command */
#define BMX160_NVM_BACKUP_EN                      UINT8_C(0xA0)

/* Delay in ms settings */
#define BMX160_ACCEL_DELAY_MS                     UINT8_C(5)
#define BMX160_GYRO_DELAY_MS                      UINT8_C(80)
#define BMX160_ONE_MS_DELAY                       UINT8_C(1)
#define BMX160_MAG_COM_DELAY                      UINT8_C(10)
#define BMX160_GYRO_SELF_TEST_DELAY               UINT8_C(20)
#define BMX160_ACCEL_SELF_TEST_DELAY              UINT8_C(50)

/** Self test configurations */
#define BMX160_ACCEL_SELF_TEST_CONFIG             UINT8_C(0x2C)
#define BMX160_ACCEL_SELF_TEST_POSITIVE_EN        UINT8_C(0x0D)
#define BMX160_ACCEL_SELF_TEST_NEGATIVE_EN        UINT8_C(0x09)
#define BMX160_ACCEL_SELF_TEST_LIMIT              UINT16_C(8192)

/** Power mode settings */
/* Accel power mode */
#define BMX160_ACCEL_NORMAL_MODE                  UINT8_C(0x11)
#define BMX160_ACCEL_LOWPOWER_MODE                UINT8_C(0x12)
#define BMX160_ACCEL_SUSPEND_MODE                 UINT8_C(0x10)

/* Gyro power mode */
#define BMX160_GYRO_SUSPEND_MODE                  UINT8_C(0x14)
#define BMX160_GYRO_NORMAL_MODE                   UINT8_C(0x15)
#define BMX160_GYRO_FASTSTARTUP_MODE              UINT8_C(0x17)

/* Magneto power mode */
#define BMX160_MAG_SUSPEND_MODE                   UINT8_C(0x18)
#define BMX160_MAG_NORMAL_MODE                    UINT8_C(0x19)
#define BMX160_MAG_LOWPOWER_MODE                  UINT8_C(0x1A)

/** Range settings */
/* Accel Range */
#define BMX160_ACCEL_RANGE_2G                     UINT8_C(0x03)
#define BMX160_ACCEL_RANGE_4G                     UINT8_C(0x05)
#define BMX160_ACCEL_RANGE_8G                     UINT8_C(0x08)
#define BMX160_ACCEL_RANGE_16G                    UINT8_C(0x0C)

/* Gyro Range */
#define BMX160_GYRO_RANGE_2000_DPS                UINT8_C(0x00)
#define BMX160_GYRO_RANGE_1000_DPS                UINT8_C(0x01)
#define BMX160_GYRO_RANGE_500_DPS                 UINT8_C(0x02)
#define BMX160_GYRO_RANGE_250_DPS                 UINT8_C(0x03)
#define BMX160_GYRO_RANGE_125_DPS                 UINT8_C(0x04)