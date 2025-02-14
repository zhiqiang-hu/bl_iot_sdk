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
#ifndef __BL808_SF_CFG_H__
#define __BL808_SF_CFG_H__

#include "string.h"
#include "bl808_glb.h"
#include "bl808_glb_gpio.h"
#include "bl808_sflash.h"
#include "bl808_sf_ctrl.h"

/** @addtogroup  BL808_Peripheral_Driver
 *  @{
 */

/** @addtogroup  SF_CFG
 *  @{
 */

/** @defgroup  SF_CFG_Public_Types
 *  @{
 */

/*@} end of group SF_CFG_Public_Types */

/** @defgroup  SF_CFG_Public_Constants
 *  @{
 */

/*@} end of group SF_CFG_Public_Constants */

/** @defgroup  SF_CFG_Public_Macros
 *  @{
 */
/* Flash option sf2 */
/* Flash CLK */
#define BFLB_EXTFLASH_CLK0_GPIO                 GLB_GPIO_PIN_27
/* FLASH CS */
#define BFLB_EXTFLASH_CS0_GPIO                  GLB_GPIO_PIN_28
/* FLASH DATA */
#define BFLB_EXTFLASH_DATA00_GPIO               GLB_GPIO_PIN_29
#define BFLB_EXTFLASH_DATA10_GPIO               GLB_GPIO_PIN_30
#define BFLB_EXTFLASH_DATA20_GPIO               GLB_GPIO_PIN_31
#define BFLB_EXTFLASH_DATA30_GPIO               GLB_GPIO_PIN_32
/* Flash option sf3 */
/* Flash CLK */
#define BFLB_EXTFLASH_CLK1_GPIO                 GLB_GPIO_PIN_35
/* FLASH CS */
#define BFLB_EXTFLASH_CS1_GPIO                  GLB_GPIO_PIN_36
/* FLASH DATA */
#define BFLB_EXTFLASH_DATA01_GPIO               GLB_GPIO_PIN_37
#define BFLB_EXTFLASH_DATA11_GPIO               GLB_GPIO_PIN_38
#define BFLB_EXTFLASH_DATA21_GPIO               GLB_GPIO_PIN_33
#define BFLB_EXTFLASH_DATA31_GPIO               GLB_GPIO_PIN_34
#define BFLB_FLASH_ID_VALID_FLAG                0x80000000
#define BFLB_FLASH_ID_VALID_MASK                0x7FFFFFFF

/*@} end of group SF_CFG_Public_Macros */

/** @defgroup  SF_CFG_Public_Functions
 *  @{
 */
BL_Err_Type SF_Cfg_Get_Flash_Cfg_Need_Lock(uint32_t flashID,SPI_Flash_Cfg_Type * pFlashCfg);
void SF_Cfg_Init_Flash_Gpio(SF_Ctrl_Pin_Select flashPinCfg, uint8_t restoreDefault);
uint32_t SF_Cfg_Flash_Identify(uint8_t callFromFlash,uint32_t autoScan,uint32_t flashPinCfg,uint8_t restoreDefault,
                               SPI_Flash_Cfg_Type * pFlashCfg);
void SF_Cfg_Init_Ext_Flash_Gpio(uint8_t extFlashPin);
void SF_Cfg_Deinit_Ext_Flash_Gpio(uint8_t extFlashPin);
void SF_Cfg_Flash_Init(SF_Ctrl_Pin_Select sel, const SF_Ctrl_Cfg_Type *pSfCtrlCfg, const SF_Ctrl_Bank2_Cfg *pBank2Cfg);

/*@} end of group SF_CFG_Public_Functions */

/*@} end of group SF_CFG */

/*@} end of group BL808_Peripheral_Driver */

#endif /* __BL808_SF_CFG_H__ */
