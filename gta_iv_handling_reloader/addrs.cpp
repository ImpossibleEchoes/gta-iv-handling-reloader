#include "addrs.h"
#include "hookFns.h"
//#include "Hooking.Patterns-master/Hooking.Patterns.h"
#include "Hooking.Patterns-master/Hooking.Patterns.h"

size_t g_hookAddr_CWorld__process;
size_t g_nativeCallAddr_isGameKeyboardKeyJustPressed;
size_t g_nativeCallAddr_isGameKeyboardKeyPressed;
size_t g_ReadHandling;


size_t findPattern(const char* pszPattern, ptrdiff_t offset = 0) {
	size_t found_address = (size_t)hook::pattern(pszPattern).count(1).get_first(offset);
	return found_address;
}

DWORD initAddrsDynamicAll() {

	DWORD result = 0;

	g_ReadHandling = findPattern("E8 ? ? ? ? E8 ? ? ? ? E8 ? ? ? ? E8 ? ? ? ? E8 ? ? ? ? E8 ? ? ? ? E8 ? ? ? ? E8 ? ? ? ? E8 ? ? ? ? E8 ? ? ? ? B9 ? ? ? ? E8 ? ? ? ? E8 ? ? ? ? E8 ? ? ? ? E9 ? ? ? ? ");
	if (!g_ReadHandling)
		result |= 1;
	else
		g_ReadHandling = getFnAddrInCallOpcode(g_ReadHandling);

	g_hookAddr_CWorld__process = findPattern("E8 ? ? ? ? E8 ? ? ? ? B9 ? ? ? ? E8 ? ? ? ? 83 3D ? ? ? ? ? 74 05 E8 ? ? ? ? ");
	if (!g_hookAddr_CWorld__process)
		result |= 1;

	g_nativeCallAddr_isGameKeyboardKeyJustPressed = findPattern("68 ? ? ? ? 68 7D 12 0D 54 E8 ? ? ? ? ");
	if (!g_nativeCallAddr_isGameKeyboardKeyJustPressed)
		result |= 1;
	else
		g_nativeCallAddr_isGameKeyboardKeyJustPressed = *(size_t*)(g_nativeCallAddr_isGameKeyboardKeyJustPressed + 1);

	g_nativeCallAddr_isGameKeyboardKeyPressed = findPattern("68 ? ? ? ? 68 62 62 A9 5F E8 ? ? ? ? ");
	if (!g_nativeCallAddr_isGameKeyboardKeyPressed)
		result |= 1;
	else
		g_nativeCallAddr_isGameKeyboardKeyPressed = *(size_t*)(g_nativeCallAddr_isGameKeyboardKeyPressed + 1);

	return result;

}

