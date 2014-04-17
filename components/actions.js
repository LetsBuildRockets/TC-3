var serial;
var settings;
var logger;
var sequencer;
var ignitorInterval = null;
var outputs = new Array(16);
var outputNames = new Array(16);

exports.init = function(newSettings, newSequencer, newSerial, newLogger){
	settings = newSettings;
	logger = newLogger;
	serial = newSerial;
	sequencer = newSequencer;
	for(var i = 0; i < outputs.length; i++)
		outputs[i] = 0;
	for(var i = 0; i < outputNames.length; i++)
		outputNames[i] = (settings.outputs.names[i] ? settings.outputs.names[i]: "NaN");
	logActions(outputNames);
};

exports.startCountdown = function(){
	logActions();
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
	logActions();
};

exports.ignitorFuelValve = function ignitorFuelValve(state){
	var address = settings.outputs.ignitorFuelValve;
	serial.write(address, state);
	outputs[address] = state;
	logActions();
};

exports.ignitorOxyValve = function ignitorOxylValve(state){
	var address = settings.outputs.ignitorOxyValve;
	serial.write(address, state);
	outputs[address] = state;
	logActions();
};

exports.fuelValve = function fuelValve(state){
	var address = settings.outputs.fuelValve;
	serial.write(address, state);
	outputs[address] = state;
	logActions();
};

exports.oxyValve = function oxyValve(state){
	var address = settings.outputs.oxyValve;
	serial.write(address, state);
	outputs[address] = state;
	logActions();
};

exports.end = function(){
	exports.ignitor(false);
	exports.fuelValve(false);
	exports.oxyValve(false);
	logger.close();
};


function logActions(dataArray){
	var str = "";
	if(dataArray == null) {
		dataArray = outputs;
		for(var i = 0; i < dataArray.length; i++)
			str += (dataArray[i] ? "1" : "0") + ",";
	} else 
		for(var i = 0; i < dataArray.length; i++)
			str += dataArray[i] + ",";
	logger.write(sequencer.time() + "," + str);
};

exports.outputs = outputs;
