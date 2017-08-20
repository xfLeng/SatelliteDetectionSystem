#ifndef SIMDATATYPE_H
#define SIMDATATYPE_H

#include "ConstData.h"
#include <QVariant>

/*******************************************************************\
调制方式
\*******************************************************************/
enum  ModulateMode
{
    M_Close = 0,
    M_BPSKQ = 1,
    M_BPSKI = 2,
    M_QPSK = 3,
    M_SingleCarrier = 15
};

/*******************************************************************\
用户位置数据结构体
\*******************************************************************/
struct UserTrkData
{
	UINT64 UserID;
    UINT64 TrackBDT;//轨迹时间 ms
	DWORD wn;
	DWORD sow;
    double  Pos[3]; //用户位置
    double  Vel[3]; //用户速度
    double  Acc[3]; //用户加速度
    double  Jek[3]; //用户加加速度

    double Attitude[3];	//姿态 rad
    double AngleRate[3];	//角速度 rad/s
};
/*******************************************************************\
日期时间信息结构体
\*******************************************************************/
typedef struct _SimTimeInfo
{
    WORD Year;
    BYTE Month;
    BYTE Day;

    BYTE Hour;
    BYTE Minute;
    BYTE Second;
    WORD Millisecond;

    DWORD BDWn;	//整周计数
    DWORD Sow;	//周内秒
    DWORD BDLeapSecond;	//闰秒

    DWORD GPSWn;	//整周计数
    DWORD GPSLeapSecond;	//闰秒

    //DWORD GALWn;	//整周计数
    //DWORD GALLeapSecond;	//闰秒

    DWORD GLOWn;	//整周计数
    DWORD GLOLeapSecond;	//闰秒

}SimTimeInfo, *PSimTimeInfo;


/*******************************************************************\
单颗星观测数据结构体
\*******************************************************************/
struct SatObsData
{
    BYTE Modulate;			//调制方式
	int SatID;				//卫星号
    double Pseudorange[4];		//伪距0、1、2、3阶量 单位：s、m/s、m/s^2、m/s^3
    double Carrier;			//载波
    double Power;				//功率dBm
    double Elevation;			//卫星俯仰角
    double Azimuth;				//卫星方位角
    double SatPos[3];
    double SatVel[3];
};
/*******************************************************************\
观测数据结构体
\*******************************************************************/
struct ObsData
{
	BYTE AntId;				//天线ID 1-8
	BYTE SatCnt;			//卫星数量
	WORD FreqID;			//频点ID
	DWORD Wn;
    DWORD Sow;				//周内秒,ms
    SatObsData SatObs[MAX_BDS_OBS_SAT_NUM];
};

/*******************************************************************\
卫星系统编号
\*******************************************************************/
enum eSatSystemType
{
    BD2 = 1,
    GPS = 2,
    GLO = 3,
    GAL = 4
};

/*******************************************************************\
硬件频点编号
\*******************************************************************/
enum eFreqType
{
    BD2_B1 = 1,
    BD2_B2 = 2,
    BD2_B3 = 3,
    GPS_L1 = 4,
    GPS_L2 = 5,
    GPS_L5 = 6,
    GLO_L1 = 7,
    GLO_L2 = 8,
    BD2_B1C = 9,  //BOC(6,1)
    BD2_B1A = 10, //BOC(14,2)
    BD2_B2A = 11, //BPSK(10) - TDDM - BOC(15, 10)
    BD2_B2B = 12, //BPSK(10)-TDDM-BOC(15,10)
    BD2_B3A = 13, //QPSK(10)
    BD2_B3C = 14, //QPSK(5)
    GPS_L1C = 15,
    BD2_B3AE = 16, //B3增强信号  QPSK(10)
    GPS_L1M = 17,

    GAL_E1BC = 20,
    GAL_E6C = 22,
    GAL_E5A = 24,
    GAL_E5B = 25,

    GLO_L3 = 26,

    BD2_B1A2 = 27, //TDDM + BOC(14,2)
    BD2_B2A2 = 28, //BPSK(10)-AltBOC(15,10)
    BD2_B2B2 = 29, //BPSK(10)-AltBOC(15,10)
    BD2_B3C2 = 30, //BOC(15,2.5)
    BD2_BS = 31,   //QPSK(8)

    BD2_B2A3 = 18,//BD2_B2A_ACE ACE-BOC(15,10)
    BD2_B2B3 = 19,//BD2_B2A_ACE ACE-BOC(15,10)
    BD2_B1C2 = 21,//BD2_B1C_QM  QMBOC
    BD2_B1A3 = 23,//BD2_B1A     BOC(14,2)

    Trans_C1 = 32, //转发式C1
    Trans_C2 = 33, //转发式C2
    Trans_C3 = 34, //转发式C3

    GPS_SBAS = 35,  //SBAS

    BD_S = 100,

    Plans_T1S1 = 201,
    Plans_T1S2 = 202,
    Plans_T2S1 = 203,
    Plans_T2S2 = 204
};

typedef struct _InterfacePara
{
    eFreqType FreqId;
    char RemoteIP[256];
    WORD RemotePort;
    WORD LocalPort;
}InterfacePara, *PInterfacePara;

/*******************************************************************\
DDS数据结构体
\*******************************************************************/
typedef struct _sDDSData
{
    DWORD	CodePhase; /*码片参数:  最高8位L220ms周期数/槽位号
                       次高8位为Q码在I码内的计数
                       低16位为码片数
                       */

    /*20120520针对高性能模拟器修改*/
    DWORD	ComIG1Para;/*高16位副码位置计数(sec_code_addr)+低16位副码内码片数(sec_code_cnt) (目前=符号内码片数) */
    DWORD	ComIG2Para;/*no use*/

    UINT64	CodeK0_NCO;
    UINT64	CodeK1_NCO;
    INT64   CodeK2_NCO;
    INT64   CodeK3_NCO;

    UINT64	CarrK0_NCO;
    INT64   CarrK1_NCO;
    INT64   CarrK2_NCO;
    INT64	CarrK3_NCO;
}sDDSData;

/*******************************************************************\
RNSS频点卫星DDS数据包结构体
\*******************************************************************/
typedef struct _RNSSSatDataPakect      /*----100bytes----*/
{
    DWORD CompData1;/*  通道有效标志（最高位）、参数加载标志（次高位）、卫星号（中间8位）、调制类型(低16bits)*/
    /*
    调制类型	                参数含义
    0			I-Q功率0:0
    1			I-Q功率0:1
    2			I-Q功率1:0
    3			I-Q功率1:1
    15			单载波
    */
    DWORD CompData2;/*  IQ，IPower(高16bits)，QPower(低16bits) */

    DWORD ComIG1Para;/*no use I支路G1多项式(高16bits)， I支路G1多项式初相(低16bits)*/
    DWORD ComIG2Para;/*no use I支路G2多项式(高16bits)， I支路G2多项式初相(低16bits)*/

    DWORD ChipAgPara;

    DWORD PaK0DDSLo;
    DWORD PaK0DDSHi;
    DWORD PaK1DDSLo;
    DWORD PaK1DDSHi;
    DWORD PaK2DDSLo;
    DWORD PaK2DDSHi;
    DWORD PaK3DDSLo;
    DWORD PaK3DDSHi;

    DWORD PbK0DDSLo;
    DWORD PbK0DDSHi;
    DWORD PbK1DDSLo;
    DWORD PbK1DDSHi;
    DWORD PbK2DDSLo;
    DWORD PbK2DDSHi;
    DWORD PbK3DDSLo;
    DWORD PbK3DDSHi;

    DWORD IGNPBits;
    DWORD QGNPBits;


}RNSSSatDataPakect, *PRNSSSatDataPakect;

/*******************************************************************\
网络命令字结构体
\*******************************************************************/
typedef struct _NetCmdWord
{
    DWORD CMD;
    DWORD Length;
    DWORD TimeFlag;
    DWORD Check;
}NetCmdWord, *PNetCmdWord;


/*******************************************************************\
*BD外部设置星历数据结构体
\*******************************************************************/
typedef struct _BDEphemerisSetPara
{
    int				toe;		//星历参考时间
    int				toc;		//钟差参考时间
    int             WN;			//整周计数
    double			M0;			//平近角点
    double			e; 			//偏心率
    double			sqrtA;		//长半轴方根
    double			OMEGA0;		//升交点赤经
    double			i0;			//轨道倾角
    double			omega;		//近地点幅角
    double			IDOT;		//轨道倾角变化率
    double			Crs; 		//轨道半径的正弦调和改正项的振幅
    double			deltan;		//卫星平均运动速率与计算值之差
    double			OMEGADOT;	//升交点赤经变化率
    double			Crc;		//轨道半径的余弦调和改正项的振幅
    double			Cuc;		//纬度幅角的余弦调和改正项的振幅
    double			Cus;		//纬度幅角的正弦调和改正项的振幅
    double			Cic;		//轨道倾角的余弦调和改正项的振幅
    double			Cis;		//轨道倾角的正弦调和改正项的振幅
    double         a0;			//钟差 s
    double         a1;			//钟速 s/s
    double         a2;         //钟速 s/s^2
    double			TGD1;		//星上设备时延差1
    double         TGD2;		//星上设备时延差2
    double         a[4];		//电离层参数Alpha
    double         b[4];		//电离层参数Beta
}BDEphemerisSetPara, *PBDEphemerisSetPara;	////BD外部设置星历数据结构体

/**************************************************************\
* BD电文卫星参数
\**************************************************************/
typedef struct NavSVPara16
{
    INT			toe;			//(单位需要转换) *2^-3
    INT			toc;			//(单位需要转换) *2^-3
    int                     weeknum;                // 北斗周数
    double			M0;			//(单位需要转换) *2^31/3.1415926	填写历数信息时单位转换为 *2^23/3.1415926
    double			e; 			//单位需要转换) *2^33				填写历数信息时单位转换为 *2^21
    double			sqrtA;			//(单位需要转换) *2^19				填写历数信息时单位转换为 *2^11
    double			OMEGA0;			//(单位需要转换) *2^31/3.1415926	填写历数信息时单位转换为 *2^23/3.1415926
    double			i0;			//(单位需要转换) *2^31/3.1415926
    double			omega;			//(单位需要转换) *2^31/3.1415926	填写历数信息时单位转换为 *2^23/3.1415926
    double			IDOT;			//(单位需要转换) *2^43/3.1415926
    double			Crs; 			//(单位需要转换) *2^6
    double			deltan;			//(单位需要转换) *2^43/3.1415926
    double			OMEGADOT;		//(单位需要转换) *2^43/3.1415926	填写历数信息时单位转换为 *2^38/3.1415926
    double			Crc;			//(单位需要转换) *2^6
    double			Cuc;			//(单位需要转换) *2^31
    double			Cus;			//(单位需要转换) *2^31
    double			Cic;			//(单位需要转换) *2^31
    double			Cis;			//(单位需要转换) *2^31
    double                  af0;
    double                  af1;
    double                  af2;
    double			TGD1;
    double                  TGD2;
    // meo/igso ionosphere
    double                  a_g[4];
    double                  b_g[4];
    // geo ionosphere
    double			A1; 			//电离层参数      (单位需要转换)*2^-1
    double			B; 			//电离层参数      (单位需要转换) /7
    double			a_b[4]; 		//电离层参数      (单位需要转换)*2^30、*2^27 、*2^24、 *2^24
    double			b_b[4]; 		//电离层参数      (单位需要转换)*2^-11、 *2^-14 、*2^-16、 *2^-17
    double			c_b[4]; 		//电离层参数      (单位需要转换)*2^-6、 *2^-11 、*2^-14、 *2^-15
}NavSVPara16;

/**************************************************************\
* GPS电文卫星参数
\**************************************************************/
typedef struct NavSVPara  //外部参数设置结构体
{
    BYTE			Alert;			//固定0
    BYTE			Anti;			//固定0
    unsigned short	WeekNo;
    BYTE			CodeOnL2;     	//01
    BYTE			SVAccuracy;   	//0000
    BYTE			SvHealth;		//默认值000000
    unsigned short	IODC;
    BYTE			L2PDataFlag;  	//00
    double			TGD;			//
    INT				toc;			//
    double			af2;			//
    double			af1;			//
    double			af0;			//
    INT				IODE;			//
    double			Crs; 			//
    double			deltan;			//
    double			M0;				//
    double			Cuc;			//
    double			e; 				//
    double			Cus;			//
    double			sqrtA;			//
    INT				toe;			//
    BYTE			FitIntervalFlag;//0
    INT				AODO; 			//
    double			Cic;			//
    double			OMEGA0;			//
    double			Cis;			//
    double			i0;				//
    double			Crc;			//
    double			omega;			//
    double			OMEGADOT;		//
    double			IDOT;			//
    INT				toa;			//
    double			ai_alm;			//
    double			e_alm;
    double			OMEGADOT_alm;
    double			sqrtA_alm;
    double			OMEGA0_alm;
    double			omega_alm;
    double			M0_alm;
    int             health_alm;
    double			af1_alm;
    double			af0_alm;
    BYTE			WNa;
    double			a[4];
    double			b[4];
    double			A1;
    double			A0;
    INT				tot;
    BYTE			WNt;
    BYTE			deltaTLS;
    BYTE			WNLSF;
    BYTE			DN;
    BYTE			deltaTLSF;
    BYTE			SVCONFIG;
    BYTE			AvailabilityIndicator;
    BYTE			ERD; 			//100000
}NavSVPara;

typedef struct GLO_NavSVPara  //外部参数设置结构体
{
    unsigned short	WeekNo;
    double			TGD;
	int				toc;
	double			af2;
	double			af1;
	double			af0;
    double			Crs;
    double			deltan;
    double			M0;
    double			Cuc;
    double			e;
    double			Cus;
    double			sqrtA;
    int				toe;
    double			Cic;
    double			OMEGA0;
    double			Cis;
    double			i0;
    double			Crc;
    double			omega;
    double			OMEGADOT;
    double			IDOT;
    double			a[4];
    double			b[4];
}GLO_NavSVPara;

typedef struct extGLONASS_Almanac
{
    unsigned char M;   //MnA`卫星型号
    unsigned char n;   //nA：卫星号
    unsigned char H;   //HnA：频率数
    unsigned char l;   //
    unsigned char Cn;  //健康标识
    double tau;        //修正值
    double lambda;     //λnA：
    double delta_i;    //ΔinA：
    double epsilon;    //εnA：
    double omega;      //ωnA：
    double t;          //ke能是tλnA：
    double delta_T;    //ΔTnA
    double delta_T_dot;//ΔTnA·
//	char dump[3];
}extGLONASS_Almanac;

typedef struct extGLONASS_Data
{
	//========== 星历相关参数 =============
	int tk;           // 填0，外部使用周内秒表示
	int tb;           // 星历的参考时间，以一天内的分钟表示

	double x;         // 根据星历文件填写
	double x_dot;     // 根据星历文件填写
	double x_dot_dot; // 根据星历文件填写	
	double y;         // 根据星历文件填写
	double y_dot;     // 根据星历文件填写
	double y_dot_dot; // 根据星历文件填写
	double z;         // 根据星历文件填写
	double z_dot;     // 根据星历文件填写
	double z_dot_dot; // 根据星历文件填写	
	double tau;       // 填0，glonass时间与卫星时间之间的差值
	double gamma;     // 填0，γn(tb)：
	double delta_tau; // 填0，Δτn：

	unsigned char B;  // 填0，卫星健康状态，0表示健康，4表示故障Bn：
	unsigned char P;  // 填0，P：
	unsigned char l;  // 填0，卫星监控状态，0健康，1故障In：
	unsigned char E;  // 填1En：
	unsigned char P1; // 填0
	unsigned char P2; // 填0
	unsigned char P3; // 填0
	unsigned char P4; // 填0，
	unsigned char FT; // 填0，用户距离精度索引
	unsigned char n;  // 卫星编号
	unsigned char M;  // 填1
	unsigned short NT;// 填0，通过调用时间设置函数处理，
	// 从上一个闰年的1月1日起算的天数，最大不超过四年

	//========== 历书相关参数 ===============
	unsigned short NA; // 填0，通过调用时间设置函数处理，
	// 闰年开始的日期计数
	double tauc;       // 填0，相对于NA时刻，GLONASS时间尺度相对UTC(SU)的时间改正
	double tauGPS;     // 填0，GPS时间相对GLONASS时间的改正
	unsigned char N4;  // 填0，通过调用时间设置函数处理,
	// 代表从1996年开始的4年的间隔计数；
	extGLONASS_Almanac almanac[24];
	double B1;	   // 填0，以S为单位的从 日开始的UTC与UT1之间的偏差的零阶项，可以通过外部修改；
	double B2;	   // 填0，以S为单位的从 日开始的UTC与UT1之间的偏差的一阶项，可以通过外部修改；
	unsigned char KP;  // 填0，跳秒标识，00无跳秒，01加一秒，11减一秒
}extGLONASS_Data;



typedef struct _BDEphemeris
{
	double toe;			//(单位需要转换) *2^-3
	double toc;			//(单位需要转换) *2^-3
	double weeknum;                // 北斗周数
	double M0;			//(单位需要转换) *2^31/3.1415926	填写历数信息时单位转换为 *2^23/3.1415926
	double e; 			//单位需要转换) *2^33				填写历数信息时单位转换为 *2^21
	double sqrtA;			//(单位需要转换) *2^19				填写历数信息时单位转换为 *2^11 
	double OMEGA0;			//(单位需要转换) *2^31/3.1415926	填写历数信息时单位转换为 *2^23/3.1415926
	double i0;			//(单位需要转换) *2^31/3.1415926	
	double omega;			//(单位需要转换) *2^31/3.1415926	填写历数信息时单位转换为 *2^23/3.1415926
	double IDOT;			//(单位需要转换) *2^43/3.1415926
	double Crs; 			//(单位需要转换) *2^6
	double deltan;			//(单位需要转换) *2^43/3.1415926
	double OMEGADOT;		//(单位需要转换) *2^43/3.1415926	填写历数信息时单位转换为 *2^38/3.1415926
	double Crc;			//(单位需要转换) *2^6
	double Cuc;			//(单位需要转换) *2^31
	double Cus;			//(单位需要转换) *2^31
	double Cic;			//(单位需要转换) *2^31
	double Cis;			//(单位需要转换) *2^31
	double af0;
	double af1;
	double af2;
	// meo/igso ionosphere   8 paras
	double a_g[4];
	double b_g[4];
	// geo ionosphere       14 paras
	double A1; 			//电离层参数      (单位需要转换)*2^-1
	double B; 			//电离层参数      (单位需要转换) /7
	double a_b[4];
	double b_b[4];
	double c_b[4];
	// =====  almanace =====================
	double sqrtA_alm;	//从文件提取
	double a0_alm;		//从文件提取
	double a1_alm;		//从文件提取
	double OMEGA0_alm;	//从文件提取
	double e_alm; 		//从文件提取
	double ceilta;		//从文件提取
	double OMEGADOT_alm;	//从文件提取
	double omega_alm;	//从文件提取
	double M0_alm;		//从文件提取  
	double Hea;		//从文件提取  
	double toa;		//从文件提取        
}BDEphemeris;

typedef struct BD_GMI_PARA  //BD系统GEO/MEO/IGSO卫星D1信息结构体
{
	unsigned short  	WN;		// 通过BD2_SetTime函数设定
	unsigned int		SOW;		// 程序控制
	char			URAI;		// 0
	char			SatH1;		// 0
	double			TGD1;		// 0
	double			TGD2;		// 0
	char			IODC;           // 1
	int			toc;		// 采用toe
	double			a0;		// 用户自行赋值，可用以前程序中的参考值
	double			a1;		// 用户自行赋值，在更换星历的条件下建议该值赋 0
	double			a2;		// 用户自行赋值，在更换星历的条件下建议该值赋 0
	char			IODE;		// 1
	int			toe;		//从文件提取
	double			M0;		//从文件提取
	double			e; 		//从文件提取
	double			sqrtA;		//从文件提取
	double			OMEGA0;		//从文件提取
	double			i0;		//从文件提取
	double			omega;		//从文件提取
	double			IDOT;		//从文件提取
	double			Crs; 		//从文件提取
	double			deltan;		//从文件提取
	double			OMEGADOT;	//从文件提取
	double			Crc;		//从文件提取
	double			Cuc;		//从文件提取
	double			Cus;		//从文件提取
	double			Cic;		//从文件提取
	double			Cis;		//从文件提取
}BD_GMI_PARA;

typedef struct BDGEOID2Frm2_3_4  //BD系统GEO卫星D2 I支路 子帧2 子帧3 子帧4 信息结构体
{
	unsigned int		SOW;
	char			EncF2;		// 1
	char			EncF3;		// 1
	char			EncF4;		// 1
	char			SatH2;		// 0
	char			BD2ID[30];	// 全0
	char			GPSID[30];	// 全0
	char			GALID[30];	// 全0
	char			UDREI[3][18];	// 全0
	char			RURAI[3][18];	// 全0
	unsigned short		deltat[3][18];	// 全0
}BDGEOID2Frm2_3_4;

typedef struct BDGEOID2Frm5  //BD系统GEO卫星D2 I支路 子帧5 信息结构体
{

	unsigned int		SOW;			//周内秒
	char			EncF5;			//表示子帧是否加密
	double			Ion[160];		// 0
	double			Iona[160];		// 0
	double			T1;                     // 0
	double			deltaX1;		// 0
	double			deltaY1;		// 0
	double			deltaZ1;		// 0
	double			A0l;			// 0
	double			A1l;			// 0
	double			deltaXDOTl;		// 0
	double			deltaYDOTl;		// 0
	double			deltaZDOTl;		// 0
	double			T2;			// 0
	double			deltaX2;		// 0
	double			deltaY2;		// 0
	double			deltaZ2;		// 0
	double			A02;			// 0
	double			A12;			// 0
	double			deltaXDOT2;		// 0
	double			deltaYDOT2;		// 0
	double			deltaZDOT2;		// 0
	double			EPIO[14];		// 3840
	// ===== iono  8 paras==================
	double			a8[4]; 			//电离层参数 6.519300000000e-009,1.490200000000e-008,-5.960500000000e-008,-1.192100000000e-007;
	double			b8[4]; 			//电离层参数 7.782400000000e+004,3.277000000000e+004,-6.554000000000e+004,-1.966100000000e+005;

	// ===== iono 14 paras==================
	double			A1; 			//电离层参数 0.000000000000e+000;
	double			B; 			//电离层参数 0.000000000000e+000;
	double			a[4]; 			//电离层参数 6.519300000000e-009,1.490200000000e-008,-5.960500000000e-008,-1.192100000000e-007;
	double			b[4]; 			//电离层参数 7.782400000000e+004,3.277000000000e+004,-6.554000000000e+004,-1.966100000000e+005;
	double			c[4]; 			//电离层参数 1.000000000000e-001,0.000000000000e+000,0.000000000000e+000,0.000000000000e+000
	// =====  almanace =====================  以下数组必须固定30,北斗一期仅仅定义了30颗卫星的历书  ==================
	double			sqrtA_alm[30];	        //从文件提取  //30
	double			a0_alm[30];		//从文件提取
	double			a1_alm[30];		//从文件提取
	double			OMEGA0_alm[30];	        //从文件提取
	double			e_alm[30]; 		//从文件提取
	double			ceilta[30];		//从文件提取
	double			OMEGADOT_alm[30];	//从文件提取
	double			omega_alm[30];		//从文件提取
	double			M0_alm[30];		//从文件提取
	double			Hea[30];		//从文件提取
	int			toa;			//从文件提取
	double			WNa;                    //通过BD2_SetTime函数设定
	// ===== time transfer =================
	double			A0MAT;			// 0
	double			A1MAT;			// 0
	double			A0GPS;			// 0
	double			A1GPS;			// 0
	double			A0Galileo;		// 0
	double			A1Galileo;		// 0
	double			A0Glo;			// 0
	double			A1Glo;			// 0
	short			deltaTLS;		// 0
	short			deltaTLSF;		// 0
	char			WNLSF;			// 0
	double			A0UTC;			// 0
	double			A1UTC;			// 0
	char			DN;			// 0
}BDGEOID2Frm5;



Q_DECLARE_METATYPE(ObsData)
Q_DECLARE_METATYPE(UserTrkData)
Q_DECLARE_METATYPE(SatObsData)

typedef struct _NavigationBaseinformation
{
	BYTE Message[40];//电文信息
	WORD FreqID;//频点号
	int SatID;//卫星号
	DWORD Sow;//周内秒
	DWORD Wekcount;//周计数

}NavigationBaseinformation, *pNavigationBaseinformation;
typedef struct _InertialNavigation
{
	UINT64 SNOW;
	double Gyro[3];//陀螺x y z
	double ACC[3];//加速度计 x,y,z

}InertialNavigation, *PInertialNavigation;


#endif
