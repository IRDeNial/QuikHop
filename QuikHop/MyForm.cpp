#include "MyForm.h"
#include "ExMem.h"

#include <Windows.h>
#include <stdio.h>
#include <string>

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "Advapi32.lib")

#pragma hdrstop

#define ARRAY_LENGTH(array) (sizeof(array)/sizeof((array)[0]))
#define _INTSIZEOF(n) ( (sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1) )

using namespace QuikHop;
using namespace ExMem;

System::Void MyForm::MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
    add_log("Before asking for help, be sure you bound a key to \"+jump 32;-jump 32\"!\n");
    add_log("\n");

    /*
    this->Width = 452;
    this->Height = 276;
    */
}

System::Void MyForm::form_resize(int form_width,int form_height,int tab_height) {
    int x = form_width,
        y = form_height;
    const int rate = 1,
              start_x = this->Width,
              start_y = this->Height;

    int current_size_x = this->Width,
        current_size_y = this->Height;

    bool increase_x = false,
         increase_y = false,
         decrease_x = false,
         decrease_y = false;

    //this->tabControl1->Width = tab_width;
    this->tabControl1->Height = tab_height;

    if(start_x != x) {
        if(start_x > x)
            decrease_x = true;
        else
            increase_x = true;
    }
    if(start_y != y) {
        if(start_y > y)
            decrease_y = true;
        else
            increase_y = true;
    }

    while((current_size_x != x) && (current_size_y != y)) {
        // Change width
        if(decrease_x) {
            if(current_size_x > x) {
                this->Width = --current_size_x;
            }
        } else if(increase_x) {
            if(current_size_x < x) {
                this->Width = ++current_size_x;
            }
        }

        // Change height
        if(decrease_y) {
            if(current_size_y > y) {
                this->Height = --current_size_y;
            }
        } else if(increase_y) {
            if(current_size_y < y) {
                this->Height = ++current_size_y;
            }
        }
    }
}

System::Void MyForm::button_initialize_Click(System::Object^  sender, System::EventArgs^  e) {
    char buffer[5000];
    /* Subroutine bytecode */
    BYTE shellCode[] =  "\x89\x8F\x20\x02"
	"\x00\x00\x60\x6A\x20\xE8\xDE\xAD\xC0"
	"\xDE\x98\x25\x00\x00\x00\x80\x74\x0D"
	"\x68\xDE\xAD\xC0\xDE\xE8\xDE\xAD\xC0"
	"\xDE\x83\xC4\x04\x61\xE9\xDE\xAD\xC0\xDE"
    // Empy memory placeholder for other functions
    "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
    "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00";
    
    DWORD EngineBase = NULL,
          ClientBase = NULL,
          ptrCMDEXEC = NULL,
          ptrHOOKCODE = NULL,
          dwPID = NULL;
    ULONG AllocSize = ARRAY_LENGTH(shellCode);
    PVOID pSection = NULL;
    HANDLE hProc = NULL;

    if(checkBox8->Checked) {
        sprintf_s(buffer,"[DEBUG] shellCode size: %i\n",AllocSize);
        add_log(buffer);

        sprintf_s(buffer,"[DEBUG] ShellCode location: %X\n",shellCode);
        add_log(buffer);
    }

    int configLoc = 41;
    char *tmp = ";+jump 1;-jump 1";
    strcpy((char *)&shellCode[configLoc],tmp);
    configLoc += 16;
 
    // Flashlight Spam
    if(checkBox1->Checked) {
        char *tmp = ";impulse 100";
        strcpy((char *)&shellCode[configLoc],tmp);
        configLoc += 12;
    }
    // Jump Sound
    if(checkBox2->Checked) {
        char *tmp = ";playgamesound ambient/water/drip1.wav";
        strcpy((char *)&shellCode[configLoc],tmp);
        configLoc += 38;
    }

    // Chat Spam
    if(checkBox4->Checked) {
        char *tmp = ";say I JUMPED!";
        strcpy((char *)&shellCode[configLoc],tmp);
        configLoc += 14;
    }
    
    // Jump Attack
    if(checkBox5->Checked) {
        char *tmp = ";+attack 1;-attack 1";
        strcpy((char *)&shellCode[configLoc],tmp);
        configLoc += 20;
    }

    // Toggle crouch
    if(checkBox6->Checked) {
        char tmp[] = ";+duck 50;wait;wait;wait;wait;wait;wait;wait;wait;wait;wait;wait;-duck 50";
        strcpy((char *)&shellCode[configLoc],tmp);
        configLoc += 73;
    }

    // Junk jumps
    if(checkBox7->Checked) {
        char tmp[] = ";wait;wait;+jump 10;-jump 10;wait;wait;wait;+jump 10;-jump 10";
        strcpy((char *)&shellCode[configLoc],tmp);
        configLoc += 61;
    }

    if(checkBox8->Checked) {
        add_log("[DEBUG] Shell Code: ");
        for(int i=41;i<configLoc;i++) {
            sprintf_s(buffer,"%c",(char *)shellCode[i]);
            add_log(buffer);
        }
        add_log("\n");
    }

    shellCode[configLoc+1]=0;

    /* Activation Key */
    int keyCode = 32;
    if(comboBox1->SelectedIndex == 0) {
        keyCode = 32;
    } else if(comboBox1->SelectedIndex == 1) {
        keyCode = 162;
    } else if(comboBox1->SelectedIndex == 2) {
        keyCode = 163;
    } else if(comboBox1->SelectedIndex == 3) {
        keyCode = 1;
    } else if(comboBox1->SelectedIndex == 4) {
        keyCode = 2;
    } else if(comboBox1->SelectedIndex == 5) {
        keyCode = 3;
    } else if(comboBox1->SelectedIndex == 6) {
        keyCode = 160;
    } else if(comboBox1->SelectedIndex == 7) {
        keyCode = 161;
    } else if(comboBox1->SelectedIndex == 8) {
        keyCode = 164;
    } else if(comboBox1->SelectedIndex == 9) {
        keyCode = 165;
    } else if(comboBox1->SelectedIndex == 10) {
        keyCode = 45;
    } else if(comboBox1->SelectedIndex == 11) {
        keyCode = 46;
    } else if(comboBox1->SelectedIndex == 12) {
        keyCode = 36;
    } else if(comboBox1->SelectedIndex == 13) {
        keyCode = 35;
    } else if(comboBox1->SelectedIndex == 14) {
        keyCode = 33;
    } else if(comboBox1->SelectedIndex == 15) {
        keyCode = 34;
    }

    /* Get the PID */
    dwPID = GetPIDByName("hl2.exe");
    
    if(!dwPID) {
        sprintf_s(buffer,"[1] [Error] Process 'hl2.exe' not found\n");
        add_log(buffer);
        return;
    } else {
        sprintf_s(buffer,"[1] Process ID: %X\n",dwPID);
        add_log(buffer);
    }

    /* Get handle */
    
    hProc = ExMem::GetAccessHandle(dwPID);
    
    if(!hProc) {
        sprintf_s(buffer,"[2] [Error] Unable to acquire process handle\n");
        add_log(buffer);
        return;
    } else {
		sprintf_s(buffer,"[2] Process handle acquired\n");
        add_log(buffer);
    }

    /* Get Engine Base Address */
    
    EngineBase = ExMem::GetModuleBase(dwPID,"engine.dll");
    
    if(!EngineBase) {
        sprintf_s(buffer,"[3] [Error] Engine module base not found\n");
        add_log(buffer);
        return;
    } else {
        sprintf_s(buffer,"[3] Engine Module Base: %X\n",EngineBase);
        add_log(buffer);
    }

    /* Get Client Base Address */
    
    ClientBase = ExMem::GetModuleBase(dwPID,"client.dll");
    
	if(!ClientBase) {
        sprintf_s(buffer,"[4] [Error] Client module base not found\n");
        add_log(buffer);
        return;
    } else {
        sprintf_s(buffer,"[4] Client Module Base: %X\n",ClientBase);
        add_log(buffer);
    }

    /* Get pointer to the command queue */
    
    ptrCMDEXEC = ExMem::dwFindPatternEx(hProc,EngineBase,0x3D1000,(BYTE*)"\x55\x8B\xEC\x51\xFF\x15\x00\x00\x00\x00\x8B\xC8\xA1\x00\x00\x00\x00\x3B\xC8\x74\x13\x56\x8B\xD1\xBE\x00\x00\x00\x00\x33\xC0\xF0\x0F\xB1\x16\x5E\x85\xC0\x75\x08\xFF\x05\x00\x00\x00\x00\xEB\x10\xF3\x90\x6A\x00\x51\xB9\x00\x00\x00\x00\xFF\x15\x00\x00\x00\x00\x8B\x45\x08\x6A\x00\x50\xB9\x00\x00\x00\x00\xE8\x00\x00\x00\x00",_X("xxxxxx????xxx????xxxxxxxx????xxxxxxxxxxxxx????xxxxxxxx????xx????xxxxxxx????x????"));
    
    if (!ptrCMDEXEC) {
        sprintf_s(buffer,"[5] [Error] Unable to find queue function.\n");
        add_log(buffer);
        return;
    } else {
        sprintf_s(buffer,"[5] Queue function found: %X\n",ptrCMDEXEC);
        add_log(buffer);
    }
    

    /* Get pointer to hook code */
    
    ptrHOOKCODE = ExMem::dwFindPatternEx(hProc,ClientBase,0x54b000,(BYTE*)"\x89\x8F\x00\x00\x00\x00\xEB\x0A\xC7\x87\x00\x00\x00\x00\x00\x00\x00\x00\x85\xDB",_X("xx????xxxx????????xx"));
    
    if (!ptrHOOKCODE) {
        sprintf_s(buffer,"[6] [Error] QuikHop has already been loaded\n");
        add_log(buffer);
        return;
    } else {
        sprintf_s(buffer,"[6] Target code found\n");
        add_log(buffer);
    }


	/* Hack */
    if(ExMem::AllocVM(hProc,&pSection,NULL,&AllocSize,MEM_COMMIT,PAGE_EXECUTE_READWRITE)) {
        sprintf_s(buffer,"[7] [Error] Unable to initialize memory\n");
        add_log(buffer);
        return;
    } else {
        sprintf_s(buffer,"[7] Initialized memory\n");
        add_log(buffer);
    }

	*(char*)(ExMem::dwFindPattern((DWORD)&shellCode[0],1337,(BYTE*)"\x6A\x20\xE8","xxx")+1)=(char)keyCode;

	//GetAsyncKeyState
	ExMem::Shell::FixJmpAddr(&shellCode[0],(DWORD)GetProcAddress(LoadLibrary(_X("user32.dll")), _X("GetAsyncKeyState")),pSection);
	
    //Pointer to command string
    ExMem::Shell::FixAddr(&shellCode[0],(DWORD)pSection+41,pSection);

	//RunCommand aka. Cbuf_addtext
	ExMem::Shell::FixJmpAddr(&shellCode[0],ptrCMDEXEC,pSection);

	//Return address (Original instruction was 6 bytes)
	ExMem::Shell::FixJmpAddr(&shellCode[0],ptrHOOKCODE+6,pSection);

    /* Upload the shellcode, and make the patches */
    if (!ExMem::WriteVM(hProc,pSection,&shellCode,ARRAY_LENGTH(shellCode),NULL)) {
		add_log("[8] QuikHop Loaded!\n");
    } else {
        add_log("[8] Unable to load QuikHop\n");
		return;
    }

    
    char patch[]="\xE9\x00\x00\x00\x00";
	*(DWORD *)&patch[1]=(DWORD)pSection-ptrHOOKCODE-5;
	ExMem::ForceWriteVM(hProc,(void*)ptrHOOKCODE,&patch,5);
    
    add_log("\n");

    if(checkBox3->Checked) {
        exit(1);
	}
}

System::Void MyForm::add_log(const char *input) {
    char buffer[5000];
    vsprintf_s(buffer,input, (char*)&input + _INTSIZEOF(input));
    this->textBox1->AppendText(gcnew System::String(input));
}