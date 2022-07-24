#pragma once
#include "../../SDK/SDK.h"

class CAntiAim
{
private:
	void FixMovement(CUserCmd* pCmd, const Vec3& vOldAngles, float fOldSideMove, float fOldForwardMove);
	float EdgeDistance(float edgeRayYaw);
	bool FindEdge(float edgeOrigYaw);
	bool IsOverlapping(float a, float b, float epsilon);
	float GetAngle(int nIndex);
	std::pair<float, float> GetAnglePairPitch(int nIndex);	//	send angles, real angles
	float CalculateCustomRealPitch(float WishPitch, bool FakeDown);
	bool bPacketFlip = true;
public:
	void Run(CUserCmd* pCmd, bool* pSendPacket);
	void Event(CGameEvent* pEvent, const FNV1A_t uNameHash);
};

ADD_FEATURE(CAntiAim, AntiAim)