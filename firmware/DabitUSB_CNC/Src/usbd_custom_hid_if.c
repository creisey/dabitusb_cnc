/**
  ******************************************************************************
  * @file           : usbd_custom_hid_if.c
  * @brief          : USB Device Custom HID interface file.
  ******************************************************************************
  * COPYRIGHT(c) 2016 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  * 1. Redistributions of source code must retain the above copyright notice,
  * this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  * this list of conditions and the following disclaimer in the documentation
  * and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of its contributors
  * may be used to endorse or promote products derived from this software
  * without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include "usbd_custom_hid_if.h"
/* USER CODE BEGIN INCLUDE */
#include "commpackets.h"
#include "housekeeping.h"
#include <machine/endian.h>		/* Defines BYTE_ORDER to be either BIG_ENDIAN or LITTLE_ENDIAN */

#if BYTE_ORDER != LITTLE_ENDIAN
#error Compile in little-endian mode please
#endif
/* USER CODE END INCLUDE */
/** @addtogroup STM32_USB_OTG_DEVICE_LIBRARY
  * @{
  */

/** @defgroup USBD_CUSTOM_HID 
  * @brief usbd core module
  * @{
  */ 

/** @defgroup USBD_CUSTOM_HID_Private_TypesDefinitions
  * @{
  */ 
/* USER CODE BEGIN PRIVATE_TYPES */
/* USER CODE END PRIVATE_TYPES */ 
/**
  * @}
  */ 

/** @defgroup USBD_CUSTOM_HID_Private_Defines
  * @{
  */ 
/* USER CODE BEGIN PRIVATE_DEFINES */
/* USER CODE END PRIVATE_DEFINES */
  
/**
  * @}
  */ 

/** @defgroup USBD_CUSTOM_HID_Private_Macros
  * @{
  */ 
/* USER CODE BEGIN PRIVATE_MACRO */
/* USER CODE END PRIVATE_MACRO */

/**
  * @}
  */ 

/** @defgroup USBD_AUDIO_IF_Private_Variables
 * @{
 */
__ALIGN_BEGIN static uint8_t CUSTOM_HID_ReportDesc_FS[USBD_CUSTOM_HID_REPORT_DESC_SIZE] __ALIGN_END =
{
  /* USER CODE BEGIN 0 */ 
	// desc size=(28 bytes)
		0x06, 0x12, 0xff,							// Usage page 0xff12
		0x0A, 0x00, 0x02,							// rawhid usage 0x0200
		0xA1, 0x01,										// Collection 0x01
		0x75, 0x08,										// report size = 8 bits
		0x15, 0x00,										// logical minimum = 0
		0x26, 0xFF, 0x00,							// logical maximum = 255
		0x95, CUSTOM_HID_EPIN_SIZE,		// report count
		0x09, 0x01,										// usage
		0x81, 0x02,										// Input (array)
		0x95, CUSTOM_HID_EPOUT_SIZE,	// report count
		0x09, 0x02,				// usage
		0x91, 0x02,				// Output (array)

	#if 0
		// desc size=(33 bytes)
	  0x06, 0x00, 0xFF,              // USAGE_PAGE = 0xFF00 (Vendor Defined Page 1)
		0x09, 0x01,                    // USAGE (Vendor Usage 1)
		0xa1, 0x01,                    // COLLECTION (Application)

		  // IN report

		0x19, 0x01,                    // Usage Minimum
		0x29, 0x40,                    // Usage Maximum
		0x15, 0x00,										 // Logical Minimum (value 0x00)
	  0x26, 0xFF, 0x00,							 // Logical Maximum (0x00ff == 255)
		0x75, 0x08,										 // Report Size: 8-bit field size
		0x95, CUSTOM_HID_EPIN_SIZE,    //   REPORT_COUNT (this is the byte length)
		0x81, 0x02,                    //   INPUT (Data,Array,Abs)

		  // OUT report

		0x19, 0x01,                    // Usage Minimum
		0x29, 0x40,                    // Usage Maximum
	  0x75, 0x08,										 //Report Size: 8-bit field size
	
		0x95, CUSTOM_HID_EPOUT_SIZE,   //   REPORT_COUNT (this is the byte length)
		0x91, 0x02,                    //   OUTPUT (Data,Array,Abs)
  /* USER CODE END 0 */ 
#endif
	  0xC0    /*     END_COLLECTION	             */
   
}; 

/* USER CODE BEGIN PRIVATE_VARIABLES */
/* USER CODE END PRIVATE_VARIABLES */
/**
  * @}
  */ 
  
/** @defgroup USBD_CUSTOM_HID_IF_Exported_Variables
  * @{
  */ 
  extern USBD_HandleTypeDef hUsbDeviceFS;
/* USER CODE BEGIN EXPORTED_VARIABLES */
/* USER CODE END EXPORTED_VARIABLES */

/**
  * @}
  */ 
  
/** @defgroup USBD_CUSTOM_HID_Private_FunctionPrototypes
  * @{
  */
static int8_t CUSTOM_HID_Init_FS     (void);
static int8_t CUSTOM_HID_DeInit_FS   (void);
static int8_t CUSTOM_HID_OutEvent_FS (uint8_t event_idx, uint8_t state);
 

USBD_CUSTOM_HID_ItfTypeDef USBD_CustomHID_fops_FS = 
{
  CUSTOM_HID_ReportDesc_FS,
  CUSTOM_HID_Init_FS,
  CUSTOM_HID_DeInit_FS,
  CUSTOM_HID_OutEvent_FS,
};

/* Private functions ---------------------------------------------------------*/
/**
  * @brief  CUSTOM_HID_Init_FS
  *         Initializes the CUSTOM HID media low layer
  * @param  None
  * @retval Result of the operation: USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CUSTOM_HID_Init_FS(void)
{ 
  /* USER CODE BEGIN 4 */ 
  return (0);
  /* USER CODE END 4 */ 
}

/**
  * @brief  CUSTOM_HID_DeInit_FS
  *         DeInitializes the CUSTOM HID media low layer
  * @param  None
  * @retval Result of the operation: USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CUSTOM_HID_DeInit_FS(void)
{
  /* USER CODE BEGIN 5 */ 
  return (0);
  /* USER CODE END 5 */ 
}

/**
  * @brief  CUSTOM_HID_OutEvent_FS
  *         Manage the CUSTOM HID class events       
  * @param  event_idx: event index
  * @param  state: event state
  * @retval Result of the operation: USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CUSTOM_HID_OutEvent_FS  (uint8_t event_idx, uint8_t state)
{ 
  /* USER CODE BEGIN 6 */ 
	USBD_CUSTOM_HID_HandleTypeDef *hhid = (USBD_CUSTOM_HID_HandleTypeDef *)hUsbDeviceFS.pClassData;
	uint8_t *data;
	uint8_t idx=0, tmp, loopctr=16, i;
	while (idx<64 && --loopctr) {
		data = &hhid->Report_buf[idx];
		/* Determine packet type and process the packet */
		switch (data[1]) {
			/* Timestamp? */
			case PKT_TIMESTAMP_USEC_ID:
				//prim = __get_PRIMASK();
				__disable_irq();
				sender_timestamp = ((sPkt_Timestamp *)data)->timestamp;
				bGotData = true;
				__enable_irq();
				break;
			/* Command for a motor */
			case PKT_JOINTMOTOR_ID:
				tmp = ((sPkt_JointMotor *)data)->jointnr;
				if (tmp >= NR_JOINTS)
					break;
				//prim = __get_PRIMASK();
				__disable_irq();
				ja[tmp].commanded_position = ((sPkt_JointMotor *)data)->position;
				ja[tmp].commanded_velocity = ((sPkt_JointMotor *)data)->velocity;
				ja[tmp].commanded_acceleration = ((sPkt_JointMotor *)data)->acceleration;
				bGotData = true;
				CommTimeoutCtr = COMM_TIMEOUT;
				__enable_irq();
				break;
			/* Digital output */
			case PKT_DIGITALIO_ID:
				// Only handle address 0
				if (((sPkt_DigIO8 *)data)->address == 0) {
					tmp = ((sPkt_DigIO8 *)data)->value;
					HAL_GPIO_WritePin(DIGOUT0_GPIO_Port, DIGOUT0_Pin, tmp & 0x01);
					HAL_GPIO_WritePin(DIGOUT1_GPIO_Port, DIGOUT1_Pin, tmp & 0x02);
					HAL_GPIO_WritePin(DIGOUT2_GPIO_Port, DIGOUT2_Pin, tmp & 0x04);
					HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, !(tmp & 0x08));
				}
				break;
			/* Complete host-to-machine packet? */
			case PKT_DABITUSB_H2M_V1:
				__disable_irq();
				// joint data
				for (i=0;i<NR_JOINTS;i++) {
					ja[i].commanded_position = ((sPkt_DaBitUSB_H2M_v1 *)data)->position[i];
					ja[i].commanded_velocity = ((sPkt_DaBitUSB_H2M_v1 *)data)->velocity[i];
					ja[i].commanded_acceleration = ((sPkt_DaBitUSB_H2M_v1 *)data)->acceleration[i];
				}
				// timestamp
				sender_timestamp = ((int64_t)((sPkt_DaBitUSB_H2M_v1 *)data)->tslowres) << 6;
				bGotData = true;
				CommTimeoutCtr = COMM_TIMEOUT;
				__enable_irq();
				// digital io
				tmp = ((sPkt_DaBitUSB_H2M_v1 *)data)->digout_a0;
				HAL_GPIO_WritePin(DIGOUT0_GPIO_Port, DIGOUT0_Pin, tmp & 0x01);
				HAL_GPIO_WritePin(DIGOUT1_GPIO_Port, DIGOUT1_Pin, tmp & 0x02);
				HAL_GPIO_WritePin(DIGOUT2_GPIO_Port, DIGOUT2_Pin, tmp & 0x04);
				HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, !(tmp & 0x08));
				// PWM: todo
				break;
			/* End of data frame command */
			case PKT_ENDOFCOMMAND:
				idx = 64;
				break;
		}
		/* go to next packet */
		idx += data[0];
	}
	//

  return (0);
  /* USER CODE END 6 */ 
}

/* USER CODE BEGIN 7 */ 
/**
  * @brief  USBD_CUSTOM_HID_SendReport_FS
  *         Send the report to the Host       
  * @param  report: the report to be sent
  * @param  len: the report length
  * @retval Result of the operation: USBD_OK if all operations are OK else USBD_FAIL
  */
/*  
static int8_t USBD_CUSTOM_HID_SendReport_FS ( uint8_t *report,uint16_t len)
{
  return USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, report, len); 
}
*/
/* USER CODE END 7 */ 

/* USER CODE BEGIN PRIVATE_FUNCTIONS_IMPLEMENTATION */
/* USER CODE END PRIVATE_FUNCTIONS_IMPLEMENTATION */

/**
  * @}
  */ 

/**
  * @}
  */  
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
