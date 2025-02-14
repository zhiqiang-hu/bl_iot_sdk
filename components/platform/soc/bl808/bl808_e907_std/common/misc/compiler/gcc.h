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
#ifndef __GCC_H
#define __GCC_H

#ifndef __ORDER_BIG_ENDIAN__
#define __ORDER_BIG_ENDIAN__ (1)
#endif

#ifndef __ORDER_LITTLE_ENDIAN__
#define __ORDER_LITTLE_ENDIAN__ (2)
#endif

#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__

/* CPP header guards */
#ifdef __cplusplus
#define EXTERN_C_BEGIN extern "C" {
#define EXTERN_C_END   }
#else
#define EXTERN_C_BEGIN
#define EXTERN_C_END
#endif

#define __MACRO_BEGIN do {
#define __MACRO_END \
    }               \
    while (0)

#if defined(__GNUC__)
#ifndef __ASM
#define __ASM __asm
#endif
#ifndef __INLINE
#define __INLINE inline
#endif
#ifndef __INLINE__
#define __INLINE__ inline
#endif
#ifndef __ALWAYS_INLINE
#define __ALWAYS_INLINE inline __attribute__((always_inline))
#endif
#ifndef __ALWAYS_STATIC_INLINE
#define __ALWAYS_STATIC_INLINE __attribute__((always_inline)) static inline
#endif
#ifndef __STATIC_INLINE
#define __STATIC_INLINE static inline
#endif
#ifndef __NO_RETURN
#define __NO_RETURN __attribute__((noreturn))
#endif
#ifndef __USED
#define __USED __attribute__((used))
#endif
#ifndef __UNUSED__
#define __UNUSED__ __attribute__((__unused__))
#endif
#ifndef __WEAK
#define __WEAK __attribute__((weak))
#endif
#ifndef __WEAK__
#define __WEAK__ __attribute__((weak))
#endif
#ifndef __PACKED
#define __PACKED __attribute__((packed, aligned(1)))
#endif
#ifndef __PACKED__
#define __PACKED__ __attribute__((packed))
#endif
#ifndef __PACKED_STRUCT
#define __PACKED_STRUCT struct __attribute__((packed, aligned(1)))
#endif
#ifndef __PACKED_UNION
#define __PACKED_UNION union __attribute__((packed, aligned(1)))
#endif
#ifndef __IRQ
#define __IRQ __attribute__((interrupt))
#endif
#ifndef __IRQ_ALIGN64
#define __IRQ_ALIGN64 __attribute__((interrupt, aligned(64)))
#endif
#ifndef ALIGN4
#define ALIGN4 __attribute((aligned(4)))
#endif
#ifndef PACK_START
#define PACK_START
#endif
#ifndef PACK_END
#define PACK_END __attribute__((packed))
#endif
#ifndef likely
#define likely(x) __builtin_expect(!!(x), 1)
#endif
#ifndef unlikely
#define unlikely(x) __builtin_expect(!!(x), 0)
#endif
#ifndef __ALIGNED__
#define __ALIGNED__(x) __attribute__((aligned(x)))
#endif
#ifndef SECTION
#define SECTION(x) __attribute__((section(x)))
#endif
#ifndef __CONST__
#define __CONST__ __attribute__((__const__))
#endif
#ifndef __NAKED__
#define __NAKED__ __attribute__((naked))
#endif
#ifndef __deprecated
#define __deprecated __attribute__((deprecated))
#endif
#endif

#endif