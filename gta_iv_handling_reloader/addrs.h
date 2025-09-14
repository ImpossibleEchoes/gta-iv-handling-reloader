#pragma once
#include "Windows.h"


extern size_t g_hookAddr_CWorld__process;
extern size_t g_nativeCallAddr_isGameKeyboardKeyJustPressed;
extern size_t g_nativeCallAddr_isGameKeyboardKeyPressed;
extern size_t g_ReadHandling;

DWORD initAddrsDynamicAll();
