/***********************************************************************
KinectServerPlugin - Server object to implement the Kinect 3D video
tele-immersion protocol for the Vrui collaboration infrastructure.
Copyright (c) 2010 Oliver Kreylos

This file is part of the Kinect 3D Video Capture Project (Kinect).

The Kinect 3D Video Capture Project is free software; you can
redistribute it and/or modify it under the terms of the GNU General
Public License as published by the Free Software Foundation; either
version 2 of the License, or (at your option) any later version.

The Kinect 3D Video Capture Project is distributed in the hope that it
will be useful, but WITHOUT ANY WARRANTY; without even the implied
warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See
the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with the Kinect 3D Video Capture Project; if not, write to the Free
Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
02111-1307 USA
***********************************************************************/

#ifndef KINECTSERVERPLUGIN_INCLUDED
#define KINECTSERVERPLUGIN_INCLUDED

#include <string>
#include <Collaboration/ProtocolServer.h>

#include "KinectPipe.h"

class KinectServerPlugin:public Collaboration::ProtocolServer,public KinectPipe
	{
	/* Embedded classes: */
	private:
	class ClientState:public Collaboration::ProtocolServer::ClientState
		{
		/* Elements: */
		public:
		std::string kinectServerHostName; // Host name of client's Kinect server
		int kinectServerPortId; // Port number of client's Kinect server
		bool hasServer; // Flag whether the client has its own Kinect server
		Collaboration::CollaborationPipe::OGTransform inverseNavigationTransform; // Client's current inverse navigation transformation
		
		/* Constructors and destructors: */
		public:
		ClientState(void);
		virtual ~ClientState(void);
		};
	
	/* Methods from Collaboration::ProtocolServer: */
	public:
	const char* getName(void) const;
	virtual unsigned int getNumMessages(void) const;
	virtual ClientState* receiveConnectRequest(unsigned int protocolMessageLength,Collaboration::CollaborationPipe& pipe);
	virtual void receiveClientUpdate(Collaboration::ProtocolServer::ClientState* cs,Collaboration::CollaborationPipe& pipe);
	virtual void sendClientConnect(Collaboration::ProtocolServer::ClientState* sourceCs,Collaboration::ProtocolServer::ClientState* destCs,Collaboration::CollaborationPipe& pipe);
	virtual void sendServerUpdate(Collaboration::ProtocolServer::ClientState* sourceCs,Collaboration::ProtocolServer::ClientState* destCs,Collaboration::CollaborationPipe& pipe);
	};

#endif
