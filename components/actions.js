var serial = require('./serial');
var settings;
var outputs = new Array(4);

exports.init = function(newSettings){
	settings = newSettings;
	for(var i = 0; i < outputs.length; i++)
		outputs[i] = 0;
};

exports.ignitor = function ignitor(state){
	var address = settings.outputs.ignitor;
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
