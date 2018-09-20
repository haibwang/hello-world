
/**********************************************
** File name : def_type.h
** Author    : haibowang
** Time      : 2018-9-20
** version   : 1.0
** Dscription: type define 
***********************************************/

#pragma once

typedef signed char				int8;       /**< 8位有符号数 */
typedef unsigned char			uint8;      /**< 8位无符号数 */
typedef short					int16;      /**< 16位有符号数 */
typedef unsigned short			uint16;     /**< 16位无符号数 */
typedef long					int32;      /**< 32位有符号数 */
typedef unsigned long			uint32;     /**< 32位无符号数 */
typedef long long				int64;      /**< 64位有符号数 */
typedef unsigned long long		uint64;     /**< 64位无符号数 */
typedef void *					Object;     /**< 定义任意类型为Object */
typedef const char *			String;     /**< 定义字符串类型 (在RAM区) */
typedef int8					TResult;    /**< 返回的结果类型 */


#ifndef true
#define true    (uint8)1
#endif

#ifndef false
#define false    (uint8)0
#endif

#ifndef __NULL
#define __NULL    ((void *)0)
#endif

#ifndef NULL
#define NULL    0
#endif




