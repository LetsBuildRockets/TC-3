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
		device[i].value = i*3;
	}

	logger.logArray(sequencer.time(), extract(device, 'name'));

	//Create Random Data
	/*setInterval(function(){
		for(var i = 0; i < device.length; i++)
			device[i].value = Math.round(Math.random()*50);
	},1000);*/
};

function extract(array, object) {
	var vals = new Array();
	for(var i = 0; i < array.length; i++)
		vals [i] = array[i][object];
	if(settings.debug) console.log(vals);
	return vals;
}

function integrateDevices(){
	for(var i = 0; i < device.length; i++) {
		if(device[i].integrand) {
			var integrand = parseInt(device[i].integrand);
			if(!device[i].value) device[i].value = 0; //this is dumb...
			device[i].value += (((device[integrand].value + device[integrand].lastValue) / 2) * (sequencer.time() - device[integrand].lastUpdate));
			if(settings.debug) console.log("integrand: " + integrand + " integtal: " + device[i].value);
		}
	}
	cacheDeviceData();
}

function cacheDeviceData() {
	for(var i = 0; i < device.length; i++) {
		device[i].lastUpdate = sequencer.time();
		device[i].lastValue = device[i].value;
	}
}

exports.updateDevice = function (newdevice) {
	device[0].value = newdevice[0].value;
	integrateDevices();
};

exports.startCountdown = function() {
	cacheDeviceData();
	logDevices = setInterval(function() {
		logger.logArray(sequencer.time(), extract(device, 'value'));
	},100);
};

exports.device = device;