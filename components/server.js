var yaml = require('js-yaml');
var fs = require('fs');
var express = require('express');
var app = express()
, server = require('http').createServer(app)
, io = require('socket.io').listen(server);

var sequencer = require('./sequencer');
var settings = yaml.safeLoad(fs.readFileSync('./config/settings.yaml', 'ascii'));

server.listen(settings.server.port);

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

	socket.on('controlState', function (data) {
		if(data == 'initiate') {
			sequencer.startSequence(sendUpdate, settings);
			if(settings.debug) console.log(sequencer.getsequenceState());
		} else if (data == 'stop') {
			sequencer.stopSequence(sendUpdate, settings);
			if(settings.debug) console.log(sequencer.getsequenceState());
		}
	});

});

function sendUpdate(name, data){
	io.sockets.emit(name, data);
};