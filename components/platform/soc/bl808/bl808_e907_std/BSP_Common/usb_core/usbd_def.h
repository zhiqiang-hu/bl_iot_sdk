/*
 * Copyright (c) 2016-2023 Bouffalolab.
 *
 * This file is part of
 *     *** Bouffalolab Software Dev Kit ***
 *      (see www.bouffalolab.com).
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *   1. Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *   2. Redistributions in binary form must reproduce the above copyright notice,
 *      this list of conditions and the following disclaimer in the documentation
 *      and/or other materials provided with the distribution.
 *   3. Neither the name of Bouffalo Lab nor the names of its contributors
 *      may be used to endorse or promote products derived from this software
 *      without specific prior written permission.
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
 */
#ifndef __USBD_DEF_H
#define __USBD_DEF_H

#include "bflb_bsp_driver_glue.h"
#include "usb_def.h"
#include "usbd_conf.h"

#ifndef NULL
#define NULL  0
#endif


#define  USB_LEN_DEV_QUALIFIER_DESC                     0x0A
#define  USB_LEN_DEV_DESC                               0x12
#define  USB_LEN_CFG_DESC                               0x09
#define  USB_LEN_IF_DESC                                0x09
#define  USB_LEN_EP_DESC                                0x07
#define  USB_LEN_OTG_DESC                               0x03
#define  USB_LEN_LANGID_STR_DESC                        0x04
#define  USB_LEN_OTHER_SPEED_DESC_SIZ                   0x09

#define  USBD_IDX_LANGID_STR                            0x00 
#define  USBD_IDX_MFC_STR                               0x01 
#define  USBD_IDX_PRODUCT_STR                           0x02
#define  USBD_IDX_SERIAL_STR                            0x03 
#define  USBD_IDX_CONFIG_STR                            0x04 
#define  USBD_IDX_INTERFACE_STR                         0x05 

#define  USB_REQ_TYPE_STANDARD                          0x00
#define  USB_REQ_TYPE_CLASS                             0x20
#define  USB_REQ_TYPE_VENDOR                            0x40
#define  USB_REQ_TYPE_MASK                              0x60

#define  USB_REQ_RECIPIENT_DEVICE                       0x00
#define  USB_REQ_RECIPIENT_INTERFACE                    0x01
#define  USB_REQ_RECIPIENT_ENDPOINT                     0x02
#define  USB_REQ_RECIPIENT_MASK                         0x03

#define  USB_REQ_GET_STATUS                             0x00
#define  USB_REQ_CLEAR_FEATURE                          0x01
#define  USB_REQ_SET_FEATURE                            0x03
#define  USB_REQ_SET_ADDRESS                            0x05
#define  USB_REQ_GET_DESCRIPTOR                         0x06
#define  USB_REQ_SET_DESCRIPTOR                         0x07
#define  USB_REQ_GET_CONFIGURATION                      0x08
#define  USB_REQ_SET_CONFIGURATION                      0x09
#define  USB_REQ_GET_INTERFACE                          0x0A
#define  USB_REQ_SET_INTERFACE                          0x0B
#define  USB_REQ_SYNCH_FRAME                            0x0C

#define  USB_DESC_TYPE_DEVICE                              1
#define  USB_DESC_TYPE_CONFIGURATION                       2
#define  USB_DESC_TYPE_STRING                              3
#define  USB_DESC_TYPE_INTERFACE                           4
#define  USB_DESC_TYPE_ENDPOINT                            5
#define  USB_DESC_TYPE_DEVICE_QUALIFIER                    6
#define  USB_DESC_TYPE_OTHER_SPEED_CONFIGURATION           7
#define  USB_DESC_TYPE_BOS                                 0x0F

#define USB_CONFIG_REMOTE_WAKEUP                           2
#define USB_CONFIG_SELF_POWERED                            1

#define USB_FEATURE_EP_HALT                                0
#define USB_FEATURE_REMOTE_WAKEUP                          0
#define USB_FEATURE_TEST_MODE                              2

#define USB_DEVICE_CAPABITY_TYPE                           0x10

#define USB_HS_MAX_PACKET_SIZE                            512
#define USB_FS_MAX_PACKET_SIZE                            64
#define USB_MAX_EP0_SIZE                                  64

/*  Device Status */
#define USBD_STATE_DEFAULT                                1
#define USBD_STATE_ADDRESSED                              2
#define USBD_STATE_CONFIGURED                             3
#define USBD_STATE_SUSPENDED                              4


/*  EP0 State */    
#define USBD_EP0_IDLE                                     0
#define USBD_EP0_SETUP                                    1
#define USBD_EP0_DATA_IN                                  2
#define USBD_EP0_DATA_OUT                                 3
#define USBD_EP0_STATUS_IN                                4
#define USBD_EP0_STATUS_OUT                               5
#define USBD_EP0_STALL                                    6    

#define USBD_EP_TYPE_CTRL                                 5/*0*/
#define USBD_EP_TYPE_ISOC                                 2/*1*/
#define USBD_EP_TYPE_BULK                                 4/*2*/
#define USBD_EP_TYPE_INTR                                 0/*3*/


typedef  struct  usb_setup_req 
{
    uint8_t   bmRequest;                      
    uint8_t   bRequest;                           
    uint16_t  wValue;                             
    uint16_t  wIndex;                             
    uint16_t  wLength;                            
}USBD_SetupReqTypedef;

struct _USBD_HandleTypeDef;
    
typedef struct _Device_cb
{
    uint8_t  (*Init)             (struct _USBD_HandleTypeDef *pdev , uint8_t cfgidx);
    uint8_t  (*DeInit)           (struct _USBD_HandleTypeDef *pdev , uint8_t cfgidx);
    
    /* Control Endpoints*/
    uint8_t  (*Setup)            (struct _USBD_HandleTypeDef *pdev , USBD_SetupReqTypedef  *req);  
    uint8_t  (*EP0_TxSent)       (struct _USBD_HandleTypeDef *pdev );    
    uint8_t  (*EP0_RxReady)      (struct _USBD_HandleTypeDef *pdev );  
    
    /* Class Specific Endpoints*/
    uint8_t  (*DataIn)           (struct _USBD_HandleTypeDef *pdev , uint8_t epnum);   
    uint8_t  (*DataOut)          (struct _USBD_HandleTypeDef *pdev , uint8_t epnum); 
    uint8_t  (*SOF)              (struct _USBD_HandleTypeDef *pdev); 
    uint8_t  (*IsoINIncomplete)  (struct _USBD_HandleTypeDef *pdev , uint8_t epnum); 
    uint8_t  (*IsoOUTIncomplete) (struct _USBD_HandleTypeDef *pdev , uint8_t epnum);   

    uint8_t  *(*GetHSConfigDescriptor)(uint16_t *length); 
    uint8_t  *(*GetFSConfigDescriptor)(uint16_t *length);   
    uint8_t  *(*GetOtherSpeedConfigDescriptor)(uint16_t *length);
    uint8_t  *(*GetDeviceQualifierDescriptor)(uint16_t *length);
#if (USBD_SUPPORT_USER_STRING == 1)
    uint8_t  *(*GetUsrStrDescriptor)(struct _USBD_HandleTypeDef *pdev ,uint8_t index,  uint16_t *length);   
#endif
} USBD_ClassTypeDef;

/* Following USB Device Speed */
typedef enum 
{
    USBD_SPEED_HIGH  = 0,
    USBD_SPEED_FULL  = 1,
    USBD_SPEED_LOW   = 2,  
}USBD_SpeedTypeDef;

/* Following USB Device status */
typedef enum {
    USBD_OK   = 0,
    USBD_BUSY,
    USBD_FAIL,
}USBD_StatusTypeDef;

/* USB Device descriptors structure */
typedef struct
{
    uint8_t  *(*GetDeviceDescriptor)( USBD_SpeedTypeDef speed , uint16_t *length);  
    uint8_t  *(*GetLangIDStrDescriptor)( USBD_SpeedTypeDef speed , uint16_t *length); 
    uint8_t  *(*GetManufacturerStrDescriptor)( USBD_SpeedTypeDef speed , uint16_t *length);  
    uint8_t  *(*GetProductStrDescriptor)( USBD_SpeedTypeDef speed , uint16_t *length);  
    uint8_t  *(*GetSerialStrDescriptor)( USBD_SpeedTypeDef speed , uint16_t *length);  
    uint8_t  *(*GetConfigurationStrDescriptor)( USBD_SpeedTypeDef speed , uint16_t *length);  
    uint8_t  *(*GetInterfaceStrDescriptor)( USBD_SpeedTypeDef speed , uint16_t *length); 
#if (USBD_LPM_ENABLED == 1)
    uint8_t  *(*GetBOSDescriptor)( USBD_SpeedTypeDef speed , uint16_t *length); 
#endif  
} USBD_DescriptorsTypeDef;

/* USB Device handle structure */
typedef struct
{ 
    uint32_t                status;
    uint32_t                total_length;    
    uint32_t                rem_length; 
    uint32_t                maxpacket;   
} USBD_EndpointTypeDef;

/* USB Device handle structure */
typedef struct _USBD_HandleTypeDef
{
    uint8_t                 id;
    uint32_t                dev_config;
    uint32_t                dev_default_config;
    uint32_t                dev_config_status; 
    USBD_SpeedTypeDef       dev_speed; 
    USBD_EndpointTypeDef    ep_in[8];
    USBD_EndpointTypeDef    ep_out[8];
    uint32_t                ep0_state;  
    uint32_t                ep0_data_len;     
    uint8_t                 dev_state;
    uint8_t                 dev_old_state;
    uint8_t                 dev_address;
    uint8_t                 dev_connection_status;  
    uint8_t                 dev_test_mode;
    uint32_t                dev_remote_wakeup;
    uint32_t                BLSetAddressFlag;

    USBD_SetupReqTypedef    request;
    USBD_DescriptorsTypeDef *pDesc;
    USBD_ClassTypeDef       *pClass;
    void                    *pClassData;  
    void                    *pUserData;    
    void                    *pData;    
} USBD_HandleTypeDef;


/** @defgroup USBD_DEF_Exported_Macros
  * @{
  */ 
#define  SWAPBYTE(addr)            (((uint16_t)(*((uint8_t *)(addr)))) + (((uint16_t)(*(((uint8_t *)(addr)) + 1))) << 8))
#define LOBYTE(x)                ((uint8_t)(x & 0x00FF))
#define HIBYTE(x)                ((uint8_t)((x & 0xFF00) >>8))
#define MIN(a, b)                (((a) < (b)) ? (a) : (b))
#define MAX(a, b)                (((a) > (b)) ? (a) : (b))


#if defined   (__GNUC__)
    #define __ALIGN_END    __attribute__ ((aligned (4)))
    #define __ALIGN_BEGIN         
#else                           
    #define __ALIGN_END
    #if defined   (__CC_ARM)
        #define __ALIGN_BEGIN    __align(4)  
    #elif defined (__ICCARM__)
        #define __ALIGN_BEGIN 
    #elif defined  (__TASKING__)
        #define __ALIGN_BEGIN    __align(4) 
    #endif
#endif
  

#endif /* __USBD_DEF_H */
