#include "handling.h"

#include "addrs.h"
#include "hookFns.h"

#define KEY_0 11
#define KEY_L 38

bool isGameKeyboardKeyPressed(int key) {
	int* context[3];
	context[2] = &key;
	int result;
	context[0] = &result;
	((int(__cdecl*)(void*))(g_nativeCallAddr_isGameKeyboardKeyPressed))(context);

	return result;
}

bool isGameKeyboardKeyJustPressed(int key) {
	int* context[3];
	context[2] = &key;
	int result;
	context[0] = &result;
	((int(__cdecl*)(void*))(g_nativeCallAddr_isGameKeyboardKeyJustPressed))(context);

	return result;
}

size_t g_processGame_origcall;

__forceinline int readHandling() {
	return ((int(*)())(g_ReadHandling))();
}

char processGame() {
	if (isGameKeyboardKeyPressed(KEY_0) && isGameKeyboardKeyJustPressed(KEY_L))
		readHandling();

	return ((char(*)())(g_processGame_origcall))();

}

void initHandlingReloader() {
	g_processGame_origcall = setFnAddrInCallOpcode(g_hookAddr_CWorld__process, (size_t)processGame);
}