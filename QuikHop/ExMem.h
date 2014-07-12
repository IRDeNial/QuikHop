//Library designed for external memory operations
//#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <Ntsecapi.h>
#include <Vector>
#include <TlHelp32.h>

#define _INTSIZEOF(n) ( (sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1) )
#define _X
#define byte int

#define emit(X) __asm _emit X
#define STARTV emit(0xEB) emit(0x10) emit(0x43) emit(0x56) emit(0x20) emit(0x20) emit(0x0C) emit(0x00) emit(0x00) emit(0x00) emit(0x00) emit(0x00) emit(0x00) emit(0x00) emit(0x43) emit(0x56) emit(0x20) emit(0x20) 
#define ENDV emit(0xEB) emit(0x10) emit(0x43) emit(0x56) emit(0x20) emit(0x20) emit(0x0D) emit(0x00) emit(0x00) emit(0x00) emit(0x00) emit(0x00) emit(0x00) emit(0x00) emit(0x43) emit(0x56) emit(0x20) emit(0x20) 


/* Create some defines from the Driver Developer Kit so we don't have to include it */
#define ARRAY_LENGTH(array) (sizeof(array)/sizeof((array)[0]))
#define OBJ_KERNEL_HANDLE       0x00000200L
#define InitializeObjectAttributes( p, n, a, r, s ) { \
    (p)->Length = sizeof( ExMem::OBJECT_ATTRIBUTES );   \
    (p)->RootDirectory = r;                             \
    (p)->Attributes = a;                                \
    (p)->ObjectName = n;                                \
    (p)->SecurityDescriptor = s;                        \
    (p)->SecurityQualityOfService = NULL;               \
    }

HANDLE hDebugConsole;
DWORD dw_msg_size;

const char xor_key[]={13,42,37,73,54};
std::vector<char> decrypt(char *str)
{
	std::vector<char> data(str,strlen(str)+str);
	for(byte pos=0; pos<data.size() ; pos++)
		data[pos]^=xor_key[pos%sizeof(xor_key)];
	data.push_back(0);
	return data;
}

namespace ExMem
{
	/* ZwWriteVirtualMemory */
    NTSTATUS(_stdcall *WriteVM)(HANDLE ProcessHandle, PVOID BaseAddress, PVOID Buffer, ULONG NumberOfBytesToWrite, PULONG NumberOfBytesWritten)=(NTSTATUS(_stdcall*)(HANDLE ProcessHandle, PVOID BaseAddress, PVOID Buffer, ULONG NumberOfBytesToWrite, PULONG NumberOfBytesWritten))(void*)GetProcAddress(GetModuleHandle(_X("ntdll")), _X("NtWriteVirtualMemory"));
   
	/* ZwReadVirtualMemory */
	NTSTATUS(_stdcall *ReadVM)(HANDLE ProcessHandle, PVOID BaseAddress, PVOID Buffer, ULONG NumberOfBytesToRead, PULONG NumberOfBytesRead)=(NTSTATUS(_stdcall*)(HANDLE ProcessHandle, PVOID BaseAddress, PVOID Buffer, ULONG NumberOfBytesToRead, PULONG NumberOfBytesRead))(void*)GetProcAddress(GetModuleHandle(_X("ntdll")), _X("NtReadVirtualMemory"));
    
	/* ZwProtectVirtualMemory */
	NTSTATUS(_stdcall *ProtectVM)(HANDLE ProcessHandle, PVOID BaseAddress, PULONG NumberOfBytesToProtect, ULONG NewAccessProtection, PULONG OldAccessProtection)=(NTSTATUS(_stdcall*)(HANDLE ProcessHandle, PVOID BaseAddress, PULONG NumberOfBytesToProtect, ULONG NewAccessProtection, PULONG OldAccessProtection))(void*)GetProcAddress(GetModuleHandle(_X("ntdll")), _X("NtProtectVirtualMemory"));

	/* ZwAllocateVirtualMemory */
	NTSTATUS(_stdcall *AllocVM)(HANDLE ProcessHandle, PVOID *BaseAddress, ULONG ZeroBits, PSIZE_T RegionSize, ULONG AllocationType, ULONG Protect)=(NTSTATUS(_stdcall*)(HANDLE ProcessHandle, PVOID *BaseAddress, ULONG ZeroBits, PSIZE_T RegionSize, ULONG AllocationType, ULONG Protect))(void*)GetProcAddress(GetModuleHandle(_X("ntdll")), _X("NtAllocateVirtualMemory"));

	typedef struct _OBJECT_ATTRIBUTES {
		ULONG           Length;
		HANDLE          RootDirectory;
		PUNICODE_STRING ObjectName;
		ULONG           Attributes;
		PVOID           SecurityDescriptor;
		PVOID           SecurityQualityOfService;
	}  OBJECT_ATTRIBUTES, *POBJECT_ATTRIBUTES;
	
	typedef struct _CLIENT_ID {
		PVOID UniqueProcess;
		PVOID UniqueThread;
	} CLIENT_ID, *PCLIENT_ID;

    BOOL EnableDebugPrivilege() { 
	    HANDLE           hToken; 
	    LUID             sedebugnameValue; 
	    TOKEN_PRIVILEGES tp; 
 
	    if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES|TOKEN_QUERY,&hToken)) {
		    return FALSE; 
        }

	    if (!LookupPrivilegeValue(NULL,SE_DEBUG_NAME,&sedebugnameValue)) { 
		    CloseHandle( hToken ); 
		    return FALSE; 
	    } 
 
	    tp.PrivilegeCount = 1; 
	    tp.Privileges[0].Luid = sedebugnameValue; 
	    tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED; 
 
	    if (!AdjustTokenPrivileges(hToken,FALSE,&tp,sizeof(tp),NULL,NULL)) { 
		    CloseHandle( hToken ); 
		    return FALSE; 
	    } 
 
	    CloseHandle( hToken ); 
	    return TRUE; 
    }

    /* ZwOpenProcess */
    NTSTATUS(_stdcall *ZwOpenProcess)(PHANDLE ProcessHandle, ULONG ACCESS_MASK, POBJECT_ATTRIBUTES ObjectAttributes, PCLIENT_ID ClientId)=(NTSTATUS(_stdcall*)(PHANDLE ProcessHandle, ULONG ACCESS_MASK, POBJECT_ATTRIBUTES ObjectAttributes, PCLIENT_ID ClientId))(void*)GetProcAddress(GetModuleHandle(_X("ntdll")), _X("NtOpenProcess"));

	/* Easy API to setup and make ZwOpenProcess call for usable Handle */
	HANDLE GetAccessHandle(DWORD ProcessID) {
		HANDLE hProc;
		ExMem::OBJECT_ATTRIBUTES objAttr;
		ExMem::CLIENT_ID ClientID;
		InitializeObjectAttributes( &objAttr, NULL, OBJ_KERNEL_HANDLE, NULL, NULL );
        objAttr.ObjectName = NULL;
        
		ClientID.UniqueProcess = (PVOID)ProcessID;
		ClientID.UniqueThread = NULL;
        
        EnableDebugPrivilege();
		if(ExMem::ZwOpenProcess(&hProc,PROCESS_ALL_ACCESS,&objAttr,&ClientID)) {
			return 0;
        }
		return hProc;
	}

	/* API for writing to any memory, reguardless of protections */
	bool ForceWriteVM(HANDLE ProcessHandle, PVOID BaseAddress, PVOID Buffer, ULONG NumberOfBytesToWrite) {
		bool retval;
		DWORD numBytes        = NumberOfBytesToWrite;
		DWORD oldAccess       = NULL;
		PVOID ProtectBaseAddr = BaseAddress;
		ExMem::ProtectVM(ProcessHandle,&ProtectBaseAddr,&numBytes,PAGE_EXECUTE_READWRITE,&oldAccess);
		retval = ExMem::WriteVM(ProcessHandle,BaseAddress,Buffer,NumberOfBytesToWrite,NULL);
		ExMem::ProtectVM(ProcessHandle,&ProtectBaseAddr,&numBytes,oldAccess,&oldAccess);
		return retval;
    }

	DWORD GetPIDByName(char* Name) {
		HANDLE hProcessSnap;
		PROCESSENTRY32 pe32 = {sizeof(pe32)};
		hProcessSnap = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0 );
		if ( hProcessSnap == INVALID_HANDLE_VALUE )
			return NULL;
		BOOL More = Process32First(hProcessSnap, &pe32);
		for (; More; More = Process32Next(hProcessSnap, &pe32)) {
			if (!strcmp(Name,pe32.szExeFile)) {
				CloseHandle(hProcessSnap);
				return pe32.th32ProcessID;
			}
		}
		CloseHandle(hProcessSnap);
		return NULL;
	}
	
	DWORD GetModuleBase( DWORD dwPID, char* szModuleName ) {
		HANDLE hModuleSnap;
		MODULEENTRY32 me32 = {sizeof(me32)};
		hModuleSnap = CreateToolhelp32Snapshot( TH32CS_SNAPMODULE, dwPID );
		if ( hModuleSnap == INVALID_HANDLE_VALUE )
			return NULL;
		BOOL More = Module32First( hModuleSnap, &me32 );
		for (; More; More = Module32Next(hModuleSnap, &me32)) {
			if (!strcmp(szModuleName ,me32.szModule )) {
				CloseHandle(hModuleSnap);
				return (DWORD)me32.modBaseAddr;
			}
		}
		CloseHandle(hModuleSnap);
		return NULL;
	}
	
	/* FOR EnableTokenPrivilege(SE_DEBUG_NAME) */
	BOOL EnableTokenPrivilege (LPTSTR privilege) {
		HANDLE hToken;                       
		TOKEN_PRIVILEGES token_privileges;                 
		DWORD dwSize;                       
		ZeroMemory (&token_privileges, sizeof (token_privileges));
		token_privileges.PrivilegeCount = 1;
		if ( !OpenProcessToken (GetCurrentProcess(), TOKEN_ALL_ACCESS, &hToken))
			return FALSE;
		if (!LookupPrivilegeValue ( NULL, privilege, &token_privileges.Privileges[0].Luid))
		{
			CloseHandle (hToken);
			return FALSE;
		}
	 
		token_privileges.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
		if (!AdjustTokenPrivileges ( hToken, FALSE, &token_privileges, 0, NULL, &dwSize))
		{
			CloseHandle (hToken);
			return FALSE;
		}
		CloseHandle (hToken);
		return TRUE;
	}
	
	bool bDataCompare(const BYTE* pData, const BYTE* bMask, const char* szMask)	{
		for(;*szMask;++szMask,++pData,++bMask){
			if(*szMask=='x' && *pData!=*bMask )
				return false;
		}
		return (*szMask) == NULL;
	}

	DWORD dwFindPattern(DWORD dwAddress,DWORD dwLen, BYTE *bMask, char * szMask) {
		for(DWORD i=0;i<dwLen;i++){
			if( bDataCompare( (BYTE*)( dwAddress+i ),bMask,szMask) )
				return (DWORD)(dwAddress+i);
		}
		return NULL;
	}

	/* Should work perfectly, if not, debug it yourself */
	DWORD dwFindPatternEx(HANDLE hProcess, DWORD dwAddress, DWORD dwLen, BYTE *bMask, char *szMask)	{
		DWORD dwRead;
		DWORD dwPattern = NULL;
		BYTE* bpMemBuffer = (BYTE*) malloc(dwLen);

		if(bpMemBuffer == NULL)	{
            //MessageBoxA(0,"Malloc Failed","Error",0);
			//add_log("ERROR: Malloc Failed");
			return 0;
		}
        //MessageBoxA(0,"Malloc Success","Error",0);
		if (ExMem::ReadVM(hProcess, (void*)dwAddress, (void*)bpMemBuffer, dwLen, &dwRead)) {
            //MessageBoxA(0,"ZwReadvirtualMemory Failed","Error",0);
			//add_log("ERROR: ZwReadVirtualMemory Failed");
			return 0;
		}
        //MessageBoxA(0,"ZwReadvirtualMemory Success","Error",0);
		if (dwLen!=dwRead) {
            //char buffer[255];
            //sprintf_s(buffer,"Error: ERROR: [dwLen=%X]  [dwRead=%X]",dwLen,dwRead);
            //MessageBoxA(0,buffer,"Error",0);
			//add_log("ERROR: [dwLen=%X]  [dwRead=%X]",dwLen,dwRead);
			return 0;
		}
        //char buffer[255];
        //sprintf_s(buffer,"[dwLen=%X]  [dwRead=%X]",dwLen,dwRead);
        //MessageBoxA(0,buffer,"Error",0);

		if(!(dwPattern = dwFindPattern((DWORD)bpMemBuffer, dwLen, bMask, szMask))) {
            //MessageBoxA(0,"Error: Pattern not found","Error",0);
			//add_log("ERROR: Pattern not found!");
			return 0;
		}
        //MessageBoxA(0,"Pattern found","Error",0);

		free(bpMemBuffer);
		dwPattern -= (DWORD)bpMemBuffer;
		return dwAddress + dwPattern;
	}



    /* This section contains functions used in the building and fixing of shellcode */
	namespace Shell
	{

		/* Calculates a jump increment AFTER the opcode */
		DWORD CalcJmp(DWORD from, DWORD to) {
            return to-from-4;
		}

		/* Searches shellcode for a signature of 0xDEADC0DE and replaces the first match with given address */
		DWORD FixAddr(BYTE* shellcode, DWORD newAddr, PVOID AllocBase, DWORD dwLen=1024) {
			DWORD fixAddr    = dwFindPattern((DWORD)&shellcode[0],dwLen,(BYTE*)"\xDE\xAD\xC0\xDE","xxxx");
			DWORD realOffset = (fixAddr - (DWORD)&shellcode[0]) + (DWORD)AllocBase;
			if (fixAddr) {
			*(DWORD *)fixAddr = newAddr;
			return realOffset;
			}
			return NULL;
		}

		DWORD FixAddr_Find(BYTE* shellcode, DWORD newAddr, PVOID AllocBase, BYTE* pattern, char* mask, DWORD dwLen=1024) {
			DWORD fixAddr    = dwFindPattern((DWORD)&shellcode[0],dwLen,pattern,mask);
			DWORD realOffset = (fixAddr - (DWORD)&shellcode[0]) + (DWORD)AllocBase;
			if (fixAddr) {
			*(DWORD *)fixAddr = newAddr;
			return realOffset;
			}
			return NULL;
		}

		/* Searches shellcode for a signature of 0xDEADC0DE and replaces the first match with given address for a jump/call */
		DWORD FixJmpAddr(BYTE* shellcode, DWORD newAddr, PVOID AllocBase, DWORD dwLen=1024) {
			DWORD fixAddr    = dwFindPattern((DWORD)&shellcode[0],dwLen,(BYTE*)"\xDE\xAD\xC0\xDE","xxxx");
			DWORD realOffset = (fixAddr - (DWORD)&shellcode[0]) + (DWORD)AllocBase;
			if (fixAddr) {
			*(DWORD *)fixAddr = CalcJmp(realOffset,newAddr);
			return realOffset;
			}
			return NULL;
		}

	}

}
//haloshadow