#include <stdio.h>

int main(){
	char * buffer = "%d\n";
	_asm{
		sub esp, 0x0c
		mov dword ptr [ebp - 0x04], 0x02
		mov dword ptr [ebp - 0x08], 0x04
		mov eax, dword ptr [ebp - 0x04]
		add eax, dword ptr [ebp - 0x08]
		mov dword ptr [ebp - 0x0c], eax
		
		push dword ptr [ebp - 0x0c]
		push buffer
		call printf
		add esp, 0x0c
		add esp, 0x08
	}
}