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
	setInterval(function(){
		device[0].value = Math.round(Math.random()*10);
		calculateSpecialDevices();
	},1000);
};

function extract(array, object) {
	var vals = new Array();
	for(var i = 0; i < array.length; i++)
		vals [i] = array[i][object];
	if(settings.debug) console.log(vals);
	return vals;
}

exports.updateDevice = function (newdevice) {
	device[0].value = newdevice[0].value; //TODO: replace with proper update. Not just device 0.
	calculateSpecialDevices();
};

exports.startCountdown = function() {
	cacheDeviceData();
	logDevices = setInterval(function() {
		logger.logArray(sequencer.time(), extract(device, 'value'));
	},100);
};

//calculations for integrals and derivatives
function calculateSpecialDevices() {
	derivateDevices();
	integrateDevices();
	cacheDeviceData();
}

function integrateDevices() {
	var hrTime = process.hrtime();
	time = (hrTime[0] + hrTime[1] / 1000000000);
	for(var i = 0; i < device.length; i++) {
		if(device[i].integrand) {
			var integrand = parseInt(device[i].integrand);
			if(!device[i].value) device[i].value = 0; //TODO: this is dumb...
			device[i].value += (((device[integrand].value + device[integrand].lastValue) / 2) * (time - device[i].lastUpdate));
			if(settings.debug) console.log("integrand: " + integrand + " integral: " + device[i].value);
		}
	}
}

function derivateDevices() {
	var hrTime = process.hrtime();
	time = (hrTime[0] + hrTime[1] / 1000000000);
	for(var i = 0; i < device.length; i++) {
		if(device[i].derivativeOf) {
			var derivativeOf = parseInt(device[i].derivativeOf);
			if(!device[i].value) device[i].value = 0; //TODO: this is dumb...
			device[i].value = ((device[derivativeOf].value - device[derivativeOf].lastValue) / (time - device[i].lastUpdate));
			if(settings.debug)	console.log("derivativeOf: " + derivativeOf + " derivative: " + device[i].value);
		}
	}
}

function cacheDeviceData() {
	var hrTime = process.hrtime();
	time = (hrTime[0] + hrTime[1] / 1000000000);
	for(var i = 0; i < device.length; i++) {
		device[i].lastUpdate = time;
		device[i].lastValue = device[i].value;
	}
}

exports.device = device;