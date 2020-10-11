#include "Pletacka_wifi.hpp"
#include "Pletacka.hpp"

/**
 * @brief Construct a new Pletacka_wifi::Pletacka_wifi object
 * 
 */
Pletacka_wifi::Pletacka_wifi()
{
 
}

Pletacka_wifi::~Pletacka_wifi()
{
}

void Pletacka_wifi::init(PletackaConfig* config)
{
	wifiCfg.wifiName = config->wifiName;
	wifiCfg.wifiPassword = config->wifiPassword;
	wifiCfg.wifiChanel = config->wifiChenel;
	wifiCfg.wifiDefaulAp = config->wifiDefaulAp;
	wifiCfg.apName = config->apName;
	wifiCfg.apPassword = config->apPassword;
	sensorNumber = config->sensorNumber;

	configConnection();
}

void Pletacka_wifi::configConnection()
{
	if(wifiCfg.wifiDefaulAp)
	{
		startAP();
			
	}
	else
	{
		connectWifi();
			
	}
		
}


void Pletacka_wifi::connectWifi()
{
	pletacka.println("Connecting to " + wifiCfg.wifiName);

	// From : https://randomnerdtutorials.com/esp32-static-fixed-ip-address-arduino-ide/
		// Set your Static IP address
		IPAddress local_IP(192, 168, 1, 150+sensorNumber);
		// Set your Gateway IP address
		IPAddress gateway(192, 168, 1, 1);

		IPAddress subnet(255, 255, 255, 252);
		IPAddress primaryDNS(8, 8, 8, 8);   //optional
		IPAddress secondaryDNS(8, 8, 4, 4); //optional

		// Configures static IP address
		if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)) {
			pletacka.showError("STA Failed to configure");
		}		

	//End from

	WiFi.begin(wifiCfg.wifiName.c_str(), wifiCfg.wifiPassword.c_str());

	int counter = 0;
	bool ledWifiState = true;

	while (WiFi.status() != WL_CONNECTED) {
			counter++;
			delay(500);
			pletacka.print(".");
			pletacka.showMsg("Connecting " + wifiCfg.wifiName); 
			digitalWrite(LED_WIFI, ledWifiState);
			ledWifiState = !ledWifiState;

			if(counter> 10)
			{
					pletacka.showError("Not connected to WiFi");            
			}
	}

	
	pletacka.showMsg("WiFi " + wifiCfg.wifiName);
	pletacka.hideError();

	pletacka.println("\nWiFi connected");
	pletacka.print("IP address: ");
	pletacka.print(WiFi.localIP().toString());
	pletacka.print("    MAC address: ");
	pletacka.println(String(WiFi.macAddress()));   
	digitalWrite(LED_WIFI, true); 
		
}

void Pletacka_wifi::startAP()
{
		pletacka.showMsg("AP: "+wifiCfg.apName);
		pletacka.println("Starting **" + wifiCfg.apName + "** AP");
		WiFi.softAP(wifiCfg.apName.c_str(), wifiCfg.apPassword.c_str(), wifiCfg.apChanel );

}



