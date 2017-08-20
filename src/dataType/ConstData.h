/**************************************************************\
* Copyright (c) 2015, NUDT 3
*
* 文件名称：ConstData.h
* 摘 要：常量
*
* 当前版本：1.0
* 作 者:
* 完成日期：2015年9月25日
\***************************************************************/


#ifndef CONSTDATA_H
#define CONSTDATA_H

typedef unsigned long ULONG;
typedef ULONG *PULONG;
typedef unsigned short USHORT;
typedef USHORT *PUSHORT;
typedef unsigned char UCHAR;
typedef UCHAR *PUCHAR;

typedef unsigned long       DWORD;
typedef int                 BOOL;
typedef unsigned char       BYTE;
typedef unsigned short      WORD;
typedef float               FLOAT;
typedef FLOAT               *PFLOAT;

typedef int                 INT;
typedef unsigned int        UINT;
typedef unsigned int        *PUINT;

typedef signed char         INT8, *PINT8;
typedef signed short        INT16, *PINT16;
typedef signed int          INT32, *PINT32;
typedef long long      INT64, *PINT64;
typedef unsigned char       UINT8, *PUINT8;
typedef unsigned short      UINT16, *PUINT16;
typedef unsigned int        UINT32, *PUINT32;
typedef unsigned long long    UINT64, *PUINT64;

/**************************************************************\
* 基础操作宏定义
\**************************************************************/
/*#define MAKEWORD(a, b)      ((WORD)(((BYTE)(((DWORD_PTR)(a)) & 0xff)) | ((WORD)((BYTE)(((DWORD_PTR)(b)) & 0xff))) << 8))
#define MAKELONG(a, b)      ((LONG)(((WORD)(((DWORD_PTR)(a)) & 0xffff)) | ((DWORD)((WORD)(((DWORD_PTR)(b)) & 0xffff))) << 16))
#define LOWORD(l)           ((WORD)(((DWORD_PTR)(l)) & 0xffff))
#define HIWORD(l)           ((WORD)((((DWORD_PTR)(l)) >> 16) & 0xffff))
#define LOBYTE(w)           ((BYTE)(((DWORD_PTR)(w)) & 0xff))
#define HIBYTE(w)           ((BYTE)((((DWORD_PTR)(w)) >> 8) & 0xff))*/


//PI
const double PI = 3.1415926535897932384626433832795;

//2PI
const double PI2 = 6.283185307179586476925286766559;

//2PI毫弧度
const double PI2mrad = 6283.185307179586476925286766559;

//WGS84椭球长半轴
const double WGS84_A = 6378137.0;

//WGS84椭球短半轴
const double WGS84_B = 6356752.31414036;

//WGS84扁率
const double WGS84_F = 0.00335281068118231893543414612613;

//光速
const double LightSpeed = 299792458.0;

//弧度转角度常数
const double Rad2Deg = 57.295779513082320876798154814105;

//角度转弧度常数
const double Deg2Rad = 0.01745329251994329576923690768489;

//周内秒数
const DWORD TSow = 604800;

//周内毫秒数
const DWORD TmSow = 604800000;

const double DSM64 = 65536.0 * 65536.0 * 65536.0 * 65536.0;

const double DSM32 = 65536.0 * 65536.0;

const double DSM96 = 65536.0 * 65536.0 * 65536.0 * 65536.0 * 65536.0 * 65536.0;

const WORD SimStep = 20;			//仿真步长 ms

const WORD BDG_SAT_NUM = 40;//全球信号卫星数量，目前的区域信号按照40处理

const WORD MAX_INTERFERENCE_NUM = 16;

const WORD MAX_BDS_OBS_SAT_NUM = 16; //最大的可视卫星数量，更改此值需要注意更换SIMDLL

const WORD MAX_GLO_OBS_SAT_NUM = 16; //最大的可视卫星数量，更改此值需要注意更换SIMDLL

const WORD BD2_STA_NUM = 27;//北斗监测站数量 

const WORD BDS_NAVLEN = 300;

const WORD GPS_NAVLEN = 300;

const WORD GLO_NAVLEN = 200;

const WORD MAX_CHANNEL_NUM = 12;	//最大通道数量

const BYTE	MAX_SIGNALGEN_NUM = 8;	//板卡最大信号生成单元数量

const BYTE	MAX_BOARD_NUM = 20;	//板卡最大数量

const BYTE MAX_ANT_NUM = 8;			//最大天线数量

const WORD MAX_NAVDATA_LEN = 250;	//最大电文长度  字节

const WORD ADVAN_NAVDATA_STEP = 2;	//取电文超前节拍

const int MAX_ARRAYUNIT_CNT = 8;// 最大阵元数量

const int GpsSatNum=32;// gps卫星数

const int BdsSatNum = 15;//BD卫星数

const int GalSatNum = 30;// GAL卫星数
const int GLOSatNum=24;//GLO卫星数

const DWORD DAT_DOWN_CMD = 0x44;
const DWORD DAT_DOWN_ACK = 0xc4;

const DWORD CTL_MOD_CMD = 0x05;
const DWORD CTL_MOD_ACK = 0x85;

const DWORD CFG_MOD_CMD = 0x04;
const DWORD CFG_GET_CMD = 0x03;
const DWORD CFG_MOD_ACK = 0x84;
const DWORD CFG_SAV_CMD = 0x73;
const DWORD SIG_SW_CMD = 0x74;
const DWORD DAT_DOWN_REQ = 0x06;

const DWORD AUTO_CALI_CMD = 0x0A;	//自动校准

const DWORD LowerACKSize = 20;		//下位机请求数据包大小



const DWORD SYSTIME_VALID_BIT = 0x00000001;		//模块系统时钟正常
const DWORD FLASH_VALID_BIT = 0x00000002;		//板载FLASH正常
const DWORD DA_VALID_BIT = 0x00000004;		//DA正常
const DWORD NET_VALID_BIT = 0x00000008;		//网络正常
const DWORD PRM_VALID_BIT = 0x00000010;		//PRM初始化正常
const DWORD PRM_CODE_VALID_BIT = 0x00000020;		//PRM码流检测正常
const DWORD REFCLK_VALID_BIT = 0x00000040;		//参考时钟正常
const DWORD CODE_VALID_BIT = 0x00000080;		//伪码正常
const DWORD ATTPARA_VALID_BIT = 0x00000100;		//衰减参数正常
const DWORD POWGENE_VALID_BIT = 0x00000200;		//功率因子正常
const DWORD SIGPPS_VALID_BIT = 0x00000400;		//秒脉冲信号正常

#endif
