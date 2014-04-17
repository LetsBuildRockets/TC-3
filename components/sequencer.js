var actions;
var sequenceState = "";
var sequenceRunning = false;
var sequence = { };
var sequenceInitTime;
var lastTimeSent = "";
var countdown;

exports.init = function init(newActions, newSettings){
	actions = newActions;
};

exports.startSequence = function startSequence(settings) {
	if(!sequenceRunning){
		sequenceRunning = true;
		countdown = settings.sequence.command0.time;

		var commandNum = -1;
		var commands = new Array();

		while(commands[commandNum] != undefined || commandNum == -1){
			commandNum++;
			commands[commandNum] = settings.sequence['command'+commandNum];
			if(commands[commandNum] != undefined){
				if(settings.debug) console.log(commands[commandNum]);
				que(commandNum, commands, settings);
			}
		}
	}
};

exports.stopSequence = function stopSequence(settings) {
	sequence.end(settings);
};

function que(index, commands, settings) {
	setTimeout(function() {
		if(sequenceRunning){
			if(settings.debug) console.log(index);
			sequence[commands[index].run](settings, commands[index].params);
		}
	}, (commands[index].time-countdown)*1000);
}

sequence.init = function sequenceInit(settings, params){
	var hrTime = process.hrtime();
	sequenceInitTime = (hrTime[0] + hrTime[1] / 1000000000);
	sequenceState = "sequencer initialized";
};

sequence.ignitor = function sequenceIgnitor(settings, state){
	sequenceState = "ignitor " + state;
	actions.ignitor(state);
};

sequence.ignitorFuelValve = function sequenceIgnitorFuelValve(settings, state){
	sequenceState = "ignitorFuelValve " + state;
	actions.ignitorFuelValve(state);
};

sequence.ignitorOxyValve = function sequenceIgnitorOxyValve(settings, state){
	sequenceState = "ignitorOxyValve " + state;
	actions.ignitorOxyValve(state);
};

sequence.fuelValve = function sequencefuelValve(settings, state){
	sequenceState = "fuelValve " + state;
	actions.fuelValve(state);
};

sequence.oxyValve = function sequenceOxyValve(settings, state){
	sequenceState = "oxyValve " + state;
	actions.oxyValve(state);
};

sequence.end = function sequenceEnd(settings, params){
	sequenceRunning = false;
	sequenceState = "stop";
	actions.end();
};

exports.sequenceState = function getsSquenceState(){
	return sequenceState;
};

exports.time = function updateTime(){
	if(sequenceRunning) {
		var hrTime = process.hrtime();
		var T = countdown+(hrTime[0] + hrTime[1] / 1000000000)-sequenceInitTime;
		return Math.round(T);
	} else
		return null;
};