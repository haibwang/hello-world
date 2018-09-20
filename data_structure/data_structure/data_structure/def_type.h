
/**********************************************
** File name : def_type.h
** Author    : haibowang
** Time      : 2018-9-20
** version   : 1.0
** Dscription: type define 
***********************************************/

#pragma once

typedef signed char				int8;       /**< 8λ�з����� */
typedef unsigned char			uint8;      /**< 8λ�޷����� */
typedef short					int16;      /**< 16λ�з����� */
typedef unsigned short			uint16;     /**< 16λ�޷����� */
typedef long					int32;      /**< 32λ�з����� */
typedef unsigned long			uint32;     /**< 32λ�޷����� */
typedef long long				int64;      /**< 64λ�з����� */
typedef unsigned long long		uint64;     /**< 64λ�޷����� */
typedef void *					Object;     /**< ������������ΪObject */
typedef const char *			String;     /**< �����ַ������� (��RAM��) */
typedef int8					TResult;    /**< ���صĽ������ */


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




