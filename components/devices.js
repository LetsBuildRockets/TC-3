var sensors = new Array();
var settings;
var sequencer;
var serial;
var logger;
var devicesNames = new Array(11);

exports.init = function init(newSettings, newSequencer, newSerial, newLogger){
	logger = newLogger;
	settings = newSettings;
	serial = newSerial;
	sequencer = newSequencer;
	
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

	for(var i = 0; i < sensors.length; i++)
		devicesNames[i] = (settings.devices.names[i] ? settings.devices.names[i] : "NaN");
	logger.logArray(sequencer.time(), devicesNames);
};


exports.updateSensors = function (newSensors){
	sensors[0] = newSensors[0];
};

exports.startCountdown = function() {
	logDevices = setInterval(function(){
		logger.logArray(sequencer.time(), sensors);
	},100);
};

exports.sensors = sensors;