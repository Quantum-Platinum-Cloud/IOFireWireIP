/*
 * Copyright (c) 1998-2001 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 *
 * The contents of this file constitute Original Code as defined in and
 * are subject to the Apple Public Source License Version 1.1 (the
 * "License").  You may not use this file except in compliance with the
 * License.  Please obtain a copy of the License at
 * http://www.apple.com/publicsource and read it before using this file.
 *
 * This Original Code and all software distributed under the License are
 * distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE OR NON-INFRINGEMENT.  Please see the
 * License for the specific language governing rights and limitations
 * under the License.
 *
 * @APPLE_LICENSE_HEADER_END@
 */
#ifndef _IOKIT_IPPORT_H
#define _IOKIT_IPPORT_H

#include <IOKit/IOService.h>
#include <IOKit/firewire/IOFWLocalIsochPort.h>

class IOFireWireController;

class IOIPPort : public IOFWLocalIsochPort
{
    OSDeclareDefaultStructors(IOIPPort)

private:
	
	UInt32	fChannel ;
		
public:
    virtual bool init(IODCLProgram *program, IOFireWireController *control, UInt32 channel);

	// Return maximum speed and channels supported
	// (bit n set = chan n supported)
    IOReturn getSupported(IOFWSpeed &maxSpeed, UInt64 &chanSupported);

    // Allocate hardware resources for port
    virtual IOReturn allocatePort(IOFWSpeed speed, UInt32 chan);
    virtual IOReturn releasePort();     // Free hardware resources
    virtual IOReturn start();           // Start port processing packets
    virtual IOReturn stop();            // Stop processing packets
    virtual IOReturn notify(IOFWDCLNotificationType 	notificationType,
							DCLCommand ** 				dclCommandList, 
							UInt32 						numDCLCommands ) ;
    
};

#endif /* _IOKIT_IPPORT_H */
