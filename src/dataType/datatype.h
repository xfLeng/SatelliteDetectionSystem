#ifndef DATATYPE_H
#define DATATYPE_H

#include <QObject>


#define ROLE_CONTEXTMENU Qt::UserRole+1  //右键菜单
#define ROLE_ICON  Qt::UserRole+2        //图标
#define ROLE_ICONSTATE  Qt::UserRole+3    //状态图标
#define ROLE_ELEDATA  Qt::UserRole+4     //参数
#define ROLE_NODENAME Qt::UserRole+5      //节点名称
#define ROLE_DATFILENAME Qt::UserRole+6    //数据文件名
#define ROLE_PARAID Qt::UserRole+7          //参数ID
//#define ROLE_MotionType Qt::UserRole+8  //汽车飞机轮船中运动类型（用于点击列表显示相应参数）

#include "ConstData.h"

enum CfgType
{
    HardwareCfg=0,
    SimCfg,
    SysCfg
};

//载体类型
enum VehicleType
{
    VehicleTypeUnknow = 0,
    Static = 1,//静止
    Simple = 2,//简单运动
    Aircraft = 3,//飞机
    Land = 4,//汽车
    Ship = 5,//轮船
    Spacecraft = 6,//太空
    Remote = 7,//远程
    Special = 8,//特殊
    TrkFile=9, //外部轨迹
	Circle=10
};
// enum SatSystemType
// {
//   BDS=0,
//   GPS=1,
//   GLONASS=2,
//   Galileo=3
// };

//载体运动类型
enum VehicleMotion
{
    VehicleMotionUnknow = 0,
    UserCircle = 1,//用户圆周运动
    UserHelix = 2,//用户螺旋运动
    UserBigRound = 3,//用户大圆运动
    UserVel = 4,//用户匀速运动
    UserAcc = 5,//用户加速运动
    UserJek = 6,//用户加加速运动
    SatPseudorangeFix = 11,//卫星伪距固定
    SatPseudorangeIncrease = 12,//卫星伪距递增
    SatVelFix = 13,//卫星速度固定
    SatAccFix = 14,//卫星加速度固定
    SatJekFix = 15,//卫星加加速度固定
    SatPseudorangeSin = 16//卫星伪距正弦变化
};

//新建载体操作类型
enum VehicleNewOperatorMotion
{
    Unknow = 0,
    Insert = 1,//插入
    Replace = 2//替换
};

/*
atmosphere_mode低16位为对流层模型选择；高16位为电离层模型选择。

trop_mode	模型
0	Saastamoinen萨斯塔莫宁模型
1	改进的霍普菲尔德模型
2	MOPS
3~14	预留，目前为关闭
15	关闭
注：0,1均可用于RTK测试；
td, Ps, humid含义均为温度（摄氏度）、大气压力（毫帕）和相对湿度（百分比），典型值为20,1000,50

iono_mode	模型	                        备注
0	        航空、航天模型	                常数模型
1	        航空、航天模型	                多项式模型
2	        航空、航天模型	                用户自定义模型
3~7	        预留，目前为关闭
8	        8参数Klobuchar模型
9	        14参数Klobuchar模型(仅用于BD)
10			（混合模型）GEO使用14参数Klobuchar模型
MEO使用8参数Klobuchar型(仅用于BD)
9~14	        预留，目前为关闭
15	        关闭
注：航空、航天模型的使用参见iono_dll库
*/
//对流层模型（枚举）
enum TroposphereMode
{
	None = 15,           //关闭，不使用任何模型
	Saastamoinen = 0,       //萨斯塔莫宁
	ImproveHopfield = 1,        //改进的霍普菲尔德
	MOPS = 2
};
//电离层模型
enum IonosphereMode
{
	NoneMode = 15,      //关闭，不使用任何模型
	LandMode = 0,       //陆地电离层模型
	SpaceMode = 1        //空间电离层模型
};
//
enum SpaceIonoTECMode
{
	Constant = 0,     //常量TEC参数
	Multinomial = 1,     //多项式TEC参数
	UserDefined = 2     //用户自定义参数
};
enum LandIonosphereMode
{
	Para8 = 8,    //GPS,BDS
	Para14 = 9,       //BDS
	GalileoParam = 2  //Galileo
};

enum eSenceParaId
{
	SimTimePara = 1,//仿真时间
	FileChoosePara = 2,//文件选择
	FileChooseEnablePara = 3,//文件选择使能
	TrkStatic = 4,//静态载体
	TrkUserCircle = 5,//用户圆周运动
	TrkUserHelix = 6,//用户螺旋运动
	TrkUserBigRound = 7,//用户大圆运动
	TrkUserVel = 8,//用户匀速运动
	TrkUserAcc = 9,//用户加速运动
	TrkUserJek = 10,//用户加加速运动
	TrkSatPseudorangeFix = 11,//卫星伪距固定
	TrkSatPseudorangeIncrease = 12,//卫星伪距递增
	TrkSatVelFix = 13,//卫星速度固定
	TrkSatAccFix = 14,//卫星加速度固定
	TrkSatJekFix = 15,//卫星加加速度固定
	TrkSatPseudorangeSin = 16,//卫星伪距正弦变化
	TroposphereModel = 17,//对流层参数
	BdSatHealthInfo = 18,//北斗卫星健康信息
	GpsSatHealthInfo = 19,//gps卫星健康信息
	GalSatHealthInfo = 20,//Gal卫星健康信息
	GloSatHealthInfo=21,//glo卫星健康信息
	BdIonoModel = 22,//bd电离层参数
	GpsIonoModel = 23,//gps电离层参数
	GalIonoModel = 24,//Gal电离层参数
	GloIonoModel = 25,//GLO电离层参数
	BdEphemeris = 26, //bd星历及历书
	GpsEphemeris = 27,//Gps星历及历书
	GalEphemeris = 28,//Gal星历及历书
	GLOEphemeris = 29,//GLO星历及历书
	Bdclockerr = 30,//bd钟差
	Gpsclockerr = 31,//gps钟差
	Galclockerr = 32,//gal钟差
	Gloclockerr = 33,//glo钟差
	BdTGD = 34,//北斗设备时延
	GpsTGD = 35,//Gps设备时延
	GalTGD = 36,//Gal设备时延
	Glotimesyn=37,//glo时间同步
	Bdtimesyn = 38,//Bd设备时间同步
	Gpstimesyn = 39,//Gps设备时间同步
	Galtimesyn = 40,//gal设备时间同步
	Interference = 41,//干扰
	CarOrAirDataType = 42,//飞机或汽车
	ShipDataType = 43,//轮船
	INSDataType = 44,//惯导
	AntDataType = 45,//天线
	PowSet = 46,//功率设置	
	EphFile=47,
	GLOAlmanac = 48//GLO非即时信息
};


class CarrierNewOperator
{
public:
    /// <summary>
    /// 载体类型
    /// </summary>
    VehicleType type;

    /// <summary>
    /// 载体运动类型
    /// </summary>
    VehicleMotion motionType;

    /// <summary>
    /// 载体操作类型
    /// </summary>
    VehicleNewOperatorMotion operatorType;

    /// <summary>
    /// 是否保留天线信息
    /// </summary>
    bool IsKeepAntenna;
};

enum InterfereType
{
	MultiPath = 0,//多路径干扰
	Transmit = 1,//转发式干扰
	UserDefine = 2 //其他干扰

};
typedef struct MFaultParametervalue
{
  int  startime;//开始时间
  int type;//1阶跃 2斜坡
  int lenth;//时长
  int SatNO;//卫星号
  double value;//变化值
}FaultParametervalue;

#endif // DATATYPE_H
