/**
 * multiOTP Credential Provider, extends privacyIdea
 *
 * @author    Yann Jeanrenaud, SysCo systemes de communication sa, <info@multiotp.net>
 * @version   5.8.4.0
 * @date      2021-11-18
 * @since     2021
 * @copyright (c) 2016-2021 SysCo systemes de communication sa
 * @copyright (c) 2015-2016 ArcadeJust ("RDP only" enhancement)
 * @copyright (c) 2013-2015 Last Squirrel IT
 * @copyright Apache License, Version 2.0
 *
 *
 * Change Log
 *
 *   2021-03-24 1.0.0.0 SysCo/yj New implementation from scratch
 *
 *********************************************************************/
#include "MultiotpHelpers.h"
#include "MultiOTP.h"
#include "OfflineHandler.h"
#include "Logger.h"
#include "Endpoint.h"
#include "PIConf.h"
#include "Codes.h"
#include "SecureString.h"
#include <Windows.h>
#include <string>
#include <map>
#include <functional>
#include <atomic>
#include "MultiotpRegistry.h"

using namespace std;

MultiOTP::MultiOTP(PICONFIG conf):PrivacyIDEA(conf)
{
}

HRESULT MultiOTP::validateCheck(const std::wstring& username, const std::wstring& domain, const SecureWString& otp, const std::string& transaction_id)
{
	HRESULT hr = E_UNEXPECTED;
	hr = multiotp_request(username, L"", otp);

	// G�rer le prev OTP
	

	if ((hr == MULTIOTP_SUCCESS)) {
		if (DEVELOP_MODE) PrintLn("MultiotpCredential::multiOTP Success, value ", hr);//OTP ok
		return PI_AUTH_SUCCESS;
	}
	else {
		if (DEVELOP_MODE) PrintLn("MultiotpCredential::multiOTP Error, value ", hr);//OTP ok
		return PI_AUTH_FAILURE;
	}
}