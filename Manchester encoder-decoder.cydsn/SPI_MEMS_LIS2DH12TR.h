/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "cyfitter.h"
#include "cytypes.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

/***************************************
*        Data Struct Definition
***************************************/



/***************************************
*           API Constants
***************************************/

#define MEMS_ADDR_STATUS_REG_AUX (0x07)
#define MEMS_ADDR_OUT_TEMP_L (0x0C)
#define MEMS_ADDR_OUT_TEMP_H (0x0D)

#define MEMS_ADDR_WHO_AM_I (0x0F)
#define MEMS_DEFAULT_WHO_AM_I (0x33)

#define MEMS_ADDR_CTRL_REG0 (0x1E)
#define MEMS_DEFAULT_CTRL_REG0 (0x10)



#define MEMS_ADDR_TEMP_CFG_REG (0x1F)
#define MEMS_DEFAULT_TEMP_CFG_REG (0x00)

#define MEMS_ADDR_CTRL_REG1 (0x20)
#define MEMS_DEFAULT_CTRL_REG1 (0x07)

#define MEMS_PWR_DWN_CTRL_REG1 (0x00)
#define MEMS_ODR_1Hz_CTRL_REG1 (0x10)
#define MEMS_ODR_10Hz_CTRL_REG1 (0x20)
#define MEMS_ODR_25Hz_CTRL_REG1 (0x30)
#define MEMS_ODR_50Hz_CTRL_REG1 (0x40)
#define MEMS_ODR_100Hz_CTRL_REG1 (0x50)
#define MEMS_ODR_200Hz_CTRL_REG1 (0x60)
#define MEMS_ODR_400Hz_CTRL_REG1 (0x70)
#define MEMS_ODR_1620Hz_CTRL_REG1 (0x80)
#define MEMS_ODR_5376Hz_CTRL_REG1 (0x90)

#define MEMS_HR_MODE_CTRL_REG1 (0x00)
#define MEMS_LP_MODE_CTRL_REG1 (0x08)

#define MEMS_Zen_MODE_CTRL_REG1 (0x04)

#define MEMS_Yen_MODE_CTRL_REG1 (0x02)

#define MEMS_Xen_MODE_CTRL_REG1 (0x01)

#define MEMS_ADDR_CTRL_REG2 (0x21)
#define MEMS_DEFAULT_CTRL_REG2 (0x00)

//to do datasheet

#define MEMS_ADDR_CTRL_REG3 (0x22)
#define MEMS_DEFAULT_CTRL_REG3 (0x00)

//to do datasheet

#define MEMS_ADDR_CTRL_REG4 (0x23)
#define MEMS_DEFAULT_CTRL_REG4 (0x00)

//to do datasheet

#define MEMS_ADDR_CTRL_REG5 (0x24)
#define MEMS_DEFAULT_CTRL_REG5 (0x00)

//to do datasheet

#define MEMS_ADDR_CTRL_REG6 (0x25)
#define MEMS_DEFAULT_CTRL_REG6 (0x00)

//to do datasheet

#define MEMS_ADDR_REFERENCE (0x26)
#define MEMS_DEFAULT_REFERENCE (0x00)

//to do datasheet

#define MEMS_ADDR_STATUS_REG (0x27)
#define MEMS_ADDR_OUT_X_L (0x28)
#define MEMS_ADDR_OUT_X_H (0x29)
#define MEMS_ADDR_OUT_Y_L (0x2A)
#define MEMS_ADDR_OUT_Y_H (0x2B)
#define MEMS_ADDR_OUT_Z_L (0x2C)
#define MEMS_ADDR_OUT_Z_H (0x2D)

#define MEMS_ADDR_FIFO_CTRL_REG (0x2E)
#define MEMS_DEFAULT_FIFO_CTRL_REG (0x00)

#define MEMS_ADDR_FIFO_SRC_REG (0x2F)

#define MEMS_ADDR_INT1_CFG (0x30)
#define MEMS_DEFAULT_INT1_CFG (0x00)

#define MEMS_ADDR_INT1_SRC (0x31)

#define MEMS_ADDR_INT1_THS (0x32)
#define MEMS_DEFAULT_INT1_THS (0x00)

#define MEMS_ADDR_INT1_DURATION (0x33)
#define MEMS_DEFAULT_INT1_DURATION (0x00)

#define MEMS_ADDR_INT2_CFG (0x34)
#define MEMS_DEFAULT_INT2_CFG (0x00)

#define MEMS_ADDR_INT2_SRC (0x35)

#define MEMS_ADDR_INT2_THS (0x36)
#define MEMS_DEFAULT_INT2_THS (0x00)

#define MEMS_ADDR_INT2_DURATION (0x37)
#define MEMS_DEFAULT_INT2_DURATION (0x00)

#define MEMS_ADDR_CLICK_CFG (0x38)
#define MEMS_DEFAULT_CLICK_CFG (0x00)

#define MEMS_ADDR_CLICK_SRC (0x39)

#define MEMS_ADDR_CLICK_THS (0x3A)
#define MEMS_DEFAULT_CLICK_THS (0x00)

#define MEMS_ADDR_TIME_LIMIT (0x3B)
#define MEMS_DEFAULT_TIME_LIMIT (0x00)

#define MEMS_ADDR_TIME_LATENCY (0x3C)
#define MEMS_DEFAULT_TIME_LATENCY (0x00)

#define MEMS_ADDR_TIME_WINDOW (0x3D)
#define MEMS_DEFAULT_TIME_WINDOW (0x00)

#define MEMS_ADDR_ACT_THS (0x3E)
#define MEMS_DEFAULT_ACT_THS (0x00)

#define MEMS_ADDR_ACT_DUR (0x3F)
#define MEMS_DEFAULT_ACT_DUR (0x00)



/* [] END OF FILE */
