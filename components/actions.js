var serial;
var settings;
var logger;
var sequencer;
var ignitorInterval = null;
var outputs = new Array(16);
var outputNames = new Array(16);

exports.init = function(newSettings, newSequencer, newSerial, newLogger){
	this.settings = newSettings;
	this.logger = newLogger;
	this.serial = newSerial;
	this.sequencer = newSequencer;
	for(var i = 0; i < outputs.length; i++)
		this.outputs[i] = 0;
	for(var i = 0; i < outputNames.length; i++)
		outputNames[i] = (this.settings.outputs.names[i] ? this.settings.outputs.names[i] : "NaN");
	this.logger.logArray(this.sequencer.time(), outputNames);
};

exports.startCountdown = function(){
	this.logger.logArray(this.sequencer.time(), outputs);
};

exports.ignitor = function ignitor(state){
	var address = this.settings.outputs.ignitor;
	if(state)
		ignitorInterval = this.serial.pulse(address, 100);
	else {
		clearInterval(ignitorInterval);
		this.serial.write(address, false);
	}
	this.outputs[address] = state;
	this.logger.logArray(this.sequencer.time(), outputs, true);
};

exports.ignitorFuelValve = function ignitorFuelValve(state){
	var address = this.settings.outputs.ignitorFuelValve;
	this.serial.write(address, state);
	outputs[address] = state;
	this.logger.logArray(this.sequencer.time(), outputs, true);
};

exports.ignitorOxyValve = function ignitorOxylValve(state){
	var address = this.settings.outputs.ignitorOxyValve;
	this.serial.write(address, state);
	this.outputs[address] = state;
	this.logger.logArray(this.sequencer.time(), outputs, true);
};

exports.fuelValve = function fuelValve(state){
	var address = this.settings.outputs.fuelValve;
	this.serial.write(address, state);
	this.outputs[address] = state;
	this.logger.logArray(this.sequencer.time(), outputs, true);
};

exports.oxyValve = function oxyValve(state){
	var address = this.settings.outputs.oxyValve;
	this.serial.write(address, state);
	this.outputs[address] = state;
	this.logger.logArray(this.sequencer.time(), outputs, true);
};

exports.end = function(){
	exports.ignitor(false);
	exports.fuelValve(false);
	exports.oxyValve(false);
	this.logger.close();
};
exports.outputs = outputs;