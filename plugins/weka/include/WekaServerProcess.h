// WekaServerProcess.h
// author: Johannes Wagner <wagner@hcm-lab.de>
// created: 2013/06/27
// Copyright (C) University of Augsburg, Lab for Human Centered Multimedia
//
// *************************************************************************************************
//
// This file is part of Social Signal Interpretation (SSI) developed at the 
// Lab for Human Centered Multimedia of the University of Augsburg
//
// This library is free software; you can redistribute itand/or
// modify it under the terms of the GNU General Public
// License as published by the Free Software Foundation; either
// version 3 of the License, or any laterversion.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FORA PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public
// License along withthis library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
//
//*************************************************************************************************

#pragma once

#ifndef SSI_WEKASERVERPROCESS_H
#define SSI_WEKASERVERPROCESS_H

#include "WekaServer.h"

namespace ssi {

class WekaServerProcess : public WekaServer {

public:

	WekaServerProcess (ssi_size_t port,
		ssi_size_t n_buffer,
		const ssi_char_t *model,
		const ssi_char_t *class_path,
		const ssi_char_t *lib_path) :
		WekaServer (port, n_buffer, model, class_path, lib_path) {};
	virtual ~WekaServerProcess () {};

	void enter ();
	void run ();
	void flush ();

protected:

	size_t ExecuteProcess(std::wstring FullPathToExe, std::wstring Parameters, size_t SecondsToWait);
	
	bool _is_running;
	STARTUPINFO _startup_info;
    PROCESS_INFORMATION _process_info;
};

}

#endif