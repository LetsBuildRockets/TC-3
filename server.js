var yaml = require('js-yaml');
var fs = require('fs');
var app = require('express')()
, server = require('http').createServer(app)
, io = require('socket.io').listen(server);
var devices = require('./components/devices');
var settings = yaml.safeLoad(fs.readFileSync('./config/settings.yaml', 'ascii'));


server.listen(settings.server.port);

app.get('/', function (req, res) {
	res.sendfile(__dirname + '/index.html');
});

io.sockets.on('connection', function (socket) {
	socket.emit('status', 'Connected!');

	socket.on('burnState', function (data) {
		if(data == 'initiate') {
			devices.burn(settings);
			if(settings.debug) console.log(devices.getBurnState());
		} else if (data == 'stop') {
			devices.stop(settings);
			if(settings.debug) console.log(devices.getBurnState());
		}
	});


	var lastSent = "";
	setInterval(function() {
		var data = devices.getBurnState().toString();
		if(data != lastSent) {
			socket.emit('burn', data);
			lastSent = data;
		}
	}, 10);

});