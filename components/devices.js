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
		//device.push([i, settings.devices[i]]);
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
	console.log(str);
	return str;
}

exports.updateDevice = function (newdevice) {
	device[0] = newdevice[0].value;
};

exports.startCountdown = function() {
	logDevices = setInterval(function() {
		logger.logArray(sequencer.time(), device);
	},100);
};

exports.device = device;