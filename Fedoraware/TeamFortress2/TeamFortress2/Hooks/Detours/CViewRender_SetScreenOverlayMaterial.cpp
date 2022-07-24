#include "../Hooks.h"

MAKE_HOOK(CViewRender_SetScreenOverlayMaterial, Utils::GetVFuncPtr(I::ViewRender, 20), void, __fastcall,
	void* ecx, void* edx, IMaterial* pMaterial)
{
	const int matIndex = Vars::Visuals::VisualOverlay.Value;

	if (!matIndex && Vars::Visuals::RemoveScreenOverlays.Value) {
		return Hook.Original<FN>()(ecx, edx, nullptr);
	}

	IMaterial* mat = pMaterial;

	switch (matIndex) {
	case 1: {
		mat = I::MaterialSystem->Find("effects/imcookin", TEXTURE_GROUP_CLIENT_EFFECTS, false);
		break;
	}
	case 2: {
		mat = I::MaterialSystem->Find("effects/jarate_overlay", TEXTURE_GROUP_CLIENT_EFFECTS, false);
		break;
	}
	case 3: {
		mat = I::MaterialSystem->Find("effects/bleed_overlay", TEXTURE_GROUP_CLIENT_EFFECTS, false);
		break;
	}
	case 4: {
		mat = I::MaterialSystem->Find("effects/stealth_overlay", TEXTURE_GROUP_CLIENT_EFFECTS, false);
		break;
	}
	case 5: {
		mat = I::MaterialSystem->Find("effects/dodge_overlay", TEXTURE_GROUP_CLIENT_EFFECTS, false);
		break;
	}
	}

	return Hook.Original<FN>()(ecx, edx, mat);
}