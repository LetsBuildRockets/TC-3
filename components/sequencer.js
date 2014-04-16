var actions;
var sendUpdate;
var sequenceState = "";
var sequenceRunning = false;
var sequence = { };
var sequenceInitTime;
var lastTimeSent = "";

exports.init = function init(newActions, newSendUpdate, newSettings){
	actions = newActions;
	sendUpdate = newSendUpdate;
	actions.init(newSendUpdate, newSettings);
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
	sendUpdate('sequenceState', sequenceState);
};

function que(index, commands, settings) {
	setTimeout(function() {
		if(sequenceRunning){
			if(settings.debug) console.log(index);
			sequence[commands[index].run](settings, commands[index].params);
			sendUpdate('sequenceState', sequenceState);
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

exports.getsequenceState = function getsSquenceState(){
	return sequenceState;
};

setInterval(function() {
	if(sequenceRunning){
		updateTime();
	}
}, 500);

function updateTime(){
	var hrTime = process.hrtime();
	var T = countdown+(hrTime[0] + hrTime[1] / 1000000000)-sequenceInitTime;
	T = Math.round(T);
	if(T != lastTimeSent)
		sendUpdate('time', T.toString());
	lastTimeSent = T;
}