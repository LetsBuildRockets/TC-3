var yaml = require('js-yaml');
var fs = require('fs');
var express = require('express');
var app = express()
, server = require('http').createServer(app)
, io = require('socket.io').listen(server);

var sequencer = require('./sequencer');
var devices = require('./devices');
var actions = require('./actions');
var settings = yaml.safeLoad(fs.readFileSync('./config/settings.yaml', 'ascii'));

exports.init = function init(){
	server.listen(settings.server.port);

	devices.init(settings);
	actions.init(settings);
	sequencer.init(actions, settings);
};


app.use(express.static('./components/web/'));

app.get('/', function (req, res) {
	res.sendfile('./components/web/index.html');
});

app.get('/control', function (req, res) {
	res.sendfile('./components/web/control.html');
});

app.get('/estop', function (req, res) {
	res.sendfile('./components/web/estop.html');
});

io.sockets.on('connection', function (socket) {
	socket.emit('serverStatus', 'connected');
	update(true);
	socket.on('controlState', function (data) {
		if(data == 'initiate') {
			sequencer.startSequence(settings);
			if(settings.debug) console.log(sequencer.getsequenceState());
		} else if (data == 'stop') {
			sequencer.stopSequence(settings);
			if(settings.debug) console.log(sequencer.getsequenceState());
		}
	});

	setInterval(function() {
		update();
	}, 500);
});

var lastSensorsUpdate = "";
var lastActionsUpdate = "";
var lastTimeUpdate = "";
var lastSequenceUpdate = "";
function update(force) {
	var sensorsUpdate = "";
	for(var s = 0; s < devices.sensors.length; s++){
		sensorsUpdate += s + ":" + devices.sensors[s] + "\n";
	}
	if(sensorsUpdate != lastSensorsUpdate || force)
		sendUpdate('sensor', sensorsUpdate);
	lastSensorsUpdate = sensorsUpdate;

	var actionsUpdate = "";
	for(var a = 0; a < actions.outputs.length; a++){
		actionsUpdate += a + ":" + (actions.outputs[a] ? 1 : 0) + "\n";
	}
	if(actionsUpdate != lastActionsUpdate || force)
		sendUpdate('action', actionsUpdate);
	lastActionsUpdate = actionsUpdate;

	var timeUpdate = sequencer.time();
	if(timeUpdate != lastTimeUpdate || force)
		sendUpdate('time', timeUpdate);
	lastTimeUpdate = timeUpdate;


	var sequenceUpdate = sequencer.sequenceState();
	if(sequenceUpdate != lastSequenceUpdate)
		sendUpdate('sequenceState', sequenceUpdate);
	lastSequenceUpdate = sequenceUpdate;
};

function sendUpdate(name, data) {
	io.sockets.emit(name, data);
};