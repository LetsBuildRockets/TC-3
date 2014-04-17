var serial;
var settings;
var ignitorInterval = null;
var outputs = new Array(4);

exports.init = function(newSettings, newSerial){
	settings = newSettings;
	serial = newSerial;
	for(var i = 0; i < outputs.length; i++)
		outputs[i] = 0;
};

exports.ignitor = function ignitor(state){
	var address = settings.outputs.ignitor;
	if(state)
		ignitorInterval = serial.pulse(address, 100);
	else {
		clearInterval(ignitorInterval);
		serial.write(address, false);
	}
	outputs[address] = state;
};

exports.ignitorFuelValve = function ignitorFuelValve(state){
	var address = settings.outputs.ignitorFuelValve;
	serial.write(address, state);
	outputs[address] = state;
};

exports.ignitorOxyValve = function ignitorOxylValve(state){
	var address = settings.outputs.ignitorOxyValve;
	serial.write(address, state);
	outputs[address] = state;
};

exports.fuelValve = function fuelValve(state){
	var address = settings.outputs.fuelValve;
	serial.write(address, state);
	outputs[address] = state;
};

exports.oxyValve = function oxyValve(state){
	var address = settings.outputs.oxyValve;
	serial.write(address, state);
	outputs[address] = state;
};

exports.end = function(){
	exports.ignitor(false);
	exports.fuelValve(false);
	exports.oxyValve(false);
};

exports.outputs = outputs;
