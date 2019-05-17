#include <Windows.h>
#include <stdio.h>

#include "XSidecar.h"

typedef unsigned long long QWORD;

int main( )
{
	if ( LoadXSidecar( ) )
	{
		auto List = XSidecarOpenEmulatorList( ); // List is actually a structure
		auto ListCount = XSidecarGetListItemCount( List ); // *(DWORD*)(List + 0x4)

		printf( "List: %08X\n", List );

		printf( "List Count: %i\n", ListCount );

		WCHAR ConsoleNameBuffer[ 0x200 ];
		BYTE SerialNumber[ 0x8 ]; // this is most likely a struct

		for ( int i = 0; i < ListCount; ++i )
		{
			auto Sidecar = XSidecarOpenListItem( List, i );

			if ( XSidecarGetName( Sidecar, ConsoleNameBuffer, 50, 0 ) == 0 )
			{
				printf( "Name: %ws\n", ConsoleNameBuffer );
			}

			memset( ConsoleNameBuffer, 0, sizeof( ConsoleNameBuffer ) );

			if ( XSidecarGetConsoleSerialNumber( Sidecar, SerialNumber ) == 0 )
			{
				printf( "Serial Number: %0.2x%0.2x%0.2x%0.2x%0.2x\n", SerialNumber[ 1 ], SerialNumber[ 2 ], SerialNumber[ 3 ], SerialNumber[ 4 ], SerialNumber[ 5 ] );
			}

			VERSION_INFOMATION Info;

			if ( XSidecarGetVersionInformation( Sidecar, &Info ) == 0 )
			{
				printf( "Version Information:\n    FW:    %d.%d\n    FPGA:  %x.%x\n    Board: %x.%x\n", Info.FWMajor, Info.FWMinor, Info.FPGAMajor, Info.FPGAMinor, Info.BoardMajor, Info.BoardMinor );
			}

			XSidecarEmulatorSetPowerState( Sidecar, FALSE );

		}

		XSidecarCloseList( List );
	}

	printf( "Unloading\n" );

	UnloadXSidecar( );

	getchar( );

	return 0;
}