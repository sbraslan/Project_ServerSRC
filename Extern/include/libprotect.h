#ifndef __INC_LIBCRASHLICENCE_MAIN_H__
#define __INC_LIBCRASHLICENCE_MAIN_H__

#include <memory>
#include <cstring>
#include <vector>
#include <math.h>

#define ENABLE_CSHIELD
typedef unsigned char uint8_t;
typedef unsigned int uint32_t;

#ifndef __WIN32__
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;
#endif

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

	extern const char* BlockedList(void);
	extern int MonitorUser(void);

#ifdef __cplusplus
}
#endif

#ifdef ENABLE_CSHIELD
class CShield
{
public:
	CShield();

private:
	float fLimitMoveSpeed;
	float fLimitMoveSpeedRiding;

	uint32_t dwLimitAniAtkSpeed;
	uint32_t dwLimitAtkSpeed;
	uint32_t dwLimitBowAniAtkSpeed;
	uint32_t dwLimitBowAtkSpeed;
	uint32_t dwAtkLimit;

	// ENABLE_CHECK_MOVESPEED_HACK
public:
	void ResetMoveSpeedhack(uint32_t time);
	bool CheckMoveSpeedhack(long x, long y, uint32_t time, bool bIsRiding, float move_speed);
	int CalculateDurationCheck(int iSpd, int iDur);

private:
	uint32_t m_mshNextReduction;
	bool isRidingLocal;
	int m_mshHackCount;
	long m_mshStartX;
	long m_mshStartY;
	uint32_t m_mshStartDetect;
	uint32_t m_mshLastDetect;
	uint32_t m_mshIgnoreUntil;
	uint32_t m_mshFirstDetect;
	std::vector<double> m_mshRates;
	double g_dMovspeedHackThreshold = 0.75;	// Serverside Config
	bool g_bDisableMovspeedHacklog = false;	// Serverside Config

	// ENABLE_CHECK_WAIT_HACK
public:
	bool CheckWaithack(long x, long y, uint32_t time, float move_speed);
private:
	uint32_t m_dwCountWaithackPoint;
	long m_mshStartX2;
	long m_mshStartY2;
	uint32_t m_mshStartDetect2;
	uint32_t startDetect;
	int distWalked;
	int mobCount;


	// ENABLE_CHECK_ATTACKSPEED_HACK
public:
	uint8_t CheckAttackspeedHack(bool bIsRiding, uint32_t ani_attack_speed, long long atk_speed, uint32_t player_vid, uint32_t time);
	uint8_t CheckAttackspeedBowHack(uint32_t ani_attack_speed, long long atk_speed, uint32_t time);
private:
	uint32_t m_dwCountAttackSpeedhackPoint;
	uint32_t dwAttackVID;
	uint32_t dwAttackTime;
};
#endif

typedef std::shared_ptr<CShield> spCShield;

#endif // __INC_LIBCRASHLICENCE_MAIN_H__
