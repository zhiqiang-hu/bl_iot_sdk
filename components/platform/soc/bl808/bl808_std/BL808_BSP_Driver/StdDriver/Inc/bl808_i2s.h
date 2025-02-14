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
#ifndef __BL60X_I2S_H__
#define __BL60X_I2S_H__

#include "i2s_reg.h"
#include "bl808_common.h"

/** @addtogroup  BL60x_Peripheral_Driver
 *  @{
 */

/** @addtogroup  I2S
 *  @{
 */

/** @defgroup  I2S_Public_Types
 *  @{
 */

/**
 *  @brief I2S No. type definition
 */
typedef enum {
    I2S0_ID,                                 /*!< I2S0 define */
    I2S1_ID,                                 /*!< I2S1 define */
}I2S_ID_Type;

/**
 *  @brief I2S mode type definition
 */
typedef enum {
    I2S_MODE_I2S_LEFT,                       /*!< Left-Justified Mode */
    I2S_MODE_I2S_RIGHT,                      /*!< Right-Justified Mode */
    I2S_MODE_I2S_DSP,                        /*!< DSP Mode */
}I2S_Mode_Type;

/**
 *  @brief I2S Audio data mode type definition
 */
typedef enum {
    I2S_AUDIO_DATA_MODE_NORMAL,              /*!< I2S audio data mode,Normal */
    I2S_AUDIO_DATA_MODE_LEFT,                /*!< I2S audio data mode,Left-Justified */
    I2S_AUDIO_DATA_MODE_RIGHT,               /*!< I2S audio data mode,Right-Justified */
    I2S_AUDIO_DATA_MODE_DSP,                 /*!< I2S audio data mode,DSP Mode */
}I2S_Audio_Data_Mode_Type;

/**
 *  @brief I2S role type definition
 */
typedef enum {
    I2S_ROLE_MASTER = 0,                     /*!< I2S as master */
    I2S_ROLE_SLAVE = 1,                      /*!< I2S as slave */
}I2S_Role_Type;

/**
 *  @brief I2S data size type definition
 */
typedef enum {
    I2S_SIZE_DATA_8 = 0,                     /*!< I2S data size 8 bits */
    I2S_SIZE_DATA_16,                        /*!< I2S data size 16 bits */
    I2S_SIZE_DATA_24,                        /*!< I2S data size 24 bits */
    I2S_SIZE_DATA_32,                        /*!< I2S data size 32 bits */
}I2S_Data_Size_Type;

/**
 *  @brief I2S frame size type definition
 */
typedef enum {
    I2S_SIZE_FRAME_8 = 0,                    /*!< I2S frame size 8 bits */
    I2S_SIZE_FRAME_16,                       /*!< I2S frame size 16 bits */
    I2S_SIZE_FRAME_24,                       /*!< I2S frame size 24 bits */
    I2S_SIZE_FRAME_32,                       /*!< I2S frame size 32 bits */
}I2S_Frame_Size_Type;

/**
 *  @brief I2S endian data type definition
 */
typedef enum {
    I2S_DATA_ENDIAN_MSB = 0,                 /*!< I2S use MSB first */
    I2S_DATA_ENDIAN_LSB,                     /*!< I2S use LSB first */
}I2S_Endian_Type;

/**
 *  @brief I2S frame select mode type definition
 */
typedef enum {
    I2S_FS_MODE_EVEN = 0,                    /*!< I2S frame is even */
    I2S_FS_MODE_1T,                          /*!< I2S frame is only 1T high */
}I2S_Fs_Mode_Type;

/**
 *  @brief I2S frame channel mode type definition
 */
typedef enum {
    I2S_FS_CHANNELS_2 = 0,                   /*!< I2S frame is for 2 channels */
    I2S_FS_CHANNELS_4,                       /*!< I2S frame is for 4 channels */
}I2S_Fs_Channel_Type;

/**
 *  @brief I2S mono control definition
 */
typedef enum {
    I2S_MONO_CONTROL_STEREO = 0,             /*!< I2S output stereo */
    I2S_MONO_CONTROL_MONO,                   /*!< I2S output mono */
}I2S_MonoControl_Type;

/**
 *  @brief I2S configuration structure type definition
 */
typedef struct {
    I2S_Endian_Type endianType;             /*!< I2S endian configuration */
    I2S_Mode_Type modeType;                 /*!< I2S mode configuration */
    uint32_t audioFreqHz;                   /*!< I2S audio pll output frequency in Hz */
    uint32_t sampleFreqHz;                  /*!< I2S sample data frequency in Hz */
    BL_Fun_Type bclkInvert;                 /*!< I2S bclk invert configuration */
    I2S_Frame_Size_Type frameSize;          /*!< I2S frame size configuration */
    BL_Fun_Type fsInvert;                   /*!< I2S frame select invert configuration */
    I2S_Fs_Mode_Type fsMode;                /*!< I2S frame mode configuration */
    I2S_Fs_Channel_Type fsChannel;          /*!< I2S frame channels configuration */
    uint32_t dataOffset;                    /*!< I2S data output offset configuration */
    I2S_Data_Size_Type dataSize;            /*!< I2S data size configuration */
    BL_Fun_Type monoMode;                   /*!< I2S enable mono mode,when this mode enable,lRMerge must be disabled */
}I2S_CFG_Type;

/**
 *  @brief I2S FIFO configuration structure type definition
 */
typedef struct {
    BL_Fun_Type lRMerge;                     /*!< I2S FIFO contains both left and right channel data in one entry */
    BL_Fun_Type frameDataExchange;           /*!< I2S exchange left and right channel data in one entry */
    BL_Fun_Type txfifoDmaEnable;             /*!< Enable or disable I2S tx fifo dma function. */
    BL_Fun_Type rxfifoDmaEnable;             /*!< Enable or disable I2S rx fifo dma function. */
    uint8_t rxFifoLevel;                     /*!< I2S receive fifo interrupt trigger level. only valid when fifo mode enabled. */
    uint8_t txFifoLevel;                     /*!< I2S transmit fifo interrupt trigger level. only valid when fifo mode enabled. */
}I2S_FifoCfg_Type;

/*@} end of group I2S_Public_Types */

/** @defgroup  I2S_Public_Constants
 *  @{
 */

/** @defgroup  I2S_ID_TYPE
 *  @{
 */
#define IS_I2S_ID_TYPE(type)                             (((type) == I2S0_ID) || \
                                                          ((type) == I2S1_ID))

/** @defgroup  I2S_MODE_TYPE
 *  @{
 */
#define IS_I2S_MODE_TYPE(type)                           (((type) == I2S_MODE_I2S_LEFT) || \
                                                          ((type) == I2S_MODE_I2S_RIGHT) || \
                                                          ((type) == I2S_MODE_I2S_DSP))

/** @defgroup  I2S_AUDIO_DATA_MODE_TYPE
 *  @{
 */
#define IS_I2S_AUDIO_DATA_MODE_TYPE(type)                (((type) == I2S_AUDIO_DATA_MODE_NORMAL) || \
                                                          ((type) == I2S_AUDIO_DATA_MODE_LEFT) || \
                                                          ((type) == I2S_AUDIO_DATA_MODE_RIGHT) || \
                                                          ((type) == I2S_AUDIO_DATA_MODE_DSP))

/** @defgroup  I2S_ROLE_TYPE
 *  @{
 */
#define IS_I2S_ROLE_TYPE(type)                           (((type) == I2S_ROLE_MASTER ) || \
                                                          ((type) == I2S_ROLE_SLAVE ))

/** @defgroup  I2S_DATA_SIZE_TYPE
 *  @{
 */
#define IS_I2S_DATA_SIZE_TYPE(type)                      (((type) == I2S_SIZE_DATA_8 ) || \
                                                          ((type) == I2S_SIZE_DATA_16) || \
                                                          ((type) == I2S_SIZE_DATA_24) || \
                                                          ((type) == I2S_SIZE_DATA_32))

/** @defgroup  I2S_FRAME_SIZE_TYPE
 *  @{
 */
#define IS_I2S_FRAME_SIZE_TYPE(type)                     (((type) == I2S_SIZE_FRAME_8 ) || \
                                                          ((type) == I2S_SIZE_FRAME_16) || \
                                                          ((type) == I2S_SIZE_FRAME_24) || \
                                                          ((type) == I2S_SIZE_FRAME_32))

/** @defgroup  I2S_ENDIAN_TYPE
 *  @{
 */
#define IS_I2S_ENDIAN_TYPE(type)                         (((type) == I2S_DATA_ENDIAN_MSB ) || \
                                                          ((type) == I2S_DATA_ENDIAN_LSB))

/** @defgroup  I2S_FS_MODE_TYPE
 *  @{
 */
#define IS_I2S_FS_MODE_TYPE(type)                        (((type) == I2S_FS_MODE_EVEN ) || \
                                                          ((type) == I2S_FS_MODE_1T))

/** @defgroup  I2S_FS_CHANNEL_TYPE
 *  @{
 */
#define IS_I2S_FS_CHANNEL_TYPE(type)                     (((type) == I2S_FS_CHANNELS_2 ) || \
                                                          ((type) == I2S_FS_CHANNELS_4))

/** @defgroup  I2S_MONOCONTROL_TYPE
 *  @{
 */
#define IS_I2S_MONOCONTROL_TYPE(type)                    (((type) == I2S_MONO_CONTROL_STEREO ) || \
                                                          ((type) == I2S_MONO_CONTROL_MONO))

/*@} end of group I2S_Public_Constants */

/** @defgroup  I2S_Public_Macros
 *  @{
 */
#define I2S_TX_FIFO_SIZE               16
#define I2S_RX_FIFO_SIZE               16

/*@} end of group I2S_Public_Macros */

/** @defgroup  I2S_Public_Functions
 *  @{
 */

/**
 *  @brief I2S Functions
 */
void I2S_SetBclkPeriod(I2S_ID_Type i2sNo,I2S_CFG_Type *i2sCfg);
void I2S_Init(I2S_ID_Type i2sNo,I2S_CFG_Type *i2sCfg);
void I2S_FifoConfig(I2S_ID_Type i2sNo, I2S_FifoCfg_Type * fifoCfg);
void I2S_Enable(I2S_ID_Type i2sNo,I2S_Role_Type roleType);
void I2S_Disable(I2S_ID_Type i2sNo);
void I2S_Write(I2S_ID_Type i2sNo, uint32_t data);
void I2S_Mute(I2S_ID_Type i2sNo, BL_Fun_Type enabled);
uint32_t I2S_GetTxFIFO_AvlCnt(I2S_ID_Type i2sNo);
uint32_t I2S_GetRxFIFO_AvlCnt(I2S_ID_Type i2sNo);
void I2S_Flush(I2S_ID_Type i2sNo);

/*@} end of group I2S_Public_Functions */

/*@} end of group I2S */

/*@} end of group BL60x_Peripheral_Driver */

#endif /* __BL60X_I2S_H__ */
