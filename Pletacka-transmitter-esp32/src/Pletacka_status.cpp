#include "Pletacka_status.hpp"
#include "pletacka.hpp"



void Pletacka_status::init(PletackaConfig config)
{
	optoFinish.setPin(config.pinFinish);
	optoStop.setPin(config.pinStop);

	opto.finish = optoFinish.state();
	opto.stop = optoStop.state();
}

String Pletacka_status::getStatus()
{
	static int Spletac1_run = ON;

	String output = "";
	
	opto.finish = optoFinish.state();
	opto.stop = optoStop.state();

	switch (Spletac1_run)
	{
		case ON:
			//pletacka.debugln("ON", "St:");
			Spletac1_run = DEF;
			output = "ON";
			break;
		case STOP:
			//pletacka.debugln("STOP", "St:");
			output = "STOP";

			if (opto.stop!=SSTOP) //END STOP
			{
				//pletacka.debugln("REWORK", "St:");
				Spletac1_run = DEF;
				output = "REWORK";
			}
			break;
		
		default:
			//pletacka.debugln("DEF", "St:");

			if(opto.stop==SSTOP)
			{
				Spletac1_run = STOP;
			}
			else
			{
				if(opto.finish==SFINISHED)
				{
					output = "FINISHED";
				}
				else
				{
					output = "";
				}
				
			}
			break;
	}    


}