#pragma once

#include <Windows.h>

/*List*/
typedef HANDLE	( WINAPI * XSidecarOpenEmulatorList_t )					( );
typedef HANDLE	( WINAPI * XSidecarOpenListItem_t )						( HANDLE List, int ListIndex );
typedef SIZE_T	( WINAPI * XSidecarGetListItemCount_t )					( HANDLE List );
typedef HRESULT	( WINAPI * XSidecarGetListItemName_t )					( HANDLE Handle, int ListIndex, LPCWSTR Name, SIZE_T Length, DWORD* BytesRead );

typedef void	( WINAPI * XSidecarCloseList_t )						( HANDLE List );

typedef HRESULT	( WINAPI * XSidecarGetName_t )							( HANDLE Handle, LPWSTR Buffer, int Length, int Something );
typedef HRESULT	( WINAPI * XSidecarGetConsoleSerialNumber_t )			( HANDLE Handle, BYTE* Buffer );
typedef HRESULT	( WINAPI * XSidecarGetVersionInformation_t )			( HANDLE Handle, BYTE* Buffer );
typedef HRESULT	( WINAPI * XSidecarGetVersionInformation_t )			( HANDLE Handle, BYTE* Buffer );

/*Emulator*/

typedef HANDLE	( WINAPI * XSidecarEmulatorOpenKdPipe_t )				( HANDLE Handle, LPCWSTR Name );
typedef HANDLE	( WINAPI * XSidecarEmulatorCloseKdPipe_t )				( HANDLE Pipe );

typedef HRESULT	( WINAPI * XSidecarEmulatorSetPowerState_t )			( HANDLE Handle, BOOL Status );
typedef HRESULT	( WINAPI * XSidecarEmulatorGetPowerState_t )			( HANDLE Handle, BOOL* Status );

typedef HRESULT	( WINAPI * XSidecarEmulatorPressTrayEject_t )			( HANDLE Handle );
typedef HRESULT	( WINAPI * XSidecarEmulatorGetTrayState_t )				( HANDLE Handle, BOOL* Status );

typedef HRESULT	( WINAPI * XSidecarEmulatorSpiBegin_t )					( HANDLE Handle );
typedef HRESULT	( WINAPI * XSidecarEmulatorSpiEnd_t )					( HANDLE Handle );
typedef HRESULT	( WINAPI * XSidecarEmulatorSpiRead_t )					( HANDLE Handle, BYTE* Buffer, SIZE_T Length, DWORD* BytesRead );
typedef HRESULT	( WINAPI * XSidecarEmulatorSpiWrite_t )					( HANDLE Handle, BYTE* Buffer, SIZE_T Length );

extern XSidecarOpenEmulatorList_t XSidecarOpenEmulatorList;
extern XSidecarOpenListItem_t XSidecarOpenListItem;
extern XSidecarGetListItemCount_t XSidecarGetListItemCount;
extern XSidecarGetListItemName_t XSidecarGetListItemName;
extern XSidecarCloseList_t XSidecarCloseList;

extern XSidecarGetName_t XSidecarGetName;
extern XSidecarGetConsoleSerialNumber_t XSidecarGetConsoleSerialNumber;
extern XSidecarGetVersionInformation_t XSidecarGetVersionInformation;

extern XSidecarEmulatorOpenKdPipe_t XSidecarEmulatorOpenKdPipe;
extern XSidecarEmulatorCloseKdPipe_t XSidecarEmulatorCloseKdPipe;

extern XSidecarEmulatorSetPowerState_t XSidecarEmulatorSetPowerState;
extern XSidecarEmulatorGetPowerState_t XSidecarEmulatorGetPowerState;

extern XSidecarEmulatorPressTrayEject_t XSidecarEmulatorPressTrayEject;
extern XSidecarEmulatorGetTrayState_t XSidecarEmulatorGetTrayState;

extern XSidecarEmulatorSpiBegin_t XSidecarEmulatorSpiBegin;
extern XSidecarEmulatorSpiEnd_t XSidecarEmulatorSpiEnd;
extern XSidecarEmulatorSpiRead_t XSidecarEmulatorSpiRead;
extern XSidecarEmulatorSpiWrite_t XSidecarEmulatorSpiWrite;

bool LoadXSidecar( );

bool UnloadXSidecar( );