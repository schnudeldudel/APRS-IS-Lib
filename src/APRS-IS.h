
#ifndef APRS_IS_Lib_h_
#define APRS_IS_Lib_h_

#ifdef ESP8266
#include <ESP8266WiFi.h>
#else
#include <WiFi.h>
#endif
#include <APRS-Decoder.h>

class APRS_IS
{
public:
	APRS_IS(const String & user, const String & passcode, const String & tool_name, const String & version);

	bool connect(const String & server, const int port);
	bool connect(const String & server, const int port, const String & filter);
	bool connected();
	void disconnect();
	bool sendMessage(const String & message);
	bool sendMessage(const std::shared_ptr<APRSMessage> message);

	int available();

	String getMessage();
	std::shared_ptr<APRSMessage> getAPRSMessage();

private:
	const String _user;
	const String _passcode;
	const String _tool_name;
	const String _version;
	WiFiClient _client;

	bool _connect(const String & server, const int port, const String & login_line);
};

#endif

