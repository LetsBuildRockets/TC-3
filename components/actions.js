var serial = require('./serial');
var settings;
var outputs = new Array(24);
var sendUpdate;

exports.init = function(newSendUpdate, newSettings){
	settings = newSettings;
	sendUpdate = newSendUpdate;
	setInterval(function() {
		update();
	}, 500);
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
	serial.write(address , state);
	outputs[address ] = state;
};

exports.oxyValve = function oxyValve(state){
	var address = settings.outputs.oxyValve;
	serial.write(address, state);
	outputs[address] = state;
};

exports.end = function(){
	ignitor(false);
	fuelValve(false);
	oxyValve(false);
};

function update(){
	for(var a = 0; a <= outputs.length; a++){
		sendUpdate('action', a + ":" + outputs[a]);
	}
}
