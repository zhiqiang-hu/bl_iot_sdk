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
#include <rnm_common.h>

#include <inttypes.h>
#include <rnm_utils.h>

const char *rnm_auth_to_str(uint8_t auth)
{
    switch (auth) {
    default:
        return "UNKNOWN";
    case RNM_WIFI_AUTH_OPEN:
        return "OPEN";
    case RNM_WIFI_AUTH_WEP:
        return "WEP";
    case RNM_WIFI_AUTH_WPA_PSK:
        return "WPA-PSK";
    case RNM_WIFI_AUTH_WPA2_PSK:
        return "WPA2-PSK";
    case RNM_WIFI_AUTH_WPA_WPA2_PSK:
        return "WPA-PSK/WPA2-PSK";
    case RNM_WIFI_AUTH_WPA_ENTERPRISE:
        return "WPA-ENTERPRISE";
    case RNM_WIFI_AUTH_WPA3_SAE:
        return "WPA3-SAE";
    case RNM_WIFI_AUTH_WPA2_PSK_WPA3_SAE:
        return "WPA2-PSK/WPA3-SAE";
    }
}

const char *rnm_cipher_to_str(uint8_t cipher)
{
    switch (cipher) {
    default:
        return "UNKNOWN";
    case RNM_WIFI_CIPHER_NONE:
        return "NONE";
    case RNM_WIFI_CIPHER_WEP:
        return "WEP";
    case RNM_WIFI_CIPHER_AES:
        return "AES";
    case RNM_WIFI_CIPHER_TKIP:
        return "TKIP";
    case RNM_WIFI_CIPHER_TKIP_AES:
        return "TKIP/AES";
    }
}

#define CMD_NAME_PREFIX_LEN 9
#define MAKE_DESC(c) [c] = {.cmd = c, .cmd_name = #c + CMD_NAME_PREFIX_LEN}

rnm_cmd_desc_t rnm_cmd_desc[BF1B_CMD_MAX] = {
    MAKE_DESC(BF1B_CMD_REBOOT),
    MAKE_DESC(BF1B_CMD_RESET),
    MAKE_DESC(BF1B_CMD_HELLO),
    MAKE_DESC(BF1B_CMD_PING),
    MAKE_DESC(BF1B_CMD_GET_MAC_ADDR),
    MAKE_DESC(BF1B_CMD_SCAN),
    MAKE_DESC(BF1B_CMD_STA_CONNECT),
    MAKE_DESC(BF1B_CMD_STA_DISCONNECT),
    MAKE_DESC(BF1B_CMD_STA_CONNECTED_IND),
    MAKE_DESC(BF1B_CMD_STA_DISCONNECTED_IND),
    MAKE_DESC(BF1B_CMD_STA_IP_UPDATE_IND),
    MAKE_DESC(BF1B_CMD_STA_SET_AUTO_RECONNECT),
    MAKE_DESC(BF1B_CMD_STA_GET_LINK_STATUS),
    MAKE_DESC(BF1B_CMD_AP_START),
    MAKE_DESC(BF1B_CMD_AP_STOP),
    MAKE_DESC(BF1B_CMD_AP_STARTED_IND),
    MAKE_DESC(BF1B_CMD_AP_STOPPED_IND),
    MAKE_DESC(BF1B_CMD_AP_GET_STA_LIST),
    MAKE_DESC(BF1B_CMD_MONITOR_START),
    MAKE_DESC(BF1B_CMD_MONITOR_STOP),
    MAKE_DESC(BF1B_CMD_MONITOR_SET_CHANNEL),
    MAKE_DESC(BF1B_CMD_MONITOR_GET_CHANNEL),
    MAKE_DESC(BF1B_CMD_SET_LPM_MODE),
    MAKE_DESC(BF1B_CMD_GET_DEV_VERSION),
    MAKE_DESC(BF1B_CMD_OTA),
    MAKE_DESC(BF1B_CMD_EXT),
};

int rnm_statistic_dump(const rnm_statistic_t *stat, rnm_stat_scr_ctr_desc_t *sc_desc, int sc_cnt)
{
    int i;

    if (!stat) {
        return -1;
    }
    rnm_log("---- CMD TX/RX counters ----\r\n");
    rnm_log("INDEX %-25s TX  RX\r\n", "DESC");
    for (i = 0; i < BF1B_CMD_MAX; ++i) {
        const char *cmd_desc = rnm_cmd_desc[i].cmd_name;
        if (!cmd_desc) {
            cmd_desc = "<missing>";
        }
        rnm_log("[%2d]  %-25s %" PRIu32 " %" PRIu32 "\r\n", i, cmd_desc, stat->cmds[i].tx_cnt, stat->cmds[i].rx_cnt);
    }

    if (sc_cnt > 0) {
        rnm_log("\r\n");
        rnm_log("---- Scratch counters ----\r\n");
        rnm_log("%-30s VALUE\r\n", "DESC");
        for (i = 0; i < sc_cnt; ++i) {
            const char *desc = sc_desc[i].desc;
            if (!desc) {
                desc = "<missing>";
            }
            rnm_log("%-30s %" PRIu32 "\r\n", desc, stat->scratch_counter[i]);
        }
    }
    return 0;
}
