#include "../Hooks.h"

MAKE_HOOK(CMaterial_Uncache, g_Pattern.E8(L"MaterialSystem.dll", L"E8 ? ? ? ? 83 7E 1C 00 "), void, __fastcall,
		  IMaterial* ecx, void* edx, bool bPreserveVars)
{
	if (ecx)
	{
		const std::string materialName = ecx->GetName();
		if (materialName.find("m_pmat") != std::string::npos || materialName.find("glow_color") != std::string::npos){
			return;
		}
	}

	if (ecx)
	{
		Hook.Original<FN>()(ecx, edx, bPreserveVars);
	}
}