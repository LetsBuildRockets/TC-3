var serial = require('./serial');
var settings = yaml.safeLoad(fs.readFileSync('../config/settings.yaml', 'ascii'));

exports.ignitor = function ignitor(state){
	serial.write(settings.outputs.ignitor, state);
};

exports.fuelVavle = function fuelValve(state){
	serial.write(settings.outputs.fuelVavle, state);
};

exports.oxyValve = function oxyValve(state){
	serial.write(settings.outputs.oxyValve, state);
};

exports.end = function(){
	ignitor(false);
	fuelValve(false);
	oxyValve(false);
};