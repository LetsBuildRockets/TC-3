var device = new Array();
var settings;
var sequencer;
var serial;
var logger;

exports.init = function init(newSettings, newSequencer, newSerial, newLogger) {
	logger = newLogger;
	settings = newSettings;
	serial = newSerial;
	sequencer = newSequencer;

	for(var i in settings.devices)
		device[i] = settings.devices[i];

	//init filler data
	for(var i = 0; i < device.length; i++) {
		device[i].value = i*5;
	}

	logger.write(sequencer.time() + "," + extract(device, 'name'));

	//Create Random Data
	/*setInterval(function(){
		for(var i = 0; i < device.length; i++)
			device[i].value = Math.round(Math.random()*50);
	},1000);*/
};

function extract(array, object) {
	var str = "";
	for(var i = 0; i < array.length; i++)
		str += (array[i][object]) + ",";
	if(settings.debug) console.log(str);
	return str;
}

function integrateDevices(){
	for(var i = 0; i < device.length; i++) {
		if(device[i].integrate) {
			var itegrand = parseInt(device[i].integrate); 
			device[i] = ((device[itegrand] + device[itegrand].lastValue) / 2) * (seq.time() - device[itegrand].lastUpdate);
		}
	}
}

function cacheDeviceData() {
	for(var i = 0; i < device.length; i++) {
		device[i].lastUpdate = sequencer.time();
		device[i].lastValue = device[i].value;
	}
}

exports.updateDevice = function (newdevice) {
	cacheDeviceData();
	device[0] = newdevice[0].value;
};

exports.startCountdown = function() {
	cacheDeviceData();
	logDevices = setInterval(function() {
		logger.logArray(sequencer.time(), device);
	},100);
};

exports.device = device;