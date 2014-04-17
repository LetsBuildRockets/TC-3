var sensors = new Array();
var settings;

exports.init = function init(newSettings){
	sensors[0] = 0;
	sensors[1] = 5;
	sensors[2] = 10;
	sensors[3] = 15;
	sensors[4] = 20;
	sensors[5] = 25;
	sensors[6] = 30;
	sensors[7] = 35;
	sensors[8] = 40;
	sensors[9] = 45;
	sensors[10] = 50;
	
	settings = newSettings;
};



exports.sensors = sensors;